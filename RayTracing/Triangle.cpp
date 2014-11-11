#include "Triangle.h"
Triangle::Triangle(const Vector3D& p0, const Vector3D& p1, const Vector3D& p2, const RGB& color){
	this->p0 = p0;
	this->p1 = p1;
	this->p2 = p2;
	this->color = color;
}

bool Triangle::Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const{
	double a = p0[0] - p1[0];
	double b = p0[1] - p1[1];
	double c = p0[2] - p1[2];
	double d = p0[0] - p2[0];
	double e = p0[1] - p2[1];
	double c = p0[2] - p2[2];
	double g = ray.direction_[0];
	double h = ray.direction_[1];
	double i = ray.direction_[2];
	double j = p0[0] - ray.location_[0];
	double k = p0[1] - ray.location_[1];
	double l = p0[2] - ray.location_[2];

	double eihf = e * i - h * f;
	double gfdi = g * f - d * i;
	double dheg = d * h - e * g;
	double M = a * eihf + b * gfdi + c * dheg;
	double beta = (j*eihf + k * gfdi + l*dheg) / M;
	if(beta <= 0.0 || beta >= 1.0){
		return false;
	}

	double akjb = a * k - j * b;
	double jcal = j * c - a * l;
	double blkc = b * l - k * c;
	double gamma = (i*akjb + h*jcal + g*blkc) / M;
	if(gamma <= 0.0 || gamma >= 1.0){
		return false;
	}

	double t = -(f * akjb + e*jcal + d * blkc) / M;
	if(t >= t_min && t <= t_max){
		record.t = tval;
		record.normal = (p1 - p0).cross(p2 - p0);
		record.normal = record.normal / cv::norm(record.normal);
		record.color = color;
		return true;
	}
	return false;
}


