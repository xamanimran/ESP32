#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void leveltask(void *pvParameter)
{   
    while(1){
    gpio_set_level(16,1); //c1
    gpio_set_level(17,1); //c2
    gpio_set_level(5,1); //c3
    gpio_set_level(18,1); //c4   // default , column check stop 
    gpio_set_level(27,0); //r1
    gpio_set_level(26,0); //r2
    gpio_set_level(25,0); //r3
    gpio_set_level(33,0); //r4
    printf("checking");
    vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    gpio_pad_select_gpio(27); //r1
    gpio_set_direction(27, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(26); //r2
    gpio_set_direction(26, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(25); //r3
    gpio_set_direction(25, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(33); //r4
    gpio_set_direction(33, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(17); //c1
    gpio_set_direction(17, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(16); //c2
    gpio_set_direction(16, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(5); //c3
    gpio_set_direction(5, GPIO_MODE_INPUT_OUTPUT);    
    gpio_pad_select_gpio(18); //c4
    gpio_set_direction(18, GPIO_MODE_INPUT_OUTPUT);
    xTaskCreate(&leveltask, "leveltask", 2048, NULL, 5, NULL);    
    while(1)
    {
    if(gpio_get_level(16) == 0) //column 1 //set level iruka ila store pananuma nu also check loop since printf prints la
    {
      gpio_set_level(27,1); //r1
      {
      if(gpio_get_level(27) && gpio_get_level(16) == 1){printf("button 1 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(17) == 1){printf("button 2 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(5) == 1){printf("button 3 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(18) == 1){printf("button A pressed!");}
      }
      gpio_set_level(26,1); //r2
      {
      if(gpio_get_level(26) && gpio_get_level(16) == 1){printf("button 4 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(17) == 1){printf("button 5 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(5) == 1){printf("button 6 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(18) == 1){printf("button B pressed!");}
      }
      gpio_set_level(25,1); //r3
      {
      if(gpio_get_level(25) && gpio_get_level(16) == 1){printf("button 7 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(17) == 1){printf("button 8 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(5) == 1){printf("button 9 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(18) == 1){printf("button C pressed!");}
      }
      gpio_set_level(33,1); //r4
      {
      if(gpio_get_level(33) && gpio_get_level(16) == 1){printf("button * pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(17) == 1){printf("button 0 pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(5) == 1){printf("button # pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(18) == 1){printf("button D pressed!");}
      }
      gpio_set_level(27,0); gpio_set_level(26,0); gpio_set_level(25,0); gpio_set_level(33,0);
    }
    if(gpio_get_level(17) == 0) //column 2
    {  
      gpio_set_level(27,1); //r1
      {
      if(gpio_get_level(27) && gpio_get_level(16) == 1){printf("button 1 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(17) == 1){printf("button 2 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(5) == 1){printf("button 3 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(18) == 1){printf("button A pressed!");}
      }
      gpio_set_level(26,1); //r2
      {
      if(gpio_get_level(26) && gpio_get_level(16) == 1){printf("button 4 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(17) == 1){printf("button 5 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(5) == 1){printf("button 6 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(18) == 1){printf("button B pressed!");}
      }
      gpio_set_level(25,1); //r3
      {
      if(gpio_get_level(25) && gpio_get_level(16) == 1){printf("button 7 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(17) == 1){printf("button 8 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(5) == 1){printf("button 9 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(18) == 1){printf("button C pressed!");}
      }
      gpio_set_level(33,1); //r4
      {
      if(gpio_get_level(33) && gpio_get_level(16) == 1){printf("button * pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(17) == 1){printf("button 0 pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(5) == 1){printf("button # pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(18) == 1){printf("button D pressed!");}
      }
      gpio_set_level(27,0); gpio_set_level(26,0); gpio_set_level(25,0); gpio_set_level(33,0);
    }
    if(gpio_get_level(5) == 0) // column 3
    {
      gpio_set_level(27,1); //r1
      {
      if(gpio_get_level(27) && gpio_get_level(16) == 1){printf("button 1 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(17) == 1){printf("button 2 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(5) == 1){printf("button 3 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(18) == 1){printf("button A pressed!");}
      }
      gpio_set_level(26,1); //r2
      {
      if(gpio_get_level(26) && gpio_get_level(16) == 1){printf("button 4 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(17) == 1){printf("button 5 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(5) == 1){printf("button 6 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(18) == 1){printf("button B pressed!");}
      }
      gpio_set_level(25,1); //r3
      {
      if(gpio_get_level(25) && gpio_get_level(16) == 1){printf("button 7 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(17) == 1){printf("button 8 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(5) == 1){printf("button 9 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(18) == 1){printf("button C pressed!");}
      }
      gpio_set_level(33,1); //r4
      {
      if(gpio_get_level(33) && gpio_get_level(16) == 1){printf("button * pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(17) == 1){printf("button 0 pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(5) == 1){printf("button # pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(18) == 1){printf("button D pressed!");}
      }
      gpio_set_level(27,0); gpio_set_level(26,0); gpio_set_level(25,0); gpio_set_level(33,0);

    }
    if(gpio_get_level(18) == 0)  //column 4
    {  
      gpio_set_level(27,1); //r1
      {
      if(gpio_get_level(27) && gpio_get_level(16) == 1){printf("button 1 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(17) == 1){printf("button 2 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(5) == 1){printf("button 3 pressed!");}
      else if(gpio_get_level(27) && gpio_get_level(18) == 1){printf("button A pressed!");}
      }
      gpio_set_level(26,1); //r2
      {
      if(gpio_get_level(26) && gpio_get_level(16) == 1){printf("button 4 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(17) == 1){printf("button 5 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(5) == 1){printf("button 6 pressed!");}
      else if(gpio_get_level(26) && gpio_get_level(18) == 1){printf("button B pressed!");}
      }
      gpio_set_level(25,1); //r3
      {
      if(gpio_get_level(25) && gpio_get_level(16) == 1){printf("button 7 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(17) == 1){printf("button 8 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(5) == 1){printf("button 9 pressed!");}
      else if(gpio_get_level(25) && gpio_get_level(18) == 1){printf("button C pressed!");}
      }
      gpio_set_level(33,1); //r4
      {
      if(gpio_get_level(33) && gpio_get_level(16) == 1){printf("button * pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(17) == 1){printf("button 0 pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(5) == 1){printf("button # pressed!");}
      else if(gpio_get_level(33) && gpio_get_level(18) == 1){printf("button D pressed!");}
      }
      gpio_set_level(27,0); gpio_set_level(26,0); gpio_set_level(25,0); gpio_set_level(33,0);
    }
  }
}

