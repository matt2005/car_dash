# Digital Speedometer to Car's Instrument Cluster via CAN Bus

> Implementing my own Arduino CAN bus shield and digital speedometer to car's LCD-display in instrument cluster. By databus100.

[](#things)Things used in this project
--------------------------------------

<table><tbody><tr><td colspan="6"><h3>Hardware components</h3></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/image/file/97103/Ard_Nano.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/image/file/97103/Ard_Nano.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Arduino Nano R3" src="https://hackster.imgix.net/uploads/image/file/97103/Ard_Nano.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td></td><td>×</td><td>1</td><td></td></tr><tr><td></td><td></td><td>×</td><td>1</td><td></td></tr><tr><td></td><td></td><td>×</td><td>1</td><td></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/image/file/96035/160-20.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/image/file/96035/160-20.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="16 MHz Crystal" src="https://hackster.imgix.net/uploads/image/file/96035/160-20.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td></td><td>×</td><td>1</td><td></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/image/file/96046/MFR-25FRF52-10K_sml.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/image/file/96046/MFR-25FRF52-10K_sml.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Resistor 10k ohm" src="https://hackster.imgix.net/uploads/image/file/96046/MFR-25FRF52-10K_sml.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td></td><td>×</td><td>1</td><td></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/image/file/96043/MFR-25FRF52-1K_sml.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/image/file/96043/MFR-25FRF52-1K_sml.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Resistor 1k ohm" src="https://hackster.imgix.net/uploads/image/file/96043/MFR-25FRF52-1K_sml.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td></td><td>×</td><td>1</td><td></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/image/file/96045/MFR-25FBF52-4K75_sml.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/image/file/96045/MFR-25FBF52-4K75_sml.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Resistor 4.75k ohm" src="https://hackster.imgix.net/uploads/image/file/96045/MFR-25FBF52-4K75_sml.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td><table><tbody><tr><td>Resistor 4.75k ohm</td></tr><tr><td>R3, R4 Bus Termination Resistors</td></tr></tbody></table></td><td>×</td><td>2</td><td></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/attachments/831893/4473517.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/attachments/831893/4473517.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Ceramic Disc Capacitor, 150 pF" src="https://hackster.imgix.net/uploads/attachments/831893/4473517.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td><table><tbody><tr><td>Ceramic Disc Capacitor, 150 pF</td></tr><tr><td>Bus capacitors for EMI improvements</td></tr></tbody></table></td><td>×</td><td>2</td><td></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/attachments/831896/4077779.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/attachments/831896/4077779.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Ceramic Disc Capacitor, 18 pF" src="https://hackster.imgix.net/uploads/attachments/831896/4077779.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td><table><tbody><tr><td>Ceramic Disc Capacitor, 18 pF</td></tr><tr><td>Capacitors for 16MHz crystal oscillator</td></tr></tbody></table></td><td>×</td><td>2</td><td></td></tr><tr><td></td><td><table><tbody><tr><td>Screw Block Terminal 5-R3.5</td></tr><tr><td></td></tr></tbody></table></td><td>×</td><td>1</td><td></td></tr><tr><td colspan="6"><h3>Software apps and online services</h3></td></tr><tr><td><img srcset="https://hackster.imgix.net/uploads/image/file/144203/IDE_web.jpg?auto=compress%2Cformat&amp;w=96&amp;h=96&amp;fit=fill&amp;bg=ffffff 2x, https://hackster.imgix.net/uploads/image/file/144203/IDE_web.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff" alt="Arduino IDE" src="https://hackster.imgix.net/uploads/image/file/144203/IDE_web.jpg?auto=compress%2Cformat&amp;w=48&amp;h=48&amp;fit=fill&amp;bg=ffffff"></td><td></td><td colspan="2"></td><td><a target="_blank" rel="nofollow noopener" title="More info" href="https://www.arduino.cc/en/main/software"><i><svg><use xlink:href="#svg-external-link"></use></svg></i></a></td></tr><tr><td></td><td></td><td colspan="2"></td><td><a target="_blank" rel="nofollow noopener" title="More info" href="https://www.autodesk.com/products/eagle/free-download?plc=F360&amp;term=1-YEAR&amp;support=ADVANCED&amp;quantity=1"><i><svg><use xlink:href="#svg-external-link"></use></svg></i></a></td></tr></tbody></table>

### Start of the Project

It all started in the summer of 2020, when I bought an Audi TT 2002. Unlike my previous cars, it didn’t have a digital speedometer in the instrument cluster’s little LCD-display (Driver Information System DIS in Audi). Due to the lack of digital speedometer, I decided to implement it myself. To cut a long story short, I thought I could take advantage of existing GitHub-project [\[1\]](https://github.com/derpston/Audi-radio-DIS-reader) and wrote the code for that setup first. Though I soon realized the setup used in the existing project was different to mine, so I had to start it all over.

### Basic Idea

Audi TT's DIS-display shows the radio station or the CD-track in the upmost third of the display. My plan was to replace the radio info with digital speedometer. From the previously mentioned [project](https://github.com/derpston/Audi-radio-DIS-reader) I found out that the radio sends information to the instrument cluster via three one-way data wires. When I pulled my radio out, I found out that my radio didn't use these three wires, but CAN bus instead. My car had a Chorus-radio, and the older one with three wires was a Concert.

Audis with Concert

*   one-way data connection between the radio and the instrument cluster

*   three wires for data transfer (DATA, CLOCK, ENABLE) (I thought my car had these)

Audis with Chorus

*   two-way data connection (Half-duplex) between the radio and the instrument cluster implemented with CAN bus [\[2\]](http://www.volkspage.net/technik/ssp/ssp/SSP_186_eng.pdf)

*   data transmission rate 100 kbps (Infotainment CAN) [\[3\]\[4\]](http://www.volkspage.net/technik/ssp/ssp/SSP_238.pdf)

*   two wires for data transfer (CAN-High, CAN-Low) (My car had these)

Audi Chorus Connector: CAN-Low (Orange-Brown) and CAN-High (Orange-Purple)

### Reading vehicle speed data

Before I tapped into CAN bus with Arduino, my plan was to acquire the vehicle speed signal from the radio's GALA-wire (Graduated Audio Level Adjustment). GALA increases radio volume automatically according to vehicle speed. Since my car has CAN bus, there is no need for GALA-wire and the instrument cluster sends vehicle speed data on the bus every 200 ms. I'm planning to use these CAN-messages in my digital speedometer solution.

### Designing Fault Tolerant CAN-shield for Arduino

After doing a little research on the CAN bus (especially in VW-group cars), I found out that the bus used in my car was a so called Fault Tolerant CAN bus [\[4\]](http://www.volkspage.net/technik/ssp/ssp/SSP_269_d1.pdf). For me it meant that I couldn't use off-the-shelf CAN-shields for Arduino.

I decided to design a circuit board for the CAN-shield and integrate my Arduino Nano into it. Main components needed for the CAN-shield were

*   MCP2515 Stand-Alone CAN Controller with SPI Interface (Easy to communicate with Arduino via SPI)

*   TJA1055 Enhanced fault-tolerant CAN transceiver

*   16 MHz Crystal Oscillator

*   resistors, capacitors and screw terminal block

*   circuit board

[TJA-1055T Application Hints \[5\]](https://www.nxp.com/docs/en/application-note/AH0801.pdf) \-document was useful when I dimensioned resistors and capacitors. I used [Arduino CAN Tutorial](https://circuitdigest.com/microcontroller-projects/arduino-can-tutorial-interfacing-mcp2515-can-bus-module-with-arduino) \[6\] when I drew the connections between Arduino and MCP2515.

I designed the circuit board in Autodesk Eagle. I didn't pay too much attention to the circuit board design specifics, because I knew that manufacturing and shipping of the board would take its own time. I ordered the printed circuit board from [Itead.cc](https://www.itead.cc/).

Final Printed Circuit Board

### Work in progress

I haven't been able to test my speedometer in practice, because it's winter and I only drive the car during summer. Luckily, the hardest part is over and I have the final product in my hands. The rest of this project is just programming and testing the speedometer in practice.

### Sources

I used the following information from the previously mentioned [GitHub-project](https://github.com/derpston/Audi-radio-DIS-reader) \[1\] in my Speedometer 1 code:

*   message length fixed 18-bytes

*   last byte is checksum

*   way to calculate the checksum

\[1\] GitHub: [derpston](https://github.com/derpston)/**[Audi-radio-DIS-reader](https://github.com/derpston/Audi-radio-DIS-reader)**

\[2\] Volkspage: VW Self Study Programme [186](http://www.volkspage.net/technik/ssp/ssp/SSP_186_eng.pdf)

\[3\] Volkspage: VW Self Study Programme [238](http://www.volkspage.net/technik/ssp/ssp/SSP_238.pdf)

\[4\] Volkspage: VW Self Study Programme [269](http://www.volkspage.net/technik/ssp/ssp/SSP_269_d1.pdf)

\[5\] [TJA-1055T Application Hints](https://www.nxp.com/docs/en/application-note/AH0801.pdf)

\[6\] circuitdigest.com: [Arduino CAN Tutorial](https://circuitdigest.com/microcontroller-projects/arduino-can-tutorial-interfacing-mcp2515-can-bus-module-with-arduino)

### Author

Jussi Ristiniemi

Student at Tampere University, Finland

2nd year in Electrical Engineering

Read more


[Source](https://www.hackster.io/databus100/digital-speedometer-to-car-s-instrument-cluster-via-can-bus-66e273)