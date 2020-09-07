
#include <stdio.h>
#include <conio.h>
#include <c64.h>
//#include <cbm_petscii_charmap.h>
#include <peekpoke.h>

#define poke(A,X) (*(unsigned char *)A) = (X)
#define peek(A) (*(unsigned char *)A)


unsigned long count=0;
unsigned int base=8192;
char nib1=0;
char nib2=0;
char nib3=0;
char nib4=0;
char nib5=0;
char nib6=0;
char nib7=0;
char nib8=0;
char nibout=0;
char newpix=0;
char maxtile=20;

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

// 24 tiles
                
unsigned char tile1[1280] ={
// plain green
0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,
// left cporner  
0,0,0,0,2,10,17,157,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
157,17,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,
// top corner  
0,0,0,0,2,10,42,170,2,9,39,169,170,170,170,170,128,96,216,106,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,170,168,160,128,0,0,0,0,
// bot corner  
0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,152,118,
170,42,10,2,0,0,0,0,170,170,170,170,170,42,10,2,170,170,170,170,170,168,160,128,118,152,160,128,0,0,0,0,
// left corner  
0,0,0,0,2,10,42,170,2,10,42,170,170,170,170,170,128,160,168,170,170,170,170,170,0,0,0,0,128,160,168,170,
170,42,10,2,0,0,0,0,170,170,170,170,169,39,9,2,170,170,170,170,106,216,96,128,170,168,160,128,0,0,0,0,
//yellow right to left
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	170	,	170	,	170	,	170	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,

//cross
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,

//left to right
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	170	,	170	,	170	,	170	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	170	,	170	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,

// corner 1
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	170	,	170	,	170	,	170	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	170	,	170	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//corner 2
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	170	,	170	,	170	,	170	,
128	,	160	,	168	,	170	,	170	,	170	,	170	,	170	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//corner 3
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	170	,	170	,	170	,	170	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//corner 4
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	170	,	170	,	170	,	42	,	10	,	2	,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
 //tee 1
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	170	,	170	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//tee 2//
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	170	,	170	,	170	,	170	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//tee 3
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	170	,	170	,	170	,	170	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
106	,	154	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//gap 4
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	166	,	169	,
128	,	160	,	168	,	170	,	169	,	166	,	154	,	106	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	169	,	166	,	154	,	106	,	170	,	42	,	10	,	2	,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
//gap 1
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	170	,	170	,	170	,	170	,
128	,	160	,	168	,	170	,	169	,	166	,	170	,	170	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	154	,	106	,	170	,	42	,	10	,	2	,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
// gap 2
0	,	0	,	0	,	0	,	2	,	10	,	42	,	170	,	2	,	10	,	42	,	170	,	106	,	154	,	170	,	170	,
128	,	160	,	168	,	170	,	170	,	170	,	170	,	170	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	170	,	170	,	170	,	42	,	10	,	2	,
170	,	170	,	166	,	169	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,0,0,
0	,	0	,	0	,	0	,	2	,	10	,	43	,	171	,	2	,	10	,	42	,	170	,	170	,	170	,255,255,
128	,	160	,	168	,	170	,	170	,	170	,	234	,	234	,	0	,	0	,	0	,	0	,	128	,	160	,168,170,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	170	,	170	,	154	,	106	,	170	,	42	,10,2,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,0,0,
0	,	0	,	0	,	0	,	2	,	10	,	43	,	171	,	2	,	10	,	42	,	170	,	174	,	174	,	255	,	255	,
128	,	160	,	168	,	170	,	169	,	166	,	234	,	234	,	0	,	0	,	0	,	0	,	128	,	160	,	168	,	170	,
170	,	42	,	10	,	2	,	0	,	0	,	0	,	0	,	174	,	174	,	170	,	170	,	170	,	42	,	10	,	2	,
170	,	170	,	170	,	170	,	170	,	168	,	160	,	128	,	170	,	168	,	160	,	128	,	0	,	0	,	0	,	0	,
  
};
 
unsigned char spritestat[8] = {0,0,0,0,0,0,0,0};
unsigned char map[9][10]= {
  {2,1,9,19,20,10,1,1,3,1},
  {1,1,8,1,1,8,1,1,1,2},
  {1,1,18,1,1,18,1,1,1,3},
  {1,1,8,1,1,8,1,1,1,4},
  {1,1,12,6,6,11,1,1,1,5},
  {1,1,1,1,1,1,1,1,1,6},
  {1,1,1,1,1,1,1,1,1,7},
  {1,1,1,1,1,1,1,1,1,0},
  {5,1,1,1,1,1,1,1,4,0}
};

unsigned char spritemap[9][10]= {
  {0,0,0,0,0,0,0,0,0,2},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,3},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0}
};

