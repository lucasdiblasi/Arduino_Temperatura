#include <stdio.h>

#define MOTOR_PIN 0     // Pino GPIO para acionar o motor de ventilador
#define LED_PIN 1       // Pino GPIO para acionar o LED vermelho
#define BUZZER_PIN 2    // Pino GPIO para acionar a buzina

#define TEMPERATURE_THRESHOLD 30  // Limite de temperatura para acionar o motor
#define EMERGENCY_THRESHOLD 50    // Limite de temperatura para acionar o LED e a buzina

void acionarMotor()
{
    digitalWrite(MOTOR_PIN, HIGH);  // Liga o motor
    delay(5000);                    // Espera por 5 segundos
    digitalWrite(MOTOR_PIN, LOW);   // Desliga o motor
}

void acionarEmergencia()
{
    digitalWrite(LED_PIN, HIGH);    // Liga o LED vermelho
    digitalWrite(BUZZER_PIN, HIGH); // Liga a buzina
    delay(10000);                    // Espera por 10 segundos
    digitalWrite(LED_PIN, LOW);     // Desliga o LED vermelho
    digitalWrite(BUZZER_PIN, LOW);  // Desliga a buzina
}

int main(void)
{
    while (1)
    {
        float temperatura = 0.0;  // Obtenha a leitura da temperatura do sensor (deve ser implementado)

        if (temperatura >= TEMPERATURE_THRESHOLD)
        {
            acionarMotor();
        }

        if (temperatura > EMERGENCY_THRESHOLD)
        {
            acionarEmergencia();
        }
    }

    return 0;
}
