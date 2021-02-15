#include "PDF.h"

namespace libharu {

sciter::value Image::getSize() {
    HPDF_Point point = HPDF_Image_GetSize(image);
    sciter::value val;
    val.set_item("width", point.x);
    val.set_item("height",point.y);
    return val;
}

int Image::getWidth() {
    return HPDF_Image_GetWidth(image);
}

int Image::getHeight() {
    return HPDF_Image_GetHeight(image);
}

int Image::setMaskImage(sciter::value mask) {
    return HPDF_Image_SetMaskImage(image, mask.get_asset<Image>()->get());
}

HPDF_Image Image::get() {
    return image;
}

}
