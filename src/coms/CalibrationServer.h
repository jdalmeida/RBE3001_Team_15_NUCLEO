/*
 * CalibrationServer.h
 *
 *  Created on: Sep 1, 2018
 *      Author: kl
 */

#ifndef SRC_COMS_CALIBRATIONSERVER_H_
#define SRC_COMS_CALIBRATIONSERVER_H_

#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>

#define CALIBRATION_SERVER_ID 35      // identifier for this server

class CalibrationServer: public PacketEventAbstract  {

private:
  PIDimp ** myPidObjects;    // array of PidServers - one for each joint
  int myPumberOfPidChannels;
  float * homePosition;
  int homePosLength;

public:
  CalibrationServer (PIDimp ** pidObjects, int numberOfPidChannels)
  		: PacketEventAbstract(CALIBRATION_SERVER_ID) {
  	myPidObjects = pidObjects;
  	myPumberOfPidChannels = numberOfPidChannels;
  	homePosition=0;
  	homePosLength=0;
  	}
  	void event(float * buffer);
  	void initHomePosition(float * homePosition, int length);
};

#endif /* SRC_COMS_CALIBRATIONSERVER_H_ */
