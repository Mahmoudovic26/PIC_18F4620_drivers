/* 
 * File:   application.h
 * Author: Mahmoud M.Bayoumi
 *
 * Created on September 21, 2023, 5:29 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/ecu_layer_init.h"
/*Section :Macro Declarations */


/*Section :Macro Function Declarations */

/*Section :Data Types Declarations */
extern keypad_t keypad1;
extern led_t led1;
extern chr_lcd_8bit_t lcd_2;
extern chr_lcd_4bit_t lcd_1;
/*Section :Function Declarations */
void application_intialize(void);

#endif	/* APPLICATION_H */

