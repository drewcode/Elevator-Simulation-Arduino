#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

int codes[] = {0, 1, 10, 11, 100, 101, 110, 111};
int count = 0;

int bit0 = 9;
int bit1 = 10;
int bit2 = 11;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

bool current[] = { true, false, false , false , false , false , false , false };


byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(bit0, OUTPUT);
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  //pinMode(12, OUTPUT);
}

int i,j, k,floor_no = 0;
bool x[3];
void loop() 
{
  // put your main code here, to run repeatedly:
  char key = keypad.getKey(); 
  // Move lift to appropriate floor

  if (key != NO_KEY) 
  {
    Serial.println(key);
  
  
 
    //ITERATE THROUGH ARRAY TO FIND WHICH FLOOR THE ELEVATOR CURRRENTLY IS AT
  for(i=0;i < 8 ; i++)
    {
  
      if(current[i] == true)
      {
          floor_no = i;
          current[i] = false;
          break;
      }
    }

  if((key - '0') > floor_no)
  {

    for(i = floor_no; i < (key - '0'); ++i)
    {
        Serial.print(key - '0');
        int bin = codes[i];
        for(j = 0; j < 3; ++j)
        {
            x[j] = LOW;
        }
        
        
        for(j = 0; j < 3; ++j)
        {
          Serial.print(bin);
            k = bin % 10;
            if(k == 1)
            {
                x[j] = HIGH;
            }
            bin = bin / 10;
        }
        Serial.print("***");
        for(k = 0; k< 3; ++k)
        {
          digitalWrite(i + 9, x[i]);

        }   
        Serial.print("End of inner loop");
        delay(500);
    }
    Serial.print("End of if");
    Serial.println();
    floor_no = (key - '0');
    current[floor_no] = true;
  }
  

  }
  
}
