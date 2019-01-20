#ifndef CGAME
#define CGAME

#include "CGameSettings.h"

#define whiteColor std::cout<<"\033[37;1m"
#define P1Color std::cout<<"\033[31;1m"
#define P2Color std::cout<<"\033[36m"

class CGame
{
    public:
        CCharacter *m_P1,*m_P2;
        CGameSettings* m_loadedSettings;
        CGame(CGameSettings &p_loadedSettings);
        ~CGame();
        void characterSelection();
        void display();
        void setWeapon(CCharacter* chara);
        void fight();
};
#endif