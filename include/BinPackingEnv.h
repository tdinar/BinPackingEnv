#pragma once

#include "PxPhysicsAPI.h"

enum class SimMode {
    MODE_2D,
    MODE_3D
};

class BinPackingEnv {
public:
    explicit BinPackingEnv(SimMode mode);
    ~BinPackingEnv();

    void reset();
    void step();
    int get_state() const;

private:
    SimMode mMode;
    int state_;

    physx::PxDefaultAllocator mAllocator;
    physx::PxDefaultErrorCallback mErrorCallback;

    physx::PxFoundation* mFoundation;
    physx::PxPhysics* mPhysics;
    physx::PxScene* mScene;
    physx::PxMaterial* mMaterial;
    physx::PxCpuDispatcher* mCpuDispatcher;
};
