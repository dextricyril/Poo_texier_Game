#ifndef CARCHER
#define CARCHER

#include "CCharacter.h"
#include "CBow.h"
class CArcher : public CCharacter
{
    public : 
        CArcher(std::string p_name, int p_hpMax, float p_dodge,int m_agility, CWeapon &p_weapon);
        CArcher(std::string p_name, int p_hpMax, float p_dodge,int m_agility);
        ~CArcher();
        int m_agility;
        int m_turnAimed;
        CBow* m_weapon;
        void action();
        void setBow(CBow* bow);
        void aim();
        void unarmedAttack(CCharacter &p_ennemy);
        void armedAttack(CCharacter &p_ennemy);
};

#endif