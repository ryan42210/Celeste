#ifndef CELESTE_INCLUDE_CAMERA_H_
#define CELESTE_INCLUDE_CAMERA_H_

#include "core.h"
#include "config.h"

class Camera {
 public:
  Camera() = default;
  // Camera(ImgConfig img_config);
  void SetCamConfig(const CamConfig &config);
  void SetImgConfig(const ImgConfig &config);
  Ray GenerateRay(float x, float y);
 private:
  ImgConfig img_config_;
  vec3f eye_, up_, right_, forward_;
  float focal_len_, fov_;
  float img_plane_w_, img_plane_h_;
};

#endif //CELESTE_INCLUDE_CAMERA_H_
