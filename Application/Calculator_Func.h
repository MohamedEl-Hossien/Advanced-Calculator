/******************************************************/
/************* Date : 15/03/2024 **********************/
/************* File Name : Calculator_Func ************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef APPLICATION_CALCULATOR_FUNC_H_
#define APPLICATION_CALCULATOR_FUNC_H_

#define Syntax_Error 	0x00		//Macro for Syntax_Error, Ex:15/9* ,*-54, ....
#define Math_Error		0x0F		//Macro for Math_Error,	  Ex:5/0
#define Correct 		0xFF		//Macro for Correct Expression

/******************************************************/
/****************** Function 1 ************************/
/************** Create two Arrays *********************/
/********** First Array has Operands ******************/
/********* Second Array has Operators *****************/
/****** Check if Operands == Operators +1 *************/
/**** if True -> Call another Function to Calculate
 * The Result and Check if There is Math_Error or not */
/********** if False-> Return Syntax_Error ************/
/******************************************************/
u8 M_u8_Create_KPD_Arr(u8 Copy_u8_Counter, f32* P_f32_Result);

/******************************************************/
/******************* Function 2 ***********************/
/****** Calculate The Result & Check Math_Error *******/
/*** First Calculate Multiply & Division Operators ****/
/** Second Calculate Addition & Subtraction Operators */
/******************************************************/
u8 M_u8_Calculate_Result(u8* P_u8_Operators_Arr, f32* P_f32_Operands_Arr, u8 Copy_u8_Operators_Count, f32* P_f32_Result);


#endif /* APPLICATION_CALCULATOR_FUNC_H_ */
