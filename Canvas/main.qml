import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Paint App")

    RowLayout{
        id:option
        anchors.horizontalCenter: parent.horizontalCenter
        z:canvas.z+1

        Button{
            text:'Clear'
            onClicked: {
                canvas.clear();
            }
        }
        Button{
            text:'Exit'
            onClicked: {
                Qt.quit()
            }
        }
    }
    Canvas{
        id:canvas
        anchors.fill: parent

        property int lastX: 0
        property int lastY: 0

        function clear(){
            var ctx=getContext('2d');
            ctx.reset();
            canvas.requestPaint();
        }
        MouseArea{
            id:area
            anchors.fill: parent

            onPressed: {
                canvas.lastX=mouseX;
                canvas.lastY=mouseY;
            }

            onPositionChanged: {
                canvas.requestPaint();
            }
        }

        onPaint: {
            var ctx=getContext('2d');
            ctx.lineWidth=5;
            ctx.beginPath();
            ctx.moveTo(lastX,lastY);
            lastX=area.mouseX;
            lastY=area.mouseY;
            ctx.lineTo(lastX,lastY)
            ctx.stroke();
        }
    }
}
