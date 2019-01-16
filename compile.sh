g++ -Wall -c CGameSettings.cpp -o CGameSettings.o
g++ -Wall -c CWeapon.cpp -o CWeapon.o
g++ -Wall -c CCharacter.cpp -o  CCharacter.o
g++ -Wall -c CWarrior.cpp -o CWarrior.o
g++ -Wall -c CArcher.cpp -o CArcher.o
g++ -Wall -c CWizard.cpp -o CWizard.o
g++ -Wall -c CStaff.cpp -o CStaff.o
g++ -Wall -c CSword.cpp -o CSword.o
g++ -Wall -c CBow.cpp -o CBow.o
g++ -Wall -c CGame.cpp -o CGame.o
g++ -Wall -c main.cpp -o main.o
g++ *.o -o use
rm *.o
