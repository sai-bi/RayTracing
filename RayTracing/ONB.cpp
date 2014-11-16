#include "ONB.h"
#include "common.h"
#include <opencv2/opencv.hpp>
using namespace cv;

void ONB::ONB(){

}

void ONB::ONB(const Vector3D& U, const Vector3D& V, const Vector3D& W){
    this->U_ = Vector3D(U);
    this->V_ = Vector3D(V);
    this->W_ = Vector3D(W);
}

// one axis is parallel to U, but the other tow are arbitrary
void ONB::initFromU(const Vector3D& U){
    Vector3D n(1.0, 0, 0);
    Vector3D m(0, 1.0, 0);
    this->U_ = 1.0 / norm(U) * U;
    this->V_ = cv::cross(U_, n);
    if(norm(this->V_) < ZERO_THRESHOLD){
        this->V_ = cv::cross(U,m);
    }
    this->W_ = cv::cross(U_, V_);
}   

void ONB::initFromV(const Vector3D& V){
    Vector3D n(1.0, 0, 0);
    Vector3D m(0, 1.0, 0);
    this->V_ = 1.0 / norm(V) * V;
    this->U_ = cv::cross(V_, n);
    if(norm(this->V_) < ZERO_THRESHOLD){
        this->V_ = cv::cross(U,m);
    }
    this->W_ = cv::cross(U_, V_);
}

void ONB::initFromU(const Vector3D& U){
    Vector3D n(1.0, 0, 0);
    Vector3D m(0, 1.0, 0);
    this->U_ = 1.0 / norm(U) * U;
    this->V_ = cv::cross(U_, n);
    if(norm(this->V_) < ZERO_THRESHOLD){
        this->V_ = cv::cross(U_,m);
    }
    this->W_ = cv::cross(U_, V_);
}

void ONB::initFromW(const Vector3D& W){
    Vector3D n(1.0, 0, 0);
    Vector3D m(0, 1.0, 0);
    this->W_ = 1.0 / norm(W) * W;
    this->U_ = cv::cross(W_, n);
    if(norm(this->U_) < ZERO_THRESHOLD){
        this->U_ = cv::cross(W_,m);
    }
    this->V_ = cv::cross(W_, U_);
}

void ONB::initFromUV(const Vector3D& U, const Vector3D& V){
    this->U_ = 1.0 / norm(U) * U;
    this->V_ = 1.0 / norm(V) * V;
    this->W_ = cross(U_, V_);
}

void ONB::initFromUW(const Vector3D& U, const Vector3D& W){
    this->U_ = 1.0 / norm(U) * U;
    this->V_ = cross(U, V);
    V_ = 1.0 / norm(V_) * V_;
    this->W_ = cross(U_, V_);
}

void ONB::initFromVW(const Vector3D& V, const Vector3D& W){
    this->U_ = cross(V, W);
    U_ = 1.0 / norm(U_) * U_;
    this->V_ = 1.0 / norm(V) * V;
    this->W_ = 1.0 / norm(W) * W;
}
