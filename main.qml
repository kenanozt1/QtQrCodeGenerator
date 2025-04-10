import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12
ApplicationWindow {
    id:mainWindow
    width: 600
    height: 700
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height
    visible: true
    title: qsTr("Qr Code Generator")

    property string radiusBox : "15"
    property string marginBox : "15"

    Rectangle{
        id:mainBox
        width: parent.width*0.95
        height: parent.height*0.95
        radius: radiusBox
        layer.enabled: true
        layer.effect: DropShadow {
            anchors.fill: mainBox
            horizontalOffset: 0
            verticalOffset: 0
            radius: mainBox.radius
            color: "#88000000"
            samples: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Rectangle{
            id:rectTitle
            width: parent.width
            height: 70
            radius:radiusBox
            Text {
                id: textTitle
                anchors.centerIn: parent
                font.bold: true
                font.pixelSize: 32
                text: qsTr("Qr Code Generator")
            }
        }
        Rectangle{
            id: rectCreateQr
            width: parent.width
            height: 70
            anchors.top:rectTitle.bottom
            color:"transparent"
            Rectangle{
                id:rectCreateQrInput
                width: parent.width*0.7
                height: parent.height
                anchors.left: parent.left
                anchors.top:parent.top
                anchors.leftMargin: marginBox
                border.width: 2
                border.color:"lightgray"
                clip:true
                TextInput{
                    id:input
                    anchors.fill: parent
                    anchors.leftMargin: 10
                    anchors.rightMargin: 10
                    font.pixelSize: 24
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    focus: true
                }
                Text {
                    id: placeholderText
                    width:parent.width
                    height: parent.height
                    text: qsTr("Enter Url/Text")
                    visible:input.text === ""
                    color:"lightgray"
                    font.pixelSize: 24
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    z:0
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        input.forceActiveFocus()
                    }
                }
            }
            Rectangle{
                id:rectCreateQrButton
                anchors.left: rectCreateQrInput.right
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: marginBox
                height: parent.height
                color:rectCreateQrButtonArea.pressed ? "#181C14" : "#3C3D37"
                Text{
                    text: qsTr("Create Qr")
                    anchors.centerIn: parent
                    font.pixelSize: 24
                    color: "white"
                }
                MouseArea{
                    id:rectCreateQrButtonArea
                    anchors.fill: parent
                    onClicked: {
                        if(input.text !== "")
                        {
                            rectQrBox.visible = true
                            rectQrBoxBeforeDesc.visible = false
                            rectCreateQrInput.border.color="lightgray"
                            qrCode.source =  "data:image/png;base64," + generatorController.qrCodeImage(input.text)
                        }
                        else{
                            rectQrBox.visible = false
                            rectQrBoxBeforeDesc.visible = true
                            textInfo.text = "Error! Empty Input"
                            textInfo.color = "#F7374F"
                            rectCreateQrInput.border.color="#F7374F"
                        }
                    }
                }
            }
        }
        Rectangle{
            id:rectShowQr
            anchors.top:rectCreateQr.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: marginBox
            color:"transparent"
            Rectangle {
                id:rectQrBoxBeforeDesc
                visible:true
                width: parent.width*0.7
                height: width
                color: "transparent"
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id:textInfo
                    text: qsTr("QR code not created yet!")
                    color:"lightgray"
                    z:0
                    anchors.centerIn: parent
                    font.pixelSize: 24
                }
            }

            Rectangle {
                id:rectQrBox
                visible:false
                width: parent.width*0.7
                height: width
                color: "white"
                border.width: 1
                border.color: "#DDD"
                radius: 10
                anchors.horizontalCenter: parent.horizontalCenter

                layer.enabled: true
                layer.effect: DropShadow {
                    color: "#30000000"
                    radius: 8
                    samples: 16
                }

                Image {
                    id: qrCode
                    anchors.centerIn: parent
                    width: parent.width - 20
                    height: width
                    fillMode: Image.PreserveAspectFit
                }
            }
            Rectangle{
                id:processQrCodeImage
                width: parent.width
                height: 100
                anchors.top:rectQrBox.bottom
                color:"transparent"

                Rectangle{
                    id:rectCopy
                    width: (parent.width*0.5)-marginBox/2
                    height: parent.height
                    radius:5
                    color:rectCopyArea.pressed ? "#1B56FD" : "#0118D8"
                    anchors.left: parent.left
                    Text {
                        text: qsTr("Copy")
                        font.pixelSize: 18
                        color:"white"
                        anchors.centerIn: parent
                    }
                    MouseArea{
                        id:rectCopyArea
                        anchors.fill: parent
                        onClicked: {
                            qrCode.grabToImage(function(result) {
                                generatorController.copyImageToClipboard(result.image);
                            })
                        }
                    }
                }
                Rectangle{
                    id:rectPrint
                    width: (parent.width*0.5)-marginBox/2
                    height: parent.height
                    radius:5
                    color:rectPrintArea.pressed ? "#1B56FD" : "#0118D8"
                    anchors.left:rectCopy.right
                    anchors.margins: marginBox
                    Text {
                        text: qsTr("Print")
                        font.pixelSize: 18
                        color:"white"
                        anchors.centerIn: parent
                    }
                    MouseArea{
                        id:rectPrintArea
                        anchors.fill: parent
                        onClicked: {
                            qrCode.grabToImage(function(result) {
                                var tempPath = generatorController.getTempFilePath("temp_qr.png");
                                result.saveToFile(tempPath);
                                var success = generatorController.printImage(tempPath);
                                if (success) {
                                    console.log("Printing successful");
                                } else {
                                    console.log("Printing failed");
                                }
                            })
                        }
                    }
                }
            }
        }
    }
}











