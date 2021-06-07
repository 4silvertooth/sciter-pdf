#ifndef PDF_H
#define PDF_H

#include "sciter-x.h"
#include "aux-cvt.h"
#include "hpdf.h"

namespace sciter {
    inline sciter::value setter(const HPDF_TextAlignment& value) {
        return (int)value;
    }

    inline sciter::value setter(const HPDF_PageDirection& value) {
        return (int)value;
    }

    inline sciter::value setter(const HPDF_PageSizes& value) {
        return (int)value;
    }
}
 

namespace libharu {
class Image;
class Page : public sciter::om::asset<Page> {
    HPDF_Page page;

    sciter::value TALIGN_LEFT = HPDF_TALIGN_LEFT;
    sciter::value TALIGN_RIGHT = HPDF_TALIGN_RIGHT;
    sciter::value TALIGN_CENTER = HPDF_TALIGN_CENTER;
    sciter::value TALIGN_JUSTIFY = HPDF_TALIGN_JUSTIFY;
    /**
    sciter::value TALIGN_TOP = (int)HPDF_TALIGN_TOP;
    sciter::value TALIGN_BOTTOM = (int)HPDF_TALIGN_BOTTOM;
    sciter::value TALIGN_MIDDLE = (int)HPDF_TALIGN_MIDDLE;
    */
    sciter::value SIZE_LETTER = HPDF_PAGE_SIZE_LETTER;
    sciter::value SIZE_LEGAL = HPDF_PAGE_SIZE_LEGAL;
    sciter::value SIZE_A3 = HPDF_PAGE_SIZE_A3;
    sciter::value SIZE_A4 = HPDF_PAGE_SIZE_A4;
    sciter::value SIZE_A5 = HPDF_PAGE_SIZE_A5;
    sciter::value SIZE_B4 = HPDF_PAGE_SIZE_B4;
    sciter::value SIZE_B5 = HPDF_PAGE_SIZE_B5;
    sciter::value SIZE_EXECUTIVE = HPDF_PAGE_SIZE_EXECUTIVE;
    sciter::value SIZE_US4x6 = HPDF_PAGE_SIZE_US4x6;
    sciter::value SIZE_US4x8 = HPDF_PAGE_SIZE_US4x8;
    sciter::value SIZE_US5x7 = HPDF_PAGE_SIZE_US5x7;
    sciter::value SIZE_COMM10 = HPDF_PAGE_SIZE_COMM10;

    sciter::value PORTRAIT = HPDF_PAGE_PORTRAIT;
    sciter::value LANDSCAPE = HPDF_PAGE_LANDSCAPE;

  public:

    Page(HPDF_Doc& pdf) {
        page = HPDF_AddPage (pdf);
    }
    virtual ~Page() {};
    HPDF_REAL getWidth();
    HPDF_REAL getHeight();
    int setWidth(HPDF_REAL);
    int setHeight(HPDF_REAL);
    int setSize(int, int);
    int setLineWidth(HPDF_REAL);
    int rectangle(HPDF_REAL, HPDF_REAL, HPDF_REAL, HPDF_REAL);
    int stroke();
    int beginText();
    int textOut(HPDF_REAL, HPDF_REAL, sciter::astring);
    int moveTextPos(HPDF_REAL, HPDF_REAL);
    int showText(sciter::astring);
    int endText();
    int setFontAndSize(sciter::value, HPDF_REAL);
    int moveTo(HPDF_REAL, HPDF_REAL);
    int lineTo(HPDF_REAL, HPDF_REAL);
    int measureText(sciter::astring, HPDF_REAL, HPDF_BOOL);
    int textRect(sciter::value, sciter::astring, int);
    int setRGBStroke(HPDF_REAL, HPDF_REAL, HPDF_REAL);
    int setCharSpace(HPDF_REAL);
    int setWordSpace(HPDF_REAL);
    int setTextLeading(HPDF_REAL);
    int drawImage(sciter::value, sciter::value);
    int circle(HPDF_REAL, HPDF_REAL, HPDF_REAL);

