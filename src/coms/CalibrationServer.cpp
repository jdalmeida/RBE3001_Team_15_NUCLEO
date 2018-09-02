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
	uint8_t * buff = (uint8_t *) packet;
	//if the packet being recieved is all zeros, return encoder positions
	int justStatus = 1;
	//check for all 0s and update status
	for (int i = 0; i < 16; i++) {
		if (packet[i] != 0) {
			justStatus = 0;
		}
	}
	printf("just status is %d\r\n\r\n", justStatus);
	if (justStatus) {
		for (int i = 0; i < myPumberOfPidChannels; i++) {
			float position = myPidObjects[i]->GetPIDPosition();
			packet[(i * 3) + 0] = position;
			packet[(i * 3) + 1] = 0.2F + i;
			packet[(i * 3) + 2] = 0.3F + i;
			//this makes sure calibrate can't run more than once
			hasCalibrated=0;
			//printf("%f\r\n\r\n", position);
		}
	//otherwise take the packet and update home position
	//then reset the packet
	} else if(!hasCalibrated) {
		//printf("just status is 0\r\n\r\n");
		for (int i = 0; i < homePosLength; i++) {
			//homePosition[i] += packet[i];
			printf("TEST ASDFGHJKL ", i, packet);
			myPidObjects[i]->pidReset(myPidObjects[i]->GetPIDPosition() - packet[i]);
		}
		//printf("\r\n\r\n");

		for (int i = 4; i < 64; i++)
			buff[i] = 0;
		hasCalibrated=1;
	}

}

