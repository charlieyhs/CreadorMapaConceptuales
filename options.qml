import QtQuick 2.5

Item {
    id: root
    width: mainwindow.quickWidgetSize().width
    height: mainwindow.quickWidgetSize().height

    Component.onCompleted:{
        optionsListView.model.append({optionColor: 'orange', optionText: 'Documento Nuevo', optionIndex:0});
        optionsListView.model.append({optionColor: 'orange', optionText: 'Agregar Cuadro', optionIndex:1});
        optionsListView.model.append({optionColor: 'orange', optionText: 'Salir', optionIndex:2});
    }
    ListView{
        id: optionsListView
        anchors.fill: parent
        model: ListModel{}
        spacing: 2

        delegate: Rectangle{
            width: parent.width
            height: 50
            color: optionColor

            Text{
                anchors.centerIn: parent
                text: optionText
                color: 'white'
                font.pointSize: 18
                font.bold: true
            }
            MouseArea{
                anchors.fill: parent

                onClicked:{
                    mainWindow.executeOption(optionIndex);
                }
            }
        }
    }
}
