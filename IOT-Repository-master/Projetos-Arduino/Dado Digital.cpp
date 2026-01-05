// Link:https://www.tinkercad.com/things/hm6HLWEwE94-dado-digital-c-arduino?sharecode=cjxSwwqxw0kMlvNH1I0jm6xZSd3S-bSvuakIhkVhjUI
// Projeto: Dado Digital com Arduino
// Autor: João L
// Materiais:
// - 1x Arduino Uno
// - 1x Botão
// - 6x LEDs
// - 6x Resistores 120 ohms
// Protoboard (OPCIONAL)


// Dado com 6 LEDs e botão em D2 (INPUT_PULLUP).
// Opção A: se sortear o mesmo número do último, "rerola" até ser diferente.

const int buttonPin = 2;                       // botão em D2 (INPUT_PULLUP)

int ledPins[] = {3, 4, 5, 6, 7, 8};            // Ex.: {8, 9, 10, 11, 12, 13}
const int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]);


const bool LED_ACTIVE_LOW = false;             // false => HIGH acende; true => LOW acende

const unsigned long showTimeMs = 800;          // tempo de exibição (ms)
int lastN = 0;                                 // último número mostrado (0 = nenhum)

// Helpers para lógica ativa-alta/ativa-baixa
inline void LED_ON(int pin)  { digitalWrite(pin, LED_ACTIVE_LOW ? LOW  : HIGH); }
inline void LED_OFF(int pin) { digitalWrite(pin, LED_ACTIVE_LOW ? HIGH : LOW ); }

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);            // D2 ↔ botão ↔ GND

  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    LED_OFF(ledPins[i]);                       // começa tudo apagado
  }

  randomSeed(analogRead(A0));                  // semente do aleatório
}

void loop() {
  // Com INPUT_PULLUP: pressionado = LOW
  if (digitalRead(buttonPin) == LOW) {
    int n;

    
    do {
      n = random(1, numLEDs + 1);              // sorteia 1..6
    } while (n == lastN);

    lastN = n;

    // Mostra N: acende os primeiros N LEDs
    mostrarNumero(n);

    delay(showTimeMs);                          // mantém aceso

    // Apaga todos
    apagarTodos();

    // aguarda soltar para não repetir no mesmo clique
    while (digitalRead(buttonPin) == LOW) { delay(10); }
    delay(150); // pequeno cooldown antirruído
  }
}

// --- Funções auxiliares (FORA de setup/loop) ---

void mostrarNumero(int n) {
  for (int i = 0; i < numLEDs; i++) {
    if (i < n) LED_ON(ledPins[i]);
    else       LED_OFF(ledPins[i]);
  }
}

void apagarTodos() {
  for (int i = 0; i < numLEDs; i++) {
    LED_OFF(ledPins[i]);
  }
}
