/* 
 * File:   hal_gpio.h
 * Author: BOULBALAH Lahcen
 *
 * Created on September 25, 2023, 9:15 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*section : Include */
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../GPIO/../device_config.h"

/*section : MACROS */

#define BIT_MASK                    (uint8)1


/*section : DATA Type Declaration */

typedef enum
{
    PORTA_index,
    PORTB_index,
    PORTC_index,
    PORTE_index
}port_index_t;

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum
{
    OUTPUT,
    INPUT

}direction_t;

typedef enum
{
    LOW,
    HIGH

}logic_t;

typedef struct
{
    uint8 port:3;
    uint8 pin:3;
    uint8 direction:1;
    uint8 logic:1;
}pin_config_t;


/*section : Function Declaration */
Std_ReturnType gpio_pin_direction_init(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config ,direction_t *direction_status );
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config , logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config , logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config );


/*section : Function MACROS */
#define HWREG8(_x)                  (*((volatile uint8 *)(_x)))

#define SET_BIT(REG,BIT_POS)        (REG |=(BIT_MASK<<BIT_POS))
#define CLEAR_BIT(REG,BIT_POS)      (REG &=~(BIT_MASK<<BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS)     (REG ^=(BIT_MASK<<BIT_POS))
#define READ_BIT(REG,BIT_POS)       ((REG >> BIT_POS) & BIT_MASK)


#endif	/* HAL_GPIO_H */

