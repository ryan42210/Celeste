#ifndef CELESTE_INCLUDE_CONFIG_H_
#define CELESTE_INCLUDE_CONFIG_H_

struct ImgConfig {
  int width, height;
  int ch_num;

  ImgConfig() = default;
  ImgConfig(int x, int y, int ch = 3) {
    width = x;
    height = y;
    ch_num = ch;
  }
};

#endif //CELESTE_INCLUDE_CONFIG_H_
