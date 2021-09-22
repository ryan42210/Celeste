#ifndef CELESTE_INCLUDE_LIGHT_H_
#define CELESTE_INCLUDE_LIGHT_H_

#include "core.h"

class Light {
 public:
  vec3f Sample();
  vec3f Emission();
 private:
  vec3f color_;
  float power;
};

class SunLight : public Light {
 public:
 private:
};

#endif //CELESTE_INCLUDE_LIGHT_H_
