#include "volume.h"

Volume::Volume(std::string vdb_path) {
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
vec3f &Volume::Sample() {
  vec3f res;
  return res;
}
vec3f &Volume::Tr() {
  vec3f res;
  return res;
}
vec3f &Volume::LookUp(const vec3f &p) {
  vec3f res;
  return res;
}
