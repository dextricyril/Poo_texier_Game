#ifndef CWARRIOR
#define CWARRIOR

#include "CCharacter.h"
#include "CSword.h"
class CWarrior : public CCharacter
{
    public : 
        CWarrior(int p_hpMax, int p_dodge, CWeapon &p_weapon);
        ~CWarrior();
        int m_attack;
        int m_shield;
        int numberOfTurnDefended; // 0 means no shield defence
        CSword* m_weapon;
        void action();
        void defend();
        void repair();
        void unarmedAttack(CCharacter &p_ennemy);
        void armedAttack(CCharacter &p_ennemy);
        void applyDamage(int p_damage);
};

#endif