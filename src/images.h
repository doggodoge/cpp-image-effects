#ifndef MYPROJECT_IMAGES_H
#define MYPROJECT_IMAGES_H

#include <memory>
#include <string>

#include "stb_image.h"

namespace images {
    using ImagePtr = std::unique_ptr<uint8_t[], decltype(&stbi_image_free)>;

    class Image {
    public:
        int width;
        int height;
        int channels;
        ImagePtr data;

        Image(int width, int height, int channels, ImagePtr data) : width(width), height(height), channels(channels),
                                                                    data(std::move(data)) {}

        static Image load(std::string const &path);

        void save(std::string const &path) const;

    };
}

#endif //MYPROJECT_IMAGES_H
