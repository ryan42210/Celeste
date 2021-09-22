#ifndef CELESTE_INCLUDE_IMAGE_H_
#define CELESTE_INCLUDE_IMAGE_H_

#include "core.h"
#include "config.h"

template<int ch_num>
class Image {
 public:
  Image() = default;
  Image(const int width, const int height);
 private:
  ImgConfig img_config_;
};

using Image3f = Image<3>;

#endif //CELESTE_INCLUDE_IMAGE_H_
