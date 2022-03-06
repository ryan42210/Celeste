#ifndef CELESTE_INCLUDE_VOLUME_H_
#define CELESTE_INCLUDE_VOLUME_H_

#include <nanovdb/util/OpenToNanoVDB.h>
#include "core.h"

class Volume {
  using BufferT = nanovdb::HostBuffer;
 public:
  explicit Volume(const std::string &vdb_path);
  vec3f LookUp(const vec3f &p) const;
  vec3f Sample() const;
  vec3f Tr() const;

  Ray GridToWorld(const Ray &grid_ray) const;
  Ray WorldToGrid(const Ray &world_ray) const;
 private:
  std::shared_ptr<nanovdb::GridHandle<BufferT>> p_nano_grid_;
  float sigma_s_;
  float sigma_a_;
  vec3f rho_;
};

#endif //CELESTE_INCLUDE_VOLUME_H_
