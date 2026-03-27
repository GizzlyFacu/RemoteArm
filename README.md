# RemoteArm
<div align="center">
  <img src="./docs/assets/client3DExample.gif" />
</div>

## 🚀 Project Description
Remote control system for a robotic arm using an ESP32 via WiFi.
## 🛠️ About the project
Designed and implemented a full client-server system to control and simulate a robotic arm in real time.

- Developed a TCP server using Boost.Asio to handle command-based communication
- Built a Qt/QML application with 3D visualization for real-time feedback
- Implemented a command interpreter (SET/GET/RESET/PING) with validation and dispatching architecture
- Integrated ESP32 hardware for real-world interaction and testing
- Applied modern C++ practices and design patterns (Command, Observer, etc.)

Tech: C++, Qt/QML, Boost.Asio, SPDLOG, ESP32, Networking
Build & Tooling:Cmake for QT app, Meson for Client-Server Debug app, Conan, CCache
## Workflow
You send commands from the client "SET M 45"(see client-debug folder) and the ESP32 server will make something with it, in this case: move a servo located in the mid part of the bone hierarchy 45 degrees.
- This actually works on a ESP32? yes, you can look at the firmware folder for the code (3 DOFS: low, mid, high), It works on mine. Change the ESP32Actuator.h for the actual functions(In this case I only use Serial.print for example)
- What about the 3D visualization? is a rigged 3D model made in blender(yes really simple)working on a QT app for realtime visualization of the real hardware working. But in this case it was just for testing commands.

## 📋 Prerequisites
- 💡 Being alive (optional)
- ✨ See the README of each folder for Requisites. 

## 🛠️ Quick Start
```bash
# 1. Clone repository
git clone https://github.com/GizzlyFacu/RemoteArm.git
# 2. View module-specific setup
- Firmware: view /firmware/README.md
- Client: view /client/README.md
- Server: view /server/README.md
```
