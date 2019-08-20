import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    ColumnLayout{
        anchors.centerIn: parent
        Repeater{
            model:5
            Button{
                text: 'button'
            }
        }
    }


//   ListView{
//       height: parent.height
//       width: parent.width
//       anchors.centerIn: parent
//       model:ListModel{
//           ListElement{
//               mytext:'user1'
//           }
//           ListElement{
//               mytext:'user2'
//           }
//           ListElement{
//               mytext:'user3'
//           }
//           ListElement{
//               mytext:'user4'
//           }
//       }
//       delegate: Button{
//           text:mytext
//       }
//   }
}
