void setup()

{ //serial monitor and pin setup. 
  Serial.begin(9600);
  pinMode(6,OUTPUT); //set trigpin as output
  pinMode(5,INPUT);//set echopin as input
  pinMode(7,OUTPUT);// set R,G and B as outputs
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
   
   
  // put your setup code here, to run once:

}

void loop() 

{
  
  //the trigpin sends out a signal, which bounces off an obstacle and comes back, the 
  //echopin recieves this signal and gives out +5v setting the arduino pin on which it is connected to high.
  //distance= time*speed, but this distnce is divided by 2 because signal sent out returns
  //so distance= (the time it takes for the signal to leave and return)/2.
  //i.e if the time is 6s the distance = (6s/2) = 3m or cm.
  
  int duration, distance;//declare distance and duration as integers
  digitalWrite(6,HIGH);// trigin send out signal
  _delay_ms(1000);//coninously for 1000ms
  digitalWrite(6, LOW);// then goes low
  
  duration=pulseIn(5,HIGH); // duration is the pulseIn to the echopin
  distance=(duration/2)/29.1; //  the 29.1 is used to convert the distnce to cm, the value varies for other units.
  
  if(distance > 0 && distance <= 20){//distcance is greater than 0 and less than 20cm
    digitalWrite(8,LOW);//green led is off
    digitalWrite(9,LOW);//blue led is off
    digitalWrite(7,HIGH);//red led is on
  }
  else if(distance > 20 && distance <= 50){//distance is greater than 20 and less than 80cm
        digitalWrite(7,LOW);//red led is off
        digitalWrite(9,LOW);//green led is off
        digitalWrite(8,HIGH);//blue led is on
        analogWrite(7, 255);
        analogWrite(8,0);
        analogWrite(9,255);
    
      }
      
  else if(distance > 50 && distance <= 120 ){//distcance is greater than 80 and less than 120cm
        digitalWrite(7,LOW);//red led is off
        digitalWrite(8,LOW);//blue led is off
        digitalWrite(9,HIGH);//green led is on
      }
  Serial.print("cm");
  Serial.println(distance);//print values on serial monitor
  _delay_ms(100);
}
  
  
  // put your main code here, to run repeatedly:
