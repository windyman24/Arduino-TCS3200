#define TCS3200_OE   4
#define TCS3200_OUT  5
#define TCS3200_S0   2
#define TCS3200_S1   3
#define TCS3200_S2   6
#define TCS3200_S3   7

#define RED_MAX 188
#define RED_MIN 170
#define BLUE_MAX 165
#define BLUE_MIN 150
#define GREEN_MAX 124
#define GREEN_MIN 97

enum
{
  CLEAR,
  BLUE,
  GREEN,
  RED,  
};
void SetFreqSCALING(int SCALING)
{
   switch(SCALING)
  {
    case 0://OUTPUT FREQUENCY SCALING Power down
      digitalWrite(TCS3200_S0,LOW);
      digitalWrite(TCS3200_S1,LOW);
      break;
    case 2://OUTPUT FREQUENCY SCALING 2%
      digitalWrite(TCS3200_S0,LOW);
      digitalWrite(TCS3200_S1,HIGH);
      break;
    case 20://OUTPUT FREQUENCY SCALING 20%
      digitalWrite(TCS3200_S0,HIGH);
      digitalWrite(TCS3200_S1,LOW);
      break;
    case 100://OUTPUT FREQUENCY SCALING 100%
      digitalWrite(TCS3200_S0,HIGH);
      digitalWrite(TCS3200_S1,HIGH);
      break;
  }
}
void setDetermine(int Color)
{
  switch(Color)
  {
    case CLEAR:
      digitalWrite(TCS3200_S2,HIGH);
      digitalWrite(TCS3200_S3,LOW);
      break;
    case RED:
      digitalWrite(TCS3200_S2,LOW);
      digitalWrite(TCS3200_S3,LOW);
      break;
    case GREEN:
      digitalWrite(TCS3200_S2,HIGH);
      digitalWrite(TCS3200_S3,HIGH);
      break;
    case BLUE:
      digitalWrite(TCS3200_S2,LOW);
      digitalWrite(TCS3200_S3,HIGH);
      break;
  }
}
bool IsColor(int COLOR)
{
  long freq = pulseIn(TCS3200_OUT,LOW);
  bool flag = false;
//  Serial.println(freq);
  switch(COLOR)
  {
    case RED:
      if(freq>RED_MIN && freq<RED_MAX)flag = true;
      else  flag = false;
      break;
    case BLUE:
      if(freq>BLUE_MIN && freq<BLUE_MAX)flag = true;
      else  flag = false;
      break;
    case GREEN:
      if(freq>GREEN_MIN && freq<GREEN_MAX)flag = true;
      else  flag = false;
      break;  
  }
  return flag;
}
void setup() {
  pinMode(TCS3200_OE,OUTPUT);
  pinMode(TCS3200_OUT,INPUT);
  pinMode(TCS3200_S0,OUTPUT);
  pinMode(TCS3200_S1,OUTPUT);
  pinMode(TCS3200_S2,OUTPUT);
  pinMode(TCS3200_S3,OUTPUT);
  digitalWrite(TCS3200_OE,LOW);
  Serial.begin(9600);
  setDetermine(CLEAR);
  SetFreqSCALING(2);
}

void loop() {
//  long freq = pulseIn(TCS3200_OUT,LOW);
//  Serial.println(freq);
  if(IsColor(RED))Serial.println("isRed");
  else if(IsColor(BLUE))Serial.println("isBlue");
  else if(IsColor(GREEN))Serial.println("isGreen");
  delay(1000);
}
