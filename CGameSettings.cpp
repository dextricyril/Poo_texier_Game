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
                int health;
                if( getline (m_characterFile,readLine) )
                    name = readLine.substr(1,readLine.size()); // remove tab
                if( getline (m_characterFile,readLine) )
                    health = std::stoi(readLine);
                std::cout << " name is  " << name << std::endl;
                std::cout << "  health is " << health << std::endl;
            }

            if (readLine.find("Mage") != std::string::npos) 
            {
                
            }
            if (readLine.find("Guerrier") != std::string::npos) 
            {
                
            }
        }
            
    }
    m_characterFile.close();
    m_weaponFile.close();
}
