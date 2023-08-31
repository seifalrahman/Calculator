#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "DIO_Interface.h"
#include "KPD.h"
#include "LCD_2.h"
#include<stdio.h>
u8 isoperand (u8 value);
u8 calc (u8 operand1,u8 operation , u8 operand2);
void print(u8 num);

void main(void)
{	u8 operand1=0;
	u8 operation ;
	u8 operand2 ;
	u8 result;
	u8 temp='0' ;
	DIO_VidSetPinDirection(PORT_B,PIN_0,DIO_OUTPUT);
	DIO_VidSetPinValue(PORT_B,PIN_0,DIO_HIGH);
	 LCD_VidInit();
	 KPD_VidInit();
	 while(1){
		 operand1=0;
		 operand2=0;
		 result=0;
		 temp='0';
		 operation=0;
		 while(!isoperand(temp)){
		 if(temp!=KPD_CHECK)
		 operand1=operand1*10+(temp-'0');
		 temp=KPD_U8PressedKey();
		 if(temp!=KPD_CHECK)
		 LCD_VidSendChar(temp);
		 }
		 operation=temp;
		 temp='0';
		 while(!isoperand(temp)){
			 if(temp!=KPD_CHECK)
			 	 operand2=operand2*10+(temp-'0');

			 	 temp=KPD_U8PressedKey();
			 if(temp!=KPD_CHECK)
				 LCD_VidSendChar(temp);
		 		 }
		 result=calc(operand1,operation,operand2);

		 print(result);
		 _delay_ms(3000);
		 LCD_VidSendCMD(0x01) ;
		 _delay_ms(3000);


	 }

}
u8 isoperand (u8 value){
	if(value=='+'||value=='-'||value=='*'||value=='/'||value=='='){
		return 1 ;
	}
	return 0 ;
}
u8 calc (u8 operand1,u8 operation , u8 operand2){
	u8 result ;

	switch(operation){
	case '+': result =operand1+operand2 ;break;
	case '-': result =operand1-operand2 ;break;
	case '*': result =(operand1*operand2) ;break;
	case '/': result =operand1/operand2 ;break;
	}

	return  result ;
}
void print(u8 num){
	u8 temp =0 ;

	u8 cnt=0;
	if(num<0){
		LCD_VidSendChar('-');
		num=num*-1 ;
	}
	if(num==0){LCD_VidSendChar('0');}
	while(num!=0){
		temp=temp*10+(num%10);
		num=num/10 ;
		cnt++;
	}
	while(temp!=0){

		LCD_VidSendChar(((temp%10)+'0'));
		cnt--;
		temp=temp/10 ;
	}
	while(cnt--){
		LCD_VidSendChar('0');
	}


}

