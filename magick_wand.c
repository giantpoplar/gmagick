#include "magick_wand.h"

OrientationType GMagickGetImageOrientation(MagickWand *wand) {
    // MagickGetImageOrientation is newly added in 1.3.26
    #if MagickLibVersion >= 0x191600
    	return MagickGetImageOrientation(wand);
    #endif
    return UndefinedOrientation;
}

unsigned int GMagickAutoOrientImage(MagickWand *wand, const OrientationType current_orientation) {
    // MagickAutoOrientImage is newly added in 1.3.26
    #if MagickLibVersion >= 0x191600
        return MagickAutoOrientImage(wand, current_orientation);
    #endif
    return 1;
}

GravityType GMagickGetImageGravity(MagickWand *wand) {
    // MagickGetImageGravity is available in 1.3.22
    #if MagickLibVersion >= 0x171400
        return MagickGetImageGravity(wand);
    #endif
    return ForgetGravity;
}