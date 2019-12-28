import QtQuick 2.12
import QtQuick.Controls 2.5
import "ui/components/main-coordinator"

ApplicationWindow {
    id: window
    visible: true

    width: 800
    height: 600
    minimumHeight: height
    minimumWidth: width
    maximumHeight: height
    maximumWidth: width

    title: qsTr("Stack")

    MainCoordinator {
        anchors.fill: parent
    }
}
