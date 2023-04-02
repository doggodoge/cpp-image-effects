//
// Created by gmoore on 02/04/23.
//

#ifndef MYPROJECT_EFFECTS_H
#define MYPROJECT_EFFECTS_H

#include "images.h"

namespace effects {
    images::Image blur(images::Image const &image, int blur_radius);
}

#endif //MYPROJECT_EFFECTS_H
