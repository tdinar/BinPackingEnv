#include "BinPackingEnv.h"
#include "PxPhysicsAPI.h"

using namespace physx;

BinPackingEnv::BinPackingEnv(SimMode mode)
    : mMode(mode), state_(0), mFoundation(nullptr), mPhysics(nullptr), mScene(nullptr), mMaterial(nullptr), mCpuDispatcher(nullptr) {

    mFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, mAllocator, mErrorCallback);
    mPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *mFoundation, PxTolerancesScale());

    PxSceneDesc sceneDesc(mPhysics->getTolerancesScale());
    sceneDesc.gravity = (mMode == SimMode::MODE_2D) ? PxVec3(0.0f, -9.81f, 0.0f)
                                                   : PxVec3(0.0f, -9.81f, 0.0f);

    mCpuDispatcher = PxDefaultCpuDispatcherCreate(2);
    sceneDesc.cpuDispatcher = mCpuDispatcher;
    sceneDesc.filterShader = PxDefaultSimulationFilterShader;

    mScene = mPhysics->createScene(sceneDesc);
    mMaterial = mPhysics->createMaterial(0.5f, 0.5f, 0.6f); // Static friction, dynamic friction, restitution
}

BinPackingEnv::~BinPackingEnv() {
    if (mScene) mScene->release();
    if (mMaterial) mMaterial->release();
    if (mCpuDispatcher) static_cast<PxDefaultCpuDispatcher*>(mCpuDispatcher)->release();
    if (mPhysics) mPhysics->release();
    if (mFoundation) mFoundation->release();
}

void BinPackingEnv::reset() {
    state_ = 0;
    // TODO: remove actors or reset simulation state as needed
}

void BinPackingEnv::step() {
    state_ += 1;
    // TODO: perform simulation step
}

int BinPackingEnv::get_state() const {
    return state_;
}
