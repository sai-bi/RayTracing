#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape{
public:
    Sphere(const Vector3D& center, double radius, const RGB& color);
    bool Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const;
    bool ShadowHit(const Ray& ray, double t_min, double t_max, double time) const;

    Vector3D center_;
    double radius_;
    RGB color_;
};
#endif