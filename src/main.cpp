#include <cstdio>
#include <cstdlib>
#include <memory>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using ImagePtr = std::unique_ptr<uint8_t[],
                                 decltype(&stbi_image_free)>;

int main()
{
  int width;
  int height;
  int channels;

  ImagePtr image(stbi_load("example.png", &width, &height, &channels, 0),
                 &stbi_image_free);

  if (!image)
  {
    fprintf(stderr, "Failed to load image.\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < width * height * channels; i++)
  {
    printf("%d ", image[i]);
  }

  return EXIT_SUCCESS;
}
