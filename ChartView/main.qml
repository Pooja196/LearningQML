import QtQuick 2.12
import QtQuick.Controls 2.12
import QtCharts 2.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Chart View")

    ChartView {
        anchors.fill: parent
        theme: ChartView.ChartThemeDark
        antialiasing: true

        PieSeries {
            id: pieSeries1
            PieSlice {
                label: "label"
                value: 94.9
            }
            PieSlice {
                label: "label1"
                value: 93.9
            }
        }
    }
}
