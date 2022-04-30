/*
 * File:   servo_init.c
 * Author: Erik Sarkinen
 *
 * Created on February 12, 2022, 8:26 AM
 */

#include <xc.h>
#include <stdio.h>
#include <p33ep512mc502.h>
#include <stdlib.h>
#include <string.h>

void init(void)
{
    INTCON2bits.GIE = 0;        //Global interrupt enable bit (disabled)
    return;
}
