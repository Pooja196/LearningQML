import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    Image {
        id: background
        source: "Assets/background1.png"
    }

    AddUserBtn{
        id:adduser
    }

//    Button{
//        icon.width: 50
//        icon.name: "addUser"
//        icon.color: "red"
//        icon.source: "Assets/Add_new_32.png"
//    }

//    Button{
//        icon.width: 50
//        icon.name: "done"
//        icon.color: "red"
//        icon.source: "Assets/Done_32.png"
//    }
}
