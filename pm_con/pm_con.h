

#ifndef _pmcon_h
#define _pmcon_h

#include "Arduino.h"
#include "Keyboard.h"
//#include "Serial.h"

#define maxbuttons 10

/*class dir{
  public:
	dir(int x, int y){vx = x; vy = y;};
    int16_t vx, vy;
    }	
*/


class stick{
  public:
    stick(int pinx, int piny);

	int16_t px, py; //pins
	int16_t rx, ry; //read
	int16_t cx, cy; //center
	int16_t dx, dy; //direction
	
	//int16_t vx1, vy1, vx2, vy2; //vars
	
	//void setpins(int x, int y);
	void center();
	void read();
	void direction();

	//void autosync();
	//void update();
	//void xconstrain(int xh, int xl, int yh, int yl);
    };

class pad{
  public:
    pad(int pin, int buttons);

	int16_t ipin; //pins
	int16_t vread; //read
	int16_t ibutton;
	int16_t buttonvals[maxbuttons]; //center
	int16_t dbutton;
	
	//int16_t vx1, vy1, vx2, vy2; //vars
	
	//void setpins(int x, int y);
	void read();
	void center(int button, int rval);
	
	void detect();

	//void centers(int bvals[]);
	//void autosync();
	//void update();
	//void xconstrain(int xh, int xl, int yh, int yl);
    };

	
class xcontrol{
  public:
    xcontrol(int tog){ enable= false; toggle = tog;};	
	boolean enable;
	int toggle;
	
	void sendData(int a, int b, int c, int d, int e);
	
    };
  
  #endif