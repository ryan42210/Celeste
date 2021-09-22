#include "camera.h"
// #include <cmath>

void Camera::SetCamConfig(const CamConfig &config) {
  focal_len_ = config.focal_len;
  fov_ = config.fov;

  eye_ = config.pos;
  forward_ = (config.lookat - config.pos).normalize();
  right_ = config.ref_up.cross(forward_).normalize();
  up_ = forward_.cross(right_);
}

void Camera::SetImgConfig(const ImgConfig &config) {
  img_config_.ch_num = config.ch_num;
  img_config_.width = config.width;
  img_config_.height = config.height;
  img_plane_w_ = focal_len_ * tanf(fov_ * PI / 360) * config.aspect_ratio;
  img_plane_h_ = focal_len_ * tanf(fov_ * PI / 360);
}

Ray Camera::GenerateRay(float x, float y) {
  float x_offset = img_plane_w_ * (2 * x / img_config_.width - 1);
  float y_offset = img_plane_h_ * (1 - 2 * y / img_config_.width);
  vec3f dir = (forward_ + x_offset * right_ + y_offset * up_).normalize();
  Ray ray(eye_, dir);
  return ray;
}