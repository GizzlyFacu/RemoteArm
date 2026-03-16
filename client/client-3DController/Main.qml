import QtQuick
import QtQuick3D
import QtQuick.Controls
import QtQuick3D.Helpers
import RobotArmPrueba
import com.giz.virtualArmQT
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
                eulerRotation.y:45
            }
        }
    }
    Button{
        height: 100
        width: 100
        text:"Eso tilin"
        onClicked: console.log("brrm")
    }

}
