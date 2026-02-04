# STM32 Smart Fan Controller

Inteligentny sterownik wentylatora oparty na mikrokontrolerze STM32. System reguluje prędkość obrotową wentylatora (PWM) w zależności od temperatury, z obsługą wyświetlacza OLED oraz sterowaniem przez UART.

##  Główne funkcjonalności
* Automatyczna regulacja: Płynna zmiana prędkości wentylatora w oparciu o odczyty temperatury.
* System Fail-Safe: Aktywny system bezpieczeństwa – w przypadku awarii czujnika (odczyt < 5°C lub > 95°C) wentylator wchodzi w tryb awaryjny, zapobiegając przegrzaniu.
* Tryb Manualny: Możliwość ręcznego sterowania prędkością obrotową poprzez komendy UART.
* Interfejs: Wyświetlanie aktualnej temperatury, oraz statusu systemu na ekranie OLED.
* Architektura: Kod napisany z podziałem na warstwy, Każdy moduł można wykorzystywać w kolejnych projektach wprowadzając drobne zmiany.

##  Jak to działa?
1.  System startuje w trybie AUTO
2.  Czujnik temperatury na bieżąco wysyła dane do ADC które są przetwarzane przez DMA i zamieniane na temperaturę.
3.  Jeśli temperatura przekroczy zdefiniowane progi bezpieczeństwa, aktywowany jest tryb ERROR.
4.  Po wpisaniu wartości z jaką ma obracać się wentylator (zakres od 1 do 1000) w terminalu UART, następuje przerwanie które zmienia tryb systemu na MANUAL(Każda wpisana wartość musi być potwierdzona ENTEREM)
5.  Gdy chcemy powrócić do trybu AUTO należy wpisać wartość 0.

 ## 🛠 Użyte technologie i sprzęt
* Mikrokontroler: NUCLEO-F411RE
* Język: C
* IDE: STM32CubeIDE
* CubeMX
* Peryferia:
    * ADC + DMA (pomiar temperatury)
    * Timer PWM (sterowanie silnikiem)
    * I2C (obsługa OLED)
    * UART (komunikacja z PC)
