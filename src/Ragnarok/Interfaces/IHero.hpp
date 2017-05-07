#pragma once

namespace Ragnarok
{

class IEnemy;

class IHero
{
public:
    virtual void hit(IEnemy*) = 0;
    virtual ~IHero() = default;
};

}
