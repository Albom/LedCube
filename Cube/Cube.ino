

const byte DATA_OUT  = 0;
const byte LATCH_OUT = 1;
const byte TAKT_OUT  = 2;


// 24 bit output
void sendo(long output) {
  for (int i = 23; i >= 0; i--) {
    digitalWrite(DATA_OUT, (output >> i) & 1);
    digitalWrite(TAKT_OUT, HIGH);
    delayMicroseconds(5);
    digitalWrite(TAKT_OUT, LOW);
  }
  digitalWrite(LATCH_OUT, HIGH);
  delayMicroseconds(5);
  digitalWrite(LATCH_OUT, LOW);
}


void setup() {


  pinMode(DATA_OUT,  OUTPUT);
  pinMode(LATCH_OUT, OUTPUT);
  pinMode(TAKT_OUT,  OUTPUT);

  digitalWrite(TAKT_OUT,  LOW);
  digitalWrite(LATCH_OUT, LOW);
  digitalWrite(DATA_OUT, LOW);


}

void play_layers() {
  sendo(B1111 * 256 * 256 + B11111111 * 256 + B11111110);
  delay(300);

  sendo(B1111 * 256 * 256 + B11111111 * 256 + B11111101);
  delay(300);

  sendo(B1111 * 256 * 256 + B11111111 * 256 + B11111011);
  delay(300);

  sendo(B1111 * 256 * 256 + B11111111 * 256 + B11110111);
  delay(300);
}

void play_layers_add(){

sendo(B1111*256*256 + B11111111*256 + B11111110);
delay(300);

sendo(B1111*256*256 + B11111111*256 + B11111100);
delay(300);

sendo(B1111*256*256 + B11111111*256 + B11111000);
delay(300);

sendo(B1111*256*256 + B11111111*256 + B11110000);
delay(300);

}

void play_one() {
  sendo(B00011110);
  delay(300);

  sendo(B00101110);
  delay(300);

  sendo(B01001110);
  delay(300);

  sendo(B10001110);
  delay(300);
}

void loop()
{

play_layers();
delay(1000);

play_layers_add();
delay(1000);

}














