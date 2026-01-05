// OBS: Lista de materiais e link do projeto no final do código foram perdidos.

int celsius =0;
int sensor = 0;

void setup()
{
  Serial.begin(9600);
  for(int i = 5;i<=13;i++){
  	pinMode(i,OUTPUT);
  }
}

void loop()
{
  sensor = analogRead(A1);
  
  celsius = map(((sensor -20) *3.04),0,1023,-40,125);
  Serial.print("Medida do sensor =");
  Serial.println(sensor);
  Serial.print("Temperatura");
  Serial.println(celsius);
  Serial.print("C, ");
  Serial.println("");
  
  if (celsius <=-40){
    for(int i=5;i<=13;i++){
     digitalWrite(i,LOW);
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
    }
  }
  if(celsius >10 && celsius <=20){
    for(int i=5;i<=13;i++){
     digitalWrite(i,LOW);
     digitalWrite(11, HIGH);
     digitalWrite(12, HIGH);
     digitalWrite(13, HIGH);
   }
    
  }
  if (celsius >20 && celsius <=30){
  	digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (celsius >30 && celsius <=120){
  	digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }



}
