# Door Opener

## Requirements

Uses [OpenTheDamnDoor](https://github.com/michaelkamphausen/OpenTheDamnDoor)  as submodule.

## Installation

### Arduino
* connect the Arduino USB Serial Light to the Arduino Ethernet via the six pins at the opposite site of the Ethernet port, with both boards' top side up
* connect Arduino USB Serial Light via micro USB cable to your computer
* download and install [Arduino Software Environment](http://arduino.cc/en/Main/Software)
* open [acts_as_door.ino](door-opener/arduino/acts_as_door/acts_as_door.ino) in Arduino Software Environment
* if the following steps do not work, check <http://arduino.cc/en/Guide/MacOSX>
* from the menu choose *Tools > Board > Arduino Ethernet*
* choose *Tools > Serial Port > /dev/tty.usbmodemXXXXX*
* make your changes to the Arduino code, click upload in the editor window and check the console output
* for programming reference, see <http://arduino.cc/en/Reference/HomePage>
* for the DoorOpener hardware layout, check the [DoorOpener.fzz](door-opener/arduino/DoorOpener.fzz) sketch file

### Frontend
* OS X Menu Bar Tool: open OpenTheDamnDoor.app if already build, otherwise open [OpenTheDamnDoor.xcodeproj](frontend/OpenTheDamnDoor/OpenTheDamnDoor.xcodeproj), choose *Product > Archive* from the menu and then click *Distribute…* and *Export as Application*, choose *Don't Re-Sign* if you do not participate in the Mac Developer Program
* Web App: open <http://10.0.0.64/letmein.html> on your iPhone, tap the action button, choose add to homescreen, close your browser and open the new app
* Bookmarklet: copy the content of [OpenTheDamnDoor.js](door-opener/frontend/bookmarklet/OpenTheDamnDoor.js) to your browser's address bar, hit return and save it as bookmark

## License

Licensed under the terms of the [MIT License](LICENSE).