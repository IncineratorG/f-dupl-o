import QtQuick 2.12
import QtQuick.Dialogs 1.3

Rectangle {
    color: "transparent"

    Rectangle {
        id: busyIndicatorWrapper

        anchors.fill: parent

        visible: MakeTransparentScreenModel.busy
        color: "#b3000000"
        z: 1

        MouseArea {
            anchors.fill: parent

            visible: MakeTransparentScreenModel.busy
        }
    }

    Rectangle {
        id: imageWrapper

        anchors.top: parent.top
        anchors.bottom: buttonsWrapper.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.topMargin: 4
        anchors.leftMargin: 4
        anchors.rightMargin: 4

//        color: MakeTransparentScreenModel.busy ? "#000000bf" : "transparent"

        border.width: 1
        border.color: "grey"

        Text {
            id: imagePath

            anchors.left: parent.left

            width: parent.width
            height: parent.height

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: MakeTransparentScreenModel.imagePath
            clip: true
            elide: Text.ElideRight

            visible: MakeTransparentScreenModel.imagePath === MakeTransparentScreenModel.noImagePathString
        }


        Canvas {
            id: canvas

            property string imagePathProp: MakeTransparentScreenModel.imagePath
            onImagePathPropChanged: {
                if (imagePathProp !== MakeTransparentScreenModel.noImagePathString) {
                    canvas.loadImage(imagePathProp)
                }
            }

            anchors.fill: parent

            visible: !imagePath.visible

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    var r = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[0]
                    var g = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[1]
                    var b = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[2]
                    var a = canvas.getContext("2d").getImageData(mouseX, mouseY, 1, 1).data[3]

//                    console.log(r + " - " + g + " - " + b + " - " + a)

                    MakeTransparentScreenController.setTargetColor(r, g, b, a)
                }
            }

            onCanvasSizeChanged: {
                canvas.requestPaint()
            }

            onImageLoaded: {
                var ctx = canvas.getContext("2d");
                ctx.drawImage(imagePathProp,canvas.x,canvas.y,canvas.width,canvas.height);
                canvas.requestPaint();

//                var ar = ctx.getImageData(0, 0, width, height);

//                            for( var x=0; x < ar.data.length; x=x+4 )
//                            {

//                                // To read RGBA values
//                                var red   =  ar.data[x];
//                                var green =  ar.data[x + 1];
//                                var blue  =  ar.data[x + 2];
//                                var alpha =  ar.data[x + 3];

//                                console.log(red + ", " + green + ", " + blue + ", " + alpha );

//                                // To convert to grey scale, modify rgba according to your formula
//                                ar.data[x]     = 0.2126 *ar.data[x]  + 0.7152* ar.data[x+1]  + 0.0722 *ar.data[x+2];
//                                ar.data[x+1]   = 0.2126 *ar.data[x]  + 0.7152* ar.data[x+1]  + 0.0722 *ar.data[x+2];
//                                ar.data[x+2]   = 0.2126 *ar.data[x]  + 0.7152* ar.data[x+1]  + 0.0722 *ar.data[x+2];
//                                ar.data[x+3]   =  255;

//                            }
            }
        }

//        Image {
//            id: image

//            anchors.fill: parent

//            source: MakeTransparentScreenModel.imagePath

//            visible: !imagePath.visible

//            MouseArea {
//                anchors.fill: parent

//                visible: MakeTransparentScreenModel.pixelCoordinatesMode

//                onClicked: {
//                    console.log("CLICKED: " + mouseX + " - " + mouseY + " - " + image.paintedWidth)
//                }
//            }
//        }

        MouseArea {
            anchors.fill: parent

            visible: !MakeTransparentScreenModel.pixelCoordinatesMode

            onClicked: {
                fileDialog.open()
            }
        }
    }

    Rectangle {
        id: buttonsWrapper

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        height: 50

        color: "transparent"

        Rectangle {
            id: chooseColorButtonWrapper

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left

            width: parent.width / 2

            color: "transparent"

            Rectangle {
                id: chooseColorButton

                anchors.fill: parent

                anchors.margins: 4

                color: MakeTransparentScreenModel.targetColor

                border.width: MakeTransparentScreenModel.pixelCoordinatesMode ? 1 : 0
                border.color: "black"

                Text {
                    id: colorHex

                    anchors.left: parent.left

                    width: parent.width
                    height: parent.height

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    text: MakeTransparentScreenModel.targetColorHex
                    clip: true
                    elide: Text.ElideRight
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        MakeTransparentScreenModel.pixelCoordinatesMode = !MakeTransparentScreenModel.pixelCoordinatesMode
                    }
                }
            }
        }

        Rectangle {
            id: changeToTransparentButtonWrapper

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: chooseColorButtonWrapper.right
            anchors.right: parent.right

            color: "transparent"

            Rectangle {
                id: changeToTransparentButton

                anchors.fill: parent

                anchors.margins: 4

                color: "green"

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
//                        console.log("ON_CHANGE_TO_TRANSPARENT_BUTTON_CLICKED")

                        MakeTransparentScreenController.setTargetColorTransparent()
                    }
                }
            }
        }
    }

    FileDialog {
        id: fileDialog

        visible: false

        selectFolder: false

        title: "Выберите изображение"

        onAccepted: {
            MakeTransparentScreenController.setImagePath(fileDialog.fileUrl)
        }
    }
}
