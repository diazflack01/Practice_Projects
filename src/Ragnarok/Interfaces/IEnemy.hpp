#pragma once

namespace Ragnarok
{

class IEnemy
{
public:
    virtual void receiveAttack(unsigned dmg) = 0;
};

}
