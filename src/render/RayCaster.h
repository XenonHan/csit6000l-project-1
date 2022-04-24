#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "Arguments.h"
#include "Renderer.h"

class RayCaster : public RenderFunction {
public:
    RayCaster() = delete;
    RayCaster(const Arguments &args)
        : args(args) {}
    ~RayCaster() {}

    virtual Vector3f render(const Scene &scene, const Ray &ray);

protected:
    const Arguments &args;
    bool rayCasting = true;
    bool getSpecularColor = false;
};

class DepthRayCaster : public RayCaster {
public:
    DepthRayCaster(const Arguments &args) : RayCaster(args) {}
    Vector3f render(const Scene &scene, const Ray &ray);
};

class NormalsRayCaster : public RayCaster {
public:
    NormalsRayCaster(const Arguments &args) : RayCaster(args) {}
    Vector3f render(const Scene &scene, const Ray &ray);
};

#endif // RAYCASTER_H
