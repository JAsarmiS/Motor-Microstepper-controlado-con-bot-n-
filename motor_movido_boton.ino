//Se mueve pulsando el boton
#include <AccelStepper.h>

// Pines de control del motor
#define DIR_PIN 2
#define STEP_PIN 3

// Pin del pulsador
#define BUTTON_PIN 5

// Variables para el manejo del motor
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

bool buttonPressed = false;

void setup() {
  // Configuración del monitor serial
  Serial.begin(9600);

  // Configuración de pines
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Configuración del motor
  stepper.setMaxSpeed(1000); // Velocidad máxima del motor
  stepper.setAcceleration(500); // Aceleración del motor
}

void loop() {
  // Lectura del botón
  int buttonState = digitalRead(BUTTON_PIN);

  // Si el botón se presiona, mueve el motor un paso
  if (buttonState == LOW && !buttonPressed) {
    stepper.move(1);
    stepper.run();
    Serial.print("Position: ");
    Serial.println(stepper.currentPosition());
    buttonPressed = true;
  } else if (buttonState == HIGH) {
    buttonPressed = false;
  }
}