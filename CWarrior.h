#ifndef CWARRIOR
#define CWARRIOR

#include "CCharacter.h"
#include "CSword.h"
class CWarrior : public CCharacter
{
    public : 
        CWarrior(std::string p_name, int p_hpMax, float p_dodge,int p_attack,int p_shield, CWeapon &p_weapon);
        CWarrior(std::string p_name, int p_hpMax, float p_dodge,int p_attack, int p_shield);
        ~CWarrior();
        int m_attack;
        int m_shield;
        int numberOfTurnDefended; // 0 means no shield defence
        CSword* m_weapon;
        void action(CCharacter &p_ennemy);
        void defend();
        void repair();
        void setWeapon(CWeapon* weapon);
        void unarmedAttack(CCharacter &p_ennemy);
        void armedAttack(CCharacter &p_ennemy);
        void displayStats();
        void applyDamage(int p_damage);
        std::string getClass();
};

#endif