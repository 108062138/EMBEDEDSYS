default:
	avr-g++ -L C:\Users\USER\Desktop\arduino_build\arduino -I C:\Users\USER\Desktop\arduino_build\arduino -Wall -DF_CPU=16000000UL -Os -mmcu=atmega328p -o changeBright.exe changeBright.c -larduino
	avr-objcopy -O ihex -R .eeprom changeBright.exe changeBright.hex
upload:
	avrdude -c arduino -p m328p -b 57600 -P COM4 -U flash:w:changeBright.hex
all: 
	default upload
