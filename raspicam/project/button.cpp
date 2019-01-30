/*
isr4pi.c
D. Thiebaut
based on isr.c from the WiringPi library, authored by Gordon Henderson
https://github.com/WiringPi/WiringPi/blob/master/examples/isr.c

Compile as follows:

    gcc -o isr4pi isr4pi.c -lwiringPi

Run as follows:

    sudo ./isr4pi

 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <iostream>

// Use GPIO Pin 17, which is Pin 0 for wiringPi library

#define BUTTON_PIN 7


// the event counter 
volatile int eventCounter = 0;

bool event = false;


#include <chrono>
#include <sys/timeb.h>


using namespace std::chrono;
using namespace std;
class Timestamp{


public:
    Timestamp(){}

    int64_t getNanoSecs(){
    
    nanoseconds ns = duration_cast< nanoseconds >(
        system_clock::now().time_since_epoch()
    );
    return ns.count();
    }



};

// -------------------------------------------------------------------------
// myInterrupt:  called every time an event occurs
void myInterrupt(void) {
   event= true;
}


// -------------------------------------------------------------------------
// main
int main(void) {
  // sets up the wiringPi library
  if (wiringPiSetup () < 0) {
      fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno));
      return 1;
  }

    wiringPiSetupPhys();//use the physical pin numbers on the P1 connector
    pinMode(7, INPUT);
  // set Pin 17/0 generate an interrupt on high-to-low transitions
  // and attach myInterrupt() to the interrupt
  if ( wiringPiISR (BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt) < 0 ) {
      fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno));
      return 1;
  }

  // display counter value every second.
  Timestamp timestamp;
  int64_t time_stamp1, time_stamp2;
  while ( 1 ) {
    if (event == true) {
        event = false;
        time_stamp1 = timestamp.getNanoSecs();
        event = false;
        std::cout<< time_stamp1-time_stamp2<<std::endl;
        time_stamp2 = time_stamp1;
    }
    

  }

  return 0;
}