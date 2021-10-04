#ifndef CELESTE_INCLUDE_CORE_H_
#define CELESTE_INCLUDE_CORE_H_

#include <nanovdb/NanoVDB.h>
#include <nanovdb/util/Ray.h>

using vec3f = nanovdb::Vec3f;
using vec3i = nanovdb::Vec3i;

using Ray = nanovdb::Ray<float>;

static constexpr unsigned int CH_NUM = 3;
static constexpr float PI = 3.141592653579f;
#endif //CELESTE_INCLUDE_CORE_H_
