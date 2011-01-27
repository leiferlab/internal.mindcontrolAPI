/*
 * mc_api_dll.h
 *
 *  Created on: Jan 27, 2011
 *      Author: andy
 */

#ifndef MC_API_DLL_H_
#define MC_API_DLL_H_

#define MC_API_OK 0
#define MC_API_ERROR -1

#define MC_API_TRUE 1
#define MC_API_FALSE 0


/*
 * Returns MC_API_OK if server is running
 * Returns MC_API_ERROR otherwise
 */
int MC_API_PingServer();

/*
 * To Be Used Only by MindControl
 *
 * Returns MC_API_OK or
 * Returns MC_API_ERROR otherwise
 *
 *
 *
 */
int MC_API_StartServer();


/*
 * To Be Used Only by MindControl
 *
 * Returns MC_API_OK or
 * Returns MC_API_ERROR otherwise
 *
 */
int MC_API_StopServer();

/*
 *
 * Returns MC_API_OK or
 * Returns MC_API_ERROR otherwise
 *
 */

int MC_API_StartClient();

/*
 * Returns MC_API_OK or
 * Returns MC_API_ERROR otherwise
 *
 */
int MC_API_StopClient();

/*
 *  Registers the presence of a laser controller software
 *  that will provide the power level of
 *  the blue or green lasers.
 *
 *
 */
int MC_API_RegisterLaserController();

/*
 * Check to see if laser controller is present
 *  Returns MC_API_OK or
 * Returns MC_API_ERROR otherwise
 *
 */
int MC_API_PingLaserController();


/*
 * Unregisters Laser Controller
 *
 */
int MC_API_UnRegisterLaserController();

/*
 *  Set the Laser Power, an integer value between 1 and 100
 */
int MC_API_SetGreenLaserPower(int power);
int MC_API_SetBlueLaserPower(int power);

/*
 * Get the laser power. An integer value between 1 and 100
 * Returns MC_API_ERROR if the value cannot be acquired.
 */
int MC_API_GetGreenLaserPower();
int MC_API_GetBlueLaserPower();



#endif /* MC_API_DLL_H_ */
