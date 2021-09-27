extern "C" {
#include <canmsg.h>
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("[Slave sonar+proximity]");
  
  setupCAN();
  Serial.println("CAN Ready");

  setupProximity();
  Serial.println("Proxmity Ready");

  setupSonar();
  Serial.println("Sonar Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  usLoop();
  proximityLoop();
  canLoop();
}
