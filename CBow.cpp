#include "CBow.h"

CBow::CBow(std::string p_name, int p_damage,int p_bonus,int p_criticalStrike,int p_nbArrow)
{
    m_name = p_name;
    m_damage = p_damage;
    m_bonus = p_bonus;
    m_criticalStrike = p_criticalStrike;
    m_nbArrow = p_nbArrow;
}

void CBow::shoot()
{
    if (haveArrow())
        m_nbArrow--;
}

bool CBow::haveArrow()
{
    if(m_nbArrow>0)
        return true;
    else 
        return false;
}
std::string CBow::getClass()
{
    return "CBow";
}