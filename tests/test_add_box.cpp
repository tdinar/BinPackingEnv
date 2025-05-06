#include "gtest/gtest.h"
#include "BinPackingEnv.h"

TEST(AddBoxTest, AddSingleBoxIncrementsCount) {
    BinPackingEnv env(SimMode::MODE_2D);
    EXPECT_EQ(env.getBoxCount(), 0);

    env.addBox(1.0f, 2.0f);
    EXPECT_EQ(env.getBoxCount(), 1);

    env.addBox(0.5f, 0.5f);
    EXPECT_EQ(env.getBoxCount(), 2);
}
