import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    visible: true
    width: 800; height: 480
    title: qsTr("MicroFludic")

    //SplashScreen { id: splashscreen }
    //PickUser { id: pickuser }
   //  PickUser_Users{id: users}
    BioMarkerSet{id:biomarker}
   // BioMarkerSet_func{id:bioFunc}
   // PickUsers_Users_Userid{id:userid}
}
