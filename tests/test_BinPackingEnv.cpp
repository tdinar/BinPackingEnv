#include "gtest/gtest.h"
#include "BinPackingEnv.h"

TEST(BinPackingEnvTest, InitializeAndStep) {
    // Initialize the environment in 2D mode
    BinPackingEnv env(SimMode::MODE_2D);

    // Initial state should be 0
    EXPECT_EQ(env.get_state(), 0);

    // After reset, state should still be 0
    env.reset();
    EXPECT_EQ(env.get_state(), 0);

    // After one step, state should be 1
    env.step();
    EXPECT_EQ(env.get_state(), 1);

    // After another step, state should be 2
    env.step();
    EXPECT_EQ(env.get_state(), 2);
}
