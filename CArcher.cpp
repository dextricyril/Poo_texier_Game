#include "CArcher.h"

CArcher::CArcher(std::string p_name, int p_hpMax, 
            float p_dodge,int p_agility, CWeapon &p_weapon)
{
    srand (time(NULL));
    m_name = p_name;
    m_weapon = (CBow*)&p_weapon;
    m_hpMax = p_hpMax + m_weapon->m_bonus;
    m_hp = p_hpMax + m_weapon->m_bonus;
    m_agility = p_agility;
} 

CArcher::CArcher(std::string p_name, int p_hpMax, 
            float p_dodge,int p_agility)
{
    srand (time(NULL));
    m_name = p_name;
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_agility = p_agility;
    m_weapon = NULL;
}

CArcher::~CArcher()
{

}

void CArcher::action(CCharacter &p_ennemy)
{
    int selectedNumber=0;
    while(selectedNumber<1 || selectedNumber > 3)
    {
        std::cout << std::endl;
        std::cout << "1 : Attack" << std::endl;
        std::cout << "2 : Shoot Arrow" << std::endl;
        std::cout << "3 : Take Aim" << std::endl;
        std::cout << std::endl;
        std::cin>>selectedNumber;
    }
    
    switch (selectedNumber)
    {
        case 1 : 
            this->unarmedAttack(p_ennemy);
            break;
        case 2 : 
           if(m_weapon != NULL)
            {
                if(m_weapon->haveArrow())
                {
                    this->armedAttack(p_ennemy);
                }
                else
                {
                    std::cout << "NO ARROW" << std::endl;
                    this->action(p_ennemy);
                }
            }
            else
            {
                std::cout << "NO WEAPON" << std::endl;
                this->action(p_ennemy);
            }
            break;
        case 3 : 
        if(m_weapon != NULL)
            {
                if(m_weapon->haveArrow())
                {
                    this->aim();
                }
                else
                {
                    std::cout << "NO ARROW" << std::endl;
                    this->action(p_ennemy);
                }
            }
            else
            {
                std::cout << "NO WEAPON" << std::endl;
                this->action(p_ennemy);
            }
            break;
            default:
                break;
    }
}

void CArcher::setWeapon(CWeapon* weapon)
{
    m_weapon = (CBow*)weapon;
    m_hpMax += m_weapon->m_bonus; 
    m_hp += m_weapon->m_bonus; 
}

void CArcher::unarmedAttack(CCharacter &p_ennemy)
{
    p_ennemy.applyDamage(0.50*m_agility);
}

void CArcher::armedAttack(CCharacter &p_ennemy)
{
    float dem;
    if(m_weapon->criticalStrike())
    {
        dem = m_agility * (1+(m_turnAimed*1.33));
        dem = 0.90 * (dem + 2 *m_weapon->m_damage); // twice weapon damage
        
    }
    else
    {
        dem = m_agility * (1 + (m_turnAimed*1.33));
        dem = 0.90 * (dem + m_weapon->m_damage);
    }
    p_ennemy.applyDamage(dem);
    m_weapon->shoot();
    m_turnAimed = 0;
}


void CArcher::aim()
{
    m_turnAimed++;
}

std::string CArcher::getClass()
{
    return "CArcher";
}

void CArcher::displayStats()
{
    if(m_weapon != NULL)
        std::cout  <<"Arrows left : " << m_weapon->m_nbArrow  
            <<" Turn aimed : " << this->m_turnAimed << std::endl;
    else
        std::cout  <<"No weapon" << std::endl;
}