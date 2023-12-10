/* 
 * File:   ecu_button.c
 * Author: Bayoumi
 *
 * Created on September 28, 2023, 9:17 AM
 */
#include "ecu_button.h"
/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;
    
    if(NULL == btn){
    ret = E_NOK;
     
    }else{
        ret = gpio_pin_direction_intialize(&(btn->button_pin));
        
    }
    return ret;
}
/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
Std_ReturnType button_read_state(const button_t *btn,button_state_t *btn_state){
    Std_ReturnType ret = E_NOK;
    logic_t pin_logic_status = LOW;
    if(NULL == btn || (NULL == btn_state)){
    ret = E_NOK;
     
    }else{   
        gpio_pin_read_logic(&(btn->button_pin),&pin_logic_status);
     if(BUTTON_ACTIVE_HIGH == btn->button_connection)
     {
         if(HIGH == pin_logic_status)
         {
             *btn_state = BUTTON_PRESSED;
         }
         else{
                                     *btn_state =  BUTTON_RELEASED ;
         }
     
     }else if(BUTTON_ACTIVE_LOW == btn->button_connection)   
     {
         if(HIGH == pin_logic_status)
            
         {
         *btn_state =  BUTTON_RELEASED ;
         }
         else{
                      *btn_state = BUTTON_PRESSED;
             }
     }
     else{/*Nothing*/}
        ret = E_OK;
    }
    return ret;
    
}