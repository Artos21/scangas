
#include <TroykaMQ.h> //подключаем библиотке для работы с датчиком MQ-2
#include <SPI.h>
#include <Ethernet2.h>


#define PIN_MQ2  A0// назначаем пин к которому подлючен датчик
MQ2 mq2(PIN_MQ2);// создаём объект для работы с датчиком и передаём ему номер пина
int timer=6000;
byte mac[]={ 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
char server[] ="monitor-gas-ru.1gb.ru";
int ppm;
int id_device=1;
int id_gas;

EthernetClient client;

void setup()
{
  Serial.begin(9600); // открываем последовательный порт
  Ethernet.begin(mac);
  delay(60000);//задаем задержку для агрева датчика
  mq2.calibrate(); // выполняем калибровку датчика на чистом воздухе
  digitalWrite(10,HIGH);
  digitalWrite(4,LOW);
}
 
void loop()
{
  // выводим значения газов в ppm
  Serial.print(" Углеводородные газы: ");
  Serial.print(mq2.readLPG());
  Serial.print(" ppm ");
  Serial.print(" Метан: ");
  Serial.print(mq2.readMethane());
  Serial.print(" ppm ");
  Serial.print(" Дым: ");
  Serial.print(mq2.readSmoke());
  Serial.print(" ppm ");
  Serial.print(" Водород: ");
  Serial.print(mq2.readHydrogen());
  Serial.println(" ppm ");
  if(mq2.readMethane()>20000){
    Serial.println("Выход за пределы измерения датчика");
    }

  id_gas=1;
  ppm=mq2.readLPG();
  sendData (ppm,id_device,id_gas);
  id_gas=2;
  ppm=mq2.readMethane();
  sendData (ppm,id_device,id_gas);
  id_gas=3;
  ppm=mq2.readSmoke();
  sendData (ppm,id_device,id_gas);
  id_gas=4;
  ppm=mq2.readHydrogen();
  sendData (ppm,id_device,id_gas);
  delay(timer);
}
 void sendData(int ppm, int id_device, int id_gas){
 client.connect(server,80);
  if (!client.connected()) {
    Serial.println();
    Serial.println("Соединение не установлено.");
    client.stop();
  }
  else{



  Serial.println("Соединение с сервером установлено");

  client.print("GET /connection.php?");
  client.print("id_gas=");
  client.print(id_gas);
  client.print("&");
  client.print("id_device=");
  client.print(id_device);
  client.print("&");
  client.print("ppm=");
  client.print(ppm);
  client.println(" HTTP/1.1");
 client.println("Host: monitor-gas-ru.1gb.ru");
  client.println("Connection: close");
  client.println();
  client.println();
 client.stop();
  client.flush();
  } 
 }
