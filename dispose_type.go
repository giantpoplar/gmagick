package gmagick

/*
#include <wand/magick_wand.h>
*/
import "C"

type DisposeType int

const (
	DISPOSE_UNDEFINED  DisposeType = C.UndefinedDispose
	DISPOSE_NONE       DisposeType = C.NoneDispose
	DISPOSE_BACKGROUND DisposeType = C.BackgroundDispose
	DISPOSE_PREVIOUS   DisposeType = C.PreviousDispose
)
