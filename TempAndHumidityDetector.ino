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
