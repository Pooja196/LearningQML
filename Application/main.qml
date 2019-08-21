import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 800; height: 480
    title: qsTr("Applictaion")

    StackView{
        id:appstackview
        anchors{
            left: parent.left
            right:parent.right
            bottom: parent.bottom
            top: parent.top
        }
        initialItem: pickUser
    }

    Component{
        id:splash_page
        SplashScreen{
            height: 480; width: 800
        }
    }
    Component{
        id:pickUser
        PickUser{
            height: 480; width: 800
        }
    }

    function splashTime()
    {
        appstackview.push(pickUser);
    }

}
