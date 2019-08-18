import QtQuick 2.12

Item {
    id:id_root2
    property int value:0
    property int granularity:60
    Rectangle{
        width: 2
        height: id_root2.height*0.4
        color: "black"
        anchors{
            horizontalCenter: id_root2.horizontalCenter
            bottom: id_root2.verticalCenter
        }
        antialiasing: true
    }
    rotation: 360/granularity*(value%granularity)
    antialiasing: true
}
