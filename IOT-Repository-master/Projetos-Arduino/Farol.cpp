// Link: https://www.tinkercad.com/things/aUSRe9KEt3K-farol-c-arduino?sharecode=w9aHI6G7v34pHZ9LttcDj13P2LQRjMY1YW_0xoMEoII
// Projeto: Farol com Arduino
// Autor: João L
// Materiais:
// - 1x Arduino Uno
// - 3x LEDs (Vermelho, Amarelo, Verde)
// - 3x Resistores 220 ohms 
// - Fios de conexão
// Protoboard (OPCIONAL)


// Farol (Semáforo) 

const int LED_VERDE    = 2;
const int LED_AMARELO  = 3;
const int LED_VERMELHO = 4;

// Tempos (em milissegundos)
unsigned long tempoVerde    = 3000;  // 3 segundos (ajuste o comentário ou o valor)
unsigned long tempoAmarelo  = 2000;  // 2 segundos
unsigned long tempoVermelho = 6000;  // 6 segundos (ajuste o comentário ou o valor)

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  // Começa com o vermelho ligado (mais seguro)
  ligarSomente(LED_VERMELHO);
}

void loop() {
  // Vermelho
  ligarSomente(LED_VERMELHO);
  delay(tempoVermelho);

  // Amarelo
  ligarSomente(LED_AMARELO);
  delay(tempoAmarelo);

  // Verde
  ligarSomente(LED_VERDE);
  delay(tempoVerde);
}

// Função utilitária: liga só um LED e garante os outros desligados
void ligarSomente(int led) {
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, LOW);

  digitalWrite(led, HIGH);
}


