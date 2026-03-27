# About each file in each folder
---
# Client - 3D Controller program
## CommandProcessor.h
This is responsible for converting the text message (a std::string or a QString in the case of CommandProcessorQT.h) into a command and sending it to the arm. It involves other members in the following order:
## Parser.h
This parses the content, converting the message into an array of std::strings.

## ParserValidate.h
This validates each word according to the established rules (the enum classes) to transform it into commands that will then be sent to the CommandDispatcher.

## CommandDispatcher.h
This connects everything mentioned above to the arm. There is an observer arm* inside that loads the commands; the original arm lives in main.cpp.

## VirtualArm.h
This is the "master arm," the one connected to the CommandDispatcher.
From this, you can create other arms that "subscribe" to its properties using `std::function`, for example:
## ArmAdapter.h
This is the example 3D arm in Qt. Each bone is subscribed to each virtual bone of the master arm, so when the virtual arm receives new modifications to its bones, it notifies the armAdapter to update its own.

## ESP32Actuator.h
This is the same, but for Arduino. When the arm receives changes, it notifies the ESP32 to perform an action, for example, turning on an LED if a bone changes position.

---

# Client - Debug
Made for debug and test the client-server connection and issues. You can actually send commands from here to the esp32. It works with Meson and Conan for 'Boost.Asio' so u will need these. Actually these two works separatedlysend commands to the server / see the actual hardware in 3D working) because I don't have the actual hardware to work with or someone that can help me with that to study the issues cases (jitter, security,etc).

# Firmware - Arduino ESP32 Server
This is the actual server, should control the hypotetical hardware arm.
## Worfklow:
You send an "SET M 45" -> ESP32 Server makes changes to midbone inside BrazoVirtual -> When BrazoVirtual Notifies something changes, you can "subscribe" the function that makes something.(in this case Blink a LED).

# Server - Server Debug
Was made for test client-server and understand how networks (and Boost.Asio)works, (Before start this project I didn't know anything about networks or clients, servers, sockets, etc)

