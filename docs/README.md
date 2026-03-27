# About each file
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

## VirtualArm.h 
From this, you can create other arms that "subscribe" to its properties using `std::function`, for example:
## ArmAdapter.h
This is the example 3D arm in Qt. Each bone is subscribed to each virtual bone of the master arm, so when the virtual arm receives new modifications to its bones, it notifies the armAdapter to update its own.

## ESP32Actuator.h
This is the same, but for Arduino. When the arm receives changes, it notifies the ESP32 to perform an action, for example, turning on an LED if a bone changes position.

