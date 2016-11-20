import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
    id: window
    width: 800
    height: 800
    visible: true

    Gauge {
        property bool accelerating

        value: accelerating ? maximumValue : 0
        maximumValue: 250
        anchors {
            fill: parent
            margins: window.height * 0.2
        }

        Component.onCompleted: forceActiveFocus()

        Behavior on value { NumberAnimation { duration: 1000 }}

        Keys.onSpacePressed: accelerating = true
        Keys.onReleased: {
            if (event.key === Qt.Key_Space) {
                accelerating = false;
                event.accepted = true;
            }
        }
    }
}
