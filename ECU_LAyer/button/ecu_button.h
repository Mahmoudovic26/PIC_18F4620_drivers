/* 
 * File:   ecu_button.h
 * Author: Bayoumi
 *
 * Created on September 28, 2023, 9:17 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/****************Includes **********************/
#include "ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*****************macros declarations************/
/*****************macros function declarations************/
/*****************data types declarations************/
typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;
typedef enum{
  BUTTON_ACTIVE_HIGH,
  BUTTON_ACTIVE_LOW
}button_active_t;
typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
            
}button_t;
/*****************software interfaces declarations************/
Std_ReturnType button_initialize(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn,button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

