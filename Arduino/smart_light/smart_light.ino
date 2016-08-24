#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#define PIN             6
#define NUMBER          7
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMBER, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  pixels.begin();//네오픽셀 사용설정
  setAllColor(NUMBER,pixels.Color(0, 0, 0));
  Serial.begin(9600);//시리얼통신사용설정
}

byte r = 0, g = 0, b = 0;
int Count = 1;
void loop() {
  if (Serial.available() > 5) { //수신받은 블루투스 데이터가 2개 초과일때
    if(Serial.read() != '[')
    {
      return;
    }
    Count = Serial.read(); 
    r = Serial.read();//첫번째 데이터를 r에 저장
    g = Serial.read();//두번째 데이터를 g에 저장
    b = Serial.read();//세번째 데이터를 b에 저장
    if(Serial.read() != ']')
    {
      return;
    }
    Serial.flush();//통신내용 초기화
    setAllColor(Count,pixels.Color(r, g, b));
  }
}

void setAllColor(int count,uint32_t color) {//전체 색상 지정함수 
  pixels.clear();
  for (int i = 0; i < count; i++) {
    pixels.setPixelColor(i, color);
  }
  pixels.show();
}
