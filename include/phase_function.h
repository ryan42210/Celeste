#ifndef CELESTE_INCLUDE_PHASE_FUNCTION_H_
#define CELESTE_INCLUDE_PHASE_FUNCTION_H_

#include "core.h"
#include "coord_trans.h"

class PhaseFunction {
 public:
  virtual ~PhaseFunction() {}
  virtual float EvalPdf(const vec3f &wo, const vec3f &wi) const = 0;
  virtual float Sample(const vec3f &wo, vec3f *wi, float u1, float u2) const = 0;
};

class HenyeyGreenstein : public PhaseFunction {
 public:
  HenyeyGreenstein(float g);
  float EvalPdf(const vec3 &wo, const vec3 &wi) const override;
  float Sample(const vec3 &wo, vec3 *wi, float u1, float u2) const override;

  void SetG(float g) {this->g = g};

 private:
  Float g;
};

HenyeyGreenstein::HenyeyGreenstein(float g) {
  this->g = g;
}

float HenyeyGreenstein::EvalPdf(const int &wo, const int &wi) const {
  return 1.0f;
}

float HenyeyGreenstein::Sample(const int &wo, int *wi, float u1, float u2) const {
  return 1.0f;
}

#endif //CELESTE_INCLUDE_PHASE_FUNCTION_H_
