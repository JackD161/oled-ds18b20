#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 10 // номер пина к которому подключен DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
#include <ds>
OLED  myOLED(8, 9, 8); // 8pin - SDA , 9pin - SCL
extern uint8_t RusFont[]; // Русский шрифт
extern uint8_t MegaNumbers[]; // Подключение больших шрифтов
extern uint8_t SmallFont[]; // Базовый шрифт без поддержки русскийх символов.
void setup()
{
  sensors.begin(); 
  myOLED.begin();
}
void loop()
{
sensors.requestTemperatures();
myOLED.clrScr(); // очищаем экран
myOLED.setFont(RusFont); // Устанавливаем русский шрифт
myOLED.print("Ntvgthfnehf", CENTER, 0); // Выводим надпись "Температура"
myOLED.setFont(SmallFont);
myOLED.print("batinsamogon.ru", CENTER, 55); // вывод текста
myOLED.setFont(MegaNumbers);
myOLED.print(String(sensors.getTempCByIndex(0) , 1), CENTER, 9);   // Отображение температуры
myOLED.update();
delay(100);
}
