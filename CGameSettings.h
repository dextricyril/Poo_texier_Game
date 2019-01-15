#ifndef CGAMESETTINGS_H
#define CGAMESETTINGS_H

#include <map>
#include <vector>
#include <fstream>
#include "CWeapon.h"
#include "CCharacter.h"
#include "CWarrior.h"
#include "CArcher.h"
#include "CWizard.h"
#include "CBow.h"
#include "CStaff.h"
#include "CSword.h"

class CGameSettings
{
    std::ifstream m_weaponFile;
    std::ifstream m_characterFile;

    public:
        std::map<std::string, CWeapon*> weapon_list;

        std::map<std::string, CCharacter*> character_list;
        
        CGameSettings(std::string p_characterFilePath, std::string p_weaponFilePath);
        ~CGameSettings();
        void printCharacterList();
        void printWeaponList();
};

#endif
