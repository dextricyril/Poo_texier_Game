#include "CGameSettings.h"


CGameSettings::~CGameSettings()
{

}



CGameSettings::CGameSettings(std::string p_characterFilePath, std::string p_weaponFilePath)
{

    m_characterFile.open(p_characterFilePath);
    m_weaponFile.open(p_weaponFilePath);

    std::string readLine;
    if(! (m_characterFile.is_open() && m_weaponFile.is_open()))
    {
        std::cerr << "files failed to open"<<std::endl;
        exit(1);
    }

    while ( getline (m_characterFile,readLine) ) 
    {
        if (!(readLine.at(0) == '\t')) // get classes from file
        {
            
            if (readLine.find("Archer") != std::string::npos) 
            {
                std::string name;
                int health,agility;
                float dodge;
                if( getline (m_characterFile,readLine) )
                    name = readLine.substr(1,readLine.size()); // remove tab
                if( getline (m_characterFile,readLine) )
                    health = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    dodge = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    agility = std::stoi(readLine);
                
                CCharacter* newPlayer = new CArcher(name,health,dodge,agility);
                character_list[newPlayer->m_name] = newPlayer;
            }

            if (readLine.find("Mage") != std::string::npos) 
            {
                std::string name;
                int health, intellect, mana;
                float dodge;
                if( getline(m_characterFile,readLine) )
                    name = readLine.substr(1,readLine.size()); // remove tab
                if( getline (m_characterFile,readLine) )
                    health = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    dodge = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    intellect = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    mana = std::stoi(readLine);
                CCharacter* newPlayer = new CWizard(name,health,dodge,intellect,mana);
                character_list[newPlayer->m_name] = newPlayer;
            }

            if (readLine.find("Guerrier") != std::string::npos) 
            {
                std::string name;
                int health, attack, shield;
                float dodge;
                if( getline (m_characterFile,readLine) )
                    name = readLine.substr(1,readLine.size());//readLine.substr(1,readLine.size());
                if( getline (m_characterFile,readLine) )
                    health = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    dodge = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    attack = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    shield = std::stoi(readLine);


                CCharacter* newPlayer = new CWarrior(name, health,dodge,attack,shield);
                character_list[newPlayer->m_name] = newPlayer; 
            }
        }
            
    }
    while ( getline (m_weaponFile,readLine) ) 
    {
        if (!(readLine.at(0) == '\t')) // get classes from file
        {
            if(readLine.find("Baton") != std::string::npos)
            {
                std::string name;
                int damage, bonus, critical, manaCost;
                if( getline (m_weaponFile,readLine) )
                    name = readLine.substr(1,readLine.size());
                if( getline (m_weaponFile,readLine) )
                    damage = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    bonus = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    critical = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    manaCost = std::stoi(readLine);
                CWeapon* newWeapon = new CStaff(name,damage,bonus,critical,manaCost);
                weapon_list[newWeapon->m_name] = newWeapon; 
            }
            if(readLine.find("Epee") != std::string::npos)
            {
                std::string name;
                int damage, bonus, critical, durabMax;
                if( getline (m_weaponFile,readLine) )
                    name = readLine.substr(1,readLine.size());
                if( getline (m_weaponFile,readLine) )
                    damage = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    bonus = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    critical = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    durabMax = std::stoi(readLine);
                CWeapon* newWeapon = new CSword(name,damage,bonus,critical,durabMax);
                weapon_list[newWeapon->m_name] = newWeapon; 
            }
            if(readLine.find("Arc") != std::string::npos)
            {
                std::string name;
                int damage, bonus, critical, arrow;
                if( getline (m_weaponFile,readLine) )
                    name = readLine.substr(1,readLine.size());
                if( getline (m_weaponFile,readLine) )
                    damage = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    bonus = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    critical = std::stoi(readLine);
                if( getline (m_weaponFile,readLine) )
                    arrow = std::stoi(readLine);
                CWeapon* newWeapon = new CBow(name,damage,bonus,critical,arrow);
                weapon_list[newWeapon->m_name] = newWeapon;
            }
        }
    }
    m_characterFile.close();
    m_weaponFile.close();
}

void CGameSettings::printCharacterList()
{
    for (const auto& x : character_list)
    {
        //std::cout <<  x.first   <<  "fisrt: " << std::endl;
        std::cout << "name: "  << x.second->m_name <<  std::endl;
        std::cout  << "health point: " <<x.second->m_hp << std::endl;
    }
}

void CGameSettings::printWeaponList()
{
    for (const auto& x : weapon_list)
    {
        //std::cout <<  x.first   <<  "fisrt: " << std::endl;
        std::cout << "Weapon name: "  << x.second->m_name <<  std::endl;
        std::cout  << "Damage point: " <<x.second->m_damage << std::endl;
        std::cout  << "Crit point: " <<x.second->m_criticalStrike << std::endl;
        std::cout  << "Bonus point: " <<x.second->m_bonus << std::endl;
        std::cout  << "Class: " <<x.second->getClass() << std::endl;
    }
}