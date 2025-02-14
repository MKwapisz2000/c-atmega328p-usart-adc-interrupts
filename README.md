# c-atmega328p-usart-adc-interrupts

**Project Description - English**

This project demonstrates automatic ADC value transmission via USART in an ATmega328P microcontroller, using external and internal interrupts. When the button is pressed, an INT0 interrupt triggers an ADC conversion. The measured voltage value is sent via USART and used to control LEDs based on voltage levels.

Features:

- USART initialization for serial communication

- ADC with interrupts – automatic reading triggered by INT0

- Voltage conversion from a potentiometer and data transmission via USART

- LED control based on voltage level

- Using ATmega328P microcontroller in pure C

Hardware Requirements:

- ATmega328P microcontroller (e.g., Arduino Nano or standalone AVR)

- Potentiometer connected to A0 (or other analog sensor)

- Button connected to INT0 (PD2)

- LEDs connected to PD3, PD4, PD5

- Connecting wires

Usage Instructions:

- Compile the code in an AVR C-compatible environment (e.g., Atmel Studio, PlatformIO, AVR-GCC).

- Connect the potentiometer, LEDs, and button according to the schematic.

- Upload the program to the microcontroller using an ISP programmer.

- Open a serial terminal (e.g., PuTTY, Tera Term) at 9600 baud.

- Press the INT0 button – the ADC value will be sent to the terminal and LEDs will light up accordingly.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Opis projektu - Polski**

Ten projekt demonstruje automatyczne przesyłanie wartości ADC przez interfejs USART w mikrokontrolerze ATmega328P, wykorzystując przerwania zewnętrzne i wewnętrzne. Po naciśnięciu przycisku wyzwalane jest przerwanie INT0, które uruchamia konwersję ADC. Odczytana wartość napięcia jest wysyłana przez USART oraz wykorzystywana do sterowania diodami LED w zależności od poziomu napięcia.

Funkcjonalność:

- Inicjalizacja interfejsu USART do komunikacji szeregowej

- ADC z przerwaniami – automatyczny odczyt po wyzwoleniu INT0

- Konwersja napięcia z potencjometru i przesyłanie wyników przez USART

- Sterowanie diodami LED w zależności od napięcia

- Obsługa mikrokontrolera ATmega328P w czystym C

Wymagania sprzętowe:

- Mikrokontroler ATmega328P (np. Arduino Nano lub standalone AVR)

- Potencjometr podłączony do A0 (lub inny czujnik analogowy)

- Przycisk podłączony do INT0 (PD2)

- Diody LED podłączone do PD3, PD4, PD5

- Przewody połączeniowe

Instrukcja użytkowania:

- Skompiluj kod w środowisku obsługującym AVR C (np. Atmel Studio, PlatformIO, AVR-GCC).

- Podłącz potencjometr, diody LED i przycisk zgodnie ze schematem.

- Wgraj program do mikrokontrolera za pomocą programatora ISP.

- Podłącz terminal szeregowy (np. PuTTY, Tera Term) do USART (9600 baud).

- Naciśnij przycisk INT0 – wartość ADC zostanie wysłana do terminala i odpowiednio zapali diody LED.



