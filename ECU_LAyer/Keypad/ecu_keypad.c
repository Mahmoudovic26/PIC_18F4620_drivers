/* 
 * File:   ecu_keypad.c
 * Author: Bayoumi
 *
 * Created on October 29, 2023, 9:54 PM
 */
#include "ecu_keypad.h"
static const uint8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMNS] = {
                                                            {'7','8','9','/'},
                                                            {'4','5','6','*'},
                                                            {'1','2','3','-'},
                                                            {'#','0','=','+'}
};
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj){
        Std_ReturnType ret = E_OK;
        uint8 rows_counter = ZERO_INIT;
        uint8 columns_counter = ZERO_INIT;
    if(NULL == _keypad_obj){
    ret = E_NOK;
     
    }else{
        for(rows_counter=ZERO_INIT;rows_counter<ECU_KEYPAD_ROW;rows_counter++){
            ret = gpio_pin_intialize(&(_keypad_obj->keypad_row_pins[rows_counter]));
        }
        for(columns_counter=ZERO_INIT;columns_counter<ECU_KEYPAD_COLUMNS;columns_counter++){
            ret = gpio_pin_direction_intialize(&(_keypad_obj->keypad_columns_pins[columns_counter]));
        }
      
    }
    return ret;

}
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value){
        Std_ReturnType ret = E_OK;
        uint8 l_rows_counter = ZERO_INIT;
        uint8 l_columns_counter = ZERO_INIT;
        uint8 l_counter = ZERO_INIT;
        uint8 pin_value = ZERO_INIT;
    if((NULL == _keypad_obj) || (NULL == value)){
    ret = E_NOK;
     
    }else{
        for(l_rows_counter=ZERO_INIT;l_rows_counter<ECU_KEYPAD_ROW;l_rows_counter++){
            for(l_counter=ZERO_INIT;l_counter<ECU_KEYPAD_ROW;l_counter++){
                       ret =  gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_counter]),LOW);
            }
                    gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_rows_counter]),HIGH);
                for(l_columns_counter=ZERO_INIT;l_columns_counter<ECU_KEYPAD_COLUMNS;l_columns_counter++){
                    ret = gpio_pin_read_logic(&(_keypad_obj->keypad_columns_pins[l_columns_counter]),&pin_value);
                
                if(HIGH == pin_value){
                  *value=  btn_values[l_rows_counter][l_columns_counter];
                }   
            }
        }
    }
    return ret;
    
    
    
    
}