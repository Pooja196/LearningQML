import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("MicroFludic")

    Image {
        id: background
        source: "Image/background1.png"
    }

    Text {
        id: text1
        x:274
        y:204
        color: "#ffffff"
        text: "tcr | vvbiotech"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 30

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
        x:307
        y:258
        color: "#ff0000"
        text: "Get to Know yourself"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize:15

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
