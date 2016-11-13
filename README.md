## OctoPower v.1.0 ##

Remotely switches on/off a 3D printer. Use amazing Denkovi <https://denkovi.com/usb-relay-board-four-channels-for-home-automation-v2> Microchip MCP2200 based board. <br/>
Controls MCP2200 GPIO via USB HID interface. <br/>
Easy OctoPrint integration. <br/>

### Requirements ###

* HIDAPI http://www.signal11.us/oss/hidapi/.

### Running OctoPower ###
```
cd ~
git clone https://github.com/mcecchi/OctoPower.git
cd OctoPower
sudo ./octopower <socket> <on|off>
```