    SOM_PASSPORT_BEGIN(Page)
    SOM_PASSPORT_FLAGS(SOM_EXTENDABLE_OBJECT)
    SOM_FUNCS(
        SOM_FUNC(setWidth),
        SOM_FUNC(setHeight),
        SOM_FUNC(getWidth),
        SOM_FUNC(getHeight),
        SOM_FUNC(setSize),
        SOM_FUNC(setLineWidth),
        SOM_FUNC(rectangle),
        SOM_FUNC(stroke),
        SOM_FUNC(setFontAndSize),
        SOM_FUNC(beginText),
        SOM_FUNC(textOut),
        SOM_FUNC(textRect),
        SOM_FUNC(moveTextPos),
        SOM_FUNC(showText),
        SOM_FUNC(measureText),
        SOM_FUNC(endText),
        SOM_FUNC(moveTo),
        SOM_FUNC(lineTo),
        SOM_FUNC(setRGBStroke),
        SOM_FUNC(setCharSpace),
        SOM_FUNC(setWordSpace),
        SOM_FUNC(setTextLeading),
        SOM_FUNC(drawImage),
        SOM_FUNC(circle)
    )
    SOM_PROPS(
        SOM_RO_PROP(TALIGN_LEFT),
        SOM_RO_PROP(TALIGN_RIGHT),
        SOM_RO_PROP(TALIGN_CENTER),
        SOM_RO_PROP(TALIGN_JUSTIFY),
     /**SOM_RO_PROP(TALIGN_TOP),
        SOM_RO_PROP(TALIGN_BOTTOM),
        SOM_RO_PROP(TALIGN_MIDDLE),*/
        SOM_RO_PROP(SIZE_LETTER),
        SOM_RO_PROP(SIZE_LEGAL),
        SOM_RO_PROP(SIZE_A3),
        SOM_RO_PROP(SIZE_A4),
        SOM_RO_PROP(SIZE_A5),
        SOM_RO_PROP(SIZE_B4),
        SOM_RO_PROP(SIZE_B5),
        SOM_RO_PROP(SIZE_EXECUTIVE),
        SOM_RO_PROP(SIZE_US4x6),
        SOM_RO_PROP(SIZE_US4x8),
        SOM_RO_PROP(SIZE_US5x7),
        SOM_RO_PROP(SIZE_COMM10),
        SOM_RO_PROP(PORTRAIT),
        SOM_RO_PROP(LANDSCAPE)
    )
    SOM_PASSPORT_END
};

class Doc : public sciter::om::asset<Doc> {
    HPDF_Doc  pdf;

  public:
    Doc();
    ~Doc();

    int newDoc();
    sciter::value addPage();
    int save(sciter::astring);
    int free();
    sciter::value loadTTFontFromFile(sciter::astring, HPDF_BOOL);
    int setPassword(sciter::astring, sciter::astring);
    sciter::value loadJpegImageFromFile(sciter::astring);
    sciter::value loadPngImageFromFile(sciter::astring);
    sciter::value getFont(sciter::astring, sciter::value);

    SOM_PASSPORT_BEGIN(Doc)
    SOM_PASSPORT_FLAGS(SOM_EXTENDABLE_OBJECT)
    SOM_FUNCS(
        SOM_FUNC(newDoc),
        SOM_FUNC(addPage),
        SOM_FUNC(save),
        SOM_FUNC(free),
        SOM_FUNC(loadTTFontFromFile),
        SOM_FUNC(setPassword),
        SOM_FUNC(loadJpegImageFromFile),
        SOM_FUNC(loadPngImageFromFile),
        SOM_FUNC(getFont)
    )
    SOM_PASSPORT_END
};

class Image : public sciter::om::asset<Image> {
    HPDF_Image  image;

  public:
    static const int JPEG = 1;
    static const int PNG = 2;

    Image(HPDF_Doc& pdf, const char* filename, int type) {
        if(type == JPEG) {
            image = HPDF_LoadJpegImageFromFile(pdf, filename);
        } else if(type == PNG) {
            image = HPDF_LoadPngImageFromFile(pdf, filename);
        }
    }
    virtual ~Image() {};

    sciter::value getSize();
    int getWidth();
    int getHeight();
    int setMaskImage(sciter::value);
    HPDF_Image get();

    SOM_PASSPORT_BEGIN(Image)
    SOM_PASSPORT_FLAGS(SOM_SEALED_OBJECT)
    SOM_FUNCS(
        SOM_FUNC(getSize),
        SOM_FUNC(getWidth),
        SOM_FUNC(getHeight),
        SOM_FUNC(setMaskImage)
    )
    SOM_PASSPORT_END
};

class Font : public sciter::om::asset<Font> {
    HPDF_Font   font;

  public:

    Font(HPDF_Doc& pdf, const char* name, sciter::value encoding) {
      if(encoding.is_null()){
        font = HPDF_GetFont(pdf, name, NULL);
      }
      else {
        font = HPDF_GetFont(pdf, name, aux::w2a(encoding.to_string()));
      }
    }
    virtual ~Font() {};
    HPDF_Font get() {
      return font;
    };

    SOM_PASSPORT_BEGIN(Font)
    SOM_PASSPORT_FLAGS(SOM_SEALED_OBJECT)
    SOM_PASSPORT_END
};

}
#endif // PDF_H
