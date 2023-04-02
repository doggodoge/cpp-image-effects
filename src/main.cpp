#include <cstdio>
#include <cstdlib>

#include "images.h"
#include "effects.h"

int main() {
    images::Image image = images::Image::load("example.png");

    if (!image.data) {
        fprintf(stderr, "Failed to load image.\n");
        return EXIT_FAILURE;
    }

    // blur the image
    effects::blur(image, 10).save("blurred.png");

    return EXIT_SUCCESS;
}
