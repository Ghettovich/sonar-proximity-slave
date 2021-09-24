extern "C" {
#include <canmsg.h>
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("[Slave sonar+proximity]");
  
  setupCAN();

  Serial.println("CAN Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  canLoop();
}
