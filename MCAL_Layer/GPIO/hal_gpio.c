/*
 * File:   hal_gpio.c
 * Author: BOULBALAH Lahcen
 *
 * Created on September 25, 2023, 9:15 PM
 */

/*section : Includes */
#include "hal_gpio.h"

/*Section : Global Declaration*/
volatile uint8 *tris_reg[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *port_reg[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 *lat_reg[] = {&LATA, &LATB, &LATC, &LATD, &LATE};

/*sections : definition of functions */

Std_ReturnType gpio_pin_direction_init(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PIN_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_pin_config->direction)
        {
        case OUTPUT:
            CLEAR_BIT(*tris_reg[_pin_config->port], _pin_config->pin);
            break;
        case INPUT:
            SET_BIT(*tris_reg[_pin_config->port], _pin_config->pin);
            break;
        default:
            ret = E_NOT_OK;
        }
    }
    return ret;
}
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status)
{
}
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PIN_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (logic)
        {
        case HIGH:
            SET_BIT(*lat_reg[_pin_config->port], _pin_config->pin);
            break;
        case LOW:
            CLEAR_BIT(*lat_reg[_pin_config->port], _pin_config->pin);
            break;

        default:
            ret = E_NOT_OK;
        }
    }
    return ret;
}
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic)
{
}
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
}

Std_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction)
{
}
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status)
{
}
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic)
{
}
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic)
{
}
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
}
