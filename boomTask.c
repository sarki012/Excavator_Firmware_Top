/*
 * File:   boom_task.c
 * Author: Erik
 *
 * Created on April 29, 2022, 4:43 PM
 */
#include <xc.h>
#include <p33ep512mc502.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
//#include "main.h"
volatile extern char rxval[20];
volatile extern int i;
int charToInt(char digit2, char digit1, char digit0);
void boomTask( void *pvParameters )
{
    int curl = 0, curl_prev = 0, delta = 0, i = 0, j = 0;
    while(1)
    {
        i++;
    
        /*
        for(i = 0; i < 15; i++)
        {
            if(rxval[i] == 'c')
            {
                curl = charToInt(rxval[i+1], rxval[i+2], rxval[i+3]);
                //Motor Arithmitic Here
                //PHASE3 and PDC3 are for PWM3L, the bucket curl motor
                //PHASE is always 2303 to give a rising edge every 20ms
                //Max Duty Cycle is PDC = 253
                //Neutral Duty Cycle is 173
                //Min Duty Cycle is PDC = 92
                curl_prev = curl;
                delta = curl - curl_prev;
               
                // Spin motor from curl_prev to curl
                
                PHASE3 = 2303;
                for(i = curl_prev; i < curl; i++)
                {
                    
                    // PDC3 = 173 + (delta
                     
                    PDC3 = (int)(173 + (80/delta)*curl_prev);
                    for(j = 0; j < 1000; j++);          //Delay
                }
            }

        }
         * */
    }
}

