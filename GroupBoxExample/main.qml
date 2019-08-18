import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "Green"

    ButtonGroup{
        id:group1
    }
    ButtonGroup{
        id:group2
    }
    SwipeView{
        id:view
        anchors.fill: parent
        currentIndex: 0
        GroupBox{
            title:"Group1"
            ColumnLayout{
                anchors.left: parent.left
                RadioButton{
                    ButtonGroup.group: group1
                    text: "option1"
                    checked: true
                }
                RadioButton{
                    ButtonGroup.group: group1
                    text: "option2"
                }
                RadioButton{
                    ButtonGroup.group: group1
                    text: "option3"
                }
                RadioButton{
                    ButtonGroup.group: group1
                    text: "option4"
                }
            }
        }

        GroupBox{
            title:"Group2"
            ColumnLayout{
                anchors.left: parent.left
                RadioButton{
                    ButtonGroup.group: group2
                    text: "option1"
                    checked: true
                }
                RadioButton{
                    ButtonGroup.group: group2
                    text: "option2"
                }
                RadioButton{
                    ButtonGroup.group: group2
                      text: "option3"
                }
                RadioButton{
                    ButtonGroup.group: group2
                    text: "option4"
                }
        }            }

        GroupBox{
            title: "group3"
            ColumnLayout{
                anchors.left: parent.left
                CheckBox{
                    text: "option1"
                    checked: true
                }
                CheckBox{
                    text: "option2"
                }
                CheckBox{
                    text: "option3"
                }
                CheckBox{
                    text: "option4"
                }
            }
        }
        GroupBox{
            title: "group4"
            ColumnLayout{
                anchors.left: parent.left
                CheckBox{
                    text: "option1"
                    checked: true
                }
                CheckBox{
                    text: "option2"
                }
                CheckBox{
                    text: "option3"
                }
                CheckBox{
                    text: "option4"
                }
            }
        }
    }

    PageIndicator{
        id:indicator
        count:view.count
        currentIndex: view.currentIndex
        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
