/*
 * EXTI.c
 *
 *  Created on: Aug 16, 2023
 *      Author: seif alrahman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI.h"
#define NULL ((void*)0)
#include <avr/interrupt.h>

void (*EXTI_PTemp[3])(void)={NULL,NULL,NULL};

void EXTI_VidInit(void){


#if EXTI==INT_0


#if EXTI_MODE==LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif EXTI_MODE==ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif	EXTI_MODE==FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif EXTI_MODE==RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#endif
	SET_BIT(GICR,INT0);
#elif EXTI==INT_1
#if EXTI_MODE==LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXTI_MODE==ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif	EXTI_MODE==FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif EXTI_MODE==RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif
	SET_BIT(GICR,INT1);
#elif EXTI==INT_2
#if	EXTI_MODE==FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
#elif EXTI_MODE==RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
#endif
	SET_BIT(GICR,INT2);
#endif
}

void EXTI_VidGIE(void){
#if GIE==ENABLE
	SET_BIT(SREG,I_BIT) ;
#elif GIE ==DISABLE
	CLR_BIT(SREG,I_BIT)	 ;
#endif

}

void EXTI_VidSetCallBack(u8 Copy_U8Index,void(*Copy_PFPtr)(void)){
	EXTI_PTemp[Copy_U8Index]=Copy_PFPtr;
}


ISR(INT0_vect){
	if(EXTI_PTemp[0]!=NULL)
	EXTI_PTemp[0]() ;
}
ISR(INT1_vect){
	if(EXTI_PTemp[1]!=NULL)
	EXTI_PTemp[1]() ;
}
ISR(INT2_vect){
	if(EXTI_PTemp[2]!=NULL)
	EXTI_PTemp[2]() ;
}


