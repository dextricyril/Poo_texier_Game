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
            std::cout << readLine <<std::endl;
            if (readLine.find("Archer") != std::string::npos) 
            {
                std::string name;
                int health,agility;
                float dodge;
                if( getline (m_characterFile,readLine) )
                    name = readLine.substr(1); // remove tab
                if( getline (m_characterFile,readLine) )
                    health = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    dodge = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    agility = std::stoi(readLine);
                //std::cout << " name is  " << name << std::endl;
                //std::cout << "  health is " << health << std::endl;
                
                
                CCharacter* newPlayer = new CArcher(name,health,dodge,agility);
                std::cout << "New archer " << newPlayer->m_name << std::endl;
                character_list[newPlayer->m_name] = newPlayer;
            }

            if (readLine.find("Mage") != std::string::npos) 
            {
                
            }
            if (readLine.find("Guerrier") != std::string::npos) 
            {
                std::string name;
                int health, attack, shield;
                float dodge;
                if( getline (m_characterFile,readLine) )
                    name = readLine;//readLine.substr(1,readLine.size());
                if( getline (m_characterFile,readLine) )
                    health = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    dodge = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    attack = std::stoi(readLine);
                if( getline (m_characterFile,readLine) )
                    shield = std::stoi(readLine);


                CCharacter* newPlayer = new CWarrior(name, health,dodge,attack,shield);
                std::cout << "BANANANNANA " << newPlayer->m_name << std::endl;
                character_list[newPlayer->m_name] = newPlayer; 
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
        std::cout  << x.second->m_name << "name:" <<  std::endl;
    }
}