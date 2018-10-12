/*
 * GripperServer.cpp
 *
 *  Created on: Sep 29, 2018
 *      Author: jfdalmeida
 */

#include "GripperServer.h"

void GripperServer::event(float * packet){
	float value = packet[0];

	myGripper->write(value);

	uint8_t * buff = (uint8_t *) packet;

	// re-initialize the packet to all zeros
	for(int i = 4; i < 64;i++)
		buff[i]=0;

	packet[0]=myGripper->read();

}


