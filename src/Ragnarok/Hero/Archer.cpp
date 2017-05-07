#include "Archer.hpp"
#include <Interfaces/IEnemy.hpp>

namespace Ragnarok
{

void Archer::hit(IEnemy* enemy)
{
    enemy->receiveAttack(mAtkPower);
}

const unsigned Archer::mAtkPower = 5;

}
