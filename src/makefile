FLAGS=-c -pthread -Wall -g

all: car

car: main.o GPIO.o Motor.o Steering.o util.o PWM.o
	g++ main.o Motor.o Steering.o GPIO.o PWM.o util.o -lpthread -g -o test
	
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
	rm *.o test
