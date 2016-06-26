#include "../include/GPIO.h"
#include "../include/Motor.h"
#include "../include/Steering.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#define PRU_NUM0 0
#include <prussdrv.h>
#include <pruss_intc_mapping.h>
using namespace exploringBB;
using namespace std;

static const int SECONDS = 1000000; //microseconds
static const int MILLISECONDS = 1000; //microseconds
/*
   static void *pru0DataMemory;
   static unsigned int *pru0DataMemory_int;

   static unsigned int bad_sample_count;
   static unsigned int max_bad_sample_count;
   static unsigned int last_bad_sample;

   static unsigned int valid_count;
   static unsigned int invalid_count;

   static unsigned int last_sample;
   static unsigned int first_sample;
   static const int MAX_DIFFERENCE = 100000;
   static const int MAX_SAMPLE = 1000000;*/
/*
   void *threadFunction(void *value){
   int i = 0;
   bool firstIter = true;
   bool valid = false;
   bad_sample_count = 0;
   max_bad_sample_count = 0;
   valid_count = 0;
   invalid_count = 0;

   m.move(15);
   do {
   int notimes = prussdrv_pru_wait_event (PRU_EVTOUT_1);
   unsigned int raw_distance = *(pru0DataMemory_int+2);
   float distin = ((float)raw_distance / (100 * 148));
   float distcm = ((float)raw_distance / (100 * 58));

   if(raw_distance < MAX_SAMPLE){
   if(firstIter){
   first_sample = raw_distance;
   last_sample = raw_distance;
   firstIter = false;
   }
   else{

   int difference = raw_distance - last_sample;
   difference = difference < 0? -difference: difference;

//if(difference < MAX_DIFFERENCE){
valid_count++;
valid = true;
last_sample = raw_distance;

if(distin > 10){

m.move(15);
if(bad_sample_count > max_bad_sample_count)
max_bad_sample_count = bad_sample_count;
bad_sample_count = 0;

}
else
{

m.move(0);
bad_sample_count++;
last_bad_sample = raw_distance;
fprintf(stderr, "%d\n", raw_distance);

}
//}
//else{
//invalid_count++;
//valid = false;
//}
}
}
else{
valid = false;
invalid_count++;
}

printf("Distance is %d (%f inches, %f cm) valid: %d   \n",
raw_distance, distin, distcm, valid);
prussdrv_pru_clear_event (PRU_EVTOUT_1, PRU0_ARM_INTERRUPT);
} while (true);
}
*/
int main() 
{
    pthread_t thread;
    tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
    Steering steering;
    Motor m;
    // Allocate and initialize memory
    // prussdrv_init ();
    // prussdrv_open (PRU_EVTOUT_0);
    // prussdrv_open (PRU_EVTOUT_1);

    // Map PRU's INTC
    // prussdrv_pruintc_init(&pruss_intc_initdata);

    // Copy data to PRU memory - different way
    // prussdrv_map_prumem(PRUSS0_PRU0_DATARAM, &pru0DataMemory);
    // pru0DataMemory_int = (unsigned int *) pru0DataMemory;
    // Use the first 4 bytes for the number of samples
    // *pru0DataMemory_int = 500;
    // Use the second 4 bytes for the sample delay in ms
    // *(pru0DataMemory_int+1) = 1000;   // 2 milli seconds between samples

    // Load and execute binary on PRU
    // prussdrv_exec_program (PRU_NUM0, "./ultrasonic.bin");
    //if(pthread_create(&thread, NULL, &threadFunction, NULL)){
    //    printf("Failed to create thread!");
    //}
    //int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
    /*
       printf("PRU program completed, event number %d.\n", n);
       printf("The data that is in memory is:\n");
       printf("- the number of samples used is %d.\n", *pru0DataMemory_int);
       printf("- the time delay used is %d.\n", *(pru0DataMemory_int+1));
       unsigned int raw_distance = *(pru0DataMemory_int+2);
       printf("- the last distance sample is %d.\n", raw_distance);

    // raw_distance is in 10ns samples
    // distance in inches = time (ms) / 148 according to datasheet
    float distin = ((float)raw_distance / (100 * 148));
    float distcm = ((float)raw_distance / (100 * 58));

    printf("-- A distance of %f inches (%f cm).\n", distin, distcm);

    printf("--- First sample : %d\n", first_sample);
    printf("--- Greatest bad sample count: %d\n", max_bad_sample_count);
    printf("--- Last bad sample : %d\n", last_bad_sample);
    printf("--- There were %d valid samples and %d invalid\n", valid_count, invalid_count);
    */
    /* Disable PRU and close memory mappings */
    //    prussdrv_pru_disable(PRU_NUM0);
    //    prussdrv_exit ();
    steering.steer(100);
    m.move(20);
    usleep((3 * SECONDS) + (100 * MILLISECONDS)); 
    m.move(0);

    return 0;

}
