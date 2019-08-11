import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: element
    anchors.fill: parent

   SwipeView {
        id: userSwipeView
        width: 300
        height: 200
        orientation: Qt.Horizontal
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        currentIndex: 0
        Item {
            id: firstItem
            PickUsers_Users_Userid{id:user1
            uName: "user1"}
        }

        Item {
            id: secondItem
            PickUsers_Users_Userid{id:user2
                uName: "user2"}
        }

        Item {
            id: thirdItem
                PickUsers_Users_Userid{id:user3
                    uName: "use3"}
           }

        Item {
            id: fourthItem
            PickUsers_Users_Userid{id:user4
                uName: "user4"}
        }

        Item {
            id: fifthItem
            PickUsers_Users_Userid{id:user5
                uName: "user5"}
        }

        Item {
            id: sixthItem
            PickUsers_Users_Userid{id:user6
                uName: "user6"}
        }
    }
    PageIndicator{
        id:swipeIndicator
        count: userSwipeView.count
        currentIndex: userSwipeView.currentIndex
        anchors.bottom: element.bottom
        anchors.horizontalCenter: element.horizontalCenter
    }
}



