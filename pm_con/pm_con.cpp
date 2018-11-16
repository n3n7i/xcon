
#include <pm_con.h>

stick::stick(int pinx, int piny){
  px = pinx;
  py = piny;  
  }
  
void stick::read(){
  rx = analogRead(px);
  ry = analogRead(py);
}	

void stick::center(){
  read();
  cx = rx; cy = ry;
  }

void stick::direction(){
  //read();
  dx = rx-cx;
  dy = ry-cy;
  }
    
  
pad::pad(int pin, int buttons){
  ipin = pin;
  ibutton = buttons;    
  //buttonvals[buttons];
  for(int i=0; i<buttons; i++){
	buttonvals[i] = 0;
    }
  }
  
void pad::read(){
  vread = analogRead(ipin);
}	

void pad::center(int button, int rval){	
  //read();
  buttonvals[button] = rval;  
  }

void pad::detect(){
  int cdif = 1024;
  int cid = -1;
  for(int i=0; i<ibutton; i++){
    int tx = vread - buttonvals[i];
	tx = abs(tx);
	if(tx < cdif) { cid = i; cdif = tx;}
	//buttonvals[i] = 0;
    }
  dbutton = cid;
  }

/*void pad::centers(int bvals[]){
  for(int i=0; i<buttons; i++){
	buttonvals[i] = bvals[i];
    }
  }*/
	
//xcontrol::xcontrol(){};



void hexChar(char c2[], int xval, int xdiv, int pos){
  //char c2[3] = {'A', 'A', 0};
  boolean ab = xval >= 0;
  int xval2 = abs(xval) / xdiv;
  if(xval2 > 15) xval2 = 15;
  char c = xval2+48;
  if(c>=58) c+= 7;
  c2[0+pos] = '0';
  c2[1+pos] = '0';
  c2[2+pos] = ' ';
  if(ab) c2[1+pos] = c;
  if(!ab) c2[0+pos] = c;
  //return c;
  }
  
/*void stringGen(char c2[], int a, int b, int c, int d, int e){
	
	char xcon[4];
	hexChar(xcon, a, 32);
	for(int i=0; i<2)
*/

void xcontrol::sendData(int a, int b, int c, int d, int e){
	
	char xcon[20];
	hexChar(xcon, a, 32, 0);
	hexChar(xcon, b, 32, 3);
	hexChar(xcon, c, 32, 6);
	hexChar(xcon, d, 32, 9);
	hexChar(xcon, e, 1, 12);
	xcon[14] = 0xB0;
	xcon[15] = 0;
	
	//Serial.println(xcon);
	
	if(e == toggle){
		enable = !enable;
		delay(250);
		}
	if(enable){
		/*Keyboard.print(String(a));
		Keyboard.print(" ");
		Keyboard.print(String(b));
		Keyboard.print(" ");
		Keyboard.print(String(c));
		Keyboard.print(" ");
		Keyboard.print(String(d));
		Keyboard.print(" ");
		Keyboard.print(String(e));
		Keyboard.print(" \n");*/
		Keyboard.print(xcon);
		
		}
	}
		
