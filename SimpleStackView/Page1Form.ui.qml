import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Page {
    width: 600
    height: 400

    title: qsTr("Page 1")

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 5

        RadioButton { text:qsTr("Hello") }

        Label {
            text: qsTr("You are on Page 1.")
        }
    }
}
