//
// Created by gmoore on 02/04/23.
//

#define STB_IMAGE_IMPLEMENTATION
#include "images.h"

Image load_image(std::string const &path) {
    int width, height, channels;
    ImagePtr image(
            stbi_load(path.c_str(), &width, &height, &channels, 0),
            &stbi_image_free);

    return Image{
            .width = width,
            .height = height,
            .channels = channels,
            .data = std::move(image)
    };
}
