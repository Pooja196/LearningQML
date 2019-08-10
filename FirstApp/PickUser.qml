import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Item {
    width: 800
    Image {
        id: background
        source: "Image/background1.png"

        Text {
            id: userselect
            x:58
            y:52
            color: "#ffffff"
            text: "Select \nUser"
            font.pointSize: 30
        }

        Text {
            id: toInitiate
            x:58
            y:150
            color: "#ffffff"
            text: "to initiate testing"
            font.pointSize: 15
            opacity: 0.6
        }

           Image {
               id: okbuttonIcon
               x: 682
               y: 52
               width: 50
               height: 50
               source: "Image/Round_icon_button.png"
               Image {
                   id: okbuttonIcon1
                  anchors.centerIn: parent
                   width: 25
                   height: 25
                   source: "Image/Done_32.png"

                   MouseArea{
                       anchors.fill: parent
                       onClicked: okbuttonIcon1.source="bioMarkerSet.qml"
                   }
               }
           }

            Image {
                id:addbuttonIcon
                x: 622
                y: 52
                width: 50
                height: 50
                source: "Image/Round_icon_button.png"
                Image {
                    id: addbuttonIcon1
                   anchors.centerIn: parent
                    width: 25
                    height: 25
                    source: "Image/Add_new_32.png"
                }
            }
          Flickable{
              x:58
              y:228
              width: 684
              height: 200
              ScrollView{
                  id:usernumber
                  x:0
                  y:0
                  width: parent.width
                  height: parent.height
                  focus: true

                  Label{
                      text: "Userusernumberusernumberusernumberusernumber"
                      font.pixelSize: 150
                  }
                  ScrollBar.horizontal: ScrollBar{
                      parent: usernumber
                      x:usernumber.leftPadding
                      y:usernumber.height-height
                      width: usernumber.availableWidth
                      active:usernumber.ScrollBar.vertical.active
                  }
                  background: Rectangle{
                      border.color: usernumber.activeFocus? "#21be2b" : "#bdbebf"
                  }

              }
          }
    }
}
