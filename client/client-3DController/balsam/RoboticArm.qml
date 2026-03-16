import QtQuick
import QtQuick3D
import com.giz.virtualArmQT
Node {
    id: node
    // Resources
    PrincipledMaterial {
        id: principledMaterial
        metalness: 1
        roughness: 1
        alphaMode: PrincipledMaterial.Opaque
    }
    Skin {
        id: skin
        joints: [
            lowbone,
            midbone,
            highbone
        ]
        inverseBindPoses: [
            Qt.matrix4x4(-4.37114e-08, 0, 1, 0, 0, 1, 0, 0, -1, 0, -4.37114e-08, 0, 0, 0, 0, 1),
            Qt.matrix4x4(-4.37114e-08, 0, 1, 0, 0, 1, 0, -0.762302, -1, 0, -4.37114e-08, 0, 0, 0, 0, 1),
            Qt.matrix4x4(-4.37114e-08, 0, 1, 0, 0, 1, 0, -1.51315, -1, 0, -4.37114e-08, 0, 0, 0, 0, 1)
        ]
    }

    // Nodes:
    Node {
        id: armature
        objectName: "Armature"
        Model {
            id: plane
            objectName: "Plane"
            source: "qrc:/3d/balsam/meshes/plane_mesh.mesh"
            skin: skin
            materials: [
                principledMaterial
            ]
        }
        Node {
            id: lowbone
            objectName: "lowbone"
            rotation: Qt.quaternion(0.707107, 0, -0.707107, 0)
            scale: Qt.vector3d(1, 1, 1)
            Node {
                id: midbone
                objectName: "midbone"
                position: Qt.vector3d(0, 0.762302, 0)
                //animacion epica
                QuaternionAnimation{
                    target: midbone
                    property: "rotation"
                    running: true
                    duration: 5000
                    from:Qt.quaternion(1, 0, 0, 0)//el que ya esta
                    to:VirtualArmQT.angleMidBone//Qt.quaternion(0.92388, 0, 0, 0.382683)//45 grados en z del weso (mi x global)
                    type:QuaternionAnimation.Slerp
                }

                Node {
                    id: highbone
                    objectName: "highbone"
                    position: Qt.vector3d(0, 0.750844, 0)

                    QuaternionAnimation{
                        target: highbone
                        property: "rotation"
                        running: true
                        duration: 5000
                        from:Qt.quaternion(1, 0, 0, 0)
                        to:VirtualArmQT.angleHighBone
                        type:QuaternionAnimation.Slerp
                    }
                }
            }
        }
    }

    // Animations:
}
