#include "CStaff.h"

CStaff::CStaff(std::string p_name, int p_damage,int p_bonus,
            int p_criticalStrike,int p_manaCost)
{
    m_name = p_name;
    m_damage = p_damage;
    m_bonus = p_bonus;
    m_criticalStrike = p_criticalStrike;
    m_manaCost = p_manaCost;
}

std::string CStaff::getClass()
{
    return "CStaff";
}