struct traffic { 
  int red;
  int yellow;
  int green;
};

//utara
int U_M = 13;
int U_K = 12;
int U_H = 11;

// timur
int T_M = 10;
int T_K = 9;
int T_H = 8;

// selatan
int S_M = 7;
int S_K = 6;
int S_H = 5;

// barat
int B_M = 4;
int B_K = 3;
int B_H = 2;

traffic roads[4] = { 
  {U_M, U_K, U_H},
  {T_M, T_K, T_H},
  {S_M, S_K, S_H},
  {B_M, B_K, B_H}
};


void setup()
{
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  semuaMerah(); // kondisi awal
  delay(3000);	
}


void loop()
{
  activeRoad(roads[0]); 
  activeRoad(roads[1]); 
  activeRoad(roads[2]); 
  activeRoad(roads[3]); 
}


void semuaMerah() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(roads[i].red, HIGH);
    digitalWrite(roads[i].yellow, LOW);
    digitalWrite(roads[i].green, LOW);
  }
}


// satu sisi
void activeRoad(struct traffic R) {

  // 1. semua merah dulu
  semuaMerah();

  // 2. transisi ke kuning
  digitalWrite(R.red, LOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(R.yellow, HIGH);
    delay(250);
    digitalWrite(R.yellow, LOW);
    delay(250);
  }

  digitalWrite(R.yellow, HIGH);
  delay(500);
  digitalWrite(R.yellow, LOW);

  // 3. hijau
  digitalWrite(R.green, HIGH);
  delay(5000);
  digitalWrite(R.green, LOW);

  // 4. transisi keluar ke kuning
  for (int i = 0; i < 3; i++) {
    digitalWrite(R.yellow, HIGH);
    delay(250);
    digitalWrite(R.yellow, LOW);
    delay(250);
  }

  digitalWrite(R.yellow, HIGH);
  delay(500);
  digitalWrite(R.yellow, LOW);

  // 5. kembali merah
  digitalWrite(R.red, HIGH);
}