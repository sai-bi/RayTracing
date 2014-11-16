#include "Triangle.h"
Triangle::Triangle(const Vector3D& p0, const Vector3D& p1, const Vector3D& p2, const RGB& color){
    this->p0_ = Vector3D(p0);
    this->p1_ = Vector3D(p1);
    this->p2_ = Vector3D(p2);
    this->color_ = RGB(color);
}

bool Triangle::Hit(const Ray& ray, double t_min, double t_max, double time, HitRecord& record) const{
    double a = p0_[0] - p1_[0];
    double b = p0_[1] - p1_[1];
    double c = p0_[2] - p1_[2];
    double d = p0_[0] - p2_[0];
    double e = p0_[1] - p2_[1];
    double f = p0_[2] - p2_[2];
    double g = ray.direction_[0];
    double h = ray.direction_[1];
    double i = ray.direction_[2];
    double j = p0_[0] - ray.location_[0];
    double k = p0_[1] - ray.location_[1];
    double l = p0_[2] - ray.location_[2];

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
    if(gamma <= 0.0 || gamma + beta >= 1.0){
        return false;
    }

    double t = -1.0 * (f * akjb + e*jcal + d * blkc) / M;
    if(t >= t_min && t <= t_max){
        record.t_ = t;
        record.normal_ = (p1_ - p0_).cross(p2_ - p0_);
        record.normal_ = record.normal_ / cv::norm(record.normal_);
        record.color_ = color_;
        return true;
    }
    return false;
}

bool Triangle::ShadowHit(const Ray& ray, double t_min, double t_max, double time) const{
    double a = p0_[0] - p1_[0];
    double b = p0_[1] - p1_[1];
    double c = p0_[2] - p1_[2];
    double d = p0_[0] - p2_[0];
    double e = p0_[1] - p2_[1];
    double f = p0_[2] - p2_[2];
    double g = ray.direction_[0];
    double h = ray.direction_[1];
    double i = ray.direction_[2];
    double j = p0_[0] - ray.location_[0];
    double k = p0_[1] - ray.location_[1];
    double l = p0_[2] - ray.location_[2];

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
    if(gamma <= 0.0 || gamma + beta >= 1.0){
        return false;
    }

    double t = -1.0 * (f * akjb + e*jcal + d * blkc) / M;
    if(t >= t_min && t <= t_max){
        return true;
    }
    return false;
}


