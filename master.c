#include "storageitems.h"

//#define TOP_FLOOR NO_OF_FLOORS
//#define GROUND_FLOOR 0

//CHECK WORKING !!!!!!!!!!!!!!!!!!!!!!!!!!
//TALK ABOUT WHICH WAY LIGHT LED FN WORKS

int main()
{
	initialise();

	char key = keypad.get_key();
	int key_pressed = key - '0';
	//int final_destination = key_pressed;

	if(key_pressed != NO_KEY) {
		/*
		register_dropoffreq(key_pressed);
		while(CURRENT_FLOOR != final_destination) {
			key_pressed = get_key();
			if( (key_pressed > CURRENT_FLOOR && key_pressed < final_destination) || 
				(key_pressed < CURRENT_FLOOR && key_pressed > final_destination)  ) && 
				 dropoff_requests[key_pressed] == 0) {
					register_dropoffreq(key_pressed);
			}
		*/
			
			//CURRENT_FLOOR < final_destination ? CURRENT_FLOOR++ : CURRENT_FLOOR--;
			/*
			if(is_reqpending(CURRENT_FLOOR)) {
				light_led(CURRENT_FLOOR);
				delay(2000);
				clear_floorreqs(CURRENT_FLOOR);
			}
		
			else {
				light_led(CURRENT_FLOOR);
				delay(500);
			}
			*/

			blink_leds(key_pressed);
			CURRENT_FLOOR = key_pressed;

		}


	}

	return 0;
}

/*

void make_trip(int start_floor, int end_floor)
{
	int current_floor = start_floor;
	while(current_floor != end_floor) {
		printf("\nCurrently at floor %d.   ", current_floor);
		for (int i = 0; i < 5; ++i) {
			//delay(1000);
			//read and check from shared memory. update necessary array depending on pu or do req.

					
		}

		if(is_reqpending(current_floor)) {
			printf("!!! Stopping here !!!");
			clear_floorreqs(current_floor);
		} else {
			printf("Not stopping here");
		}

		start_floor < end_floor ? current_floor++ : current_floor--;
	}
}

*/


