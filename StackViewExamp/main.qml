import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("StackView")

    header: ToolBar{
        RowLayout{
            anchors.fill: parent
            ToolButton{
                text: qsTr("<")
                onClicked: mystackview.pop()
            }
            Label{
                text: "StackView Example"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
        }
    }

    StackView{
        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: header.bottom
        }
        id:mystackview
        initialItem: starting_Page
    }
    Component{
        id:starting_Page
        StartingPage{}
    }
    Component{
        id:second_Page
        SecondPage{}
    }
    Component{
        id:third_Page
        ThirdPage{}
    }
    Component{
        id:fourth_Page
        FourthPage{}
    }

    function load_Page(page){
        switch(page){
        case 'page1':
            mystackview.push(starting_Page);
            break;
        case 'page2':
            mystackview.push(second_Page);
            break;
        case 'page3':
            mystackview.push(third_Page);
            break;
        case 'page4':
            mystackview.push(fourth_Page);
            break;
        }
    }
}
