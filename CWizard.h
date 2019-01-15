#ifndef CWIZZARD
#define CWIZZARD

#include "CCharacter.h"
#include "CStaff.h"

class CWizzard : public CCharacter
{
    public :
    CWizzard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana,CWeapon &p_weapon);
    CWizzard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana);
    ~CWizzard();
    int m_mana;
    int m_intellect;
    CStaff* m_weapon;
    void recoverMana();
    void action();
    void setStaff(CStaff* bow);
    void unarmedAttack(CCharacter &p_ennemy);
    void armedAttack(CCharacter &p_ennemy);
    std::string getClass();
    
};

#endif