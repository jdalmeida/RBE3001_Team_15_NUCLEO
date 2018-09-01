/*
 * CalibrationServer.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: kl
 */

#include "CalibrationServer.h"

//tells the server where the home position is in memory
void CalibrationServer::initHomePosition(float * homePosition, int length){
	this->homePosition=homePosition;
	this->homePosLength=length;
}
void CalibrationServer::event(float * packet) {
	//pulls the calibration offset then adds it into the
	//home position array initialized above
	for (int i = 0; i < homePosLength; i++) {
		homePosition[i] += packet[i];
	}
	// we will be using the same memory area in which the incoming packet was stored,
	// however, a we need to perform a type cast first (for convenience).
	uint8_t * buff = (uint8_t *) packet;

	// re-initialize the packet to all zeros
	for (int i = 4; i < 64; i++)
		buff[i] = 0;

}

