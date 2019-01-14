#include "CArcher.h"

CArcher::CArcher(std::string p_name, int p_hpMax, 
            float p_dodge,int p_agility, CWeapon &p_weapon)
{
    srand (time(NULL));
    m_name = p_name;
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_agility = p_agility;
    m_weapon = (CBow*)&p_weapon;
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

void CArcher::action()
{
    if(this->m_weapon->haveArrow())
    {
            
    }
}

void CArcher::setBow(CBow* bow)
{
    m_weapon = (CBow*)&bow;
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
        dem = m_agility * (m_turnAimed*1.33);
        dem = 0.90 * (dem + 2 *m_weapon->m_damage); // twice weapon damage
    }
    else
    {
        dem = m_agility * (m_turnAimed*1.33);
        dem = 0.90 * (dem + m_weapon->m_damage);
    }
    m_turnAimed = 0;
}


void CArcher::aim()
{
    m_turnAimed++;
}