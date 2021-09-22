#ifndef CELESTE_INCLUDE_INTERACTION_H_
#define CELESTE_INCLUDE_INTERACTION_H_

#include "core.h"
#include "phase_function.h"

struct VolumeInteraction {
  vec3f position;
  vec3f wi, wo;
  std::shared_ptr<Phase> p_phase;
};

#endif //CELESTE_INCLUDE_INTERACTION_H_
