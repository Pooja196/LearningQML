import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    SwipeView{
        id:funcSwipe
        orientation: Qt.Vertical
        anchors.fill: parent
        currentIndex: 0

        Item {
            id: firstFunc
            Rectangle{
                width: 294 ; height: 70
                color: "blue"
            }
        }

        Item {
            id: secondFunc

            Rectangle{
                width: 294 ; height: 70
                color: "red"
            }
        }

        Item {
            id: thirdFunc
            Rectangle{
                width: 294 ; height: 70
                color: "green"
            }
        }

        Item {
            id: fourthFunc
            Rectangle{
                width: 294 ; height: 70
                color: "yellow"
            }
        }
    }

}
