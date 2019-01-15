#include "CSword.h"

CSword::CSword(std::string p_name, int p_damage,int p_bonus,int p_criticalStrike , int p_durability)
{
    m_name = p_name;
    m_damage = p_damage;
    m_bonus = p_bonus;
    m_criticalStrike = p_criticalStrike;
    m_durabilityMax = p_durability;
    m_durability = p_durability; 
}

void CSword::use()
{
    if (!isBroken())
        m_durability--;
    else
        std::cout << "using broken sword" << std::endl;
}

bool CSword::isBroken()
{
    if(m_durability<1)
        return true;
    else 
        return false;
}

std::string CSword::getClass()
{
    return "CSword";
}