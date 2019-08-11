import QtQuick 2.12
import QtGraphicalEffects 1.12

Item {
  id:user
  height: 150
  width: 100

  property string uName
    Rectangle{
        id:rect
        width: 150 ; height: 200
        radius:30
        color: 'white'
        opacity: 0.5
    }
    Text {
        x:10
        y:30
        text: qsTr("Name:")
        font.pixelSize:20
    }
    TextEdit {
        id:username
        x:80
        y:30
        text:user.uName
        font.pixelSize:20
    }

    Text {
        x:10
        y:80
        text: qsTr("Age:")
        font.pixelSize:20
    }
    TextEdit {
        id:userAge
        x:80
        y:80
        text:"21"
        font.pixelSize:20
    }

    Text {
        x:10
        y:120
        text: qsTr("Gender:")
        font.pixelSize:20
    }
    TextEdit {
        id:userGender
        x:80
        y:120
        text:"22"
        font.pixelSize:20
    }

}
