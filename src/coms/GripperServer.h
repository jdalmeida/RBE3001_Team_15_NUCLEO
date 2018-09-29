/*
 * GripperServer.h
 *
 *  Created on: Sep 29, 2018
 *      Author: jfdalmeida
 */

#ifndef SRC_COMS_GRIPPERSERVER_H_
#define SRC_COMS_GRIPPERSERVER_H_

#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>

#define GRIPPER_SERVER_ID 34

class GripperServer: public PacketEventAbstract  {
private:
	Servo *myGripper;

public:
	GripperServer(Servo *gripper)
		: PacketEventAbstract(GRIPPER_SERVER_ID)
	{
		myGripper = gripper;
	}

	void event(float * buffer);

};

#endif /* SRC_COMS_GRIPPERSERVER_H_ */
