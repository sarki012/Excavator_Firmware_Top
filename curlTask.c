#include <xc.h>
#include <p33ep512mc502.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
//#include "main.h"

volatile extern char rxval[20];
volatile extern int j;
int charToInt(char digit2, char digit1, char digit0);
void curlTask( void *pvParameters )
{
    int  i = 0, j = 0;
    int boom = 0, boom_prev = 0, boom_delta;
    int curl = 0;
    while(1)
    {
        j++;
        /*
        for(i = 0; i < 15; i++)
        {
            if(rxval[i] == 'b')
            {
                boom = charToInt(rxval[i+1], rxval[i+2], rxval[i+3]);
                boom_prev = boom;
                boom_delta = boom - boom_prev;
                
                // Spin motor from curl_prev to curl
                
                 
                PHASE3 = 2303;
                for(i = boom_prev; i < boom; i++)
                {
                    //Motor Arithemetic Here
                    //PHASE3 and PDC3 are for PWM3L, the bucket curl motor
                    //PHASE is always 2303 to give a rising edge every 20ms
                    //Max Duty Cycle is PDC = 253
                    //Neutral Duty Cycle is 173
                    //Min Duty Cycle is PDC = 92
                    PDC1 = (int)(173 + (80/boom_delta)*boom_prev);
                    for(j = 0; j < 1000; j++);          //Delay
                }
            }
        }
        */
    } 
}