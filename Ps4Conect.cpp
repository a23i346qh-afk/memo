#include<Wire.h>
#include<PS4Controller.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(21,22);
  Serial.println("Ready");
  }

void loop() {
  // put your main code here, to run repeatedly:
  if(PS4.isConnected()){
    Serial.println("CONECT");

  }
}