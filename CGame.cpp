#include "CGame.h"

CGame::CGame(CGameSettings &p_loadedSettings)
{
    m_loadedSettings= &p_loadedSettings;
}

void  CGame::characterSelection()
{
    std::map<int, CCharacter*> character_list;
    int number = 1;

    std::cout << "list of characters :" << std::endl;
    for (const auto& charaEntry : m_loadedSettings->character_list)
    {
        
        CCharacter*  currChara = charaEntry.second;

        character_list[number] = currChara;


        if(currChara->getClass()=="CWarrior")
        {
            CWarrior* warrior = (CWarrior*)currChara;
            std::cout << number <<". WARRIOR name: "  << warrior->m_name << std::endl;
            std::cout <<   "health point: " << warrior->m_hpMax <<
                " dodge: " << warrior->m_dodge <<
                " attack: " << warrior->m_attack << " shield: " << 
                warrior->m_shield << std::endl;
        }
        else if (currChara->getClass()=="CArcher")
        {
            CArcher* archer = (CArcher*)currChara;
            std::cout << number <<". ARCHER name: "  << archer->m_name << std::endl;
            std::cout <<   "health point: " << archer->m_hpMax <<
                " dodge: " << archer->m_dodge <<
                " attack: " << archer->m_agility << std::endl;
        }
        else if (currChara->getClass()=="CWizard")
        {
            CWizard* wizard = (CWizard*)currChara;
            std::cout << number <<". Wizard name: "  << wizard->m_name << std::endl;
            std::cout <<   "health point: " << wizard->m_hpMax <<
                " dodge: " << wizard->m_dodge <<
                " attack: " << wizard->m_intellect << std::endl;
        }

        std::cout << std::endl; // jump line at end of description
        number++;
        //std::cout <<  x.first   <<  "fisrt: " << std::endl;
    }

    
    int selectedNumber=0;
    while(selectedNumber<1 || selectedNumber > number)
    {
        std::cout << "Choose P1 character: ";
        std::cin>>selectedNumber;
        std::cout << std::endl;
    }
    m_P1 = character_list[selectedNumber];
    selectedNumber=0;

    while(selectedNumber<1 || selectedNumber > number)
    {
        std::cout << "Choose P2 character: ";
        std::cin>>selectedNumber;
        std::cout << std::endl;
    }
    m_P2 = character_list[selectedNumber];
    
    std::cout << std::endl;

    std::cout << "You have picked : " << m_P1->m_name << std::endl
    << " class " << m_P1->getClass();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void displayPlayerStat(std::string player,CCharacter* chara)
{
    std::cout << player << " "<< chara-> m_name << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "HP / HPmax  " << chara->m_hp << "/" << chara->m_hpMax << std::endl;
    chara->displayStats();
    std::cout << "---------------------------------------------------------------------------------------------------------" << std::endl;
 
}

void CGame::display() //TODO
{
    displayPlayerStat("P1", m_P1);
    displayPlayerStat("P2", m_P2);
}