#ifndef SHAPE_H
#define SHAPE_H
#include "ray.h"
#include "RGB.h"
#include "common.h"
#include "Vector3D.h"

class HitRecord{
public:
    double t_;
    Vector3D normal_;
    RGB color_;
};

class Shape{
public:
    virtual bool Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const=0;
    virtual bool ShadowHit(const Ray& ray, double t_min, double t_max, double time) const=0;
};

#endif