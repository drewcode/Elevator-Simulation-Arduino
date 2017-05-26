#include <Key.h>
#include <Keypad.h>
//#include "storageitems.h"

int CURRENT_FLOOR = 0;
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8}; 
int bit0 = 9;
int bit1 = 10;
int bit2 = 11;


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int codes[] = {0, 1, 10, 11, 100, 101, 110, 111};


void setup() 
{     
      pinMode(bit0, OUTPUT);
      pinMode(bit1, OUTPUT);
      pinMode(bit2, OUTPUT);

      Serial.begin(9600);
      
      //Make LEDs at all floors HIGH and LED at ground floor LOW
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      
}

void blink_leds(char destination)
{

      int dest_bin_code = codes[destination];       //binary code of destination
      //int cur_flr_bin_code = codes[CURRENT_FLOOR];  //binary code of current floor

      int i, j, i_bin_code, digit;

      if(destination > CURRENT_FLOOR){
          for(i = CURRENT_FLOOR; i < destination; ++i)
          {
                i_bin_code = codes[i];                      //binary code of floor 'i'
                bool input_combination[] = {LOW, LOW, LOW};     //combination of inputs to decoder
    
    
                //loop to check the binary code of floor 'i' and obtain the correct input sequence
                for(j = 0; j < 3; ++j)                          
                {                                               
                      digit = i_bin_code % 10;
                      if(digit == 1)
                      {
                            input_combination[j] = HIGH;
                            //digitalWrite(j + 9, HIGH);
                      }
                      i_bin_code = i_bin_code / 10;
                }
    
                //loop to write the input sequence onto arduino pins
                for(j = 0; j < 3; ++j)
                {
                      digitalWrite(j + 9, HIGH);
                }
          }
      }
      
      CURRENT_FLOOR = destination;
}

void loop()
{
  //initialise();
  
  char key = keypad.getKey();
  //int key_pressed = (int)key;
  //int final_destination = key_pressed;

  if(key != NO_KEY) {
    Serial.println("  $  " + key);
    blink_leds(key);
  }

}

