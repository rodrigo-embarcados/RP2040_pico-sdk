#include "pico/stdlib.h"

#define led_r 13
#define led_g 11
#define led_b 12
#define button_1 5
#define button_2 6

void blink_led(uint gpio, int tempo);

int main()
{
    gpio_init(led_r);
    gpio_init(led_g);
    gpio_init(led_b);

    gpio_set_dir(led_r, GPIO_OUT);
    gpio_set_dir(led_g, GPIO_OUT);
    gpio_set_dir(led_b, GPIO_OUT);

    gpio_init(button_1);
    gpio_pull_up(button_1);
    gpio_set_dir(button_1, GPIO_IN);
    
    gpio_init(button_2);
    gpio_pull_up(button_2);
    gpio_set_dir(button_2, GPIO_IN);

    int tempo = 300;

    while(1)
    {
        if (gpio_get(button_1) == 0)
        {
            sleep_ms(30);
            if (gpio_get(button_1) == 0)
            {  
                if (tempo == 50)
                    tempo = 300;
                else
                    tempo -= 50;
            }
        }
        if (gpio_get(button_2) == 0)
        {
            sleep_ms(30);
            if (gpio_get(button_2) == 0)
            {
                if (tempo == 300)
                    tempo = 50;
                else
                    tempo += 50;
            }
        }
        blink_led(led_r, tempo);
        blink_led(led_g, tempo);
        blink_led(led_b, tempo);
    }
}

void blink_led(uint gpio, int tempo)
{
    gpio_xor_mask(1u << gpio);
    sleep_ms(tempo);
    gpio_xor_mask(1u << gpio);
    sleep_ms(tempo);
}