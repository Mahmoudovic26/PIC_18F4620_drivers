/* 
 * File:   ecu_relay.c
 * Author: Mahmoud M.Bayoumi
 *
 * Created on October 10, 2023, 9:12 AM
 */
#include "ecu_relay.h"
/**
 * 
 * @param _relay
 * @return 
 */
Std_ReturnType relay_initialize(const relay_t *_relay){
    Std_ReturnType ret = E_NOK ;
    if(NULL == _relay){
        ret = E_NOK;
    
    }else
    {
        pin_config_t pin_obj = {.port=_relay->relay_port,.pin=_relay->relay_pin
        ,.direction = OUTPUT,.logic= _relay->relay_status};
        gpio_pin_intialize(&pin_obj);    
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t *_relay){
        Std_ReturnType ret = E_NOK ;

 if(NULL == _relay){
        ret = E_NOK;
    
    }else
    {
     pin_config_t pin_obj = {.port=_relay->relay_port,.pin=_relay->relay_pin
        ,.direction = OUTPUT,.logic= _relay->relay_status};
     gpio_pin_write_logic(&pin_obj,HIGH);
    
            ret = E_OK;

    }
   


    return ret;}
/**
 * 
 * @param _relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t *_relay){
    Std_ReturnType ret = E_NOK ;

 if(NULL == _relay){
        ret = E_NOK;
    
    }else
    {
    
     pin_config_t pin_obj = {.port=_relay->relay_port,.pin=_relay->relay_pin
        ,.direction = OUTPUT,.logic= _relay->relay_status};
     gpio_pin_write_logic(&pin_obj,LOW);
    
            ret = E_OK;
    
    }



    return ret;}
