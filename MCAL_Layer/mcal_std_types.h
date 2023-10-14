/* 
 * File:   mcal_std_types.h
 * Author: BOULBALAH Lahcen
 *
 * Created on September 30, 2023, 2:28 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*section : include */
#include "std_libraries.h"
#include "compiler.h"

/*section : DATA Type Declaration */

typedef unsigned char uint8;

typedef uint8 Std_ReturnType;

/*section : MACROS */

#define STD_HIGH      0x01
#define STD_LOW       0x00

#define STD_ON        0x01
#define STD_OFF       0x00

#define STD_ACTIVE    0x01
#define STD_IDLE      0x00

#define E_OK          (Std_ReturnType)0x01
#define E_NOT_OK      (Std_ReturnType)0x00

/*section : Function Declaration */


/*section : Function MACROS */


#endif	/* MCAL_STD_TYPES_H */

