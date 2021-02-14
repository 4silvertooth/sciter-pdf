#include "PDF.h"
#include <sstream>

static char* error_message(unsigned int error_no) {
    switch(error_no) {
    case 0x1001:
        return "Internal error. The consistency of the data was lost.";
    case 0x1002:
        return "Internal error. The consistency of the data was lost.";
    case 0x1003:
        return "Internal error. The consistency of the data was lost.";
    case 0x1004:
        return "The length of the data exceeds HPDF_LIMIT_MAX_STRING_LEN.";
    case 0x1005:
        return "Cannot get a pallet data from PNG image.";
    case 0x1007:
        return "The count of elements of a dictionary exceeds HPDF_LIMIT_MAX_DICT_ELEMENT";
    case 0x1008:
        return "Internal error. The consistency of the data was lost.";
    case 0x1009:
        return "Internal error. The consistency of the data was lost.";
    case 0x100A:
        return "Internal error. The consistency of the data was lost.";
    case 0x100B:
        return "HPDF_SetPermission() OR HPDF_SetEncryptMode() was called before a password is set.";
    case 0x100C:
        return "Internal error. The consistency of the data was lost.";
    case 0x100E:
        return "Tried to register a font that has been registered.";
    case 0x100F:
        return "Cannot register a character to the japanese word wrap characters list.";
    case 0x1011:
        return "Tried to set the owner password to NULL.\nThe owner password and user password is the same.";
    case 0x1013:
        return "Internal error. The consistency of the data was lost.";
    case 0x1014:
        return "The depth of the stack exceeded HPDF_LIMIT_MAX_GSTATE.";
    case 0x1015:
        return "Memory allocation failed.";
    case 0x1016:
        return "File processing failed. (A detailed code is set.)";
    case 0x1017:
        return "Cannot open a file. (A detailed code is set.)";
    case 0x1019:
        return "Tried to load a font that has been registered.";
    case 0x101A:
        return "The format of a font-file is invalid .\nInternal error. The consistency of the data was lost.";
    case 0x101B:
        return "Cannot recognize a header of an afm file.";
    case 0x101C:
        return "The specified annotation handle is invalid.";
    case 0x101E:
        return "Bit-per-component of a image which was set as mask-image is invalid.";
    case 0x101F:
        return "Cannot recognize char-matrics-data of an afm file.";
    case 0x1020:
        return "1. The color_space parameter of HPDF_LoadRawImage is invalid.\n2. Color-space of a image which was set as mask-image is invalid.\n3. The function which is invalid in the present color-space was invoked.";
    case 0x1021:
        return "Invalid value was set when invoking HPDF_SetCommpressionMode().";
    case 0x1022:
        return "An invalid date-time value was set.";
    case 0x1023:
        return "An invalid destination handle was set.";
    case 0x1025:
        return "An invalid document handle is set.";
    case 0x1026:
        return "The function which is invalid in the present state was invoked.";
    case 0x1027:
        return "An invalid encoder handle is set.";
    case 0x1028:
        return "A combination between font and encoder is wrong.";
    case 0x102B:
        return "An Invalid encoding name is specified.";
    case 0x102C:
        return "The lengh of the key of encryption is invalid.";
    case 0x102D:
        return "1. An invalid font handle was set.\n2. Unsupported font format.";
    case 0x102E:
        return "Internal error. The consistency of the data was lost.";
    case 0x102F:
        return "A font which has the specified name is not found.";
    case 0x1030:
        return "Unsupported image format.";
    case 0x1031:
        return "Unsupported image format.";
    case 0x1032:
        return "Cannot read a postscript-name from an afm file.";
    case 0x1033:
        return "1. An invalid object is set.\n2. Internal error. The consistency of the data was lost.";
    case 0x1034:
        return "Internal error. The consistency of the data was lost.";
    case 0x1035:
        return "1. Invoked HPDF_Image_SetColorMask() against the image-object which was set a mask-image.";
    case 0x1036:
        return "An invalid outline-handle was specified.";
    case 0x1037:
        return "An invalid page-handle was specified.";
    case 0x1038:
        return "An invalid pages-handle was specified. (internel error)";
    case 0x1039:
        return "An invalid value is set.";
    case 0x103B:
        return "Invalid PNG image format.";
    case 0x103C:
        return "Internal error. The consistency of the data was lost.";
    case 0x103D:
        return "Internal error. The '_FILE_NAME' entry for delayed loading is missing.";
    case 0x103F:
        return "Invalid .TTC file format.";
    case 0x1040:
        return "The index parameter was exceed the number of included fonts";
    case 0x1041:
        return "Cannot read a width-data from an afm file.";
    case 0x1042:
        return "Internal error. The consistency of the data was lost.";
    case 0x1043:
        return "An error has returned from PNGLIB while loading an image.";
    case 0x1044:
        return "Internal error. The consistency of the data was lost.";
    case 0x1045:
        return "Internal error. The consistency of the data was lost.";
    case 0x1049:
        return "Internal error. The consistency of the data was lost.";
    case 0x104A:
        return "Internal error. The consistency of the data was lost.";
    case 0x104B:
        return "Internal error. The consistency of the data was lost.";
    case 0x104C:
        return "There are no graphics-states to be restored.";
    case 0x104D:
        return "Internal error. The consistency of the data was lost.";
    case 0x104E:
        return "The current font is not set.";
    case 0x104F:
        return "An invalid font-handle was spacified.";
    case 0x1050:
        return "An invalid font-size was set.";
    case 0x1051:
        return "See Graphics mode.";
    case 0x1052:
        return "Internal error. The consistency of the data was lost.";
    case 0x1053:
        return "The specified value is not a multiple of 90.";
    case 0x1054:
        return "An invalid page-size was set.";
    case 0x1055:
        return "An invalid image-handle was set.";
    case 0x1056:
        return "The specified value is out of range.";
    case 0x1057:
        return "The specified value is out of range.";
    case 0x1058:
        return "Unexpected EOF marker was detected.";
    case 0x1059:
        return "Internal error. The consistency of the data was lost.";
    case 0x105B:
        return "The length of the specified text is too long.";
    case 0x105C:
        return "The execution of a function was skipped because of other errors.";
    case 0x105D:
        return "This font cannot be embedded. (restricted by license)";
    case 0x105E:
        return "Unsupported ttf format. (cannot find unicode cmap.)";
    case 0x105F:
        return "Unsupported ttf format.";
    case 0x1060:
        return "Unsupported ttf format. (cannot find a necessary table) ";
    case 0x1061:
        return "Internal error. The consistency of the data was lost.";
    case 0x1062:
        return "1. The library is not configured to use PNGLIB.\n2. Internal error. The consistency of the data was lost.";
    case 0x1063:
        return "Unsupported Jpeg format.";
    case 0x1064:
        return "Failed to parse .PFB file.";
    case 0x1065:
        return "Internal error. The consistency of the data was lost.";
    case 0x1066:
        return "An error has occurred while executing a function of Zlib.";
    case 0x1067:
        return "An error returned from Zlib.";
    case 0x1068:
        return "An invalid URI was set.";
    case 0x1069:
        return "An invalid page-layout was set.";
    case 0x1070:
        return "An invalid page-mode was set.";
    case 0x1071:
        return "An invalid page-num-style was set.";
    case 0x1072:
        return "An invalid icon was set.";
    case 0x1073:
        return "An invalid border-style was set.";
    case 0x1074:
        return "An invalid page-direction was set.";
    case 0x1075:
        return "An invalid font-handle was specified.";
    default:
        return "Unknown Error.";
    }
}

