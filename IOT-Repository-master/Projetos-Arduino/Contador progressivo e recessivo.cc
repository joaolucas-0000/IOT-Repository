// OBS: Lista de materiais e link do projeto no final do código foram perdidos.

const int botaoProgressivo = 8;
const int botaoRegressivo = 9;
const int botaoReset = 7;
 
int contadorProgressivo = 0;
int contadorRegressivo = 10;
 
void setup() {
  Serial.begin(9600);
  pinMode(botaoProgressivo, INPUT_PULLUP);
  pinMode(botaoRegressivo, INPUT_PULLUP);
  pinMode(botaoReset, INPUT_PULLUP);
}
 
void loop() {
  // Verifica se o botão de reset foi pressionado
  if (digitalRead(botaoReset) == LOW) {
    contadorProgressivo = 0;
    contadorRegressivo = -1;
    Serial.println("Contadores reiniciados!");
  }
 
  // Verifica se o botão progressivo foi pressionado
  if (digitalRead(botaoProgressivo) == LOW) {
    while (contadorProgressivo < 10) {
      Serial.print("Contador progressivo: ");
      Serial.println(contadorProgressivo);
      delay(1000);
      contadorProgressivo++;
    }
  }
 
  // Verifica se o botão regressivo foi pressionado
  if (digitalRead(botaoRegressivo) == LOW) {
    while (contadorRegressivo >= 0) {
      Serial.print("Contador regressivo: ");
      Serial.println(contadorRegressivo);
      delay(1000);
      contadorRegressivo--;
    }
  }

}
