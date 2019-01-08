#include "CWarrior.h"

CWarrior::CWarrior()(int p_hpMax, int p_dodge, CWeapon &p_weapon)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_hpMax = p_hpMax;
    m_dodge = p_dodge;
    m_weapon = &p_weapon;
}

CWarrior::~CWarrior()
{

}

CWarrior::action()
{
    if (isAlive())
    {
    //list all possible action
    //wait for user input
    }
    else {}    
}

CWarrior::armedAttack(CCharacter p_ennemy)
{
    //TODO Finish
    if weapon is broken 
    weapon durabilité--
    p_enney.applyDamage((m_attack+m_damage)
}