int alarma = 4;
int gas;
byte e_1 = 3;
int concentracion;
byte seguro = 5, precaucion = 6, peligro = 7;


void setup() {
  pinMode (alarma, OUTPUT);
  pinMode (seguro, OUTPUT);
  pinMode (precaucion, OUTPUT);
  pinMode (peligro, OUTPUT); 
  pinMode (e_1, OUTPUT);
  Serial.begin (9600);
  digitalWrite (e_1, LOW);
}

void loop() {
 gas = analogRead (A0);
 concentracion = map(gas,487,875,0,100);
 Serial.print("Lectura: ");
 Serial.print(gas);
 Serial.print ("  Concentracion: ");
 Serial.print (concentracion);
 Serial.print ("%");
 Serial.println ();
 if ( concentracion <=10 && concentracion >= 0){
   digitalWrite (seguro, HIGH);
   digitalWrite (alarma, LOW);
   digitalWrite (e_1, LOW);
  }else{
   digitalWrite (seguro, LOW);}
 if ( concentracion <=49 && concentracion >= 11){
  digitalWrite (precaucion, HIGH);
   digitalWrite (e_1, HIGH);
   digitalWrite(alarma, HIGH); 
  }else{
  digitalWrite (precaucion, LOW);}
 if ( concentracion >=50){
  digitalWrite (peligro, HIGH);
  digitalWrite (e_1, HIGH);
  digitalWrite(alarma, HIGH);
  }else{
  digitalWrite (peligro, LOW);}
}
