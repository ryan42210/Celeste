#ifndef CELESTE_INCLUDE_COORD_TRANS_H_
#define CELESTE_INCLUDE_COORD_TRANS_H_

#include "core.h"

class CoordTransform {
 public:
  CoordTransform(vec3f w_normal);
  vec3f LocalToWorld(const vec3f &v);
  vec3f WorldToLocal(const vec3f &v);
 private:
  vec3f tangent_;
  vec3f binormal_;
  vec3f normal_;
};

CoordTransform::CoordTransform(vec3f w_normal) : normal_(w_normal) {
  if (fabsf(normal_.x()) > fabsf(normal_.z())) {
    binormal_.x() = -normal_.y();
    binormal_.y() = normal_.x();
    binormal_.z() = 0;
  } else {
    binormal_.x() = 0;
    binormal_.y() = -normal_.z();
    binormal_.z() = normal_.y();
  }
  binormal_.normalize();
  tangent_ = binormal_.cross(normal_);
}

vec3f CoordTransform::WorldToLocal(const vec3f &v) {
  return vec3f(v.dot(tangent_), v.dot(binormal_), v.dot(normal_));
}

vec3f CoordTransform::LocalToWorld(const vec3f &v) {
  return v.x() * tangent_ + v.y() * binormal_ + v.z() * normal_;
}

#endif //CELESTE_INCLUDE_COORD_TRANS_H_
