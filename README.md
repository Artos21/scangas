# scangas
Gas contamination sensor with transmission to the server. Arduino Uno project.
            1 Purpose of development
            1.1 Functional purpose
The software and hardware complex "SCANGAS" is designed for the timely detection of dangerous gases in the air and signaling about it:
  ⦁ detection of molecules of dangerous gases in the air;
  ⦁ alarm when the threshold value of the content of dangerous gases is exceeded;
  ⦁ data transfer to the remote monitoring system server.
            1.2 Operational purpose
The SCANGAS software and hardware complex can be used by mining and chemical industry enterprises, as well as enterprises that have a risk of releasing hazardous gases.
            2 Requirements for the hardware and software complex
This complex consists of 2 parts:
  ⦁ hardware
  ⦁ software.
The hardware part is implemented in the form of a device that allows measuring the content of dangerous gases in the air and transmitting it for subsequent processing.
The software part is implemented as a set of commands that organize the correct operation of the hardware

            2.1 Requirements for functional characteristics
            2.1.1 Requirements for the functional characteristics of the hardware
The hardware part of this complex should perform the following functions:
  ⦁ removing the signal from the gas sensor;
  ⦁ digitization of the signal;
  ⦁ ensuring the operation of the software part.
            2.1.2 Requirements for the functional characteristics of the software part
The software part of this complex should perform the following functions:
  ⦁ synchronization with the hardware;
  ⦁ forming and sending commands to the device;
  ⦁ receiving the digitized signal from the sensor;
  ⦁ preparing data for transmission over the network;
  ⦁ data transmission over the network.
            2.2 Reliability requirements
For reliable operation of the hardware, it is necessary to provide protection of the system elements from overvoltage.
For the reliable functioning of the software part, it is necessary to provide for the processing of the following exceptions:
  ⦁ synchronization error with the device;
  ⦁ device connection error;
  ⦁ error when reading the signal from the device;
error connecting to the server.
            2.3 Operating conditions
A specially trained user is not required to operate the hardware and software complex.
            2.4. Requirements for information and software compatibility
To develop this hardware and software complex, it is necessary to have the following components:
  ⦁ for hardware development - Arduino UNO, Arduino Ethernet Shield, MQ-2 Gas Sensor
  ⦁ for software development- Arduino IDE
To develop the software part, you must have Windows 7 and higher.
            2.5. Requirements for the composition and parameters of technical means
Minimum system requirements for hardware for software development:
  ⦁ 1 GHz processor;
  ⦁ 1 GB (for a 32-bit processor) or 2 GB (for a 64-bit processor) GB of RAM;
  ⦁ 16 GB (for a 32-bit system) or 20 GB (for a 64-bit system) of disk space;
  ⦁ Graphics device with DirectX 11 support and a minimum of 512 MB of video memory;
  ⦁ SVGA monitor supporting 800*600 resolution and higher;
  ⦁ mouse-type manipulator and keyboard.
          3 User manual for the hardware and software complex
The hardware and software complex consists of 2 parts: hardware and software. Let's first consider the user's interaction with the hardware, and then with the software. 
	The user's interaction with the hardware includes:
  ⦁ connecting all hardware components to each other;
  ⦁ providing the Arduino board with power;
  ⦁ ensuring network connectivity.
Connecting the Arduino Uno to the Ethernet Shield expansion board consists of superimposing two boards on top of each other . All Arduino Uno ports are duplicated on the Ethernet Shield board. Data exchange between devices takes place via the ICSP connector.
 

The MQ-2 sensor is connected to the Arduino board using special wires (jumpers). The sensor pins are connected to the corresponding pins of the board.
Pin of the MQ-2 sensor Pin of the Arduino Uno board
    GND	GND
    VCC	5V
    A0	A0

The Arduino board can be powered using a USB cable from a PC or other power source, or via an Arduino power connector using various batteries as a power source, for example, a Crown.
To connect the board to the network, you need to connect the RJ45 network cable to the RJ45S connector of the Ethernet Shield board.
The software part consists of two components:
  ⦁ firmware or sketch for Arduino;
  ⦁ php script for interacting with MySQL.
To configure the system, you need to connect the Arduino board to the PC via a USB port. Next, you need to install the Arduino IDE utility to edit the sketch and write it to the board. 
To change the delay time between sending data to the server, the MAC address and the address of the server to which you want to connect, you need to replace the current data with the required data. You also need to specify the port to connect to the server.
To configure the connection, you need to change the variables for connecting to MySQL to the required ones. 
To select the required table, you need to correct the SQL query.
