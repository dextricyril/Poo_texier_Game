#ifndef CARCHER
#define CARCHER

#include "CCharacter.h"
#include "CBow.h"
class CArcher : public CCharacter
{
    public : 
        CArcher(std::string p_name, int p_hpMax, float p_dodge,int p_agility, CWeapon &p_weapon);
        CArcher(std::string p_name, int p_hpMax, float p_dodge,int p_agility);
        ~CArcher();
        int m_agility;
        int m_turnAimed;
        CBow* m_weapon;
        void action(CCharacter &p_ennemy);
        void setBow(CBow* bow);
        void aim();
        void unarmedAttack(CCharacter &p_ennemy);
        void armedAttack(CCharacter &p_ennemy);
        void displayStats();
        void setWeapon(CWeapon* weapon);
        std::string getClass();
};

#endif