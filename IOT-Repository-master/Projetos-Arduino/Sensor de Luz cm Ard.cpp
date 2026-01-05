// Projeto: Sensor de Luz com Arduino
// Autor: João L 
// Link: https://www.tinkercad.com/things/kxI9OlVKKSE-sensor-de-luz-c-arduino?sharecode=cdqCSUchJ80MX_N-B52Exo2iPoEiAw_kRQjeqnTSa-s
// Materiais:
// - 1x Arduino Uno
// - 1x Fotoresistor (LDR)
// - 1x Resistor 220 ohms
// - 1x Resistor 1k ohms
// - Fios de conexão
// Protoboard (OPCIONAL)


const int pinLDR = A0;
const int pinLED = 3;

// Ajuste este limiar conforme o ambiente. Em sala iluminada pode ficar ~600-800.
// Em ambiente escuro pode ficar ~100-300. Use o Serial Monitor para calibrar.
int limiar = 500;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(pinLDR); // 0..1023
  Serial.print("Luz: ");
  Serial.println(valor);

  // Acende se estiver mais escuro que o limiar
  if (valor > limiar) {
    digitalWrite(pinLED, HIGH);
  } else {
    digitalWrite(pinLED, LOW);
  }

  delay(100);
}
