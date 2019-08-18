import QtQuick 2.12

Item {
    id:id_root1
    property int value:0
    property int granularity:60
    Rectangle{
        width: 1
        height: id_root1.height*0.6
        color: "red"
        anchors{
            horizontalCenter: id_root1.horizontalCenter
        }
        antialiasing: true
        y:id_root1.height*0.05
    }
    rotation: 360/granularity*(value%granularity)
    antialiasing:true
}
