#ifndef RAY_H
#define RAY_H
#include "common.h"
#include <opencv2/opencv.hpp>
#include <cmath>
#include "Vector3D.h"
class Ray{
public:
    Ray(const Vector3D startpoint, const Vector3D direction){
        this->location_ = Vector3D(startpoint);
        this->direction_ = Vector3D(direction);
        Precompute();
    }

    // extend the ray along the direction 
    Vector3D ExtraPolate(double t) const{
        return location_ + direction_ * t;
    }

    // given a point on the ray, return the parameter t
    double GetT(Vector3D& v) const{
        for (int i = 0; i < 3; i++){
            if (abs(v[i]) > ZERO_THRESHOLD){
                return (v[i] - location_[i]) / direction_[i];
            }
        }
        return 0;
    }

    // get the reflect direction of a ray, given the normal of surface
    Vector3D ReflectRay(const Vector3D& Normal) const{
    	return direction_ + 2.0 * (Normal.mul(Normal.dot(-1.0 * direction_)));
    }

    Vector3D location_;
    Vector3D direction_; 
private:

    Vector3D ll_; // location * location
    Vector3D ld_; // location * direction
    Vector3D dd_; // direction * direction

    void Precompute(){
    	ll_ = location_.mul(location_);
    	ld_ = location_.mul(direction_);
    	dd_ = direction_.mul(direction_);
    }
};



#endif
