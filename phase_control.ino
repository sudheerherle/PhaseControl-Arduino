 /* AC POWER CONTROL WITH PWM AND ZERO CROSS DETECTION */
 
 #include <ACPWM.h>
 #define ZERO_PIN 2 //Input pin from zero cross detector
 #define PWM_PIN 9 //Output pin to TRIAC / SSR
 int SET_PIN = A0; //Analog pin for setting the dutyCycle value with a pontentiometer
 int i=0;
 bool incr;
 
 void setup()
 {
    incr = true;
    pinMode(ZERO_PIN, INPUT);
    pinMode(PWM_PIN, OUTPUT);
    //Initialize PWM operation.
    //Mains frequency: 50Hz.
    //Zero crossing point reached whenever pulse to PIN2 changes
    //Duty cycle = 0..255. 0:always off. 255: always on. 150: 59% on.
    ACpwm.initialize(50,ZERO_PIN,RISING,PWM_PIN,130);
    //Latching on HIGH zero state: 3 microseconds.
    //Latching on LOW zero cross state: 5 microseconds.
    ACpwm.setLatch(0,0);
 }
 
 void loop() {
    //Adjust the power with the potentiometer
    //Set the duty cycle equal to the value of the potentiometer.
    ACpwm.setDutyCycle(i);
    
    delay(100);
    if(i==255){
//      i= 0;
      incr = false;
    }
    if(i==0){
      incr = true;
    }
    if(incr){
      i = i + 1;
    }
    else i = i - 1;
//    ACpwm.setDutyCycle(analogRead(SET_PIN));
 }
