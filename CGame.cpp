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


        if(currChara->getClass()=="CWarrior") //TODO change that into a ccharacter display method
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
    while(selectedNumber<1 || selectedNumber > number-1)
    {
        std::cout << "Choose P1 character: ";
        std::cin>>selectedNumber;
        std::cout << std::endl;
    }
    m_P1 = character_list[selectedNumber];
    selectedNumber=0;

    while(selectedNumber<1 || selectedNumber > number-1)
    {
        std::cout << "Choose P2 character: ";
        std::cin>>selectedNumber;
        std::cout << std::endl;
    }
    m_P2 = character_list[selectedNumber];
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    setWeapon(m_P1);
    std::cout << std::endl;
    std::cout << std::endl;
    setWeapon(m_P2);
    std::cout << std::endl;
    std::cout << std::endl;
}

void CGame::setWeapon(CCharacter* chara) // Open a weapon selection menu for the chara 
{
    std::string pClass = chara->getClass();
    std::map<int, CWeapon*> weapons;
    int index=1;
    for (const auto& weapEntry : m_loadedSettings->weapon_list)
    {
        CWeapon*  currWeap = weapEntry.second;
        currWeap->printWeaponStat();
        if(pClass == "CWarrior" && currWeap->getClass()== "CSword")
        {
            std::cout << index <<": "<< currWeap->m_name << std::endl;
            weapons[index] = currWeap;
            index++;
        }
        else if (pClass == "CArcher" && currWeap->getClass()== "CBow")
        {
            std::cout << index <<": "<< currWeap->m_name << std::endl;
            weapons[index] = currWeap;
            index++;
        }
        else if (pClass == "CWizard" && currWeap->getClass()== "CStaff")
        {
            std::cout << index <<": "<< currWeap->m_name << std::endl;
            weapons[index] = currWeap;
            index++;
        }
    }
    std::cout << index <<": unarmed" << std::endl;

    int selectedNumber=0;
    while(selectedNumber<1 || selectedNumber > index)
    {
        std::cout << "Choose weapon: ";
        std::cin>>selectedNumber;
        std::cout << std::endl;
    }
    if(selectedNumber != index)
    {
        chara->setWeapon(weapons[selectedNumber]);
    }
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
    std::cout << std::endl;
    std::cout << std::endl;
    displayPlayerStat("P2", m_P2);
    std::cout << std::endl;
    std::cout << std::endl;
}