#include "magick_wand.h"

OrientationType get_image_orientation(MagickWand *wand) {
    OrientationType orientationType = UndefinedOrientation;
    // MagickGetImageOrientation is newly added in 1.3.26
    #if MagickLibVersion >= 0x191600
    	orientationType = MagickGetImageOrientation(wand);
    #endif
    return orientationType;
}

unsigned int auto_orient_image(MagickWand *wand, const OrientationType current_orientation) {
    // MagickAutoOrientImage is newly added in 1.3.26
    #if MagickLibVersion >= 0x191600
        return MagickAutoOrientImage(wand, current_orientation);
    #endif
    return 1;
}

