/******************************************************/
/************* Date : 14/12/2023 **********************/
/************* File Name : Bit Math Operation File ****/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

/************* Header Guard *****************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(var,BIT_NO) (var|=(1<<BIT_NO))
#define CLR_BIT(var,BIT_NO) (var&=~(1<<BIT_NO))
#define TOGGLE_BIT(var,BIT_NO) (var^=(1<<BIT_NO))
#define GET_BIT(var,BIT_NO) ((var>>BIT_NO)&1)
#define ASSIGN_BIT(var,BIT_NO,value) (var = (var&=~(1<<BIT_NO))|(value<<BIT_NO))

#endif 
