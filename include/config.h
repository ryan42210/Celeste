#ifndef CELESTE_INCLUDE_CONFIG_H_
#define CELESTE_INCLUDE_CONFIG_H_

#include "core.h"

struct ImgConfig {
  int width, height;
  float aspect_ratio;

  ImgConfig() = default;
  ImgConfig(int x, int y) {
    width = x;
    height = y;
    aspect_ratio = static_cast<float>(width)/static_cast<float>(height);
  }
  ImgConfig(const ImgConfig& img_config) {
    this->width = img_config.width;
    this->height = img_config.height;
    this->aspect_ratio = img_config.aspect_ratio;
  }
};

struct CamConfig {
  vec3f pos{0,0,0};
  vec3f lookat{0,0,1};
  vec3f ref_up{0,1,0};
  float focal_len, fov;

  CamConfig() {
    focal_len = 1.0;
    fov = 45;
  }
  CamConfig(vec3f position, vec3f look_at, vec3f up, float focal_len, float fov) {
    pos = position;
    lookat = look_at;
    ref_up = up;
    this->focal_len = focal_len;
    this->fov = fov;
  }
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
