cmake_minimum_required(VERSION 3.2)
project(AutonomousCar)

set(ENV{PATH} "C:\\Users\\Ethan\\bin;C:\\Program Files\\Git\\mingw64\\bin;C:\\Program Files\\Git\\usr\\local\\bin;C:\\Program Files\\Git\\usr\\bin;C:\\Program Files\\Git\\usr\\bin;C:\\Program Files\\Git\\mingw64\\bin;C:\\Program Files\\Git\\usr\\bin;C:\\Users\\Ethan\\bin;C:\\Python27\\Scripts;C:\\Python27;C:\\MinGW\\bin;C:\\Program Files (x86)\\CMake\\bin;C:\\Windows\\system32;C:\\Windows;C:\\Windows\\System32\\Wbem;C:\\Windows\\System32\\WindowsPowerShell\\v1.0;C:\\ProgramData\\Oracle\\Java\\javapath;C:\\Program Files (x86)\\NVIDIA Corporation\\PhysX\\Common;C:\\Program Files (x86)\\QuickTime\\QTSystem;C:\\Program Files\\MiKTeX 2.9\\miktex\\bin\\x64;C:\\Program Files\\Git\\usr\\bin\\vendor_perl;C:\\Program Files\\Git\\usr\\bin\\core_perl")
set(PLATFORMIO_CMD "C:\\Python27\\Scripts\\platformio.exe")

include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/variants/standard")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/cores/arduino")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Servo/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Servo/src/avr")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Servo/src/sam")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Servo/src/samd")
include_directories("D:/Ethan/Desktop/Working/2_Projects/AutonomousCar/lib/quicrun1060esc")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Audio/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Bridge/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/EEPROM")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Esplora/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Ethernet/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Firmata")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/GSM/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/HID")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Keyboard/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/LiquidCrystal/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Mouse/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/RobotIRremote/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Robot_Control/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Robot_Motor/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/SD/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/SPI")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Scheduler/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/SoftwareSerial")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/SpacebrewYun/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Stepper/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/TFT/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Temboo/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/USBHost/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/WiFi/src")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/framework-arduinoavr/libraries/Wire")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/toolchain-atmelavr/avr/include")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/toolchain-atmelavr/lib/gcc/avr/4.8.1/include")
include_directories("$ENV{HOMEDRIVE}$ENV{HOMEPATH}/.platformio/packages/toolchain-atmelavr/lib/gcc/avr/4.8.1/include-fixed")

add_definitions(-DF_CPU=16000000L)
add_definitions(-DARDUINO_ARCH_AVR)
add_definitions(-DARDUINO_AVR_DUEMILANOVE)
add_definitions(-DARDUINO=10607)
add_definitions(-DPLATFORMIO=020803)
add_definitions(-D__AVR_ATmega328P__)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(AutonomousCar
    src/main.cpp
)
