#include "CStaff.h"

CStaff::CStaff(std::string p_nom, int p_damage,int p_bonus,
            int p_criticalStrike,int p_manaCost)
{
    m_nom = p_nom;
    m_damage = p_damage;
    m_bonus = p_bonus;
    m_criticalStrike = p_criticalStrike;
    m_manaCost = p_manaCost;
}