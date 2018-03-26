#ifndef _GMAGICK_MAGICK_WAND_H
#define _GMAGICK_MAGICK_WAND_H

#include <wand/wand_api.h>

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

extern OrientationType get_image_orientation(MagickWand *);
extern unsigned int auto_orient_image(MagickWand *, const OrientationType);

#endif