
/* Board Arduino/Genuino UNO */

#include <elapsedMillis.h>

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
int readIndex[4] = {4, 5, 2, 3};
elapsedMillis sinceDisplay;
elapsedMillis sinceMux;
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  //char select inputs
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
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
  multiplexer();
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
    for (int q = 0; q < 14; q++)
    {
      if (bitRead(character[n], q))
      {
        if (q == 0)
          display.drawLine(0 + 32 * n, 0, 28 + 32 * n, 0, WHITE);
        if (q == 1)
          display.drawLine(28 + 32 * n, 0, 28 + 32 * n, 15, WHITE);
        if (q == 2)
          display.drawLine(28 + 32 * n, 16, 28 + 32 * n, 31, WHITE);
        if (q == 3)
          display.drawLine(0 + 32 * n, 31, 28 + 32 * n, 31, WHITE);
        if (q == 4)
          display.drawLine(0 + 32 * n, 16, 0 + 32 * n, 31, WHITE);
        if (q == 5)
          display.drawLine(0 + 32 * n, 0, 0 + 32 * n, 15, WHITE);
        if (q == 6)
          display.drawLine(0 + 32 * n, 0, 14 + 32 * n, 15, WHITE);
        if (q == 7)
          display.drawLine(14 + 32 * n, 0, 14 + 32 * n, 15, WHITE);
        if (q == 8)
          display.drawLine(14 + 32 * n, 15, 28 + 32 * n, 0, WHITE);
        if (q == 9)
          display.drawLine(14 + 32 * n, 15, 28 + 32 * n, 15, WHITE);
        if (q == 10)
          display.drawLine(14 + 32 * n, 15, 28 + 32 * n, 31, WHITE);
        if (q == 11)
          display.drawLine(14 + 32 * n, 16, 14 + 32 * n, 31, WHITE);
        if (q == 12)
          display.drawLine(14 + 32 * n, 15, 0 + 32 * n, 31, WHITE);
        if (q == 13)
          display.drawLine(0 + 32 * n, 15, 14 + 32 * n, 15, WHITE);
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
