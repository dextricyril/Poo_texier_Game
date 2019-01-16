#ifndef CWIZARD
#define CWIZARD

#include "CCharacter.h"
#include "CStaff.h"

class CWizard : public CCharacter
{
    public :
    CWizard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana,CWeapon &p_weapon);
    CWizard(std::string p_name, int p_hpMax, float p_dodge,int p_intellect, int p_mana);
    ~CWizard();
    int m_mana;
    int m_intellect;
    CStaff* m_weapon;
    void recoverMana();
    void action();
    void setWeapon(CWeapon* weapon);
    void unarmedAttack(CCharacter &p_ennemy);
    void armedAttack(CCharacter &p_ennemy);
    void displayStats();
    std::string getClass();
    
};

#endif