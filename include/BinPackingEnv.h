#pragma once
#include <vector>
#include <memory>
#include "PxPhysicsAPI.h"

#include "Box.h"

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
    void addBox(float w, float h);
    size_t getBoxCount() const; 



private:
    SimMode mMode;
    int state_;
    std::vector<std::unique_ptr<Box>> mBoxes;

    physx::PxDefaultAllocator mAllocator;
    physx::PxDefaultErrorCallback mErrorCallback;

    physx::PxFoundation* mFoundation;
    physx::PxPhysics* mPhysics;
    physx::PxScene* mScene;
    physx::PxMaterial* mMaterial;
    physx::PxCpuDispatcher* mCpuDispatcher;
};
