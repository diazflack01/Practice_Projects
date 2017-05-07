#include <Hero/Archer.hpp>
#include <Mocks/EnemyMock.hpp>

using namespace testing;

class ArcherTest : public ::testing::Test
{
protected:
    Ragnarok::IHero* hero;
    EnemyMock enemyMock;

    virtual void SetUp(){ hero = new Ragnarok::Archer(); }
    virtual void TearDown(){ delete hero; }
};

TEST_F(ArcherTest, TestHitEnemy)
{
    EXPECT_CALL(enemyMock, receiveAttack(_)).Times(1);
    hero->hit(&enemyMock);
}
