#ifndef RAY_H
#define RAY_H
#include "common.h"
#include <opencv2/opencv.hpp>
#include <cmath>
class Ray{
public:
    Ray(const cv::Vec3d startpoint, const cv::Vec3d direction){
        this->location_ = startpoint;
        this->direction_ = direction;
        Precompute();
    }

    // extend the ray along the direction 
    cv::Vec3d ExtraPolate(double t) const{
        return location_ + direction_ * t;
    }

    // given a point on the ray, return the parameter t
    double GetT(cv::Vec3d& v) const{
        for (int i = 0; i < 3; i++){
            if (abs(v[i]) > ZERO_THRESHOLD){
                return (v[i] - location_[i]) / direction_[i];
            }
        }
        return 0;
    }

    // get the reflect direction of a ray, given the normal of surface
    cv::Vec3d ReflectRay(const cv::Vec3d& Normal) const{
    	return direction_ + 2 * (Normal.mul(Normal.dot(-1.0 * direction_)));
    }

private:
    cv::Vec3d location_;
    cv::Vec3d direction_; 
    cv::Vec3d ll_; // location * location
    cv::Vec3d ld_; // location * direction
    cv::Vec3d dd_; // direction * direction

    void Precompute(){
    	ll_ = location_.mul(location_);
    	ld_ = location_.mul(direction_);
    	dd_ = direction_.mul(direction_);
    }
};

#endif
