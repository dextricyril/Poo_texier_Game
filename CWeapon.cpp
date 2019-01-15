#include "CWeapon.h"

CWeapon::CWeapon() 
{
    std::srand(std::time(nullptr)); // ready random generator
    this->m_name="fist";
    this->m_bonus=0;
    this->m_damage=5;
    this->m_criticalStrike=0;
}

CWeapon::CWeapon(std::string p_name, int p_damage,int p_bonus,int p_criticalStrike)
{
    std::srand(std::time(nullptr)); // ready random generator
    this->m_name=p_name;
    this->m_bonus=p_bonus;
    this->m_damage=p_damage;
    this->m_criticalStrike=p_criticalStrike;
}

CWeapon::~CWeapon()
{

}

bool CWeapon::criticalStrike()
{
    int attack = std::rand() % 101;
    if (attack >= m_criticalStrike)
        return true;
    else
        return false;
}