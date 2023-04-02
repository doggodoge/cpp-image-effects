//
// Created by gmoore on 02/04/23.
//

#ifndef MYPROJECT_IMAGES_H
#define MYPROJECT_IMAGES_H

#include <memory>
#include <string>

#include "stb_image.h"

using ImagePtr = std::unique_ptr<uint8_t[], decltype(&stbi_image_free)>;

typedef struct Image {
    int width;
    int height;
    int channels;
    ImagePtr data;
} Image;

Image load_image(std::string const &path);

#endif //MYPROJECT_IMAGES_H
