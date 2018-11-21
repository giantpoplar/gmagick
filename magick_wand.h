#ifndef _GMAGICK_MAGICK_WAND_H
#define _GMAGICK_MAGICK_WAND_H

#include <wand/magick_wand.h>

struct FakeMagickWand
{
  char id[MaxTextExtent];
  ExceptionInfo exception;
  ImageInfo *image_info;
  QuantizeInfo   *quantize_info;
  Image    *image,    *images;
  unsigned int iterator;
  unsigned long signature;
};

extern OrientationType GMagickGetImageOrientation(MagickWand *);
extern unsigned int GMagickAutoOrientImage(MagickWand *, const OrientationType);
extern GravityType GMagickGetImageGravity(MagickWand *);

#endif