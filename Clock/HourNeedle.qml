import QtQuick 2.12

Item {
    id:id_root3
    property int value:0
    property int granularity:0
    property int valueminute:0
    Rectangle{
        width: 2
        height: id_root3.height*0.3
        color: "blue"
        anchors{
            horizontalCenter: id_root3.horizontalCenter
            bottom: id_root3.verticalCenter
        }
        antialiasing: true
    }
    rotation: 360/granularity*(value%granularity)+360/granularity*(valueminute/60)
    antialiasing: true
}
