/* 
 * File:   ecu_relay.h
 * Author: Mahmoud M.Bayoumi
 *
 * Created on October 10, 2023, 9:12 AM
 */


#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/****************Includes **********************/
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*****************macros declarations************/
#define RELAY_ON_STATUS  0x01U
#define RELAY_OFF_STATUS 0x00U

/*****************macros function declarations************/
/*****************data types declarations************/
typedef struct{
    uint8 relay_port :4;
    uint8 relay_pin : 3;
    uint8 relay_status :1;

}relay_t;

/*****************software interfaces declarations************/
Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

