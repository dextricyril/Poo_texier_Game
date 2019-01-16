#include "CWizard.h"

CWizard::CWizard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana, CWeapon &p_weapon)
{
    srand (time(NULL));
        m_name = p_name;
        m_intellect = p_intellect;
        m_mana = p_mana;
        m_weapon = (CStaff*)&p_weapon;
        m_hpMax = p_hpMax + m_weapon->m_bonus;
        m_hp = p_hpMax + m_weapon->m_bonus;
}

CWizard::CWizard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana)
{
    srand (time(NULL));
        m_name = p_name;
        m_hpMax = p_hpMax;
        m_hp = p_hpMax;
        m_intellect = p_intellect;
        m_mana = p_mana;
        m_weapon = NULL;
}

CWizard::~CWizard()
{

}

void CWizard::action()
{
    // check mana
}

void CWizard::setStaff(CStaff* p_staff)
{
    m_weapon = p_staff;
    m_hpMax += m_weapon->m_bonus; 
    m_hp += m_weapon->m_bonus; 
}


void CWizard::unarmedAttack(CCharacter &p_ennemy)
{
    p_ennemy.applyDamage(m_intellect/3);
}

void CWizard::armedAttack(CCharacter &p_ennemy)
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

void CWizard::recoverMana()
{
    int recovery = rand() % 5 + 2;
    m_mana += recovery;

}

std::string CWizard::getClass()
{
    return "CWizard";
}

void CWizard::displayStats()
{
    if(m_weapon != NULL)
    {
        std::cout << "Mana : " << this->m_mana << 
            " Mana cost : " << this->m_weapon->m_manaCost  << std::endl;
    }
    {
        std::cout << "Mana : " << this->m_mana << 
            " No weapon "  << std::endl;
    }
}