#include "CGameSettings.h"
#include "CGame.h"
#include "locale.h"

int main(int argc, char ** argv)
{
    std::setlocale(LC_CTYPE, "fr_FR.UTF-8");
    if(argc != 3)
    {
        std::cerr << "Not the right amount of file provided" << std::endl; 
        std::cerr << "USAGE : use CharacterFile WeaponFile" << std::endl; 
        return -1;
    }
    
    std::string fileCharacter = argv[1];
    std::string fileWeapon = argv[2];
    std::cout << "File 1 :   " << fileCharacter << "   File 2 :   " << fileWeapon << std::endl;;

    CGameSettings* setting = new  CGameSettings(fileCharacter, fileWeapon);
    CGame* game = new CGame(*setting);
    game->characterSelection();
    game->fight();
}

