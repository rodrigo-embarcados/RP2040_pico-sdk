#include "pico/stdlib.h"

#define led_r 13
#define led_g 11
#define led_b 12

void blink_led(uint gpio, int tempo);

int main()
{
    gpio_init(led_r);
    gpio_init(led_g);
    gpio_init(led_b);
    gpio_set_dir(led_r, GPIO_OUT);
    gpio_set_dir(led_g, GPIO_OUT);
    gpio_set_dir(led_b, GPIO_OUT);

    int cont = 0;
    int tempo = 300;
    while(1)
    {
        for (int i = 0; i <= cont; i++)
        {    
            blink_led(led_r, tempo);
        }
        for (int i = 0; i <= cont; i++)
        {            
            blink_led(led_g, tempo);
        }
        for (int i = 0; i <= cont; i++)
        {        
            blink_led(led_b, tempo);
        }
        cont = (cont + 1) % 5;
        tempo -= 50;
        if (tempo == 50)
            tempo = 300;
    }
}

void blink_led(uint gpio, int tempo)
{
    gpio_xor_mask(1u << gpio);
    sleep_ms(tempo);
    gpio_xor_mask(1u << gpio);
    sleep_ms(tempo);
}
