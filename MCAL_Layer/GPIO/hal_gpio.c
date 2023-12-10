/* 
 * File:   hal_gpio.c
 * Author: Mahmoud M.Bayoumi
 *
 * Created on September 21, 2023, 1:44 AM
 */
#include "hal_gpio.h"
/*Reference to the data direction control register */
volatile uint8 *tris_registers[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *lat_registers[] = {&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *port_registers[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/**
 * 
 * @param _pin_config
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
    ret = E_NOK;
     
    }else{
    switch(_pin_config->direction){
        case OUTPUT:
            CLEAR_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        case INPUT:
            SET_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        default :ret = E_NOK;
    }}
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param dic_status
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *dic_status){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == dic_status ||_pin_config->pin > PORT_PIN_MAX_NUMBER-1 ){
            ret = E_NOK;}
    else{
       *dic_status =  READ_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
    
    }
    
    
    
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic){
    Std_ReturnType ret = E_OK;
    
    if(NULL == _pin_config ||_pin_config->pin > PORT_PIN_MAX_NUMBER-1){
            ret = E_NOK;}
    else{
    switch(logic){
        case LOW:
            CLEAR_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
        case HIGH:
            SET_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
        default :ret = E_NOK;
    }
    }
    
    
    
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic){
    Std_ReturnType ret = E_OK;
    
    if(NULL == _pin_config || NULL == logic ||_pin_config->pin > PORT_PIN_MAX_NUMBER-1){
            ret = E_NOK;}
    else{
     *logic =  READ_BIT(*port_registers[_pin_config->port],_pin_config->pin);
    }
    
    
    
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    
    if(NULL == _pin_config ||_pin_config->pin > PORT_PIN_MAX_NUMBER-1){
            ret = E_NOK;}
    else{
    
    }
    
    
    
    return ret;
}
#endif
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config){
Std_ReturnType ret = E_OK;
    
    
    if(NULL == _pin_config){
            ret = E_NOK;}
    else{
    ret = gpio_pin_direction_intialize(_pin_config);
    ret = gpio_pin_write_logic(_pin_config,_pin_config->logic);
    }
    
    
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param direction
 * @return 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_intialize(port_index_t port,uint8 direction){
   Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOK;
    }
    else{
        *tris_registers[port] = direction;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param dic_status
 * @return 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *dic_status){
    Std_ReturnType ret = E_OK;
    
    
    if(NULL == dic_status){
            ret = E_NOK;}
    else{
    *dic_status = *tris_registers[port];
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic){
     Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOK;}
    else{
        *lat_registers[port] = logic;
    }
    return ret;

}
#endif
/**
  * 
  * @param port
  * @param logic
  * @return 
  */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic){
    Std_ReturnType ret = E_OK;
    
    if(NULL == logic){
            ret = E_NOK;}
    else{
            *logic = *lat_registers[port];
    }
    
    
    
    return ret;
}
#endif
/**
  * 
  * @param port
  * @return 
  */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE

Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    Std_ReturnType ret = E_OK;

    if(port > PORT_MAX_NUMBER)
    {
        ret = E_NOK;
    }
    else{
        *lat_registers[port] ^= PORT_MASK;
    }
    
    
    return ret;
}
#endif