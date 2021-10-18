#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <math.h>
float rpm,bearing;
float latitude,longitude,lat1,long1;
int PP=12; // blade pitch of propeller is in inches 
float PS=90; //propeller performance is % efficiency
int GR=2; // gear ratio 2:1 is written as 2
const C=656;//kph , constant is for unit conversion
float R=6378.1;//km , radius of earth
/* Create object named bt of the class SoftwareSerial */
SoftwareSerial GPS_SoftSerial(4, 5);/* (Rx, Tx) */
/* Create an object named gps of the class TinyGPSPlus */
TinyGPSPlus gps;      
float x;
float y;
int relay1 = 0;
int relay2 = 2;
void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
  GPS_SoftSerial.begin(9600); /* Define baud rate for software serial communication */
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);  
  attachInterrupt(digitalPinToInterrupt(interruptPin), encoderPulse, RISING);
  
}
float lat_val, lng_val;

void loop() {
        delay(20000);// delay time for the boat to change its course if it crosses the geofence
        smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val;
        bool loc_valid;
        
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
        if(gpsSerial.available())
        {
          if (!loc_valid)
        {          
          Serial.print("Latitude : ");
          Serial.println("*****");
          Serial.print("Longitude : ");
          Serial.println("*****");
        }
        else
        {
          
          Serial.print("Latitude in Decimal Degrees : ");
          Serial.println(lat_val, 6);

          
          Serial.print("Longitude in Decimal Degrees : ");
          Serial.println(lng_val, 6);

        }
        x=lat_val;
        y=lng_val;
        geofence(x,y);
        }
        else
        {
        lat1=lat_val;
        long1=lng_val;
        // rpm calculation is outsourced using a tinkercad module and with rpm speed of boat is calculated
        V=(rpm*PP*(1-(PS/100)))/(GR*C);//v speed of boat
        // distance is calculated using speed and time
        d=V*t;
        // bearing calculation is outsourced using a tinkercad module 
        lat2 = asin(sin(lat1)*cos(d/R) + cos(lat1)*sin(d/R)*cos(bearing));
        long2 = long1 + atan2(sin(bearing)*sin(d/R)*cos(lat1), cos(d/R)−sin(lat1)*sin(lat2));
        geofence(lat2,long2);  
        }
  
        
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (GPS_SoftSerial.available())  /* Encode data read from GPS while data is available on serial port */
      gps.encode(GPS_SoftSerial.read());
/* Encode basically is used to parse the string received by the GPS and to store it in a buffer so that information can be extracted from it */
  } while (millis() - start < ms);

}
void geofence(x,y)
 { 
         if (y==0.7510*x +73.42){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                         
        }
        else if  (y==0.574*x +74.464)  {     
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                
        }
        else if  (y==0.529*x +74.758 ){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                    
        }
        else if  (y==0.214*x  +77.0731) {
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                     
        } 
        else if  (y==0.4234*x  + 75.4217){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                  
        }
        else if  (y==0.169*x + 77.5029){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                     
        }
        else if  (y==1.033*x + 70.2771){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                   
        }
        else if  (y==1.383*x +67.2953){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                   
        }
        else if   (y==1.8733*x + 63.0682){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                 
        } 
        else if   (y==0.8257*x+ 72.1478){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                   
        }
        else if   (y==0.31367*x + 76.6969){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                            
        }
        else if   (y==0.1333*x + 78.3203){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                    
        }
        else if   (y==x + 70.4333){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                    
        }
        else if   (y==-1.0587*x + 89.286){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                   
        }
        else if   (y==0.0045766*x + 79.333224){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                   
        }
        else if   (y== -12.2130*x + 201.0887574){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);              
        }
        else if   (y==3.511278*x + 44.64210526){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                
        }
        else if   (y==16.5*x - 86.3){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                  
        }
        else if   (y==1.387755*x - 66.0816){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                  
        }
        else if   (y==1.478365*x + 44.08065){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                 
        }
        else if   (y==2.0150375*x + 59.50075){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);              
        }
        else if   (y==2.553977*x + 53.74431818){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                 
        }
        else if   (y==2.0259740*x + 29.40598){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                  
        }
        else if   (y==5.7100591*x + 18.639053){
          digitalWrite(relay1, LOW);   
          delay(1000);                     
          digitalWrite(relay1, LOW);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);                  
        }
        else   {
          digitalWrite(relay1, HIGH);   
          delay(1000);                     
          digitalWrite(relay1, HIGH);   
          digitalWrite(relay2, LOW);   
          delay(1000);                     
          digitalWrite(relay2, LOW);
        } 
  }

  
