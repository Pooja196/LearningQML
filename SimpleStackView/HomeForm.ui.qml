import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import "./main.qml"

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 5

        CheckBox {
            text: qsTr("Hello")
        }

        Label {
            text: qsTr("You are on the home page.")
        }

        Button {
            text: qsTr("Next")
            //onClicked: stackView.push("Page1Form.ui.qml")
        }
    }
}
