import processing.serial.*;

//Declare a new Serial object
Serial arduinoPort;

void setup() {
  //Make a connection to the arduino
  arduinoPort = new Serial(this, "/dev/tty.usbmodem641", 9600);
}

void draw() {
  //Nothing in here because we don't need it
}

void mouseClicked() {
  //Any time the mouse is clicked, we send a "1" to the arduino
  arduinoPort.write(1);
}
