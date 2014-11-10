#ifndef RAY_H
#define RAY_H
#include <opencv2/opencv.hpp>
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

    // 

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
