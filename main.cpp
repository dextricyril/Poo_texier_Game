#include "CGameSettings.h"

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        std::cerr << "Not the right amount of file provided" << std::endl; 
        return -1;
    }
    
    std::string fileCharacter = argv[1];
    std::string fileWeapon = argv[2];
    std::cout << "  Fichier 1 :   " << fileCharacter << "   Fichier 2 :   " << fileWeapon << std::endl;;

    CGameSettings(fileCharacter, fileWeapon);
    
}