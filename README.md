## OctoPower v.1.0 ##

Remotely switches on/off a 3D printer. <br/>
Use amazing Denkovi Microchip MCP2200 based board: https://denkovi.com/usb-relay-board-four-channels-for-home-automation-v2. <br/>
Controls MCP2200 GPIO via USB HID interface. <br/>
Easy OctoPrint integration. <br/>

### Requirements ###

* Raspberry Pi https://www.raspberrypi.org/
* MCP2200 based board (i.e. https://denkovi.com/usb-relay-board-four-channels-for-home-automation-v2)
* HIDAPI http://www.signal11.us/oss/hidapi/

### Running OctoPower ###
```
cd ~
git clone https://github.com/mcecchi/OctoPower.git
cd OctoPower
sudo ./octopower <socket> <on|off>
```
