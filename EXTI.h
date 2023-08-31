/*
 * EXTI.h
 *
 *  Created on: Aug 16, 2023
 *      Author: seif alrahman
 */

#ifndef EXTI_H_
#define EXTI_H_
/*1- INT_0
 * 2-INT_1
 * 3-INT_2
 * */
void EXTI_VidGIE(void);
void EXTI_VidSetCallBack(u8 Copy_U8Index,void(*Copy_PFPtr)(void));

#define EXTI   INT_0
#define EXTI_MODE	ANY_LOGICAL_CHANGE

/*SELECT MODE
 * */
#define LOW_LEVEL	0
#define ANY_LOGICAL_CHANGE	1
#define FALLING_EDGE	2
#define RISING_EDGE	3
#define GIE	ENABLE

#define ENABLE	0
#define DISABLE	1

#define I_BIT 7

#define INT_0   0
#define INT_1	1
#define INT_2	2



#endif
