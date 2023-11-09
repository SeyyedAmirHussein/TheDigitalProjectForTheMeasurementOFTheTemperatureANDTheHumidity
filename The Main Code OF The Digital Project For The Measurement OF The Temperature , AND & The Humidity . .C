// The Digital Project For The Measurement OF The Temperature , AND & The Humidity .

// The Main Code OF The Digital Project For The Measurement OF The Temperature , AND & The Humidity . .C

// In this program, We want to Measure the Temperature and Humidity and then Display them on the LCD Screen. If the Temperature Warms up and exceeds " Twenty-Eight (28) degrees Celsius (28 ° C) " , print the phrase " Warm " and then turn on the RED LED Light. But if the Temperature Cools and Drops Below " Twenty-Seven (27) degrees Celsius (27 ° C) " , print the phrase " Cool " and then turn on the Green LED Light .




#include <LiquidCrystal.h>                                                                                                    // Library Required for this Project .
#include <DHT.h>                                                                                                             // Library Required for this Project .
#define DHTPIN 8                                                                                                            // Library Required for this Project .
#define DHTTYPE DHT11                                                                                                      // Library Required for this Project .
DHT dht (DHTPIN, DHTTYPE);                                                                                                // Required for this Project .
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;                                                              // Definition of Different Bases .
int RED = 1, Green = 0;                                                                                                 // Basic Definition : Numbers 1 , and 0 . :
LiquidCrystal LCD (rs, en, d4, d5, d6, d7);                                                                            // Definition of Different Bases.


Void setup () {


  dht.begin ();                                                                                                  //
  pinMode (RED, OUTPUT);                                                                                        // Introducing the OUTPUT pin .
  pinMode (Green, OUTPUT);                                                                                     // Introducing the OUTPUT pin .
  Serial.begin (9600);                                                                                        // Introducing the Series .
  LCD.begin (16, 2);                                                                                         // Introducing LCD Resolution .


}


void loop () {


  float Humid = dht.ReadHumidity ();                                                                  // Read Data . :
  float Temp = dht.ReadTemperature ();                                                               // Read Data . :
  delay (2000);                                                                                     // Running the Delay Function (2 Seconds) . :
  Serial.print (" Temp : ");                                                                       // Show the Desired Message .
  Serial.println (Temp);                                                                          // Show the Desired Message .
  Serial.print (" Humid : ");                                                                    // Show the Desired Message .
  Serial.println (Humid);                                                                       // Show the Desired Message .
  LCD.setCursor (0, 0);                                                                        // To run Regularly and Display the OUTPUT Below .
  LCD.print (" Temp : ");                                                                     // Show the Desired Message .
  LCD.print (Temp);                                                                          // Show the Desired Message .
  LCD.setCursor (0, 1);                                                                     // To run Regularly and Display the OUTPUT Below .
  LCD.print (" Humid : ");                                                                 // Show the Desired Message .
  LCD.print (Humid);                                                                      // Show the Desired Message .


  if (Temp > 28) {                                                                    // If the Temperature Value exceeds " Twenty-Eight (28) degrees Celsius (28 ° C) " do the Following :


    LCD.setCursor (0, 1);                                                           // To run Regularly and Display the OUTPUT Below .
    LCD.print (" + + + + Warm + + + + ");                                          // Show the Desired Message .
    digitalWrite (RED, HIGH);                                                     // Turn on the RED LED .
    digitalWrite (Green, LOW);                                                   // Turn off the Green LED .


    }


if (Temp < 27) {                                                           // If the Temperature value drops below " Twenty-Seven (27) degrees Celsius (27 ° C) " do the following :


  LCD.setCursor (0, 1);                                                  // To run Regularly and Display the OUTPUT Below .
    LCD.print (" * * * * Cool * * * * ");                               // Show the Desired Message .
    digitalWrite (Green, HIGH);                                        // Turn on the Green LED .
    digitalWrite (RED, LOW);                                          // Turn off the RED LED .


  }


}
