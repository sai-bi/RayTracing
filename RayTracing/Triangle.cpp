#include "Triangle.h"
Triangle::Triangle(const Vector3D& p0, const Vector3D& p1, const Vector3D& p2, const RGB& color){
	this->p0 = p0;
	this->p1 = p1;
	this->p2 = p2;
	this->color = color;
}

bool Triangle::Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const{
	
}