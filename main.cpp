#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <util/delay.h>

#define __DELAY__ 200 //Menginisialsisasi Nilai Delay dengan 200

//Membuat Variable array activeLed[] dengan Tipe data Constant Char
const char activeLed[]={ 
	0x7F, // LED 0 Aktif nilai dalam bit 01111111
	0xBF, // LED 1 Aktif nilai dalam bit 10111111 
	0xDF, // LED 2 Aktif nilai dalam bit 11011111
	0xEF, // LED 3 Aktif nilai dalam bit 11101111 
	0xF7, // LED 4 Aktif nilai dalam bit 11110111 
	0xFB, // LED 5 Aktif nilai dalam bit 11111011
	0xFD, // LED 6 Aktif nilai dalam bit 11111101 
	0XFE  // LED 7 Aktif nilai dalam bit 11111110 
};

int main(void) {
	
	DDRD = 0xff; //Set DDRD  GPIO sebagai output
	DDRC = 0xFF; //Set DDRC  GPIO sebagai output
	
	while (1) {
		
		//Perulangan sebanyak 8 kali
		for (uint8_t i= 8 ; i>0;i--){ 
			
			PORTD = activeLed[i-1];	 // Mengakses array activeLed dari index belakang
			PORTC = ~activeLed[i-1];	 // Mengakses array activeLed dari index belakang, kemudian di Inverskan
			
			_delay_ms(__DELAY__);   // delay sebesar dari inisialisasi __delay__
		}

		
		//Perulangan sebanyak 8 kali
		for (uint8_t i=0; i< 8 ;i++){ 
			
			PORTD = activeLed[i];		// Mengakses array activeLed dari index depan
			PORTC = ~activeLed[i];	// Mengakses array activeLed dari index depan, kemudian di Inverskan
			
			_delay_ms(__DELAY__); // delay sebesar dari inisialisasi __delay__
			
		}
		
	}
}
