#define buttonPin 2        // analog input pin to use as a digital input
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 7);

//=================================================
byte sensor_hall();
byte tensao();
  
void setup() {
  lcd.begin(16, 2);

    lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Instrumento de");
  lcd.setCursor(0, 1);
  lcd.print("medicao, aperte");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("1x p/ Gauss, 2x");
  lcd.setCursor(0, 1);
  lcd.print("para Voltimetro");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("e segure 2 seg");
 lcd.setCursor(0, 1);
  lcd.print("para Fasimetro"); 
  Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
   // Set button input pin
pinMode(buttonPin, INPUT_PULLUP);

pinMode(A4, INPUT);
pinMode(A5, INPUT);
}

void loop() {

 int j = analogRead(A0);
 Serial.println(j);
 delay(20);
     // Get button event and act accordingly
   int b = checkButton();
   if (b == 1) clickEvent();
   if (b == 2) doubleClickEvent();
   if (b == 3) holdEvent();
   if (b == 4) longHoldEvent();

}

//=================================================
void clickEvent() {
 int x,gss;
  int aValue = analogRead(A1);

 if (aValue <235){
  gss = mapFloat(aValue, 20, 235, -180, 0);
  }

  else{
  gss = mapFloat(aValue, 235, 448, 0,180);
}

delay(10);

  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Campo em Gauss");
  lcd.setCursor(2, 1);
  lcd.print(gss);  
  delay(10);
}

void doubleClickEvent() {
float tensaoanalog=0;
float val=0;
float soma = 0;
float media=0;
int i =0;

tensaoanalog = analogRead(A0);
Serial.println("O valor lido pela entrada analogica e");
Serial.println(tensaoanalog);

if (tensaoanalog >1 && tensaoanalog <8){
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 3, 7, 0, 11);
  soma = soma+val;
   }
  }

  
if (tensaoanalog>7 && tensaoanalog <12)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 7,12, 10, 22);
  soma = soma+val;
   }
} 

if (tensaoanalog>11 && tensaoanalog <22)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 13,21, 20, 32);
  soma = soma+val;
   }
} 

if (tensaoanalog>21 && tensaoanalog <38)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 22,38, 32, 40);
  soma = soma+val;
   }
} 

if (tensaoanalog>38 && tensaoanalog <52)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 39,51, 40,51);
  soma = soma+val;
   }
}

if (tensaoanalog>53 && tensaoanalog <70)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 54,69, 51,61);
  soma = soma+val;
   }
}

if (tensaoanalog>71 && tensaoanalog <91)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 72,90,61,70);
  soma = soma+val;
   }
}

if (tensaoanalog>90 && tensaoanalog <112)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 91,111,71,81);
  soma = soma+val;
   }
}

if (tensaoanalog>112 && tensaoanalog <137)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 113,136,81,91);
  soma = soma+val;
   }
}

if (tensaoanalog>136 && tensaoanalog <163)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 137,162,91,101);
  soma = soma+val;
   }
}

if (tensaoanalog>162 && tensaoanalog <190)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 163,189,101,111);
  soma = soma+val;
   }
}

if (tensaoanalog>191 && tensaoanalog <218)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 192,217, 111, 121);
  soma = soma+val;
   }
} 

if (tensaoanalog>219 && tensaoanalog <250)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 220,249, 121, 131);
  soma = soma+val;
   }
} 


if (tensaoanalog>251 && tensaoanalog <282)
{
   for(i=0;i<1000;i++){
    val = mapFloat(tensaoanalog, 252,281, 131, 141);
  soma = soma+val;
   }
} 

media = soma/1000;

  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Tensao em volts:");
  lcd.setCursor(2, 1);
  lcd.print(media);  
  delay(10);
}
void holdEvent() {
  
float now = analogRead(A5);
  delay(20);
 float now2 = analogRead(A4);
  delay(20);
  
  if (now >= 300 && now2 <300)
  {
    lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("FASIMETRO");
   lcd.setCursor(2, 1);
  lcd.print("Sequencia +");
  delay(10);
  }
  

  if (now2 >= 300 && now <300)
  {
      lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("FASIMETRO");
   lcd.setCursor(2, 1);
  lcd.print("Sequencia -");
  delay(30);
  }
}
void longHoldEvent() {
     lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Presione o botao");
    lcd.setCursor(0, 1);
    lcd.print("novamente");  
  delay(10);
  
}


float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) 
{ 
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; 
}

int debounce = 20;          // ms debounce period to prevent flickering when pressing or releasing the button
int DCgap = 800;            // max ms between clicks for a double click event
int holdTime = 2000;        // ms hold period: how long to wait for press+hold event
int longHoldTime = 4000;    // ms long hold period: how long to wait for press+hold event

// Button variables
boolean buttonVal = HIGH;   // value read from button
boolean buttonLast = HIGH;  // buffered value of the button's previous state
boolean DCwaiting = false;  // whether we're waiting for a double click (down)
boolean DConUp = false;     // whether to register a double click on next release, or whether to wait and click
boolean singleOK = true;    // whether it's OK to do a single click
long downTime = -1;         // time the button was pressed down
long upTime = -1;           // time the button was released
boolean ignoreUp = false;   // whether to ignore the button release because the click+hold was triggered
boolean waitForUp = false;        // when held, whether to wait for the up event
boolean holdEventPast = false;    // whether or not the hold event happened already
boolean longHoldEventPast = false;// whether or not the long hold event happened already

int checkButton() {    
   int event = 0;
   buttonVal = digitalRead(buttonPin);
   // Button pressed down
   if (buttonVal == LOW && buttonLast == HIGH && (millis() - upTime) > debounce)
   {
       downTime = millis();
       ignoreUp = false;
       waitForUp = false;
       singleOK = true;
       holdEventPast = false;
       longHoldEventPast = false;
       if ((millis()-upTime) < DCgap && DConUp == false && DCwaiting == true)  DConUp = true;
       else  DConUp = false;
       DCwaiting = false;
   }
   // Button released
   else if (buttonVal == HIGH && buttonLast == LOW && (millis() - downTime) > debounce)
   {        
       if (not ignoreUp)
       {
           upTime = millis();
           if (DConUp == false) DCwaiting = true;
           else
           {
               event = 2;
               DConUp = false;
               DCwaiting = false;
               singleOK = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal == HIGH && (millis()-upTime) >= DCgap && DCwaiting == true && DConUp == false && singleOK == true && event != 2)
   {
       event = 1;
       DCwaiting = false;
   }
   // Test for hold
   if (buttonVal == LOW && (millis() - downTime) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast)
       {
           event = 3;
           waitForUp = true;
           ignoreUp = true;
           DConUp = false;
           DCwaiting = false;
           //downTime = millis();
           holdEventPast = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime) >= longHoldTime)
       {
           if (not longHoldEventPast)
           {
               event = 4;
               longHoldEventPast = true;
           }
       }
   }
   buttonLast = buttonVal;
   return event;
}

