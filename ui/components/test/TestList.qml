import QtQuick 2.12
import QtQuick.Controls 1.4

Item {
    Rectangle {
        height: 300
        width: 200

        border.color: "grey"
        border.width: 1

        color: "transparent"

        ListView {
            anchors.fill: parent
            anchors.margins: 4

            clip: true
            spacing: 4

            model: TestScreenListModel

            delegate: Rectangle {
                width: parent.width
                height: 40

                border.width: 1
                border.color: "red"

                Text {
                    width: parent.width

                    text: model.itemName

                    color: "black"
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        TestScreenController.removeTestListItem(model.id)
                    }
                }
            }
        }
    }
}
