/*
 * mc_host.c
 *
 *  Created on: Jan 28, 2011
 *      Author: andy
 */

#include <conio.h>
#include <stdio.h>

#include "../mc_api_dll.h"

int main(){
	printf("Starting server.\n");
	SharedMemory_handle sm=MC_API_StartServer();
	int val=MC_API_isLaserControllerPresent(sm);
	printf("Is laser controller present?: %d\n",val);

	printf("Stopping server.. %d\n",MC_API_StopServer(sm));
	printf("Goodbye!");




}
