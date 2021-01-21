<img src="https://raw.githubusercontent.com/nadir-it/AutoFarm/main/rain_gauge.jpg">

# AutoFarm
Solar powered irrigation system using donated 20 year old solar panels and a shoestring budget.

A battery powered real-time clock is used to keep track of irrigation scheduling in the event of a total power failure.

Code was designed to be portable however the C++11 STL was never fully implemented for the harvard architecture ATMega328 series microprocessor. To migrate un-include Vector.h from source files. Vector.h and Vector.cpp exploit the fact that C/C++ treats arrays and pointers identically under the hood to mimic the STL Vector class allowing C++11 and newer code to compile and run on the ATMega328p.

Code was written for a prototype with an Arduino Nano core and a custom, hand-soldered I/O board to interface with a rain gauge and amperage sensor. The amperage sensor was a shunt resistor connected to a hand-soldered operational amplifier circuit. Irrigation valves were toggled using darlington pair transistors. The intent is to migrate this code base to an Automation Direct ProductivityOpen PLC at a later date.

The amperage sensor was used to monitor the charging of a used automotive battery. A buck converter was used to step the 18 volt solar panel down to a safe voltage for the automotive battery at or just above 12 volts.

Hibernate mode with interrupt wake needs to be implemented at a later date.

Code makes use of RTClib which is available under an MIT license. The rest of this project is available under GNU General Public License v3.

<img src="https://raw.githubusercontent.com/nadir-it/AutoFarm/main/OpAmp.JPG">
