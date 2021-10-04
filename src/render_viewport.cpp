#include "render_viewport.h"

#include <iostream>

ViewPort::ViewPort() {
  initialized_ = false;
}
ViewPort::~ViewPort() {
  glfwTerminate();
}
void ViewPort::UpdateFrameBuffer(const std::vector<float> &input) {
  if (frame_buffer_.size() == input.size()) {
    frame_buffer_ = input;
  } else {
    std::cerr << "size not match" << std::endl;
  }
}
bool ViewPort::Initialize(const ImgConfig& img_config) {
  if (initialized_) return false;
  img_config_.width = img_config.width;
  img_config_.height = img_config.height;
  frame_buffer_.resize(img_config_.width * img_config_.height * CH_NUM, 0.1f);
  glfwInit();
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  p_window_ = glfwCreateWindow(img_config_.width, img_config_.height, "Celeste", NULL, NULL);
  return true;
}
void ViewPort::ShowViewPort() {
  glfwMakeContextCurrent(p_window_);
  while (!glfwWindowShouldClose(p_window_)) {
    if (glfwGetKey(p_window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(p_window_, true);
    glfwPollEvents();
    glfwSwapBuffers(p_window_);
    glDrawPixels(img_config_.width, img_config_.height, GL_RGB, GL_FLOAT, frame_buffer_.data());
  }
}
