#include <iostream>
#include "render_viewport.h"
#include "volume.h"
#include "image.h"
#include "camera.h"

int main() {
  ImgConfig img_config(1920, 1080);
  ViewPort view_port;
  ImageRGB img(img_config);
  std::cout << "hello celeste!" << std::endl;
  view_port.Initialize(img_config);
  view_port.UpdateFrameBuffer(img.GetImage());
  view_port.ShowViewPort();
  return 0;
}