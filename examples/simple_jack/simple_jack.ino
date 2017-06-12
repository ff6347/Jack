#include <Jack.h>
// this is the normal constructor
boolean isInputJack = true;
Jack jackIn(11, isInputJack);
Jack jackOut(12, false);

void setup() {
  Serial.begin(9600);
  // use the setInterval(long interval) method
  // to change the interval for the sending period
  // of the output pin default is 50
   // jack.setInterval(1000);
}

void loop() {
  // listen for incoming messages
  // if there is a message we start some action
  if (jackIn.listen() == true && action == false) {
    action = true;
  }
  if (action == true) {
    // start the thing you want to do
    // your code goes in here
    // use delay to block the rest for testing purpose
    // delay(2000);
    // we are done let's send a message out to other
    // jacks that are listening
    jackOut.send();
    action = false;
  }
}

