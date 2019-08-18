import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("Loader QML")
    color:"light green"

    Loader{
        id:myLoader
        anchors.fill: parent
        source: "MyText.qml"
    }
    Component{
        id:my_component
        Item {
            anchors.fill: parent
            Text {
                anchors.centerIn: parent
                text: "This is component object"
                font.pixelSize: 50
            }
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            if(myLoader.source==""){
                myLoader.sourceComponent=null
                myLoader.source="MyText.qml"
            }
            else{
                myLoader.source=""
                myLoader.sourceComponent=my_component
            }
        }
    }
}
