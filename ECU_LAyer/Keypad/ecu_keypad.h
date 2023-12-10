/* 
 * File:   ecu_keypad.h
 * Author: Bayoumi
 *
 * Created on October 29, 2023, 9:53 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
/****************Includes **********************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"

/*****************macros declarations************/
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COLUMNS 4

/*****************macros function declarations************/
/*****************data types declarations************/
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;
/*****************software interfaces declarations************/
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj,uint8 *value);


#endif	/* ECU_KEYPAD_H */

