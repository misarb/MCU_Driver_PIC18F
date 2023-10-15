/*
 * File:   application.c
 * Author: BOULBALAH Lahcen
 *
 * Created on September 25, 2023, 8:00 PM
 */

#include "application.h"

pin_config_t led1 = {
    .port = PORTC_index,
    .pin = PIN0,
    .direction = OUTPUT,
    .logic = LOW
    };
pin_config_t led2 = {
    .port = PORTC_index,
    .pin = PIN1,
    .direction = OUTPUT,
    .logic = HIGH
    };
pin_config_t led3 = {
    .port = PORTC_index,
    .pin = PIN2,
    .direction = OUTPUT,
    .logic = HIGH
    };
Std_ReturnType ret = E_NOT_OK;
int main()
{
    
    
    ret = gpio_pin_direction_init(&led1);
    ret = gpio_pin_write_logic(&led1, HIGH);
    ret = gpio_pin_direction_init(&led2);
    ret = gpio_pin_write_logic(&led2, HIGH);
    ret = gpio_pin_direction_init(&led3);
    ret = gpio_pin_write_logic(&led3, HIGH);
    
    
    //ret = gpio_pin_direction_init(&led);
    

    return (EXIT_SUCCESS);
}
