#include "storageitems.h"

int pickup_requests[NO_OF_FLOORS+1];
int dropoff_requests[NO_OF_FLOORS+1];

void initialise()
{
	for(int i = 0; i < NO_OF_FLOORS+1; ++i) {
		pickup_requests[i] = 0;
		dropoff_requests[i] = 0;
	}
}

void register_pickupreq(int floor)
{
	pickup_requests[floor] = 1;
}

void register_dropoffreq(int floor)
{
	dropoff_requests[floor] = 1;
}

int is_reqpending(int floor)
{
	return (pickup_requests[floor] == 1 || dropoff_requests[floor] == 1);
}

void clear_floorreqs(int floor)
{
	pickup_requests[floor] = dropoff_requests[floor] = 0;
}
















