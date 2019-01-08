g++ -Wall -c CGameSettings.cpp -o CGameSettings.o
g++ -Wall -c CWeapon.cpp -o CWeapon.o
g++ -Wall -c CCharacter.cpp -o  CCharacter.o
g++ -Wall -c main.cpp -o main.o
g++ *.o -o use
rm *.o
