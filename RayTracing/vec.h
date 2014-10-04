#ifndef VEC_H
#define VEC_H
#include <cmath>
using namespace std;

class Vector3D{
public:
    double x_;
    double y_;
    double z_;
    
    Vector3D(){ }
    Vector3D(double X, double Y, double Z){
    	x_ = X;
    	y_ = Y;    
    	z_ = Z;
    }
    Vector3D(double X){
    	x_ = X;
    	y_ = X;
    	z_ = X;
    }
    Vector3D(const Vector3D& v){
    	x_ = v.x_;
    	y_ = v.y_;
    	z_ = v.z_;
    }

    // unary operators
    Vector3D operator+ () const; 
    Vector3D operator- () const; 
    
    // binary operators
    friend Vector3D operator+ (const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator- (const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator* (const Vector3D& v, double a); // v' = v * a;
    friend Vector3D operator* (double a, const Vector3D& v); // v' = a * v;
    friend Vector3D operator/ (const Vector3D& v, double a); // v' = v / a;
};

class RGBColor : public Vector3D{
public:
	RGBColor() {}
	RGBColor(double X, double Y, double Z) {
		x_ = X;
		y_ = Y;
		z_ = Z;
	}
	RGBColor(double X){
		x_ = X;
		y_ = X;
		z_ = X;
	}
	RGBColor(const Vector3D& v){
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
	}
	friend RGBColor NormalizeColor(const RGBColor& v);
};

// magnitude
inline double Magnitude(const Vector3D& v){
	return sqrt(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);
}

inline Vector3D Vector3D::operator+ () const{
	return *this;
}

inline Vector3D Vector3D::operator- () const{
	return Vector3D(-x_, -y_, -z_);
}

inline Vector3D operator+ (const Vector3D& v1, const Vector3D& v2){
	return Vector3D(v1.x_ + v2.x_, v1.y_ + v2.y_, v1.z_ + v2.z_);
}

inline Vector3D operator- (const Vector3D& v1, const Vector3D& v2){
	return Vector3D(v1.x_ - v2.x_, v1.y_ - v2.y_, v1.z_ - v2.z_);
}

inline Vector3D operator* (const Vector3D& v, double a){
	return Vector3D(v.x_ * a, v.y_ * a, v.z_ * a);
}

inline Vector3D operator/ (const Vector3D& v, double a){
	return Vector3D(v.x_ / a, v.y_ / a, v.z_ / a);
}

inline Vector3D operator* (double a, const Vector3D& v){
	return Vector3D(v.x_ * a, v.y_ * a, v.z_ * a);
}

inline double DotProd(const Vector3D& v1, const Vector3D& v2){
	return v1.x_ * v2.x_ + v1.y_ * v2.y_ + v1.z_ * v2.z_; 
}

inline Vector3D Normalize(const Vector3D& v){
	double mag = Magnitude(v);
	return v / mag; 
}

inline Vector3D CrossProd(const Vector3D& v1, const Vector3D& v2){
	return Vector3D(v1.y_ * v2.z_ - v1.z_ * v2.y_,
					v1.z_ * v2.x_ - v1.x_ * v2.z_,
					v1.x_ * v2.y_ - v1.y_ * v2.x_);
}

inline RGBColor NormalizeColor(const RGBColor& v){
	double max_v = v.x_ > v.y_ ? v.x_ : v.y_;
    max_v = max_v > v.z_ ? max_v : v.z_;
	if(abs(max_v) > 1e-10){
		return v / max_v;
	}
	return v;
}


#endif