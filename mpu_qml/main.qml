import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import com.vvbiotech.serial 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SerialPort{
        id: serial

        onData1Changed: {
        }
        onData2Changed: {
        }
        onData3Changed: {
        }
        onData4Changed: {
        }
        onData5Changed: {
        }
        onData6Changed: {
        }
    }

    Column{
        spacing: 10
        Text {
            id: accx
            font.pixelSize: 20
            text: serial.data1
        }
        Text {
            id: accy
            font.pixelSize: 20
            text: serial.data2
        }
        Text {
            id: accz
            font.pixelSize: 20
            text: serial.data3
        }
        Text {
            id: gyrox
            font.pixelSize: 20
            text: serial.data4
        }
        Text {
            id: gyroy
            font.pixelSize: 20
            text: serial.data5
        }
        Text {
            id: gyroz
            font.pixelSize: 20
            text: serial.data6
        }
    }

}
