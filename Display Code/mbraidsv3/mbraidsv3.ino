#include <elapsedMillis.h>
#include <PinChangeInterrupt.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
int muxCount;
// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
word character[4];
int histTotal;
uint16_t digit;
int readIndex[4] = {4, 5, 2, 3};
elapsedMillis sinceDisplay;
elapsedMillis sinceMux;
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

constexpr int NUM_SEGMENTS = 14;
void setup()   {
  //char select inputs
  pinMode(readIndex[0], INPUT);
  attachPCINT(digitalPinToPCINT(readIndex[0]), dispcharISR0, RISING);
  pinMode(readIndex[1], INPUT);
  attachPCINT(digitalPinToPCINT(readIndex[1]), dispcharISR1, RISING);
  pinMode(readIndex[2], INPUT);
  attachPCINT(digitalPinToPCINT(readIndex[2]), dispcharISR2, RISING);
  pinMode(readIndex[3], INPUT);
  attachPCINT(digitalPinToPCINT(readIndex[3]), dispcharISR3, RISING);
  //
  pinMode(A0, INPUT); //mux in
  pinMode(A1, OUTPUT); //s0
  pinMode(A2, OUTPUT); //s1
  pinMode(A3, OUTPUT); //s2
  pinMode(A4, OUTPUT); //s3
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done
  display.clearDisplay();
}


void loop()
{
  if (sinceDisplay > 20)
  {
    testOutput();
    //writeOutput();
    sinceDisplay = 0;
  }
}

void testOutput()
{
  display.clearDisplay();
  for (int n = 0; n < 4; n++)
  {
    digit = 32 * n;
    for (int q = 0; q < 14; q++)
    {
      if (bitRead(character[n], q))
      {
        if (q == 0)
          display.fillRoundRect(4 + digit, 1, 23, 3,1, WHITE);
        if (q == 1)
          display.fillRoundRect(27 + digit, 4, 3 , 11,1, WHITE);
        if (q == 2)
          display.fillRoundRect(27 + digit, 17, 3 , 11,1, WHITE);
        if (q == 3)
          display.fillRoundRect(4 + digit, 28, 23 , 3,1, WHITE);
        if (q == 4)
          display.fillRoundRect(2 + digit, 17, 3 , 11,1, WHITE);
        if (q == 5)
          display.fillRoundRect(2 + digit, 4, 3, 11,1, WHITE);
        if (q == 6){
          display.drawLine(5 + digit, 5, 14 + digit, 14, WHITE);
          display.drawLine(6 + digit, 5, 14 + digit, 13, WHITE);
          display.drawLine(5 + digit, 6, 13 + digit, 14, WHITE);}
        if (q == 7)
          display.fillRoundRect(15 + digit, 5, 3 , 10,1, WHITE);
        if (q == 8){
          display.drawLine(17 + digit, 14, 26 + digit, 5, WHITE);
          display.drawLine(18 + digit, 14, 26 + digit, 6, WHITE);
          display.drawLine(17 + digit, 13, 25 + digit, 5, WHITE);}
        if (q == 9)
          display.fillRoundRect(16 + digit, 15, 10 , 3,1, WHITE);
         if (q == 12){
          display.drawLine(5 + digit, 27, 14 + digit, 17, WHITE);     
          display.drawLine(5 + digit, 26, 13 + digit, 17, WHITE);   
          display.drawLine(6 + digit, 27, 14 + digit, 18, WHITE);   }
        if (q == 11)
          display.fillRoundRect(15 + digit, 17, 3 , 10,1, WHITE);
        if (q == 10){
          display.drawLine(17 + digit, 17, 27 + digit, 27, WHITE);
          display.drawLine(18 + digit, 17, 27 + digit, 26, WHITE);
          display.drawLine(17 + digit, 18, 26 + digit, 27, WHITE);}
         if (q == 13)
          display.fillRoundRect(5 + digit, 15, 9 , 3,1, WHITE);        
      }
    }
  }
  display.display();
}

void writeOutput()
{
  display.clearDisplay();
  for (int i = 0; i < 5; i++)
  {
    for (int x = 0; x < 16; x++)
    {
      if (i < 4)
      {
        if (bitRead(character[i], x))
          display.drawPixel(x * 8, i * 7, WHITE);
        else
          display.drawPixel(x * 8, i * 7, BLACK);
      }
      else
        display.drawPixel(x * 8, i * 7, WHITE);
    }
  }
  display.display();
}

void inputDetect()
{
  for (int i = 0; i < 4; i++)
  {
    if (digitalRead(readIndex[i]))
    {
      boolean inputRead;
      inputRead = digitalRead(A0);
      if (inputRead)
        bitSet(character[i], muxCount);
      else
        bitClear(character[i], muxCount);
    }
  }
}

void multiplexer()
{
  digitalWrite(A1, muxCount & 0b01);
  digitalWrite(A2, muxCount & 0b10);
  digitalWrite(A3, muxCount & 0b100);
  digitalWrite(A4, muxCount & 0b1000);
  inputDetect();
  muxCount = (muxCount + 1) % 14;
}

inline void dispcharISR(int selected) {
  for (uint8_t mux_count = 0; mux_count < NUM_SEGMENTS; mux_count++) {
    PORTC = mux_count << 1;
    bitWrite(character[selected], mux_count, PINC & 0b1);
  }
}

void dispcharISR0(){
  dispcharISR(0);
}
void dispcharISR1(){
  dispcharISR(1);
}
void dispcharISR2(){
  dispcharISR(2);
}
void dispcharISR3(){
  dispcharISR(3);
}
