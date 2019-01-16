#ifndef CGAME
#define CGAME

#include "CGameSettings.h"

class CGame
{
    public:
        CCharacter *m_P1,*m_P2;
        CGameSettings* m_loadedSettings;
        CGame(CGameSettings &p_loadedSettings);
        ~CGame();
        void characterSelection();
        void display();
};
#endif