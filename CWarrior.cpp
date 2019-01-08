#include "CWarrior.h"

CWarrior::CWarrior(int p_hpMax, int p_dodge,int p_attack, int p_shield ,  CWeapon &p_weapon)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_dodge = p_dodge;
    m_attack = p_attack;
    m_shield = p_shield;
    m_weapon = (CSword*)&p_weapon;
}

CWarrior::CWarrior(int p_hpMax, int p_dodge,int p_attack, int p_shield)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_dodge = p_dodge;
    m_attack = p_attack;
    m_shield = p_shield;
    m_weapon = NULL;
}

CWarrior::~CWarrior()
{

}

void CWarrior::setSword(CSword* sword)
{
    m_weapon = sword;
}

void CWarrior::action()
{
    if (isAlive())
    {
    //list all possible action
    //wait for user input
    //do not enable sword use if broken
        if(!m_weapon->isBroken())
        {
            
        }
    }
    else 
    {
        
    }    
}

void CWarrior::armedAttack(CCharacter &p_ennemy)
{
    if (m_weapon == NULL)
    {
        std::cout << "Armed attack without sword, using fist" << std::endl;
        unarmedAttack(p_ennemy);
        return;
    }

    float dem;
    if(m_weapon->criticalStrike())
    {
        dem = 2*m_weapon->m_damage;
        dem = 0.75 * (dem + m_attack);
    }
    else
    {
        dem = m_weapon->m_damage;
        dem = 0.75 * (dem + m_attack);
    }
    m_weapon->use();
    p_ennemy.applyDamage(2*m_weapon->m_damage);
    //TODO Finish
    /*
    if weapon is broken 
    weapon durabilité--
    p_enney.applyDamage((m_attack+m_damage)*/
}

void CWarrior::unarmedAttack(CCharacter &p_ennemy)
{
    p_ennemy.applyDamage(0.66*m_attack);
}
void CWarrior::applyDamage(int p_damage)
{
    if (numberOfTurnDefended>0)
    {
        numberOfTurnDefended--;
        if (p_damage > (0.25 * m_shield))
        {
             m_hp = p_damage - (0.25 * m_shield); 
        }
    }
    else
    {
        m_hp -= p_damage;
        if(m_hp < 0)
            m_hp = 0;
    }
}