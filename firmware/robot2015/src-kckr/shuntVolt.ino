//README
//PROBLEMS:
//THE OUTPUT VOLTAGE IS LIKELY THE VOLTAGE AFTER A KICK HAS HAPPENED, NOT BEFORE


const int shuntPin = 0
//shunt resistor input

const int miso = 5
//MISO

const int kicker = 2
//digital command to kick


void setup() {
  pinMode(kicker,INPUT)
  //digital input pin
  
  int volt = 0
  //read from shunt
  
  int kick = 0
  //number of kicks (0, 1, or 2)
  
  unsigned long time1 = 0
  //time of first kick
  
  unsigned long time2 = 0
  //time of second kick
  
  unsigned long charge = 0
  //charge time
}


void loop() {
  //check if kick
  
  if(digitalRead(kicker) == HIGH)
  {
    kick = kick++
    //num kicks increases by 1
    
    if(kick == 1)
    { 
      time1 = millis()
      //if first kick check time

      volt = analogRead(shuntpin)
      analogWrite(miso,volt)
      //read and write first voltage
    }
    if(kick == 2)
    {
      //if second kick output second voltage and charge time
      
      kick = 0
      volt = analogRead(shuntpin)
      time2 = millis()
      charge = time2 - time1
      map(volt,0,1023,0,255)
      //scale down voltage value so it can be output (~1/4 scale)
      
      map(charge,0,5100,0,255)
      //scale down charge time so it can be output (1/20 scale)
      
      analogWrite(miso,volt)
      analogWrite(miso,charge)
    }
  } 
}
