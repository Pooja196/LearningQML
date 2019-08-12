import QtQuick 2.0

Item {
    width: 800
    height: 480
    Image {
        id: background
        source: "/Assets/background1.png"

        Text {
            x:53
            y:39
            text: "Select \nBiomarker"
            font.pixelSize: 40
            color: "#ffffff"

        }
        Text {
            x:53
            y:137
            text: "to test various health parameters"
            font.pixelSize: 20
            color: "#ffffff"
            opacity: 0.6

        }
        Rectangle{
            id:testImage
            x:53
            y:196
            width: 333
            height: 241
            color: "#000000"
            opacity: 0.6
        }

        BioMarkerSet_func{
            id:biofunc
            x:440
            y:195
            anchors.bottomMargin: 100
        }

    }
}
