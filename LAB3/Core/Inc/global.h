/*
 * global.h
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int status1; //status of first lights
extern int status2; //status of second lights
extern int status3; //status of manual mode

extern int count_down1;
extern int count_down2;

extern int red_time;
extern int green_time;
extern int yellow_time;

extern int man_red_time;
extern int man_green_time;
extern int man_yellow_time;

#define BLINKY_TIME 500

#define RED_TIME 	5
#define YELLOW_TIME 2
#define GREEN_TIME	3

#define INIT 		0
#define AUTO_RED 	1
#define AUTO_GREEN 	2
#define AUTO_YELLOW 3

#define MAN_RED		12
#define MAN_GREEN	13
#define MAN_YELLOW	14

#endif /* INC_GLOBAL_H_ */
