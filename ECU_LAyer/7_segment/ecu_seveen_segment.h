/* 
 * File:   ecu_seveen_segment.h
 * Author: Bayoumi
 *
 * Created on October 26, 2023, 12:48 PM
 */

#ifndef ECU_SEVEEN_SEGMENT_H
#define	ECU_SEVEEN_SEGMENT_H
/****************Includes **********************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_seven_segment_cfg.h"
/*****************macros declarations************/
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 3
/*****************macros function declarations************/

/*****************data types declarations************/
typedef enum{
    EGMENT_COMMON_ANODE,
    EGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct {
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;
/*****************software interfaces declarations************/
Std_ReturnType seven_segment_initialize(const segment_t *seg);
Std_ReturnType seven_segment_write_number(const segment_t *seg, uint8 number);

#endif