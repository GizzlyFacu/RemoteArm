import QtQuick
import QtQuick3D
import com.giz.virtualArmQT

Node {
    id: node2

    // Resources
    PrincipledMaterial {
        id: defaultMaterial_material10
        objectName: "DefaultMaterial"
        baseColor: "#ffcccccc"
    }
    Skin {
        id: armature2
        joints: [
            rootNode1,
            low5,
            mid5,
            high7
        ]
        inverseBindPoses: [
            Qt.matrix4x4(-0.01, 0, 0, 3.47605e-09, 0, 0, 0.01, 0.506337, 0, 0.01, 0, -0.400354, 0, 0, 0, 1),
            Qt.matrix4x4(0.01, 0, 1.50996e-09, -3.47605e-09, 0, 0.01, 0, -0.400354, -1.50996e-09, 0, 0.01, 5.24869e-16, 0, 0, 0, 1),
            Qt.matrix4x4(0.01, 5.58396e-11, 5.79895e-10, -9.42268e-09, -5.58348e-11, 0.01, -8.12607e-08, -1.06495, -5.79896e-10, 8.12607e-08, 0.01, -8.65386e-06, 0, 0, 0, 1),
            Qt.matrix4x4(0.01, 4.87349e-19, 6.3573e-10, 1.16748e-10, -7.43322e-19, 0.01, 3.11776e-19, -1.70836, -6.3573e-10, -3.23811e-18, 0.01, 5.22839e-06, 0, 0, 0, 1)
        ]
    }

    // Nodes:
    Node {
        id: high
        objectName: "RootNode"
        Node {
            id: node0
            objectName: "Armature"
            rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
            scale: Qt.vector3d(100, 100, 100)
            Node {
                id: rootNode1
                objectName: "Root"
                position: Qt.vector3d(3.47605e-09, 0.506337, 0.400354)
                rotation: Qt.quaternion(-4.37114e-08, 0, 0, 1)
                Node {
                    id: low5
                    objectName: "Low"
                    position: Qt.vector3d(0, 0.506337, 0)
                    //rotation: Qt.quaternion(1.37679e-07, 1.37679e-07, 0.707107, 0.707107)
                    rotation: VirtualArmQT.angleLowBone//Qt.quaternion(0.707107, 0, -0.707107, 0)

                    Behavior on rotation {
                        QuaternionAnimation {
                            duration: 1000
                            type: QuaternionAnimation.Slerp
                        }
                    }
                    Node {
                        id: mid5
                        objectName: "Mid"
                        position: Qt.vector3d(0, 0.664596, 0)
                        //rotation: //Qt.quaternion(1, -4.06303e-06, 0, 0)
                        rotation: VirtualArmQT.angleMidBone//Qt.quaternion(0.707107, 0, -0.707107, 0)

                        Behavior on rotation {
                            QuaternionAnimation {
                                duration: 1000
                                type: QuaternionAnimation.Slerp
                            }
                        }
                                  Node {
                            id: high7
                            objectName: "High"
                            position: Qt.vector3d(-1.00804e-16, 0.643409, 4.54754e-13)
                            //rotation: Qt.quaternion(1, 4.06303e-06, 0, 0)
                            rotation: VirtualArmQT.angleHighBone//Qt.quaternion(0.707107, 0, -0.707107, 0)

                            Behavior on rotation {
                                QuaternionAnimation {
                                    duration: 1000
                                    type: QuaternionAnimation.Slerp
                                }
                            }
                            Node {
                                id: high6
                                objectName: "High_end"
                                position: Qt.vector3d(0, 0.520236, 0)
                            }
                        }
                    }
                }
            }
        }
        Model {
            id: defaultMaterial_material9
            objectName: "Base"
            source: "qrc:/3d/mesh/defaultMaterial_material11.mesh"
            skin: armature2
            materials: [
                defaultMaterial_material10
            ]
        }
    }

    // Animations:
}
