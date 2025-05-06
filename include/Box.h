#pragma once

#include "PxPhysicsAPI.h"

class Box {
public:
    Box(physx::PxPhysics* physics, physx::PxMaterial* material,
        float x, float y, float w, float h);

    void addBox(float w, float h);
    size_t getBoxCount() const; // optional, to verify in the test
    ~Box();

private:


    physx::PxRigidDynamic* mActor;
};
