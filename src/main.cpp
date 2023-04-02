#include <cstdlib>

#include "images.h"
#include "effects.h"

int main() {
    images::Image image = images::Image::load("example.png");
    effects::blur(image, 10).save("blurred.png");

    return EXIT_SUCCESS;
}
