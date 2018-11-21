package gmagick

/*
#include <wand/magick_wand.h>
*/
import "C"

type PixelPacket struct {
	pp *C.PixelPacket
}

func newPixelPacketFromCAPI(mpp *C.PixelPacket) *PixelPacket {
	return &PixelPacket{mpp}
}
