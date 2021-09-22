#ifndef CELESTE_INCLUDE_INTEGRATOR_H_
#define CELESTE_INCLUDE_INTEGRATOR_H_

#include "core.h"
#include "config.h"
#include "camera.h"
#include "scene.h"

class Integrator {
 public:
  void Render();
 private:
  std::shared_ptr<Camera> p_camera_;
  std::shared_ptr<Scene> p_scene_;

  ImgConfig img_config_;
  CamConfig cam_config_;
  IntegratorConfig integrator_config_;
};

#endif //CELESTE_INCLUDE_INTEGRATOR_H_
