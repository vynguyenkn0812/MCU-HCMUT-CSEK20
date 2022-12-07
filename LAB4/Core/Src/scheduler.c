/*
 * scheduler.c
 *
 *  Created on: Dec 4, 2022
 *      Author: PC
 */


#include "scheduler.h"

uint8_t current_index_task = 0;
unsigned char Error_code_G = 0;

void SCH_Init(void) {
    unsigned char i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_Delete_Task(i);
    }
    // Reset the global error variable
    // - SCH_Delete_Task() will generate an error code,
    // (because the task array is empty)
    Error_code_G = 0;
}

void SCH_Update(void){
    unsigned char Index;
    // NOTE: calculations are in *TICKS* (not milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
        // Check if there is a task at this location
        if (SCH_tasks_G[Index].pTask){
            if (SCH_tasks_G[Index].Delay == 0) {
                // The task is due to run
                // Inc. the 'RunMe' flag
                SCH_tasks_G[Index].RunMe += 1;
                if (SCH_tasks_G[Index].Period) {
                    // Schedule periodic tasks to run again
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            } else {
                // Not yet ready to run: just decrement the delay
                SCH_tasks_G[Index].Delay -= TIME_CYCLE;
            }
        }
    }
}

void SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD)
{
    // Have we reached the end of the list?
    if (current_index_task == SCH_MAX_TASKS)
    {
        // Task list is full
    	return;
    }
    current_index_task++;
    // If we're here, there is a space in the task array
	SCH_tasks_G[current_index_task].pTask = pFunction;
	SCH_tasks_G[current_index_task].Delay = DELAY;
	SCH_tasks_G[current_index_task].Period = PERIOD;
	SCH_tasks_G[current_index_task].RunMe = 0;
	SCH_tasks_G[current_index_task].TaskID = current_index_task; //using to delete task

}

void SCH_Dispatch_Tasks(void)
{
    unsigned char Index;
    // Dispatches (runs) the next task (if one is ready)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++){
        if (SCH_tasks_G[Index].RunMe > 0) {
            (*SCH_tasks_G[Index].pTask)(); // Run the task
            SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe flag
            // Periodic tasks will automatically run again
            // - if this is a 'one shot' task, remove it from the array
            if (SCH_tasks_G[Index].Period == 0)
            {
                SCH_Delete_Task(Index);
            }
        }
    }
}

void SCH_Delete_Task(uint32_t TASK_INDEX){
    if (TASK_INDEX > SCH_MAX_TASKS || TASK_INDEX < NO_TASK_ID) {
    	return;
    }
    if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
        // No task at this location...
        return;
    }
    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;
}
