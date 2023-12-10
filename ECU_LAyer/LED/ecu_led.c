/* 
 * File:   ecu_led.c
 * Author: Mahmoud M.Bayoumi
 *
 * Created on September 21, 2023, 5:27 AM
 */
#include "ecu_led.h"
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_initialize(const led_t *led){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led){
    ret = E_NOK;
     
    }else{
        pin_config_t pin_obj = {
        .port = led->port_name,
        .pin=led->pin,
        .logic = led->led_status,
    .direction = OUTPUT };
        gpio_pin_direction_intialize(&pin_obj);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
    ret = E_NOK;
     
    }else{
        pin_config_t pin_obj = {
        .port = led->port_name,
        .pin=led->pin,
        .logic = led->led_status,
    .direction = OUTPUT };
        gpio_pin_write_logic(&pin_obj,HIGH);
    }
    return ret;

}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led){Std_ReturnType ret = E_OK;
    if(NULL == led){
    ret = E_NOK;
     
    }else{
        pin_config_t pin_obj = {
        .port = led->port_name,
        .pin=led->pin,
        .logic = led->led_status,
    .direction = OUTPUT };
        gpio_pin_write_logic(&pin_obj,LOW);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_toggle(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
    ret = E_NOK;
     
    }else{
        pin_config_t pin_obj = {
        .port = led->port_name,
        .pin=led->pin,
        .logic = led->led_status,
    .direction = OUTPUT };
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}
