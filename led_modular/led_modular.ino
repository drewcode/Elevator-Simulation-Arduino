int CURRENT_FLOOR = 0;

int codes[] = {0, 1, 10, 11, 100, 101, 110, 111};

int bit0 = 9;
int bit1 = 10;
int bit2 = 11;

void setup() 
{     
      pinMode(bit0, OUTPUT);
      pinMode(bit1, OUTPUT);
      pinMode(bit2, OUTPUT);

      //Make LEDs at all floors HIGH and LED at ground floor LOW
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      
      blink_leds(5);
}

void blink_leds(int destination)
{
      int dest_bin_code = codes[destination];       //binary code of destination
      //int cur_flr_bin_code = codes[CURRENT_FLOOR];  //binary code of current floor

      int i, j, i_bin_code, digit;

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
      
      
      CURRENT_FLOOR = destination;
}

void loop() 
{
      

}










