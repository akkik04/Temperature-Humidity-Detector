  /*
   * A FEW CLARIFICATIONS FOR THIS PROJECT:
   * 
   *  - OPTIMAL ROOM TEMPERATURE RANGE FOR THIS PROJECT IS BETWEEN 18.0°C and 25.0°C.
   */
    
  // importing the required module to operate the LCD.
  #include <LiquidCrystal.h>
  
  // importing the required module to access the DHT's functions.
  #include <DHT.h>
  
  // declaring the LCD pins.
  LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
  
  // declaring the DHT's pins.
  DHT dht(4, DHT11);

// SETUP.
void setup() {

  // declaring the pins for optimal temperature range detection.
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  
  // initializing the DHT.
  dht.begin();
    
  // initializing the LCD.
  lcd.begin(16, 2);

  }

// MAIN LOOP.
void loop() {

  // creating a delay of 1500ms before every measurement.
  delay(1500);

  // reading the humidity and temperature.
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // clearing the LCD.
  lcd.clear();

  // creating an if-statement to handle errors on the LCD.
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Measurement Failed");
    
  } 

  // if no error is found we start the printing process at the first row.
  else {

    // creating a nested if-statement to check if the temperature is below the optimal range.
    if (temperature < 18.0) {

      // flashing the 'blue' LED to indicate that the room temp is too cold.
      digitalWrite(2, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      delay(100);

      // code to print that the temperature is below optimal range on the LCD.
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("   Too cold!");
    }

    // checking if the temperature is above the optimal range.
    else if (temperature > 25.0) {

      // flashing the 'red' LED to indicate that the room temp is too hot.
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);

      // code to print that the temperature is above optimal range on the LCD.
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Too hot!");
    }

    // code to let the user know that they are within the optimal range if conditions are met.
    else {

      lcd.setCursor(0, 0);
      lcd.print(" Optimal Temp");
    }

    // adding a delay for LCD effect.
    delay(1000);

    lcd.setCursor(0, 0);

    // printing the temperature with the '°' character.
    lcd.print("Temp: ");
    lcd.print(temperature);     
    lcd.print((char)223);
    lcd.print("C");

    // printing the humidity in the second row.
    lcd.setCursor(0, 1);  
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");
    
  }
}
