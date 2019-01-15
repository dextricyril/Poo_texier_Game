#ifndef CBow_H
#define CBow_H

#include "CWeapon.h"

class CBow : public CWeapon
{
    public:
        int m_nbArrow;
        void shoot();
        bool haveArrow();
        CBow(std::string p_name, int p_damage,int p_bonus,int p_criticalStrike,int p_nbArrow);
};


#endif