#include "CGameSettings.h"
#include "locale.h"

int main(int argc, char ** argv)
{
    std::setlocale(LC_CTYPE, "fr_FR.UTF-8");
    if(argc != 3)
    {
        std::cerr << "Not the right amount of file provided" << std::endl; 
        return -1;
    }
    
    std::string fileCharacter = argv[1];
    std::string fileWeapon = argv[2];
    std::cout << "  Fichier 1 :   " << fileCharacter << "   Fichier 2 :   " << fileWeapon << std::endl;;

    CGameSettings* setting = new  CGameSettings(fileCharacter, fileWeapon);
    setting->printCharacterList();
    setting->printWeaponList();
}