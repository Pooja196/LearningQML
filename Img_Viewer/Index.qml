import QtQuick 2.12

Item {
    id:root
    signal indexChanged
    property int newInd : -1

    ListModel{
        id:listIndex
    }

    Component{
        id:component
        Item {
            property int updateInd :root.newInd
            width: root.height
            height: root.height

            Rectangle{
                id:id_index
                anchors.fill: parent
                anchors.margins: 2
                radius: root.height/2
                property int mIndex:INDEX
                color: "blue"

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        root.newInd=id_index.mIndex
                        root.indexChanged()
                    }
                }
            }

            onUpdateIndChanged: {
                if(id_index.mIndex==root.newInd){
                    id_index.color="red"
                }
                else{
                    id_index.color="blue"
                }
            }
        }
    }

    Flickable{
        anchors{
            top:root.top
            bottom: root.bottom
            horizontalCenter: root.horizontalCenter
        }
        width: root.height*listIndex.count

        Row{
            id:layout
            anchors.fill: parent
            Repeater{
                model:listIndex
                delegate: component
            }
        }
    }

    function addItem(index){
        listIndex.append({"INDEX":index})
    }

    function next(){
        root.newInd=(root.newInd+1)%listIndex.count
        root.indexChanged()
    }

    function previous(){
        if(root.newInd==0){
            root.newInd=listIndex.count-1
        }
        else{
            root.newInd=root.newInd-1
        }
        root.indexChanged()
    }

}
