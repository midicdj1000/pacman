
#include <stdio.h>
#include <conio.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>
#include <peekpoke.h>

#define poke(A,X) (*(unsigned char *)A) = (X)
#define peek(A) (*(unsigned char *)A)


unsigned long count=0;
unsigned int base=8192;



unsigned char sprite[384] = {
	0x00, 0x28, 0x00, 0x00, 0x82, 0x00, 0x02, 0x00, 0x80,
	0x08, 0x00, 0x20, 0x20, 0x00, 0x08, 0x80, 0x00, 0x02, 0x80, 0x00, 0x02,
	0x20, 0x00, 0x08, 0x08, 0x00, 0x20, 0x02, 0x00, 0x80, 0x00, 0x82, 0x00,
	0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8D, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x28, 0x00, 0x00, 0xAA, 0x00, 0x00, 0xAA, 0x00, 0x02, 0xAA,
	0x80, 0x02, 0xAA, 0x80, 0x02, 0xAA, 0x80, 0x02, 0xAA, 0x80, 0x02, 0xAA,
	0x80, 0x02, 0xAA, 0x80, 0x0A, 0xAA, 0xA0, 0x0B, 0xAA, 0xE0, 0x0B, 0xFF,
	0xE0, 0x02, 0xAA, 0x80, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0xAA, 0x00, 0x00,
	0xAA, 0x00, 0x02, 0xAA, 0x80, 0x02, 0xAA, 0x80, 0x02, 0xAA, 0x80, 0x02,
	0xAA, 0x80, 0x02, 0xAA, 0x80, 0x02, 0xAA, 0x80, 0x0A, 0xAA, 0xA0, 0x09,
	0xAA, 0x60, 0x09, 0x55, 0x60, 0x02, 0xAA, 0x80, 0x00, 0x28, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x7D, 0x00,
	0x01, 0xFF, 0x40, 0x01, 0x7D, 0x80, 0x01, 0x55, 0x80, 0x01, 0x55, 0x80,
	0x01, 0x55, 0x80, 0x01, 0x55, 0x80, 0x01, 0x55, 0x80, 0x01, 0x55, 0x80,
	0x01, 0x55, 0x80, 0x01, 0x55, 0x80, 0x01, 0x55, 0x40, 0x00, 0x55, 0x00,
	0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0xC0, 0x00, 0x0F, 0x40, 0x00, 0x3D, 0x50, 0x00, 0xF5, 0x94,
	0x00, 0xD6, 0x55, 0x00, 0xD9, 0x69, 0x40, 0xD5, 0x96, 0x50, 0x15, 0x96,
	0x5C, 0x05, 0x69, 0x7C, 0x01, 0x55, 0xFC, 0x00, 0x57, 0xF0, 0x00, 0x1F,
	0xC0, 0x00, 0x0F, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40, 0x00, 0x01, 0x50, 0x80, 0x05, 0x56, 0x00, 0x0D,
	0x55, 0x00, 0x0F, 0x55, 0x40, 0x0F, 0xD5, 0x50, 0x02, 0xF5, 0x54, 0x08,
	0x3D, 0x5C, 0x00, 0x3B, 0x7C, 0x00, 0x23, 0xF0, 0x00, 0x00, 0xC0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x87
};


unsigned char tile1[576] ={
0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,
  
0,0,0,0,2,10,17,145,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
145,17,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,
  
0,0,0,0,2,10,42,170,2,9,39,169,170,170,170,170,128,96,216,106,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,
  
0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,152,70,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,70,152,160,128,0,0,0,0,
  
0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,169,36,9,2,170,170,170,170,106,24,96,128,170,168,160,128,0,0,0,0,
  
0,0,0,0,2,10,42,170,2,10,42,170,106,154,166,169,128,160,168,170,169,166,154,106,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,169,166,154,106,170,42,10,2,106,154,166,169,170,168,160,128,170,168,160,128,0,0,0,0,  

  0,0,0,0,2,10,42,170,2,10,42,170,106,154,166,169,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,106,154,166,169,170,168,160,128,170,168,160,128,0,0,0,0,

  0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,169,166,154,106,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,169,166,154,106,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,

0,0,0,0,2,10,42,170,2,10,42,170,106,154,166,169,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,169,166,154,106,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,  
};
 

