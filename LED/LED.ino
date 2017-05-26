

int codes[] = {0, 1, 10, 11, 100, 101, 110, 111};
int count = 0;

int bit0 = 9;
int bit1 = 10;
int bit2 = 11;

void setup()
{
    pinMode(bit0, OUTPUT);
    pinMode(bit1, OUTPUT);
    pinMode(bit2, OUTPUT);
    pinMode(12, OUTPUT);
    
    Serial.begin(9600);
    /*
    digitalWrite(bit0, HIGH);
    digitalWrite(bit1, HIGH);
    digitalWrite(bit2, HIGH);

    digitalWrite(bit0, HIGH);
    digitalWrite(bit1, LOW);
    digitalWrite(bit2, LOW);

    digitalWrite(bit0, LOW);
    digitalWrite(bit1, HIGH);
    digitalWrite(bit2, LOW);

    digitalWrite(bit0, HIGH);
    digitalWrite(bit1, HIGH);
    digitalWrite(bit2, LOW);
    */
}

void loop()
{
  digitalWrite(12, LOW);
  /*
  digitalWrite(bit0, LOW);
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  delay(1000);
  digitalWrite(bit0, HIGH);
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  delay(1000);
  digitalWrite(bit0, LOW);
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  delay(1000);
  digitalWrite(bit0, HIGH);
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  delay(1000);
  */
  

  int bin = codes[count];
  int i, j;
  bool x[] = {LOW, LOW, LOW};
  j = 0;
  /*
  for(i = 0; i < 8; ++i)
  {
  Serial.print(codes[i]);
  Serial.print("\n");
  }
  */

  for(i = 0; i < 3; ++i)
  {
    j = bin % 10;
    /*
    Serial.print("\n");
    Serial.print(j);
  Serial.print("\n");
  Serial.print("\n");
  */
   if(j == 1)
    {
      x[i] = HIGH;
    }
    bin = bin / 10;
  }

  for(i = 0; i < 3; ++i)
  {
    digitalWrite(i + 2, x[i]);
    /*
    Serial.print("writing ");
    Serial.print(x[i]);// (i + 2));
    Serial.print(" to ");
    Serial.print(i + 2);
    Serial.print("\n");
    */
  }
  //Serial.print("\n");
  
  ++count;
  if(count == 8)
  {
    count = 0;
  }
  delay(500);
  
}











