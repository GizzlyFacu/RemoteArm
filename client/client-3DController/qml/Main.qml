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

            RoboticArm{
                id: robotModel
                scale: Qt.vector3d(100, 100, 100)
                //position: Qt.vector3d(0,-60,0)
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
            font{
                family: "04b 30"
                pixelSize: 15
            }
            placeholderText: qsTr("Enter Command")
            background: Rectangle{
                anchors.fill: parent
                radius: 10
                color: "#EEEEEE"
            }
        }
        Button{
            id:button1
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text:"Send Command"
            font{
                family: "04b 30"
                pixelSize: 15
            }

            onClicked: {CmdVirtualArmQT.sendMessage(textInserter.text);textInserter.text=""}
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
