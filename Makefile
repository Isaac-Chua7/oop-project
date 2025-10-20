CXXFLAGS = -Wall -std=c++11

runProgram: GameCharacter.o GameManager.o Coordinate.o Attacker.o Attacker1.o Attacker2.o Attacker3.o Defender.o Defender1.o Defender2.o Defender3.o main.o Projectile.o
	g++ GameCharacter.o GameManager.o Coordinate.o Attacker.o Attacker1.o Attacker2.o Attacker3.o Defender.o Defender1.o Defender2.o Defender3.o main.o Projectile.o -o runProgram

main.o: main.cpp
	g++ -c main.cpp

GameCharacter.o: GameCharacter.cpp GameCharacter.h
	g++ -c GameCharacter.cpp	

GameManager.o: GameManager.cpp GameManager.h
	g++ -c GameManager.cpp	

Coordinate.o: Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp

Defender.o: Defender.cpp Defender.h
	g++ -c Defender.cpp

Defender1.o: Defender1.cpp Defender1.h
	g++ -c Defender1.cpp

Defender2.o: Defender2.cpp Defender2.h
	g++ -c Defender2.cpp

Defender3.o: Defender3.cpp Defender3.h
	g++ -c Defender3.cpp

Attacker.o: Attacker.cpp Attacker.h
	g++ -c Attacker.cpp

Attacker1.o: Attacker1.cpp Attacker1.h
	g++ -c Attacker1.cpp

Attacker2.o: Attacker2.cpp Attacker2.h
	g++ -c Attacker2.cpp

Attacker3.o: Attacker3.cpp Attacker3.h
	g++ -c Attacker3.cpp

Projectile.o: Projectile.cpp Projectile.h
	g++ -c Projectile.cpp	

clean:
	rm *.o runProgram