#include <Jack.h>
// this is the normal constructor
Jack jack(11 /*input pin */, 12 /* output pin*/);
//
// ----------------------------------------
// if you know what your are doing
// you can disable the internal pullups
// beware that all Jack elments need to share the same option
// they should be all pullup or not
// if you don't use the pullup you need an external pulldown resistor
// extended constructor
// set pullup true true or false
// Jack jack(11 /*input pin*/ , 12 /* output pin*/, true);
//
// ----------------------------------------
// if you also want some additional logging
// you can set the forth parameter to true
// super extended constructor
// you need to call
// Serial.begin(9600)
// in the setup of your sketch to make this work
// Jack jack(11 /*input pin*/ , 12 /* output pin*/, true, true);
// holds if there is an action in progress
boolean action = false;

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
  if (jack.listen() == true && action == false) {
    action = true;
  }
  if (action == true) {
    // start the thing you want to do
    // your code goes in here
    // use delay to block the rest for testing purpose
    // delay(2000);
    // we are done let's send a message out to other
    // jacks that are listening
    jack.send();
    action = false;
  }
}

