import QtQuick 2.0
import "../../components/test"

Item {
    TestList {
        anchors.top: parent.top
        anchors.left: parent.left

        anchors.leftMargin: 4
        anchors.topMargin: 4
    }

    Rectangle {
        id: setTestListWrapper

        height: 30
        width: 100

        anchors.top: parent.top
        anchors.right: parent.right

        color: "red"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                TestScreenController.setTestList()
            }
        }
    }

    Rectangle {
        id: addTestListItemWrapper

        height: 30
        width: 100

        anchors.top: setTestListWrapper.bottom
        anchors.right: parent.right

        color: "green"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                TestScreenController.addTestListItem()
            }
        }
    }



//    Rectangle {
//        height: 30
//        width: 100

//        anchors.centerIn: parent

//        color: "blue"

//        MouseArea {
//            anchors.fill: parent

//            onClicked: {
//                TestScreenController.test()
//            }
//        }
//    }

//    Rectangle {
//        height: 30
//        width: 100

//        anchors.bottom: parent.bottom
//        anchors.horizontalCenter: parent.horizontalCenter

//        anchors.bottomMargin: 8

//        color: "red"

//        MouseArea {
//            anchors.fill: parent

//            onClicked: {
//                console.log("CLICKED")
//            }
//        }
//    }
}
