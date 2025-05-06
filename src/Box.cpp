#include "Box.h"

using namespace physx;

Box::Box(PxPhysics* physics, PxMaterial* material, float x, float y, float w, float h) {
    PxTransform pose(PxVec3(x, y, 0.0f));
    PxBoxGeometry geom(w / 2.0f, h / 2.0f, 0.1f);
    mActor = PxCreateDynamic(*physics, pose, geom, *material, 1.0f);
}

Box::~Box() {
    if (mActor) {
        mActor->release();
        mActor = nullptr;
    }

}
