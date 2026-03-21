import QtQuick
import QtQuick3D
import QtQuick.Controls.Basic
import QtQuick3D.Helpers
import RobotArmPrueba
import com.giz.virtualArmQT
import com.giz.cmdVirtualArmQT
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Robot Arm Client")
    Item {
        anchors.fill: parent
        Node {
            id: sceneRoot
            PerspectiveCamera {
                id:cameraNode
                z: 300
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
            }
            OrbitCameraController {
                    origin: sceneRoot
                    camera: cameraNode

                }

            RoboticArm{
                id: robotModel
                scale: Qt.vector3d(100, 100, 100)
                position: Qt.vector3d(0,-60,0)
                eulerRotation.y:45
            }
        }
    }
    TextArea{
        id:textInserter
        placeholderText: qsTr("Enter Command")
        background: Rectangle{
            anchors.fill: parent
            color: "White"
        }

    }

    Button{
        width: 100
        anchors.top: textInserter.bottom
        text:"Send Command"
        onClicked: {CmdVirtualArmQT.sendMessage(textInserter.text);textInserter.text=""}
        focus:true
    }

}
