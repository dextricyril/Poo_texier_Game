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
        CCharacter(std::string p_name, int p_hpMax, float p_dodge, CWeapon &p_weapon );
        CCharacter(std::string p_name, int p_hpMax, float p_dodge); // without weapon constructor
        virtual ~CCharacter();
        virtual void action();
        virtual void unarmedAttack(CCharacter &p_ennemy);
        virtual void armedAttack(CCharacter &p_ennemy);
        virtual void applyDamage(int p_damage);
        virtual void setWeapon(CWeapon* weapon);
        virtual std::string getClass();
        virtual void displayStats();
        bool dodge();
        bool isAlive();
};
#endif