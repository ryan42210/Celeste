#ifndef CELESTE_INCLUDE_IMAGE_H_
#define CELESTE_INCLUDE_IMAGE_H_

#include "core.h"
#include "config.h"
#include "spectrum.h"
#include <vector>

template<typename PixelT>
class Image {
 public:
  Image() = default;
  Image(int width, int height);
  Image(const ImgConfig &img_config);
  void SetPixel(int dx, int dy, const PixelT &pixel_value);
  const std::vector<float> &GetImage() const;
 private:
  ImgConfig img_config_;
  std::vector<float> data_;
};

using ImageRGB = Image<RGBSpectrum>;

template<typename PixelT>
Image<PixelT>::Image(const int width, const int height)
  : img_config_(width, height), data_(width * height * CH_NUM,0) {}

template<typename PixelT>
Image<PixelT>::Image(const ImgConfig &img_config)
  : img_config_(img_config), data_(img_config.width * img_config.height * CH_NUM, 0) {}

template<typename PixelT>
void Image<PixelT>::SetPixel(int dx, int dy, const PixelT &pixel_value) {
  data_[(img_config_.width * dy + dx) * CH_NUM] = pixel_value[0];
  data_[(img_config_.width * dy + dx) * CH_NUM + 1] = pixel_value[1];
  data_[(img_config_.width * dy + dx) * CH_NUM + 2] = pixel_value[2];
}

template<typename PixelT>
const std::vector<float> &Image<PixelT>::GetImage() const {
  return data_;
}

#endif //CELESTE_INCLUDE_IMAGE_H_
