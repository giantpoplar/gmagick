package gmagick

/*
#include <wand/magick_wand.h>
*/
import "C"

type StyleType int

const (
	STYLE_NORMAL   StyleType = C.NormalStyle
	STYLE_ITALIC   StyleType = C.ItalicStyle
	STYLE_OBLIQUE  StyleType = C.ObliqueStyle
	STYLE_ANYSTYLE StyleType = C.AnyStyle
)
