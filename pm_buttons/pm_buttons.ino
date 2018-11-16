
#include <pm_con.h>

const int buttonPin = A10;

int buttonEst[] = {0, 500, 700, 800, 900, 1000};

stick left = stick(A0, A1);

stick right = stick(A2, A3);

pad buttons = pad(A10, 6);

xcontrol kb = xcontrol(5);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

for (int i=0; 2*i<sizeof(buttonEst); i++){

  buttons.center(i, buttonEst[i]);
  }

  left.center();
  right.center();

  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  left.read();
  right.read();

  left.direction();
  right.direction();
  
  buttons.read();

  buttons.detect();  

  /*
  //Serial.print(buttons.vread);
  Serial.print(" ");

  Serial.print(buttons.dbutton * 200);
  Serial.print(" ");
*/
//aaa
/*  Serial.print(left.rx);
  Serial.print(" ");
  Serial.print(left.ry);
  Serial.print(" ");

  Serial.print(right.rx);
  Serial.print(" ");
  Serial.print(right.ry);
  Serial.println(" ");
*/
  
  /*Serial.print(left.dx);
  Serial.print(" ");
  Serial.print(left.dy);
  Serial.print(" ");

  Serial.print(right.dx);
  Serial.print(" ");
  Serial.print(right.dy);
  Serial.println(" ");
*/
  kb.sendData(left.dx, left.dy, right.dx, right.dy, buttons.dbutton);

  delay(10);

}
