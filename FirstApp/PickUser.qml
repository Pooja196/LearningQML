import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Item {
    id: element
    width: 800; height: 480

    Image {
        id: background

        Loader{
            id:load
            anchors.fill: parent
        }

        anchors.fill: parent.Center
        source: "Assets/background1.png"

        Text {
            id: userselect
            color: "#ffffff"
            x:58
            y:52
            text: "Select \nUser"
            font.pixelSize: 40
        }

        Text {
            id: toInitiate
            color: "#ffffff"
            x:58
            y:150
            text: "to initiate testing"
            font.pixelSize: 20
            opacity: 0.6
        }
        Image {
               id: okbuttonIcon
               x: 682
               y: 52
               width: 30
               height: 30
               source: "Assets/Done_32.png"

               MouseArea{
                   anchors.fill: parent
                   onClicked: {
                       load.source="BioMarkerSet.qml"
                   }
               }
           }
        Image {
                id:addbuttonIcon
                x: 622
                y: 52
                width: 30
                height: 30
                source: "Assets/Add_new_32.png"
            }

        PickUser_Users {
        id:user

        }
     }
}
