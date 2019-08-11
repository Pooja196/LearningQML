import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Image {
        id: background
        source: "/Assets/background1.png"
    }

    Text {
        id: text1
        x:253
        y:203
        color: "#ffffff"
        text: "tcr | vvbiotech"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 40

        OpacityAnimator{
            target: text1;
            from: 0
            to: 1
            duration: 3000
            running: true
        }
    }

    Text{
        id:text2
        x:295
        y:252
        color: "#ff0000"
        text: "Get to Know yourself"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize:20

        OpacityAnimator{
            target: text2;
            from: 0
            to: 1
            duration: 3000
            running: true
        }
    }

    Loader{
        id:pageLoader
    }

    MouseArea{
        anchors.fill: parent
        onClicked: pageLoader.source="pickUser.qml"
    }
}
