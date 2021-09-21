#ifndef CELESTE_INCLUDE_CAMERA_H_
#define CELESTE_INCLUDE_CAMERA_H_

#include "core.h"
#include "config.h"

class Camera {
 public:
  Camera() = default;
  Camera(ImgConfig img_config);
  Ray &GenerateRay(float x, float y);
 private:
  ImgConfig img_config_;
};

#endif //CELESTE_INCLUDE_CAMERA_H_
