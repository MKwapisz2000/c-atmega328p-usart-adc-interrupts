//Użycie interfejsu USART do odczytu wartości z potencjometru wyzwalanego automatycznie przez przerwannia zewnętrzne

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

//......................................................... USART .................................................................
void USART_init()
{
  UBRR0H = (unsigned char)(103>>8);
  UBRR0L = (unsigned char)103;
    
  //Adres we/wy rejestrów danych nadawczych USART i rejestry odbierania danych USART
  //UDR0

  //By bufor transmisji mógłbyć zapisany
  UCSR0A |= (1<<UDRE0);

  //Włączenie odbiornika
  UCSR0B |= (1<<RXEN0);

  //Włączenie nadajnika
  UCSR0B |= (1<<TXEN0);

  //Liczba bitów danych w ramce
  UCSR0C |= (1<<UCSZ00);
  UCSR0C |= (1<<UCSZ01);
}


void USART_Transmit( unsigned char data )
 {
 /* Wait for empty transmit buffer */
 while ( !( UCSR0A & (1<<UDRE0)) )
 ;
 /* Put data into buffer, sends the data */
 UDR0 = data;
 }

unsigned char USART_Receive()
 {
 /* Wait for data to be received */
 while ( !(UCSR0A & (1<<RXC0)) )
 ;
 /* Get and return received data from buffer */
 return UDR0;
 }

void USART_String(const char *array)
{
  int i=0;
  while(array[i]!='\0')
  {
    USART_Transmit(array[i]);
    i++;
  }
}


//........................................................... ADC .................................................................
void ADC_init()
{
  //zasilanie
  ADMUX |= (1<<REFS0);
  ADMUX &= ~(1<<REFS1);

  //division factor
  ADCSRA |= (1<<ADPS0);
  ADCSRA |= (1<<ADPS1);
  ADCSRA |= (1<<ADPS2);

  //kanał
  ADMUX &= ~(1<<MUX0);
  ADMUX &= ~(1<<MUX1);
  ADMUX &= ~(1<<MUX2);
  ADMUX &= ~(1<<MUX3);
  
  //włączenie przerwan
  ADCSRA |= (1<<ADIE);

  //auto trigger
  ADCSRA |= (1<<ADATE);

  //wybranie trybu przerwań - na external
  ADCSRB |= (1<<ADTS1);
  
  //włączenie ADC
  ADCSRA |= (1<<ADEN);  
}


//........................................................ INTERRUPTS .............................................................
void ExternalInterupts_init()
{
  //failling edge
  EICRA |= (1<<ISC01);
  EIMSK |= (1<<INT0);

  //wlaczenie przerwań 
  sei();
}

ISR(ADC_vect)
{
  int resultA0 = ADC;
  float napiecieA0 = resultA0*5.0/1023.0;
  char str_wynik[20];
  char str_napiecie1[20];
  char str_napiecie2[20];

  sprintf(str_wynik, "wynik: %d", resultA0);
  dtostrf(napiecieA0, 5, 2, str_napiecie1);
  sprintf(str_napiecie2, "napiecie: %sV", str_napiecie1);
    
  USART_String(str_wynik);
  USART_String("  ");
  USART_String(str_napiecie2);
  USART_String("\n");
  _delay_ms(20);
    
    if(napiecieA0 > 1.0)
    {
      PORTD |= (1<<PD5);
    }
    else
    {
      PORTD &= ~(1<<PD5);
    }
   
    if(napiecieA0 > 2.5)
    {
      PORTD |= (1<<PD3);
    }
    else
    {
      PORTD &= ~(1<<PD3);
    }
   
    if(napiecieA0 > 4.0)
    {
      PORTD |= (1<<PD4);
    }
    else
    {
      PORTD &= ~(1<<PD4);
    }

}

//.......................................................... MAIN .................................................................
int main()
{
  //Diody
  DDRD |= (1<<PD5);
  DDRD |= (1<<PD3);
  DDRD |= (1<<PD4);

  PORTD &= ~(1<<PD5);
  PORTD &= ~(1<<PD3);
  PORTD &= ~(1<<PD4);

  //Switch - pull up
  DDRD &= ~(1<<PD2);
  PORTD |= (1<<PD2);


  USART_init();
  ADC_init();
  ExternalInterupts_init();
  
  while(1)
  {}

  return 0;
}
