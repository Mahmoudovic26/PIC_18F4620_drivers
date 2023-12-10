/* 
 * File:   application.c
 * Author: Mahmoud M.Bayoumi
 *
 * Created on September 21, 2023, 1:44 AM
 */
#include "application.h"
uint8 lcd1_counter = ZERO_INIT;
uint8 lcd_ciunter_txt[4];
const uint8 customChar1[] = {0x0E,0x0A,0x11,0x11,0x11,0x11,0x1F,0x00};
const uint8 customChar2[] = {0x0E,0x0A,0x11,0x11,0x11,0x1F,0x1F,0x00};
const uint8 customChar3[] = {0x0E,0x0A,0x11,0x11,0x1F,0x1F,0x1F,0x00};
const uint8 customChar4[] = {0x0E,0x0A,0x11,0x1F,0x1F,0x1F,0x1F,0x00};
const uint8 customChar5[] = {0x0E,0x0A,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};


void welcome_message(void){
    for(lcd1_counter=1;lcd1_counter<=2;++lcd1_counter){
       lcd_4bit_send_string_pos(&lcd_1,1,5,"Hello All");
                __delay_ms(500);
                lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
                __delay_ms(100);

    }
}
void loading_screen(void){
    lcd_8bit_send_string_pos(&lcd_2,1,1,"loading");
    uint8 l_lcd2_counter = ZERO_INIT;
    for(l_lcd2_counter =8;l_lcd2_counter<=15;++l_lcd2_counter ){
        lcd_8bit_send_char_data_pos(&lcd_2,1,l_lcd2_counter,'.');
        __delay_ms(50);
    }
        lcd_8bit_send_string_pos(&lcd_2,1,8,"        ");

}
int main() {
 Std_ReturnType ret = E_NOK;
application_intialize();
    ret = lcd_4bit_send_custome_char(&lcd_1,2,20,customChar1,0);__delay_ms(250);


while(1){
    ret = lcd_8bit_send_custome_char(&lcd_2,1,20,customChar1,0);__delay_ms(250);
    ret = lcd_8bit_send_custome_char(&lcd_2,1,20,customChar2,0);__delay_ms(250);
    ret = lcd_8bit_send_custome_char(&lcd_2,1,20,customChar3,0);__delay_ms(250);
    ret = lcd_8bit_send_custome_char(&lcd_2,1,20,customChar4,0);__delay_ms(250);
    ret = lcd_8bit_send_custome_char(&lcd_2,1,20,customChar5,0);__delay_ms(250);


    

}
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOK;
    ecu_layer_initialize();

} 