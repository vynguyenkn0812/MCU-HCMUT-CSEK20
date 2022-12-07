/*
 * scheduler.h
 *
 *  Created on: Dec 4, 2022
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "global.h"

typedef struct {
	 // Pointer to the task (must be a 'void (void)' function)
	void (*pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

#define SCH_MAX_TASKS 			40
#define	NO_TASK_ID				0

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void);

void SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(uint32_t TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
