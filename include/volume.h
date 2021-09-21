#ifndef CELESTE_INCLUDE_VOLUME_H_
#define CELESTE_INCLUDE_VOLUME_H_

#include <nanovdb/util/OpenToNanoVDB.h>
#include "core.h"

class Volume {
  using BufferT = nanovdb::HostBuffer;
 public:
  Volume(std::string vdb_path);
  vec3f& LookUp(const vec3f &p);
  vec3f& Sample();
  vec3f& Tr();
 private:
  std::shared_ptr<nanovdb::GridHandle<BufferT>> p_nano_grid_;
  float sigma_s_;
  float sigma_a_;
  vec3f rho_;
};

#endif //CELESTE_INCLUDE_VOLUME_H_
