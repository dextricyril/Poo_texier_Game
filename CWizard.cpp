#include "CWizard.h"

CWizzard::CWizzard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana, CWeapon &p_weapon)
{
    srand (time(NULL));
        m_name = p_name;
        m_hpMax = p_hpMax;
        m_hp = p_hpMax;
        m_intellect = p_intellect;
        m_mana = p_mana;
        m_weapon = (CStaff*)&p_weapon;
}

CWizzard::CWizzard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana)
{
    srand (time(NULL));
        m_name = p_name;
        m_hpMax = p_hpMax;
        m_hp = p_hpMax;
        m_intellect = p_intellect;
        m_mana = p_mana;
        m_weapon = NULL;
}

CWizzard::~CWizzard()
{

}

void CWizzard::action()
{
    // check mana
}

void CWizzard::setStaff(CStaff* p_staff)
{
    m_weapon = p_staff;
}


void CWizzard::unarmedAttack(CCharacter &p_ennemy)
{
    p_ennemy.applyDamage(m_intellect/3);
}

void CWizzard::armedAttack(CCharacter &p_ennemy)
{
    if(m_weapon->criticalStrike())
    {
        p_ennemy.applyDamage((m_intellect + (2*m_weapon->m_damage) + 0.5* m_weapon->m_manaCost)*1.10);
    }
    else
    {
        p_ennemy.applyDamage((m_intellect + m_weapon->m_damage + 0.5* m_weapon->m_manaCost)*1.10);
    }
    m_mana -=  m_weapon->m_manaCost;
}

void CWizzard::recoverMana()
{
    int recovery = rand() % 5 + 2;
    m_mana += recovery;

}
