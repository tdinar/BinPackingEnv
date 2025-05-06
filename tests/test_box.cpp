#include "gtest/gtest.h"
#include "PxPhysicsAPI.h"
#include "Box.h"

using namespace physx;

class BoxTest : public ::testing::Test {
protected:
    PxDefaultAllocator allocator;
    PxDefaultErrorCallback errorCallback;
    PxFoundation* foundation = nullptr;
    PxPhysics* physics = nullptr;
    PxMaterial* material = nullptr;

    void SetUp() override {
        foundation = PxCreateFoundation(PX_PHYSICS_VERSION, allocator, errorCallback);
        ASSERT_NE(foundation, nullptr);

        physics = PxCreatePhysics(PX_PHYSICS_VERSION, *foundation, PxTolerancesScale());
        ASSERT_NE(physics, nullptr);

        material = physics->createMaterial(0.5f, 0.5f, 0.6f);
        ASSERT_NE(material, nullptr);
    }

    void TearDown() override {
        if (material) material->release();
        if (physics) physics->release();
        if (foundation) foundation->release();
    }
};

TEST_F(BoxTest, CreateAndDestroyBox) {
    Box* box = new Box(physics, material, 0.0f, 0.0f, 1.0f, 1.0f);
    ASSERT_NE(box, nullptr);
    delete box; // Destructor should cleanly release the actor
}
