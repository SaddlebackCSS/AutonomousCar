FLAGS=-c -pthread -lprussdrv -Wall -g

all: car

car: test fix_permissions

go:
	./test > output 2> bad_samples

.PHONY: fix_permissions

fix_permissions:
	./fix_permissions.sh

test: main.o ultrasonic.bin GPIO.o Motor.o Steering.o util.o PWM.o
	g++ main.o Motor.o Steering.o GPIO.o PWM.o util.o -lpthread -lprussdrv -g -o test

ultrasonic.bin: ultrasonic.p
	pasm -b ultrasonic.p
	
GPIO.o: GPIO.cpp
	g++ $(FLAGS) GPIO.cpp
	
PWM.o: PWM.cpp
	g++ $(FLAGS) PWM.cpp
	
util.o: util.cpp
	g++ $(FLAGS) util.cpp
	
Motor.o: Motor.cpp
	g++ $(FLAGS) Motor.cpp

Steering.o: Steering.cpp
	g++ $(FLAGS) Steering.cpp
	
main.o: main.cpp
	g++ $(FLAGS) main.cpp
	
clean:
	rm -fv *.o test ultrasonic.bin
