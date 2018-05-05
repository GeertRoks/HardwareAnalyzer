// CC-by-www.Electrosmash.com Pedl-Pi open-source project
// clean.c effect pedal, the signal is read by the ADC and written again using 2 PWM signals.

#include <stdio.h>
#include <bcm2835.h>

uint32_t input_signal=0;


//main program
int main(int argc, char **argv)
{
    // Start the BCM2835 Library to access GPIO.
    if (!bcm2835_init()) {
      printf("bcm2835_init failed. Are you running as root??\n"); return 1;
    }//if


    // Start the SPI BUS.
    if (!bcm2835_spi_begin()) {
      printf("bcm2835_spi_begin failed. Are you running as root??\n"); return 1;
    }//if

    //define PWM mode
    bcm2835_gpio_fsel(18,BCM2835_GPIO_FSEL_ALT5 ); //PWM0 signal on GPIO18
    bcm2835_gpio_fsel(13,BCM2835_GPIO_FSEL_ALT0 ); //PWM1 signal on GPIO13
    bcm2835_pwm_set_clock(2);                      // Max clk frequency (19.2MHz/2 = 9.6MHz)
    bcm2835_pwm_set_mode(0,1 , 1);                 //channel 0, markspace mode, PWM enabled.
    bcm2835_pwm_set_range(0,64);                   //channel 0, 64 is max range (6bits): 9.6MHz/64=150KHz PWM freq.
    bcm2835_pwm_set_mode(1, 1, 1);                 //channel 1, markspace mode, PWM enabled.
    bcm2835_pwm_set_range(1,64);                   //channel 0, 64 is max range (6bits): 9.6MHz/64=150KHz PWM freq.

    //define SPI bus configuration
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // 4MHz clock with _64
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default

    uint8_t mosi[10] = { 0x01, 0x00, 0x00 }; //12 bit ADC read channel 0.
    uint8_t miso[10] = { 0 };

    //Main Loop
    while(1) {

      //read 12 bits ADC
      bcm2835_spi_transfernb(mosi, miso, 3);
      input_signal = miso[2] + ((miso[1] & 0x0F) << 8);

      //**** CLEAN EFFECT ***///
      //Nothing to do, the input_signal goes directly to the PWM output.

      //generate output PWM signal 6 bits
      bcm2835_pwm_set_data(1,input_signal & 0x3F);
      bcm2835_pwm_set_data(0,input_signal >> 6);
    }//while

    //close all and exit
    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}
