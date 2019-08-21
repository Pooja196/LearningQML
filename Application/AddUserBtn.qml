import QtQuick 2.0

    Rectangle {
            id: myButton

            width: 200; height: 120

            property color buttonColor: "white"
            property color buttonColorPressed: "gray"
            property color buttonBorderColor: "gray"
            property color buttonBorderColorPressed: "black"

            MouseArea{
                id: myButtonMouseArea
                anchors.fill: parent
            }

            color: myButtonMouseArea.pressed
                   ? buttonColorPressed : buttonColor

            border.width: 2
            border.color: myButtonMouseArea.pressed
                          ? buttonBorderColorPressed : buttonBorderColor

//            Text{
//                id: buttonLabel
//                anchors.centerIn: parent
//                color: "red"
//                text: "Button Label"
//            }

            Image {
                id: buttonImage
                source: "Assets/Add_new_32.png"
                anchors.centerIn: parent
            }
     }


