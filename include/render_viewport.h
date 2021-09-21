#ifndef CELESTE_INCLUDE_WINDOW_H_
#define CELESTE_INCLUDE_WINDOW_H_

#include <vector>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "config.h"

class ViewPort {
 public:
  ViewPort();
  ~ViewPort();
  void UpdateFrameBuffer(const std::vector<float> &input);
  bool Initialize(const ImgConfig& img_config);
  void ShowViewPort();
 private:
  std::vector<float> frame_buffer_;
  GLFWwindow* p_window_;
  ImgConfig img_config_;
  bool initialized_;
};

#endif //CELESTE_INCLUDE_WINDOW_H_
