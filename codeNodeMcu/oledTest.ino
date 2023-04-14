
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int rState=0;
String state="000";
String pinStatus= state;
void setup() 
  {

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(1000);  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
}

void loop() {
if(rState)
    {
      displayStatus("      RECEIVED",relayState(pinStatus));//777,//888
    }
    else
    {
    
      displayStatus("   NOT RECEIVED","PRESS STATUS.....");
    }


}    
    
void displayStatus(String text1, String text2)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(8,4);
  display.print(text1);
  
  display.drawRect(0, 0, 128, 64, WHITE);
  display.drawLine(0,15, display.width()-1,15, WHITE);
  display.setCursor(0,45);
  display.print(" PUMP  E-FENCE  LIGHT");
  display.setCursor(12,25);
  display.print(text2);
 
  
  display.display();//updates the display with the changes made using the previous commands
}

String relayState(String state)
{
  String feedString = "";
  if (state.substring(0,1) == "1"){ feedString = "ON     ";}
  else { feedString = "OFF    ";}
  if (state.substring(1,2) == "1"){ feedString = feedString + "ON     ";}
  else { feedString = feedString + "OFF    ";}
  if (state.substring(2,3) == "1"){ feedString = feedString + "ON     ";}
  else { feedString = feedString + "OFF    ";}
  return feedString;
}



