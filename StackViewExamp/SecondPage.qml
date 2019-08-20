import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
   ListView{
       height: parent.height
       width: parent.width
       anchors.centerIn:parent
       spacing:10
       model: ListModel{
           ListElement{
               name:"user1"
               age:30
           }
           ListElement{
               name:"user2"
               age:35
           }
           ListElement{
               name:"user3"
               age:20
           }
           ListElement{
               name:"user4"
               age:25
           }
       }
       delegate:Rectangle{
           width:parent.width
           height: 30
           color: 'green'
           Text{
               anchors.centerIn:parent
               color: 'light blue'
               text: 'Name:'+name+',age:'+age
               font.pointSize:20
           }
       }
   }
}
