/*
 * ProtocolServer.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: jfdalmeida
 */

#include "ProtocolServer.h"

void ProtocolServer::event(float * packet){
  // we will be using the same memory area in which the incoming packet was stored,
  // however, a we need to perform a type cast first (for convenience).
  uint8_t * buff = (uint8_t *) packet;

  // re-initialize the packet to all zeros
  for(int i = 4; i < 64;i++)
	  buff[i]=0;

  /**
   * The following loop reads sensor data (encoders ticks, joint velocities and
   * force readings) and writes it in the response packet.
   */
  for(int i = 0; i < myPumberOfPidChannels; i++)
	{
	  float position = myPidObjects[i]->GetPIDPosition();

	  packet[(i*3)+0] = position;
	  packet[(i*3)+1] = 0.2F + i;
	  packet[(i*3)+2] = 0.3F + i;
	}
}


ProtocolServer::~ProtocolServer() {
	// TODO Auto-generated destructor stub
}

