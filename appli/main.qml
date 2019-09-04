import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import serialreadfrom 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Application")

    SerialDataRead{
        id:serialread
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
    TextField {
        text:serialread.data1
        onTextChanged: serialread.data1=text
    }
    TextField {
        text:serialread.data2
        onTextChanged: serialread.data2=text
    }
    TextField {
        text:serialread.data3
        onTextChanged: serialread.data3=text
    }
    TextField {
        text:serialread.data4
        onTextChanged: serialread.data4=text
    }
    TextField {
        text:serialread.data5
        onTextChanged: serialread.data5=text
    }
    TextField {
        text:serialread.data6
        onTextChanged: serialread.data6=text
    }
   }
}
