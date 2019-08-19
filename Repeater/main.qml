import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        width:parent.width
        height: 50
        color:"green"
        Label{
            anchors.centerIn: parent
            color:"white"
            id:mytitle
            font.pointSize: 20
        }
    }

    ColumnLayout{
        anchors.topMargin: 60
        anchors.fill: parent
        spacing: 5
        Repeater{
            model:5
            RowLayout{
                Layout.fillHeight:true
                width: parent.width
                height: 10
                spacing: 5
                Repeater{
                    model: ListModel{
                        ListElement{
                            mytext:"button1"
                        }
                        ListElement{
                            mytext:"button2"
                        }
                        ListElement{
                            mytext:"button3"
                        }
                        ListElement{
                            mytext:"button4"
                        }
                        ListElement{
                            mytext:"button5"
                        }
                    }

            Button{
                Layout.fillWidth: true
                text: mytext

                onClicked: {
                    mytitle.text=text
                }
             }
         }
      }
    }
  }
}
