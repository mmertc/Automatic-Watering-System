#define MotorA 7
#define MotorB 8

const short periodA = 2360; /* Period of watering+wait groups (in SECONDS) */
const short periodB = 5790;

const short timeBetweenChecks = 10; /* How much time should arduino wait until it checks again if it is time to water (in SECONDS)[This also sets one watering duration] */


short lastTillA = periodA; /* A is the one with 2 plants and B is with 4. These variables count how many seconds have passed since the beginning of last watering */
short lastTillB = periodB;



void setup() 
{
  
  pinMode(MotorA, OUTPUT); /* 7 is A, 8 is B*/
  pinMode(MotorB, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(MotorA, HIGH); /* Relay used in the system is LOW trigger, so pins idle as HIGH*/
  digitalWrite(MotorB, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
  
  if (lastTillA >= periodA && lastTillB >= periodB)
    {
      lastTillA = 0;
      lastTillB = -timeBetweenChecks; /* -timeBetweenChecks so that it will get watered next iteration */
    }
  else if (lastTillA >= periodA)
    {
      lastTillA = 0;
    }
      else if (lastTillB >= periodB)
        {
          lastTillB = 0;
        }

  if (lastTillA == timeBetweenChecks)
  {
    stopWater(MotorA);
  }
  else if (lastTillB == timeBetweenChecks)
  {
    stopWater(MotorB);
  }

  if (!lastTillA)
  {
    startWater(MotorA); 
  }
  else if (!lastTillB)
  {
    startWater(MotorB); 
  }
  

        
  lastTillA += timeBetweenChecks;
  lastTillB += timeBetweenChecks;
  
  delay(timeBetweenChecks*1000);

}

void startWater(short motorNo) 
{
  digitalWrite(motorNo, LOW);
}

void stopWater(short motorNo) 
{
  digitalWrite(motorNo, HIGH);
}
