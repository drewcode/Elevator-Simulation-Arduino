#include <stdio.h>
#include <stdlib.h>

#define NO_OF_FLOORS 7

//int pickup_requests[];
//int dropoff_requests[];

void initialise();
void register_pickupreq(int floor);
void register_dropoffreq(int floor);
int is_reqpending(int floor);
void clear_floorreqs(int floor);
