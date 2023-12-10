/* 
 * File:   ecu_dc_motor.c
 * Author: Mahmoud M.Bayoumi
 *
 * Created on October 19, 2023, 8:26 AM
 */

#include "ecu_dc_motor.h"


Std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor){
    Std_ReturnType ret =E_OK;
    if(NULL==_dc_motor){
        ret = E_NOK;
}else{
      
               
            gpio_pin_intialize(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]));
            gpio_pin_intialize(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]));
    }
    return ret;
}
Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor){
Std_ReturnType ret =E_OK;
    if(NULL==_dc_motor){
        ret = E_NOK;
    }else{
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]),HIGH);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]),LOW); 
    }
    return ret;

}
Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor){
    Std_ReturnType ret =E_OK;
    if(NULL==_dc_motor){
        ret = E_NOK;
    }else{
         
        
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]),LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]),HIGH); 
    }
    return ret;
    
    
}
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor){
    Std_ReturnType ret =E_OK;
    if(NULL==_dc_motor){
        ret = E_NOK;
    }else{
           
        
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_1]),LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[DC_MOTOR_PIN_2]),LOW); 
    }
    return ret;
    
    
    
}