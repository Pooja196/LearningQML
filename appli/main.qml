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
           console.log(data1)
        }

        onData2Changed: {
            console.log(data2)
        }
        onData3Changed: {
               console.log(data3)
        }
        onData4Changed: {
             console.log(data4)
        }
        onData5Changed: {
            console.log(data5)
        }
        onData6Changed: {
            console.log(dat6)
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
