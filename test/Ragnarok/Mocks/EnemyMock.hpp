#include "gmock/gmock.h"
#include <Interfaces/IEnemy.hpp>

class EnemyMock : public Ragnarok::IEnemy
{
public:
    MOCK_METHOD1(receiveAttack, void(unsigned));
};
