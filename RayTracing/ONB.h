#ifndef ONB_H
#define ONB_H

#include "Vector3D.h"

// define orthonormal basis class, this is used to build
// a coordinate system

class ONB{
public:
	ONB();
	ONB(const Vector3D& U, const Vector3D& V, const Vector3D& W);
	void initFromU(const Vector3D& U);
	void initFromV(const Vector3D& V);
	void initFromW(const Vector3D& W);
	void initFromUV(const Vector3D& U, const Vector3D& V);
	void initFromUW(const Vector3D& U, const Vector3D& W);
	void initFromVW(const Vector3D& V, const Vector3D& W);

	Vector3D U_;
	Vector3D V_;
	Vector3D W_;
};

#endif