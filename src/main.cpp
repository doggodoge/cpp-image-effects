#include <cstdio>
#include <cstdlib>

#include "images.h"

int main() {
    Image image = load_image("example.png");

    if (!image.data) {
        fprintf(stderr, "Failed to load image.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < image.width * image.height * image.channels; i++) {
        printf("%d ", image.data[i]);
    }

    return EXIT_SUCCESS;
}
