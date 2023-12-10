/* 
 * File:   ecu_dc_motor.h
 * Author: Mahmoud M.Bayoumi
 *
 * Created on October 19, 2023, 8:26 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/****************Includes **********************/
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*****************macros declarations************/
#define DC_MOTOR_ON_STATUS 0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

#define DC_MOTOR_PIN_1 0x00U
#define DC_MOTOR_PIN_2 0x01U


/*****************macros function declarations************/
/*****************data types declarations************/
typedef struct{

pin_config_t dc_motor_pin[2];

}dc_motor_t;
/*****************software interfaces declarations************/
Std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);
#endif	/* ECU_DC_MOTOR_H */

