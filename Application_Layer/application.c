/* 
 * File:   application.c
 * Author: Mahmoud M.Bayoumi
 *
 * Created on September 21, 2023, 1:44 AM
 */
#include "application.h"
int main() {
 Std_ReturnType ret = E_NOK;
application_intialize();
 


while(1){

}
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOK;
    ecu_layer_initialize();

} 
