import QtQuick 2.7
import QtQuick.Window 2.2
import Enum.Example 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property int value: GadgetExample.NoValue


    EnumExampleB {
        id: example
    }

    Column {
        anchors.centerIn: parent
        spacing: 20
        Text {
            id: text1

            font.pixelSize: 30
            text: "EnumExample type: " + example.type
        }

        Text {
            id: text2

            property int value

            font.pixelSize: 30
            text: "Enum type: " + value
        }
    }

    Timer {
        property int counter

        interval: 2000
        onTriggered: {
            switch (counter) {
            case 0:
                example.type    = EnumExampleB.TypeValue1    // 100
                text2.value     = GadgetExample.TypeValue1  // 1000
                break
            case 1:
                example.type    = EnumExampleB.TypeValue2    // 200
                text2.value     = GadgetExample.TypeValue2  // 2000
                break
            case 2:
                example.type    = EnumExampleB.TypeValue3    // 300
                text2.value     = GadgetExample.TypeValue3  // 3000
                break
            }
            counter = ++counter % 3
        }
        running: true
        repeat: true
    }
}
