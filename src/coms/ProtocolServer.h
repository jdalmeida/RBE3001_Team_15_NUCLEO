/*
 * ProtocolServer.h
 *
 *  Created on: Sep 1, 2018
 *      Author: jfdalmeida
 */

#ifndef SRC_COMS_PROTOCOLSERVER_H_
#define SRC_COMS_PROTOCOLSERVER_H_

#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>

#define PID_SERVER_ID 36      // identifier for this server


class ProtocolServer: public PacketEventAbstract {

private:
  PIDimp ** myPidObjects;    // array of PidServers - one for each joint
  int myPumberOfPidChannels;

public:
	ProtocolServer (PIDimp ** pidObjects, int numberOfPidChannels)
		: PacketEventAbstract(PID_SERVER_ID) {
	myPidObjects = pidObjects;
	myPumberOfPidChannels = numberOfPidChannels;
	}

	// This method is called every time a packet from MATLAB is received
	// via HID
	void event(float * buffer);

	virtual ~ProtocolServer();
};

#endif /* SRC_COMS_PROTOCOLSERVER_H_ */