unsigned char map[9][9]= {
  {2,1,1,1,1,1,1,1,3},
  {1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1},
  {1,1,1,1,5,1,1,1,1},
  {1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1},
  {5,1,1,1,1,1,1,1,4}
};
unsigned char isox[9][9]={
  {1,2,3,4,5,6,7,8,9},
  {2,3,4,5,6,7,8,9,10},
  {3,4,5,6,7,8,9,10,11},
  {4,5,6,7,8,9,10,11,12},
  {5,6,7,8,9,10,11,12,13},
  {6,7,8,9,10,11,12,13,14},
  {7,8,9,10,11,12,13,14,15},
  {8,9,10,11,12,13,14,15,16},
  {9,10,11,12,13,14,15,16,17}
};
unsigned char isoy[9][9]={
  {9,8,7,6,5,4,3,2,1},
  {10,9,8,7,6,5,4,3,2},
  {11,10,9,8,7,6,5,4,3},
  {12,11,10,9,8,7,6,5,4},
  {13,12,11,10,9,8,7,6,5},
  {14,13,12,11,10,9,8,7,6},
  {15,14,13,12,11,10,9,8,7},
  {16,15,14,13,12,11,10,9,8},
  {17,16,15,14,13,12,11,10,9}
};

  




void placetile(int x,int y, int tile){
  long pos=0;
  short counter=0;
  int ttile=0;
  y=y*320;
x=x*16;
for (counter=0;counter<32;counter++){
    pos=8192+counter+x+y;
  ttile=(tile-1)*64;
  	POKE(pos,PEEK(pos)|tile1[ttile+counter]);
  
  	POKE(pos+320,PEEK(pos+320)|tile1[ttile+counter+32]);  
  
}  
}  

void placetile2(int x,int y, int tile){
  long pos=0;
  short counter=0;
  int ttile=0;
  short oldpix=0;
  short oldpix2=0;  
  short newpix=0;
  short newpix2=0;  
  char oldbit[8],newbit[8];
  int count=0;
  int bits=128;
  y=y*320;
  
x=x*16;
for (counter=0;counter<32;counter++){
    pos=8192+counter+x+y;
  ttile=(tile-1)*64;
  //if(tile1[ttile+counter]!=0){
  	//POKE(pos,PEEK(pos)&tile1[ttile+counter]); // and
   	//POKE(pos+320,PEEK(pos+320)&tile1[ttile+counter+32]); // and   
  //	POKE(pos,PEEK(pos)|tile1[ttile+counter]);  // or
  //	POKE(pos+320,PEEK(pos+320)|tile1[ttile+counter+32]); // or    
  //} else {
    oldpix=PEEK(pos);

    newpix=tile1[ttile+counter];
//if(newpix==0){
//;;      POKE(pos,oldpix);
//} else {
  
  
for(count=0;oldpix>0;count++){
  oldbit[count]=0;
  newbit[count]=0;
  oldbit[count]=oldpix%2;
  newbit[count]=newpix%2;
  oldpix=oldpix/2;
  newpix=newpix/2;
}
if((newbit[0]==0)&&(newbit[1]==0)){
  newbit[0]=oldbit[0];
  newbit[1]=oldbit[1];
}
if((newbit[2]==0)&&(newbit[3]==0)){
  newbit[2]=oldbit[2];
  newbit[3]=oldbit[3];
}
if((newbit[4]==0)&&(newbit[5]==0)){
  newbit[4]=oldbit[4];
  newbit[5]=oldbit[5];
}
if((newbit[6]==0)&&(newbit[7]==0)){
  newbit[6]=oldbit[6];
  newbit[7]=oldbit[7];
}
  newpix=0;
  bits=128;
for(count=8;count>0;count--){
  if(newbit[count-1]==1){
    newpix+=bits;

  }
      bits=bits/2;
}  
      POKE(pos,newpix);
//}  
      oldpix=PEEK(pos+320); 
     newpix=tile1[ttile+counter+32];  
//if(newpix==0){
//      POKE(pos+320,oldpix);  
//} else {  
for(count=0;oldpix>0;count++){
  oldbit[count]=0;
  newbit[count]=0;
  oldbit[count]=oldpix%2;
  newbit[count]=newpix%2;
  oldpix=oldpix/2;
  newpix=newpix/2;
}
if((newbit[0]==0)&&(newbit[1]==0)){
  newbit[0]=oldbit[0];
  newbit[1]=oldbit[1];
}
if((newbit[2]==0)&&(newbit[3]==0)){
  newbit[2]=oldbit[2];
  newbit[3]=oldbit[3];
}
if((newbit[4]==0)&&(newbit[5]==0)){
  newbit[4]=oldbit[4];
  newbit[5]=oldbit[5];
}
if((newbit[6]==0)&&(newbit[7]==0)){
  newbit[6]=oldbit[6];
  newbit[7]=oldbit[7];
}
  newpix=0;
  bits=128;
for(count=8;count>0;count--){
  if(newbit[count-1]==1){
    newpix+=bits;

  }
      bits=bits/2;
}   
POKE(pos+320,newpix);
//}
   	//POKE(pos,tile1[ttile+counter]); // over write
      	//POKE(pos+320,tile1[ttile+counter+32]); 
 
  //}  
  //	POKE(pos+320,tile1[ttile+counter+32]); 
  //POKE(pos+320,PEEK(pos+320)&tile1[ttile+counter+32]); // and
  //POKE(pos+320,PEEK(pos+320)|tile1[ttile+counter+32]); // or

}  
}  


