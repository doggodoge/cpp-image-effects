#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "images.h"
#include "stb_image_write.h"

namespace images {
    Image Image::load(std::string const &path) {
        int width, height, channels;
        ImagePtr image(
                stbi_load(path.c_str(), &width, &height, &channels, 0),
                &stbi_image_free);

        return {width, height, channels, std::move(image)};
    }

    void Image::save(std::string const &path) const {
        stbi_write_png(path.c_str(), this->width, this->height, this->channels, this->data.get(), 0);
    }
}
