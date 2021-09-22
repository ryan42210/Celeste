#ifndef CELESTE_INCLUDE_PHASE_FUNCTION_H_
#define CELESTE_INCLUDE_PHASE_FUNCTION_H_

#include "core.h"

class PhaseFunction {
 public:
  virtual ~PhaseFunction() {}
  virtual float EvalPdf(const vec3f &wo, const vec3f &wi) const = 0;
  virtual float Sample(const vec3f &wo, vec3f *wi, float u1, float u2) const = 0;
};

#endif //CELESTE_INCLUDE_PHASE_FUNCTION_H_