void main(void) {
  	unsigned int JOYADDR=56321L;
	unsigned int JOYREAD=0;
	unsigned int JOYEX=0;
	int JUP=254;
	int JDOWN=253;
	int JLEFT=251;
	int JRIGHT=247;
	int JFIRE=239;  
	long vicc=53248L; 
  	int spritex=0;
  	int spritey=0;
	int x=0;
	int y=1;
  
  	clrscr();
	poke(53265L,peek(53265L)|32);// set memory address
  	poke(53272L,peek(53272L)|8);// set bitmap mode	
	poke(53270L,peek(53270L)|16);// set multi colour
  	poke(53281L,0); // background black
  	//poke(53282L,0); // background #1
  	//poke(53283L,0); // background #2

    	 for(count=8192;count<16192;count++){
            POKE(count,0);
           }
  for (count=0;count<1000;count++){
                POKE(count+1024,117); // 1100 =12 1110 =14
    		POKE(count+55296L,12);
  	} 
  for(x=0;x<9;x++){
    for(y=0;y<9;y++){
      placetile(isox[y][x],isoy[y][x],map[y][x]);
      }
     } 
  

  for(count=0;count<64;count++){
    POKE(832+count,sprite[count]); // poke sprite 832.
  }
  POKE(vicc+21,1); // enable sprite 1
  POKE(2040L,13);  // set sprite location 13	
  POKE(vicc+28,1); // set sprite 1 multi colour
  POKE(vicc+37,1);  // sprite multi colour low
  POKE(vicc+38,3);  // sprite multi colour high	
  POKE(53287L,13);	// this prite unique colour
  x=4;
  y=4;
 while(JOYEX==0){ 
  	JOYREAD=0;	
	JOYREAD=PEEK(JOYADDR); // check joystick	
	if ((JOYREAD&JFIRE)==JOYREAD){ // fire exit
		map[y][x]++;
           waitvsync(); 
          waitvsync();  
          waitvsync();  
          if(map[y][x]>9)map[y][x]=1;
       placetile2(isox[y][x],isoy[y][x],map[y][x]);         
	}
  		if ((JOYREAD&JUP)==JOYREAD ){// UP
			x++;
                  if(x>8)x=0;
                  waitvsync();  
                  waitvsync();  
                  waitvsync();  
		} 
		if ((JOYREAD&JRIGHT)==JOYREAD){ // RIGHT
			y++;
                  if(y>8)y=0;
                  waitvsync();  
                  waitvsync();  
                  waitvsync();  
		}
		if ((JOYREAD&JDOWN)==JOYREAD){ // DOWN
			x--;
                  if(x<0)x=8;
                  waitvsync();  
                  waitvsync();  
                  waitvsync();  
		}	
		if ((JOYREAD&JLEFT)==JOYREAD){ // LEFT
			y--;
                  if(y<0)y=8;
                  waitvsync();  
                  waitvsync();  
                  waitvsync();  
		}
  
  spritex=(isox[y][x]*16)+27;
   spritey=(isoy[y][x]*8)+52;  
  if(spritex>255){
      POKE(vicc+16,1); // sprite x olverflow
  } else {
      POKE(vicc+16,0); // sprite x olverflow    
  }  

  POKE(vicc+0,spritex); // sprite x pos < 255
  POKE(vicc+1,spritey); // sprite Y pos
	
  
  


  

  
waitvsync();  
 }
}