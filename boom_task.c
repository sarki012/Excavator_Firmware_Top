/*
 * File:   boom_task.c
 * Author: Erik
 *
 * Created on April 29, 2022, 4:43 PM
 */
#include <xc.h>
#include <p33ep512mc502.h>
int i = 0;
extern char rxval[20];
void boom_task( void *pvParameters )
{
    int count = 0, curl_prev = 0, delta = 0, i = 0, j = 0;
    int boom = 0, boom_prev = 0, boom_delta;
    int curl = 0;
    while(1)
    {
        for(i = 0; i < 15; i++)
        {
            if(rxval[i] == 'c')
            {
                curl = char_to_int(rxval[i+1], rxval[i+2], rxval[i+3]);
                //Motor Arithmitic Here
                //PHASE3 and PDC3 are for PWM3L, the bucket curl motor
                //PHASE is always 2303 to give a rising edge every 20ms
                //Max Duty Cycle is PDC = 253
                //Neutral Duty Cycle is 173
                //Min Duty Cycle is PDC = 92
                curl_prev = curl;
                delta = curl - curl_prev;
                /*
                 Spin motor from curl_prev to curl
                
                 */
                PHASE3 = 2303;
                for(i = curl_prev; i < curl; i++)
                {
                    /*
                     PDC3 = 173 + (delta
                     */
                    PDC3 = (int)(173 + (80/delta)*curl_prev);
                    for(j = 0; j < 1000; j++);          //Delay
                }
                count++;
                if(count == 2)
                {
                    count = 0;
                    break;
                }
         //       for(j = 0; j < 10000; j++);
               // for(j = 0; j < 5000; j++);
            }
            else if(rxval[i] == 'b')
            {
                boom = char_to_int(rxval[i+1], rxval[i+2], rxval[i+3]);
                boom_prev = boom;
                boom_delta = boom - boom_prev;
                /*
                 Spin motor from curl_prev to curl
                
                 */
                PHASE3 = 2303;
                for(i = boom_prev; i < boom; i++)
                {
                    //Motor Arithemetic Here
                    //PHASE3 and PDC3 are for PWM3L, the bucket curl motor
                    //PHASE is always 2303 to give a rising edge every 20ms
                    //Max Duty Cycle is PDC = 253
                    //Neutral Duty Cycle is 173
                    //Min Duty Cycle is PDC = 92
                    PDC3 = (int)(173 + (80/boom_delta)*boom_prev);
                    for(j = 0; j < 1000; j++);          //Delay
                }

                PHASE1 = 2303;
                PDC1 = (int)(172.5 + boom);
                count++;
                if(count == 2)
                {
                    count = 0;
                    break;
                }
            }
        }
    }
}

