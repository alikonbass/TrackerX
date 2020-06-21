// définit les numéros de broches LDR
const int rightSensorPin = A0;
const int leftSensorPin = A1;

// variable pour lire l'état des broches
int rightSensorRead = 0;
int leftSensorRead = 0;
int rightLightPct = 0;
int leftLightPct = 0;
int degreeChange = 1;

 
// Bibliothèque Arduino's CustomStepper
#include <CustomStepper.h> 

// définit les numéros de broches LED & bouton poussoir
int ledPinGreen = 3; // choisissez la broche pour la LED verte 
int ledPinRed = 4; // choisissez la broche pour la LED rouge
int inPin = 10;   // choisissez la broche pour le bouton poussoir

// variable pour lire l'état des broches
int val = 0;    
int run;

// définit les numéros de broches de moteur CLK+/5/ CW+/6/ EN+/7/
CustomStepper stepper(5, 6, 7, 8);

void setup() {
 Serial.begin(9600);
  run=0;
   pinMode(ledPinGreen, OUTPUT);  // déclare LED sortie
  pinMode(ledPinRed, OUTPUT);  // déclare LED sortie
  pinMode(inPin, INPUT);    // déclare le bouton poussoir entrée
  stepper.setRPM(5);
  stepper.setSPR(4075.7728395);

  digitalWrite(ledPinGreen, HIGH);// éteindre la LED rouge
}
void Start_Stop_System(){
   val = digitalRead(inPin);  // lire la valeur d'entrée

   if (val == HIGH) {         // vérifier si l'entrée est HAUTE (bouton relâché)
    if(run == 0){
      digitalWrite(ledPinGreen, LOW);// allumer la LED verte
      digitalWrite(ledPinRed, HIGH);// éteindre la LED rouge
      run = 1;
    } 
   }
}

void loop() {
    Start_Stop_System();

 
  rightSensorRead = analogRead(rightSensorPin);
  leftSensorRead = analogRead(leftSensorPin);
  rightLightPct = map(rightSensorRead, 0, 1023, 0, 100);
  leftLightPct = map(leftSensorRead, 0, 1023, 0, 100);
  degreeChange = map(abs(rightLightPct-leftLightPct),0,100,2,10);
  Serial.print("right = ");
  Serial.print(rightSensorRead);
  Serial.print(" left = ");
  Serial.print(leftSensorRead);
  Serial.print(" Pct r/l = ");
  Serial.print(rightLightPct);
  Serial.print("/");
  Serial.println(leftLightPct);
  if(rightLightPct > 10 && leftLightPct > 10 ){
    Serial.println("No sun detected!");
  }else if(rightLightPct > leftLightPct){
    Serial.println("Turning CCW!");
    rotateLeft();
    stepper.run();
  }else{
    Serial.println("Turning CW!");
    rotateRight();
    stepper.run();
  }
}

void rotateLeft(){
  stepper.setDirection(CCW);
  stepper.rotateDegrees(degreeChange);
  while(stepper.isDone() == false){
    stepper.run();
  }
}
void rotateRight(){
  stepper.setDirection(CW);
  stepper.rotateDegrees(degreeChange);
  while(stepper.isDone() == false){
    stepper.run();
  }
}
