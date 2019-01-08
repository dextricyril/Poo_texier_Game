#ifndef CWEAPON_H
#define CWEAPON_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

class CWeapon
{
    protected:
        int m_damage;
        int m_bonus;
        int m_criticalStrike;
        std::string m_nom;

    public:
        CWeapon();
        CWeapon(std::string p_nom, int p_damage,int p_bonus,int p_criticalStrike);
        virtual ~CWeapon();
        bool criticalStrike();

};

#endif
