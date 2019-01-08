#include "CCharacter.h"

CCharacter::CCharacter()
{
    m_hpMax = 100;
    m_hp = m_hpMax;
    m_dodge = 0;
    m_weapon = new CWeapon();;
    m_name = "DefaultDan";
}

CCharacter::CCharacter(int p_hpMax, int p_dodge, CWeapon &p_weapon, std::string p_name)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_dodge = p_dodge;
    m_weapon = &p_weapon;
    m_name = p_name;
}

CCharacter::CCharacter(int p_hpMax, int p_dodge,  std::string p_name)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_dodge = p_dodge;
    m_weapon = NULL;
    m_name = p_name;
}


CCharacter::~CCharacter()
{
    
}

void CCharacter::applyDamage(int p_damage)
{
    m_hp -= p_damage;
    if(m_hp < 0)
        m_hp = 0;
}

bool CCharacter::isAlive()
{
    return (m_hp > 0);
}

bool CCharacter::dodge()
{
    int dice = rand() % 100 + 1;
    return (m_dodge*100 > dice);
}

void CCharacter::action()
{
    std::cout << " Call to  CCharacter::action  not defined"  << std::endl;
}

void CCharacter::armedAttack(CCharacter &p_ennemy)
{
    std::cout << " Call to  CCharacter::armedAttack  not defined"  << std::endl;
}


void CCharacter::unarmedAttack(CCharacter &p_ennemy)
{
    std::cout << " Call to  CCharacter::unarmedAttack  not defined"  << std::endl;
}