#include <LiquidCrystal.h>    
#include <avr/io.h>
#include<avr/interrupt.h>    
#include <avr/delay.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = 0; 
const int buzzer=9;

void timer0_init(void);

void adc_init(void){
 ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));    //16Mhz/128 = 125Khz the ADC reference clock
 ADMUX |= (1<<REFS0);                //Voltage reference from Avcc (5v)
 ADCSRA |= (1<<ADEN);                //Turn on ADC
 ADCSRA |= (1<<ADSC);                //Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}
 
uint16_t read_adc(uint8_t channel){
 ADMUX &= 0xF0;                    //Clear the older channel that was read
 ADMUX |= channel;                //Defines the new ADC channel to be read
 ADCSRA |= (1<<ADSC);                //Starts a new conversion
 while(ADCSRA & (1<<ADSC));            //Wait until the conversion is done
 return ADCW;                    //Returns the ADC value of the chosen channel
}

void timer0_init(void){
  DDRB |= (1<<PB1);
TCCR0A |= ((1<<COM0A1)|(1<<WGM01)|(1<<WGM00));    //Enable pwm mode in pin PD6 and set the WGM bits to Fast pwm mode
TCCR0B |= ((1<<CS01)|(1<<CS00));                  //Set prescaler to 32
}
void setup()
{

  DDRB |= (1<<PB1);
  timer0_init();
  sei();
  adc_init();
  DDRB |= (1<<PB1);
  lcd.begin(16,2);
}

void init_PWM2(){
DDRB |= 1<<PB1;
  TCCR1B=0b00000011;
}

void loop()
{
  int value = read_adc(inPin); // read the value from the sensor
  lcd.setCursor(0,1);
  float millivolts = (value / 1024.0) * 5; 
  float celsius = (millivolts-0.5)*100;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print((celsius * 9)/5 + 32); //turning the celsius into fahrehait
  lcd.print("F");
  delay(1000);
  if(celsius>30.0){//PORTB |=(1<<PB1);init_PWM2();
    tone(buzzer,1000);delay(250);noTone(buzzer);}//else PORTB&=~(1<<PB1);
}
