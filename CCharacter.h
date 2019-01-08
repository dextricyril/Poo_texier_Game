#ifndef CCHARACTER_H
#define CCHARACTER_H

#include "CWeapon.h"
#include <time.h>  
#include <stdlib.h>

class CCharacter 
{
    public:
        std::string m_name;
        int m_hpMax;
        int m_hp;
        float m_dodge;
        CWeapon* m_weapon;
        CCharacter();
        CCharacter(int p_hpMax, int p_dodge, CWeapon &p_weapon , std::string p_name);
        CCharacter(int p_hpMax, int p_dodge,  std::string p_name); // without weapon constructor
        virtual ~CCharacter();
        virtual void action();
        virtual void unarmedAttack(CCharacter &p_ennemy);
        virtual void armedAttack(CCharacter &p_ennemy);
        virtual void applyDamage(int p_damage);
        bool dodge();
        bool isAlive();
};
#endif