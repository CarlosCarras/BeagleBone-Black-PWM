CC= gcc
CCC= g++

CFLAGS= -Wall
CPPFLAGS= $(CFLAGS)


all: test

main.o: main.cpp
	$(CCC) $(CPPFLAGS) -c main.cpp -o main.o

voltage2pwm.o: voltage2pwm.h voltage2pwm.cpp
	$(CCC) $(CPPFLAGS) -c voltage2pwm.cpp -o voltage2pwm.o

PWM.o: PWM.h PWM.cpp
	$(CCC) $(CPPFLAGS) -c PWM.cpp -o PWM.o

test: PWM.o voltage2pwm.o main.o
	$(CCC) $(CPPFLAGS) -o test main.o Radio.o Interpreter.o Handler.o Packager.o UHF_Transceiver.o I2C_Functions.o lsquaredc.o


clean:
	rm -rf *.o test