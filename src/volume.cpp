#include "volume.h"

Volume::Volume(const std::string &vdb_path)
  : sigma_s_(1.0f)
  , sigma_a_(1.0f)
  , rho_(1.0f, 1.0f, 1.0f) {
  openvdb::io::File file(vdb_path);
  openvdb::GridBase::Ptr vdb_grid;
  if (file.open()) {
    openvdb::io::File::NameIterator iter = file.beginName();
    vdb_grid = file.readGrid(iter.gridName());
  } else {
    std::cerr << "OpenVDB error: fail to open: " << vdb_path << std::endl;
    exit(0);
  }
  auto handle = nanovdb::openToNanoVDB(vdb_grid);
  p_nano_grid_ = std::make_shared<nanovdb::GridHandle<BufferT>>(
      nanovdb::openToNanoVDB<BufferT>(vdb_grid));
}
vec3f Volume::Sample() const {
  vec3f res;
  return res;
}
vec3f Volume::Tr() const {
  vec3f res;
  return res;
}
vec3f Volume::LookUp(const vec3f &p) const {
  vec3f res;
  return res;
}

Ray Volume::GridToWorld(const Ray &grid_ray) const {
  Ray world_ray;
  return world_ray;
}

Ray Volume::WorldToGrid(const Ray &world_ray) const {
  Ray grid_ray;
  return grid_ray;
}