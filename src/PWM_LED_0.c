#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// #define SERVO_PIN 22  Para controle do servomotor

#define LED_RGB_PIN 12
#define PWM_FREQ 50   // Frequência de 50 Hz (período de 20 ms)

void set_servo_angle(uint angle) {
    // Converte o ângulo para largura de pulso em microssegundos
    uint16_t pulse_width = 500 + (angle * 10);  // 500us (0°) a 2500µs (180°)
    uint16_t wrap = 125000 / PWM_FREQ;  // Wrap value para 50 Hz
    uint16_t level = (pulse_width * wrap) / 20000;  // Calcula o nível do PWM

    pwm_set_gpio_level(LED_RGB_PIN, level);
}

void set_rgb_brightness(uint brightness) {
    pwm_set_gpio_level(LED_RGB_PIN, brightness);
}

int main() {
    stdio_init_all();

    // Configura o PWM no pino 22
    gpio_set_function(LED_RGB_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LED_RGB_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f);  // Divisor de clock para 1 MHz
    pwm_config_set_wrap(&config, 125000 / PWM_FREQ);  // Wrap para 50 Hz
    pwm_init(slice_num, &config, true);

    while (true) {
        // Move o servomotor para 180°
        set_servo_angle(180);
        sleep_ms(5000);

        // Move o servomotor para 90°
        set_servo_angle(90);
        sleep_ms(5000);

        // Move o servomotor para 0°
        set_servo_angle(0);
        sleep_ms(5000);

        // Movimentação suave entre 0° e 180°
        for (int angle = 0; angle <= 180; angle++) {
            set_servo_angle(angle);
            sleep_ms(10);  // Atraso para movimentação suave
        }
        for (int angle = 180; angle >= 0; angle--) {
            set_servo_angle(angle);
            sleep_ms(10);  // Atraso para movimentação suave
        }
    }

    return 0;
}