unsigned char isox[9][10]={
  {1,2,3,4,5,6,7,8,9,10},
  {2,3,4,5,6,7,8,9,10,11},
  {3,4,5,6,7,8,9,10,11,12},
  {4,5,6,7,8,9,10,11,12,13},
  {5,6,7,8,9,10,11,12,13,14},
  {6,7,8,9,10,11,12,13,14,15},
  {7,8,9,10,11,12,13,14,15,16},
  {8,9,10,11,12,13,14,15,16,17},
  {9,10,11,12,13,14,15,16,17,18}
};
unsigned char isoy[9][10]={
  {9,8,7,6,5,4,3,2,1,0},
  {10,9,8,7,6,5,4,3,2,1},
  {11,10,9,8,7,6,5,4,3,2},
  {12,11,10,9,8,7,6,5,4,3},
  {13,12,11,10,9,8,7,6,5,4},
  {14,13,12,11,10,9,8,7,6,5},
  {15,14,13,12,11,10,9,8,7,6},
  {16,15,14,13,12,11,10,9,8,7},
  {17,16,15,14,13,12,11,10,9,8}
};

  




void placetile(int x,int y, int tile){
  long pos=0;
  short counter=0;
  int ttile=0;
  y=y*320;
x=x*16;
for (counter=0;counter<32;counter++){
    pos=32768L+8192+counter+x+y;
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

  short newpix2=0;  
  short temp=0;
  short temp2=0;
  short output=0;
  //char oldbit[8],newbit[8];
  int count=0;
  int bits=128;
  y=y*320;
  
x=x*16;
  ttile=(tile-1)*64; 
  for (counter=0;counter<32;counter++){
    pos=32768L+8192+320+counter+x+y;


      oldpix=PEEK(pos); 
     newpix=tile1[ttile+counter+32];  
nib1=newpix&192;
nib2=oldpix&192;
output=0;  
if(nib1==0){
 output+=nib2;
} else {
  output+=nib1;
}
nib3=newpix&48;
nib4=oldpix&48;
if(nib3==0){
 output+=nib4;
} else {
  output+=nib3;
}  
nib5=newpix&12;
nib6=oldpix&12;
if(nib5==0){
 output+=nib6;
} else {
  output+=nib5;
} 
nib7=newpix&3;
nib8=oldpix&3;
if(nib7==0){
 output+=nib8;
} else {
  output+=nib7;
}  
nibout=output;
POKE(pos,output) ;
//POKE(pos+640,oldpix) ;
//POKE(pos+640+640,newpix) ;    
 }   
for (counter=0;counter<32;counter++){
    pos=32768L+8192+counter+x+y;
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
output=0;  
temp=newpix&192;
temp2=oldpix&192;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
}
temp=newpix&48;
temp2=oldpix&48;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
}  
temp=newpix&12;
temp2=oldpix&12;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
} 
temp=newpix&3;
temp2=oldpix&3;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
}  
newpix=output;
POKE(pos,newpix);  
  

//}  

}   
//}
   	//POKE(pos,tile1[ttile+counter]); // over write
      	//POKE(pos+320,tile1[ttile+counter+32]); 
 
  //}  
  //	POKE(pos+320,tile1[ttile+counter+32]); 
  //POKE(pos+320,PEEK(pos+320)&tile1[ttile+counter+32]); // and
  //POKE(pos+320,PEEK(pos+320)|tile1[ttile+counter+32]); // or

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
  int UPFIRE=238;
  int DOFIRE=237;
	long vicc=53248L; 
  	int spritex=0;
  	int spritey=0;
  	int spritex2=0;
  	int spritey2=0;
  	int spritex3=0;
  	int spritey3=0;
  	int x=0;
	int y=1;
  	int x2=9;
	int y2=1;
  int x3=9;
  int y3=3;
 	int curtile=6 ;
  char keyb=0;
  nib1=0;
  nib2=0;
 nib3=0;
 nib4=0;
 nib5=0;
 nib6=0;
 nib7=0;
 nib8=0; 
  	POKE(56578L,PEEK(56578L)|3);
	POKE(56576L,(PEEK(56576L)&252)|1);	// bank  = 1   address = 32768
  	//clrscr();
	poke(53265L,peek(53265L)|32);// extended  colour mode
  	poke(53272L,peek(53272L)|8);// set bitmap mode	
	poke(53270L,peek(53270L)|16);// set multi colour
  
  	poke(53281L,0); // background black
  	//poke(53282L,0); // background #1
  	//poke(53283L,0); // background #2

    	 for(count=32768L+8192;count<32768L+16192;count++){
            POKE(count,0);
           }
  for (count=0;count<1000;count++){
                POKE(32768L+count+1024,117); // 1100 =12 1110 =14
    		POKE(count+55296L,0);
  	} 
  for(x=0;x<9;x++){
    for(y=0;y<9;y++){
      placetile(isox[y][x],isoy[y][x],map[y][x]);
      }
     } 
  

  for(count=0;count<384;count++){
    POKE(32768L+count,sprite[count]); // poke sprite 832.
     //POKE(32768L+64+count,sprite[count+128]); // poke sprite 832.   
  }
 
  //POKE(vicc+21,1); // enable sprite 1
  POKE(vicc+21,7); // enable sprite 1
  POKE(32768L+2040L,0);  // set sprite location 13	
  //POKE(vicc+28,11); // set sprite 1 multi colour
  POKE(vicc+37,6);  // sprite multi colour low
  POKE(vicc+38,12);  // sprite multi colour high	
  POKE(vicc+39,1);	// this prite unique colour
  POKE(32768L+2041L,2);  // set sprite location 13	
  POKE(vicc+28,7); // set sprite 1 multi colour
  POKE(vicc+37,6);  // sprite multi colour low
  POKE(vicc+38,11);  // sprite multi colour high	
  POKE(vicc+40,2);	// this prite unique colour  14 = on 6 = off
 POKE(32768L+2042L,4);  // set sprite location 13	
  //POKE(vicc+28,2); // set sprite 1 multi colour
  POKE(vicc+37,6);  // sprite multi colour low
  POKE(vicc+38,11);  // sprite multi colour high	
  POKE(vicc+41,15);	
  x=4;
  y=4;
