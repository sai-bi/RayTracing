#include "Sphere.h"

Sphere::Sphere(const Vector3D& center, double radius, const RGB& color){
	this->center_ = Vector3D(center);
	this->radius_ = radius;
	this->color_ = RGB(color);
}

bool Sphere::Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const{
	double a = ray.direction_.dot(ray.direction_);
	Vector3D temp = ray.location_ - center_;
	double b = 2 * ray.direction_.dot(temp);
	double c = temp.dot(temp) - radius_ * radius_;
	double determinant = b * b - 4 * a * c;
	if(determinant <= 0){
		return false;
	}
	determinant = sqrt(determinant);
	double t = (-b - determinant) / (2 * a);

	if(t < t_min){
		t = (-b + determinant) / (2 * a);
	}
	if(t < t_min || t > t_max){
		return false;
	}
	record.t_ = t;
	temp = ray.location_ + t * ray.direction_ - center_;
	record.normal_ = temp / cv::norm(temp);
	record.color_ = color_;
	return true;
}


bool Sphere::ShadowHit(const Ray& ray, double t_min, double t_max, double time) const{
	double a = ray.direction_.dot(ray.direction_);
	Vector3D temp = ray.location_ - center_;
	double b = 2 * ray.direction_.dot(temp);
	double c = temp.dot(temp) - radius_ * radius_;
	double determinant = b * b - 4 * a * c;
	if(determinant <= 0){
		return false;
	}
	determinant = sqrt(determinant);
	double t = (-b - determinant) / (2 * a);

	if(t < t_min){
		t = (-b + determinant) / (2 * a);
	}
	if(t < t_min || t > t_max){
		return false;
	}
	return true;
}



