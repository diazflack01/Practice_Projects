#pragma once

#include <Interfaces/IHero.hpp>

namespace Ragnarok
{

class Archer : public IHero
{
public:
    void hit(IEnemy*);

private:
    static const unsigned mAtkPower;
};

}
