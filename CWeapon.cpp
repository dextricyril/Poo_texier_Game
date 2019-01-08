#include "CWeapon.h"

CWeapon::CWeapon() 
{
    this->m_nom="fist";
    this->m_bonus=0;
    this->m_damage=5;
    this->m_criticalStrike=0;
}

CWeapon::CWeapon(std::string p_nom, int p_damage,int p_bonus,int p_criticalStrike)
{
    this->m_nom=p_nom;
    this->m_bonus=p_bonus;
    this->m_damage=p_damage;
    this->m_criticalStrike=p_criticalStrike;
}

CWeapon::~CWeapon()
{

}

bool CWeapon::criticalStrike()
{
    std::srand(std::time(nullptr)); // ready random generator
    int attack = std::rand() % 101;
    if (attack >= m_criticalStrike)
        return true;
    else
        return false;
}