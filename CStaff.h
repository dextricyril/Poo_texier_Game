#ifndef CSTAFF_H
#define CSTAFF_H

#include "CWeapon.h"

class CStaff : public CWeapon
{
    public :
        int m_manaCost;
        CStaff(std::string p_nom, int p_damage,int p_bonus,
        float p_criticalStrike,int p_manaCost);

};

#endif