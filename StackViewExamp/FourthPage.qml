import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    Rectangle{
        anchors.fill: parent
        color: 'green'
        Button{
            anchors.centerIn: parent
            text: 'Exit'
            onClicked: {
                Qt.quit();
            }
        }
    }
}
