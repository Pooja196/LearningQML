import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id:bioFunction
    height: 300 ; width: 290

    Component.onCompleted: {
        var func=['function0','function1','function2','function3','function4','function5','function6','function7','function8','function9']
        for(var y=0;y<10;y++){
            funcList.model.append({
                                  funcText:func[y],
                                });
            x++;
        }
    }
    ListView{
        anchors.fill: parent
        id:funcList
        model:ListModel{}
        spacing: 5
        delegate: Rectangle{
            color: 'black'
            opacity: 0.7
            border.color: 'white'
            border.width: 1
            width: 290 ; height: 60
            CheckBox{
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                anchors{
                    verticalCenter: parent.verticalCenter
                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 20
                text: funcText
                 color:'white'
            }
        }
    }

}
