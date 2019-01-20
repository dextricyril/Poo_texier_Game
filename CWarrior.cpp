#include "CWarrior.h"

CWarrior::CWarrior(std::string p_name, int p_hpMax, float p_dodge,int p_attack, int p_shield ,  CWeapon &p_weapon)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_name = p_name;
    m_dodge = p_dodge;
    m_attack = p_attack;
    m_shield = p_shield;
    m_weapon = (CSword*)&p_weapon;
    m_hpMax = p_hpMax + m_weapon->m_bonus;
    m_hp = p_hpMax + m_weapon->m_bonus; 
}

CWarrior::CWarrior(std::string p_name, int p_hpMax, float p_dodge,int p_attack, int p_shield)
{
    /* initialize random seed: */
    srand (time(NULL));
    m_name = p_name;
    m_hpMax = p_hpMax;
    m_hp = p_hpMax;
    m_dodge = p_dodge;
    m_attack = p_attack;
    m_shield = p_shield;
    m_weapon = NULL;
}

CWarrior::~CWarrior()
{

}

void CWarrior::setWeapon(CWeapon* weapon)
{
    m_weapon = (CSword*)weapon;
    m_hpMax += m_weapon->m_bonus; 
    m_hp += m_weapon->m_bonus; 
}

void CWarrior::action(CCharacter &p_ennemy)
{
    int selectedNumber=0;
    while(selectedNumber<1 || selectedNumber > 4)
    {
        std::cout << "1 : Attack" << std::endl;
        std::cout << "2 : Sword Attack" << std::endl;
        std::cout << "3 : Raise Shield" << std::endl;
        std::cout << "4 : Repair Sword" << std::endl;
        std::cout << std::endl;
        std::cin>>selectedNumber;
        std::cout << std::endl;
    }

    switch (selectedNumber)
    {
        case 1:
                this->unarmedAttack(p_ennemy);
            break;
        case 2:
            if(m_weapon != NULL)
            {
                if(!m_weapon->isBroken())
                {
                    this->armedAttack(p_ennemy);
                }
                else
                {
                    std::cout << "SWORD IS BROKEN" << std::endl;
                    this->action(p_ennemy);
                }
            }
            else
            {
                std::cout << "NO WEAPON" << std::endl;
                this->action(p_ennemy);
            }
            break;
        case 3:
                this->defend();
            break;
        case 4:
                this->repair();
            break;
        default:
            break;
    }
}

void CWarrior::armedAttack(CCharacter &p_ennemy)
{
    float dem;
    if(m_weapon->criticalStrike())
    {
        dem = 2*m_weapon->m_damage;
        dem = 0.75 * (dem + m_attack);
    }
    else
    {
        dem = m_weapon->m_damage;
        dem = 0.75 * (dem + m_attack);
    }
    m_weapon->use();
    if (m_weapon->isBroken())
    {
        std::cout << "SWORD BROKE" << std::endl;
    }
    p_ennemy.applyDamage(dem);

}

void  CWarrior::defend()
{
    numberOfTurnDefended = rand() % 2 + 1;  // 1 to 3 turn protected
}

void CWarrior::unarmedAttack(CCharacter &p_ennemy)
{
    p_ennemy.applyDamage(0.66*m_attack);
}
void CWarrior::applyDamage(int p_damage)
{
    if (numberOfTurnDefended>0)
    {
        std::cout << "SHIELDED" << std::endl;
        numberOfTurnDefended--;
        p_damage -= (0.25 * m_shield);
        this->CCharacter::applyDamage(p_damage);
    }
    else
    {
        this->CCharacter::applyDamage(p_damage);
    }
}

void CWarrior::repair()
{
    if(m_weapon->isBroken())
    {
        m_weapon->m_durability++;
    }
    else
    {
        int recovery = rand() % 12 + 3;
        m_weapon->m_durability+= recovery;
        if(m_weapon->m_durability > m_weapon->m_durabilityMax)
        {
            m_weapon->m_durability = m_weapon->m_durabilityMax;
        }
    }
}

std::string CWarrior::getClass()
{
    return "CWarrior";
}

void CWarrior::displayStats()
{
    if(m_weapon != NULL)
        std::cout  << "Shield up : " << this->numberOfTurnDefended 
            << " Sword durability : " << m_weapon->m_durability<<"/"<<m_weapon->m_durabilityMax << std::endl;
    else
        std::cout  << "Shield up : " << this->numberOfTurnDefended
        << " No weapon" << std::endl;
    
}