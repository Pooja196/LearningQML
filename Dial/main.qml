import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("dial")
    color: "light gray"

    ColumnLayout{
        anchors.fill: parent
        ProgressBar{
            id:myprogess
            Layout.fillWidth: true
            from:mydial.from
            to:mydial.to
            value: mydial.value
        }

        Dial{
            Layout.fillHeight: true
            Layout.fillWidth: true
            id:mydial
            from: 0
            to:100
            value: 50
        }
    }
    Text {
        id: progValue
        anchors.centerIn: parent
        font.pixelSize: 30
        color: "green"
        text:myprogess.value
    }
}
