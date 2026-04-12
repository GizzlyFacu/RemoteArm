import QtQuick
import QtQuick3D
import QtQuick.Controls.Basic
import QtQuick3D.Helpers
import com.giz.virtualArmQT
import com.giz.cmdVirtualArmQT
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Robot Arm Client")

    FontLoader{
        id:ttfLoader
        source:"qrc:/text/text/04B_30__.TTF"
    }

    Item {
        anchors.fill: parent
        Node {
            id: sceneRoot
            PerspectiveCamera {
                id:cameraNode
                z:300
                y:100
            }

            DirectionalLight {
            }
        }

        View3D {
            id: view1
            anchors.fill: parent
            importScene: sceneRoot
            focus:true
            environment: SceneEnvironment {
                antialiasingMode: SceneEnvironment.MSAA
                tonemapMode: SceneEnvironment.TonemapModeFilmic
                backgroundMode: SceneEnvironment.Color
                clearColor: "#D75656"
                InfiniteGrid {
                    gridInterval: 100
                }
            }
            OrbitCameraController {
                origin: sceneRoot
                camera: cameraNode
            }
            RoboticArm2{
                id: robotModel2
                scale: Qt.vector3d(1, 1, 1)
            }
            OriginGizmo {
                targetNode: cameraNode
                anchors.top: parent.top
                anchors.right: parent.right
                width: 100
                height: 100
            }
        }
    }

    Column{
        height: 250
        width: 250
        spacing: 2
        TextArea{
            height: 30
            width: 200
            anchors.horizontalCenter: parent.horizontalCenter
            id:textInserter
            color: "Black"
            font{
                family: "04b 30"
                pixelSize: 15
            }
            placeholderText: qsTr("Enter Command")
            placeholderTextColor: "Gray"
            background: Rectangle{
                anchors.fill: parent
                radius: 10
                color: "#EEEEEE"
            }
            Keys.onPressed: (event) => {
                    if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                        event.accepted = true
                        button1.clicked()
                    }
                }
        }
        Button{
            id:button1
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Send Command"
            onClicked: {CmdVirtualArmQT.sendMessage(textInserter.text);textInserter.text=""}
            contentItem: Text {
                text: parent.text
                color: "Black"
                font{
                    family: "04b 30"
                    pixelSize: 15
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            focus:true
            background: Rectangle{
                anchors.fill: parent
                radius: 10
                color:button1.pressed ? Qt.darker("#FAE251") : "#FAE251"
            }
        }

        DragHandler{}
    }
}
