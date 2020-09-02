
#include <stdio.h>
#include <conio.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>

void main(void) {
  long pos=0;
 short temp=0;
  short output=0;
  short counter=0;
  int ttile=0;
  short oldpix=0;
  short oldpix2=0;  
  short newpix=0;
  short newpix2=0;  
  short temppix=0;
  short temp2=0;
  char oldbit[8],newbit[8];
  int count=0;
  int bits=128;
  clrscr();
    oldpix=170;
    newpix=21;
  temp=newpix&192;
  printf(" newpix %d and 192 =%d \n",newpix,temp);
  temp=newpix&48;
   printf(" newpix %d and 48 =%d \n",newpix,temp); 
  temp=newpix&12;
   printf(" newpix %d and 12 =%d \n",newpix,temp);
   temp=newpix&3;
   printf(" newpix %d and 3  =%d \n",newpix,temp);
temp=oldpix&192;
  printf(" oldpix %d and 192 =%d \n",oldpix,temp);
  temp=oldpix&48;
   printf(" oldpix %d and 48 =%d \n",oldpix,temp); 
  temp=oldpix&12;
   printf(" oldpix %d and 12 =%d \n",oldpix,temp);
   temp=oldpix&3;
   printf(" oldpix %d and 3  =%d \n",oldpix,temp);
  
  printf("new = %d \n",newpix);
   printf("old = %d \n",oldpix);   
  
temp=newpix&192;
temp2=oldpix&192;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
}
  printf("output = %d \n",output);  
temp=newpix&48;
temp2=oldpix&48;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
}  
printf("output = %d \n",output);    
temp=newpix&12;
temp2=oldpix&12;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
} 
printf("output = %d \n",output);    
temp=newpix&3;
temp2=oldpix&3;
if(temp==0){
 output+=temp2;
} else {
  output+=temp;
}  
printf("output = %d \n",output);  
  
  

  
  


for(count=0;oldpix>0;count++){
  oldbit[count]=0;
  newbit[count]=0;
  oldbit[count]=oldpix%2;
  newbit[count]=newpix%2;
  oldpix=oldpix/2;
  newpix=newpix/2;
}  

  for(count=0;count<8;count++){
    printf("%d",oldbit[count]);
   }  
  printf("\r\n");
 
   for(count=0;count<8;count++){     
  	printf("%d",newbit[count]);  
   }   
    printf("\r\n");
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
  
  printf("\r\n");
 
   for(count=0;count<8;count++){     
  	printf("%d",newbit[count]);  
   }   
   printf("\r\n"); 
for(count=8;count>0;count--){
  if(newbit[count-1]==1){
    newpix+=bits;

  }
      bits=bits/2;

}  
   printf("%d \n",newpix);  
  while(kbhit  fd()!=99){
    printf("%d",kbhit());
  }  
  
}
