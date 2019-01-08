#ifndef CSWORD_H
#define CSWORD_H

#include "CWeapon.h"

class CSword : public CWeapon
{
    public :
        int m_durability;
        int m_durabilityMax;
        void use();
        bool isBroken();
        CSword(std::string p_nom, int p_damage,int p_bonus,int p_criticalStrike , int p_durability);
};


#endif