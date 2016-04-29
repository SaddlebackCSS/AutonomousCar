CFLAGS=-c -Wall -g

all: car

car: main.o GPIO.o Motor.o util.o PWM.o
	g++ main.o GPIO.o PWM.o util.o -pthread -o test
	
main.o: main.cpp
	g++ $(CFLAGS) main.cpp

Motor.o: Motor.cpp
	g++ $(CFLAGS) Motor.cpp
	
GPIO.o: GPIO.cpp
	g++ $(CFLAGS) GPIO.cpp
	
PWM.o: PWM.cpp
	g++ $(CFLAGS) PWM.cpp
	
util.o: util.cpp
	g++ $(CFLAGS) util.cpp
	
clean:
	rm *.o test