void error_handler (HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data) {
    /* throw exception when an error has occured */
    std::ostringstream err;
    err << "error_no = "   << std::hex << (unsigned int)error_no
        << " detail_no = " << (int)detail_no
        << " message = "   <<  error_message((unsigned int)error_no);
    throw sciter::om::exception(err.str());
}

namespace libharu {

Doc::Doc() {
    pdf = HPDF_New (error_handler, NULL);
    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);
    HPDF_UseUTFEncodings(pdf);
}

sciter::value Doc::addPage() {
    auto page = new libharu::Page(pdf);
    return sciter::value::wrap_asset(page);
}

int Doc::newDoc() {
    return HPDF_NewDoc (pdf);
}

int Doc::save(sciter::astring path) {
    return HPDF_SaveToFile (pdf, path.c_str());
}

sciter::value Doc::loadTTFontFromFile(sciter::astring path, HPDF_BOOL embed) {
    const char* font_name = HPDF_LoadTTFontFromFile(pdf, path.c_str(), embed);
    return sciter::value::make_string(font_name);
}

int Doc::setPassword(sciter::astring owner, sciter::astring user) {
    return HPDF_SetPassword(pdf, owner.c_str(), user.c_str() );
}

sciter::value Doc::loadPngImageFromFile(sciter::astring filename) {
    auto ret = new libharu::Image(pdf, filename.c_str(), Image::PNG);
    return sciter::value::wrap_asset(ret);
}

sciter::value Doc::loadJpegImageFromFile(sciter::astring filename) {
    auto ret = new libharu::Image(pdf, filename.c_str(), Image::JPEG);
    return sciter::value::wrap_asset(ret);
}

int Doc::free() {
    HPDF_Free (pdf);
    return 0;
}

Doc::~Doc() {
    HPDF_Free (pdf);
}

}
