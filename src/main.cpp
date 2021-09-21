#include <iostream>
#include "render_viewport.h"
#include "volume.h"

int main() {
  ImgConfig img_config(1920, 1080);
  ViewPort view_port;
  std::cout << "hello celeste!" << std::endl;
  view_port.Initialize(img_config);
  view_port.ShowViewPort();
  return 0;
}