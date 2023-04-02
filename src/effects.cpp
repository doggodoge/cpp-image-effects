#include <valarray>
#include "effects.h"

namespace effects {
    images::Image blur(images::Image const &image, int blur_radius) {
        auto width = image.width;
        auto channels = image.channels;
        auto height = image.height;

        images::ImagePtr blurred_image_data(
                new uint8_t[image.width * image.height * image.channels],
                &stbi_image_free);

        auto get_pixel_index = [width, channels](int x, int y, int channel) {
            return (y * width + x) * channels + channel;
        };

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                for (int c = 0; c < channels; ++c) {
                    int sum = 0;
                    int count = 0;
                    for (int dy = -blur_radius; dy <= blur_radius; ++dy) {
                        for (int dx = -blur_radius; dx <= blur_radius; ++dx) {
                            int neighbour_x = x + dx;
                            int neighbour_y = y + dy;
                            if (neighbour_x >= 0 && neighbour_x < width && neighbour_y >= 0 && neighbour_y < height) {
                                sum += image.data[get_pixel_index(neighbour_x, neighbour_y, c)];
                                count++;
                            }
                        }
                    }
                    blurred_image_data[get_pixel_index(x, y, c)] = static_cast<unsigned char>(sum / count);
                }
            }
        }
        return {width, height, channels, std::move(blurred_image_data)};
    }
}

