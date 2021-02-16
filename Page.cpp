#include "PDF.h"

namespace libharu {

HPDF_REAL Page::getWidth() {
    return HPDF_Page_GetWidth(page);
}

HPDF_REAL Page::getHeight() {
    return HPDF_Page_GetHeight(page);
}

int Page::setWidth(HPDF_REAL w) {
    return HPDF_Page_SetWidth(page, w);
}

int Page::setHeight(HPDF_REAL h) {
    return HPDF_Page_SetHeight(page, h);
}

int Page::setSize(int page_size, int direction) {
    return HPDF_Page_SetSize(page, (HPDF_PageSizes)page_size, (HPDF_PageDirection)direction);
}

int Page::setLineWidth(HPDF_REAL width) {
    return HPDF_Page_SetLineWidth (page, width);
}

int Page::rectangle(HPDF_REAL x, HPDF_REAL y, HPDF_REAL w, HPDF_REAL h) {
    return HPDF_Page_Rectangle (page, x, y, w, h);
}

int Page::stroke() {
    return HPDF_Page_Stroke (page);
}

int Page::beginText() {
    return HPDF_Page_BeginText (page);
}

int Page::textOut(HPDF_REAL x, HPDF_REAL y, sciter::astring text) {
    return HPDF_Page_TextOut (page, x, y, text.c_str());
}

int Page::moveTextPos(HPDF_REAL x, HPDF_REAL y) {
    return HPDF_Page_MoveTextPos (page, x, y);
}

int Page::showText(sciter::astring text) {
    return HPDF_Page_ShowText (page, text.c_str());
}

int Page::endText() {
    return HPDF_Page_EndText (page);
}

int Page::setFontAndSize(sciter::value font, HPDF_REAL font_size) {
    return HPDF_Page_SetFontAndSize (page, font.get_asset<Font>()->get(), font_size);
}

int Page::moveTo(HPDF_REAL x, HPDF_REAL y) {
    return HPDF_Page_MoveTo(page, x, y);
}

int Page::lineTo(HPDF_REAL x, HPDF_REAL y) {
    return HPDF_Page_LineTo(page, x, y);
}

int Page::measureText(sciter::astring text, HPDF_REAL width, HPDF_BOOL wordwrap) {
    return HPDF_Page_MeasureText(page, text.c_str(), width, wordwrap, NULL);
}

int Page::textRect(sciter::value rect, sciter::astring text, int align) {

    HPDF_REAL left   = rect.get_item("left")  .get<HPDF_REAL>();
    HPDF_REAL top    = rect.get_item("top")   .get<HPDF_REAL>();
    HPDF_REAL right  = rect.get_item("right") .get<HPDF_REAL>();
    HPDF_REAL bottom = rect.get_item("bottom").get<HPDF_REAL>();
    return HPDF_Page_TextRect(page, left, top, right, bottom, text.c_str(),(HPDF_TextAlignment)align, NULL);
}

int Page::setRGBStroke(HPDF_REAL r, HPDF_REAL g, HPDF_REAL b) {
    return HPDF_Page_SetRGBStroke (page, r, g, b);
}

int Page::setCharSpace(HPDF_REAL value) {
    return HPDF_Page_SetCharSpace(page, value);
}

int Page::setWordSpace(HPDF_REAL value) {
    return HPDF_Page_SetWordSpace(page, value);
}

int Page::setTextLeading(HPDF_REAL value) {
    return HPDF_Page_SetTextLeading(page, value);
}

int Page::drawImage(sciter::value img, sciter::value rect) {
    HPDF_REAL x = rect.get_item("x").get<HPDF_REAL>();
    HPDF_REAL y = rect.get_item("y").get<HPDF_REAL>();
    HPDF_REAL w = rect.get_item("w").get<HPDF_REAL>();
    HPDF_REAL h = rect.get_item("h").get<HPDF_REAL>();
    return HPDF_Page_DrawImage(page, img.get_asset<Image>()->get(), x, y, w, h);
}

int Page::circle(HPDF_REAL x, HPDF_REAL y, HPDF_REAL radius) {
    return HPDF_Page_Circle(page, x, y, radius);
}

}
