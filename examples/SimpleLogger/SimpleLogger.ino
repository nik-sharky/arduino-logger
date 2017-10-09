// Log all to Serial, comment this line to disable logging
#define LOG Serial
// Include must be placed after LOG definition to work
#include "log.h"

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

uint16_t tick=0;

void loop() {
  tick++;
  log_printf("Tick #%d\n", tick);
  delay(500);
}