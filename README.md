# AutoFarm
Solar powered AVR irrigation system

Code makes heavy use of RTClib. A battery powered real-time clock is used to keep track of irrigation scheduling in the event of a total power failure.

Code was designed to be portable however the C++11 STL was never fully implemented for the harvard architecture ATMega328 series microprocessor. To migrate un-include Vector.h from source files.

Code was written for a prototype with an Arduino Nano core and a custom, hand soldered I/O board to interface with a rain gauge, amp sensor, and toggle irrigation valves using darlington pair transistors. The intent is to migrate this code base to an Automation Direct ProductivityOpen PLC at a later date.

The amperage sensor was used to monitor the charging of a used automotive battery. A buck converter was used to step the 18 volt solar panel down to a safe voltage for the automotive battery at or just above 12 volts.

Hibernate mode with interrupt wake needs to be implemented at a later date.
