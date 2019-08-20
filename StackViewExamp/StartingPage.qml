import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Item {
    RowLayout{
    //anchors.centerIn:parent
        width: parent.width
        Button{
            text: 'page1'
            onClicked:{
             load_Page(text);
            }
        }
        Button{
            text: 'page2'
            onClicked:{
             load_Page(text);
            }
        }
        Button{
            text: 'page3'
            onClicked:{
             load_Page(text);
            }
        }
        Button{
            text: 'page4'
            onClicked:{
             load_Page(text);
            }
        }
    }

//  GridView{
//      id:mygridview
//      cellWidth:parent.width/4
//      cellHeight: 5
//      anchors.centerIn: parent
//      width: parent.width
//      height:parent.height
//      model: ListModel{
//          ListElement{
//              name:'page1'
//          }
//          ListElement{
//              name:'page2'
//          }
//          ListElement{
//              name:'page3'
//          }
//          ListElement{
//              name:'page4'
//          }
//      }
//      delegate: Button{
//          id:mybutton
//          text: name
//          onClicked: {
//              load_Page(text);
//          }

//      }
//  }
}