x2=9;
  y2=1;
  x3=9;
  y3=3;
  //placetile(1,1,curtile);
 while(JOYEX==0){ 
 /*  keyb=PEEK(631);
   if(keyb==13){
   	curtile++;
 
	if(curtile>maxtile)curtile=1;
     POKE(198,0);
            waitvsync(); 
          waitvsync();  
          waitvsync();  
          placetile2(1,1,curtile); 
       POKE(631,0);
    
   }*/  
  	JOYREAD=0;	
	JOYREAD=PEEK(JOYADDR); // check joystick	
   if ((JOYREAD&UPFIRE)==JOYREAD){
     //curtile++;
     //if(curtile>maxtile)curtile=1;
     //  placetile2(1,1,curtile);
  
     JOYREAD=0;
   }
     if(((x==x2)&&(y==y2)) ||((x==x3)&&(y==y3))){
   	POKE(53287L,4);
     } else {
  	POKE(53287L,7);
     } 
 //    if((x==x3)&&(y==y3)){
 //  	POKE(53287L,4);
 //    } else {
//  	POKE(53287L,7);
//     }
//if(x2==   
if(spritestat[0]==1){
    	POKE(53288L,1);
  x2=x;
  y2=y;
  spritemap[y2][x2]=1;  
}  
if(spritestat[0]==0){
  	POKE(53288L,6);
  } 
if(spritestat[1]==1){
    	  POKE(vicc+41,1);
  x3=x;
  y3=y;
  spritemap[y3][x3]=1;  
}  
if(spritestat[1]==0){
  	  POKE(vicc+41,15);
  }    
	if ((JOYREAD&JFIRE)==JOYREAD){ // fire exit
     if((x==x2)&&(y==y2)){
       if (spritestat[0]==0){
         spritestat[0]=1;
       } else {
         spritestat[0]=0;         
       }
     }  
     if((x==x3)&&(y==y3)){
       if (spritestat[1]==0){
         spritestat[1]=1;
       } else {
         spritestat[1]=0;         
       }         
         
	}
                   waitvsync();  
                  waitvsync();  
                  waitvsync(); 
        }     
  		if ((JOYREAD&JUP)==JOYREAD ){// UP
			x++;
                  if(x>9)x=0;
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
                  if(x<0)x=9;
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

  spritex=(isox[y][x]*16)+27; // map tiles
  spritey=(isoy[y][x]*8)+52; // map tiles 
  //spritex=(isox[y2][x2]*16)+30; // components
  //spritey=(isoy[y2][x2]*8)+46; // components   
   if(spritex>255){
      POKE(vicc+16,1); // sprite x olverflow
  } else {
      POKE(vicc+16,0); // sprite x olverflow    
  }  

  POKE(vicc+0,spritex); // sprite x pos < 255
  POKE(vicc+1,spritey); // sprite Y pos
  spritex2=(isox[y2][x2]*16)+30; // components
  spritey2=(isoy[y2][x2]*8)+46; // components   
  POKE(vicc+2,spritex2); // sprite x pos < 255
  POKE(vicc+3,spritey2); // sprite Y pos	
  spritex3=(isox[y3][x3]*16)+30; // components
  spritey3=(isoy[y3][x3]*8)+46; // components   
  POKE(vicc+4,spritex3); // sprite x pos < 255
  POKE(vicc+5,spritey3); // sprite Y pos  
  

if((x2==5)&&(x3==2)&&(y2==2)&&(y3==2)){
  POKE(53288L,14);
  spritestat[0]=2;
} 

  
waitvsync();  
 }
}



