#ifndef TRIANGLE_H
#define TRIANGLE_H	
#include "Shape.h"
class Triangle : public Shape{
public:
	Triangle(const Vector3D& p0, const Vector3D& p1, const Vector3D& p2, const RGB& color);
	bool Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const;
	bool ShadowHit(const Ray& ray, double t_min, double t_max, double time) const;

	Vector3D p0;
	Vector3D p1;
	Vector3D p2;
	RGB color;
};
#endif