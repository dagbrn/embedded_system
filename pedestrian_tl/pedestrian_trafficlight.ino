int merahK = 13;
int kuningK = 12;
int hijauK = 11;

int merahP1 = 9;
int hijauP1 = 7;
int tombolP1 = 3;
int merahP2 = 6;
int hijauP2 = 4;
int tombolP2 = 2;

volatile bool tombolDitekan = false;

void setup() {
  pinMode(merahK, OUTPUT);
  pinMode(kuningK, OUTPUT);
  pinMode(hijauK, OUTPUT);

  pinMode(merahP1, OUTPUT);
  pinMode(hijauP1, OUTPUT);
  pinMode(tombolP1, INPUT_PULLUP);

  pinMode(merahP2, OUTPUT);
  pinMode(hijauP2, OUTPUT);
  pinMode(tombolP2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(tombolP1), ISR_tombol, FALLING);
  attachInterrupt(digitalPinToInterrupt(tombolP2), ISR_tombol, FALLING);

  kondisiAwal();
}

void loop() {

  if (!tombolDitekan) {
    kondisiAwal();
  } 
  else {
    prosesPenyeberangan();
    tombolDitekan = false;
  }
}

void ISR_tombol() {
  tombolDitekan = true;
}

void kondisiAwal() {
  digitalWrite(hijauK, HIGH);
  digitalWrite(kuningK, LOW);
  digitalWrite(merahK, LOW);

  digitalWrite(merahP1, HIGH);
  digitalWrite(hijauP1, LOW);

  digitalWrite(merahP2, HIGH);
  digitalWrite(hijauP2, LOW);
}

void prosesPenyeberangan() {

  // kendaraan merah
  digitalWrite(hijauK, LOW);
  digitalWrite(kuningK, LOW);
  digitalWrite(merahK, HIGH);

  // pedestrian hijau
  digitalWrite(merahP1, LOW);
  digitalWrite(hijauP1, HIGH);

  digitalWrite(merahP2, LOW);
  digitalWrite(hijauP2, HIGH);

  delay(5000);

  // pedestrian lgsg merah lagi
  digitalWrite(hijauP1, LOW);
  digitalWrite(merahP1, HIGH);

  digitalWrite(hijauP2, LOW);
  digitalWrite(merahP2, HIGH);

  // kuning nyala (berkedip 3x)
  digitalWrite(merahK, LOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(kuningK, HIGH);
    delay(500);
    digitalWrite(kuningK, LOW);
    delay(500);
  }

  kondisiAwal();
}