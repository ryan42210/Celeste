#ifndef CELESTE_INCLUDE_CONFIG_H_
#define CELESTE_INCLUDE_CONFIG_H_

#include "core.h"

struct ImgConfig {
  int width, height;
  int ch_num;
  float aspect_ratio;

  ImgConfig() = default;
  ImgConfig(int x, int y, int ch = 3) {
    width = x;
    height = y;
    ch_num = ch;
    aspect_ratio = static_cast<float>(width)/height;
  }
};

struct CamConfig {
  vec3f pos;
  vec3f lookat;
  vec3f ref_up;
  float focal_len, fov;
};

struct IntegratorConfig {
  int max_depth;
  int spp;
  enum INTEGRAL_METHOD {
    LIGHT_ONLY,
    END
  };
};

#endif //CELESTE_INCLUDE_CONFIG_H_
