import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import SerialPortfunction 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SerialPort{
        id:serial

        onData1Changed: {
            accx.text="%1".arg(data1);
        }
    }

    TextField{
        id:accx
        text:"accx"
    }
}
