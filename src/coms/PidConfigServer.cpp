/**
 * RBE3001 - Nucleo Firmware
 * See header file for more detail on this class.
 */
#include "PidConfigServer.h"

/**
 *  @brief This function handles incoming HID packets from MATLAB.
 *
 *  @description This method expects a packet containing three single-precision 
 *               floating point numbers, which are parsed and used as new gains 
 *               for the PID controller.
 */  
void PidConfigServer::event(float * packet)
{
  
  for(int i = 0; i < myPumberOfPidChannels; i++)
    {
      // read values from the packet packet
      float kpn = packet[(i*3)+0];
      float kin = packet[(i*3)+1];
      float kdn = packet[(i*3)+2];
      
      // Set the PID constants
      myPidObjects[i]->setPIDConstants(kpn, kin, kdn);
    }
  uint8_t * buff = (uint8_t *) packet;

  // re-initialize the packet to all zeros
  for(int i = 0; i < 60;i++)
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
