cmake_minimum_required(VERSION 3.25)
include(FetchContent)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(SKIP_INSTALL_EXPORT TRUE)
project(sciter-pdf)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
if (UNIX AND NOT APPLE)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(GTK REQUIRED libgtk-3-dev)
  include_directories(${LIBGTK_INCLUDE_DIRS})  
endif (UNIX)

FetchContent_Declare(libpng
  GIT_REPOSITORY  https://github.com/glennrp/libpng.git
  GIT_TAG         v1.6.39
  GIT_SHALLOW     TRUE
  GIT_PROGRESS    TRUE
)

FetchContent_Declare(zlib
  GIT_REPOSITORY  https://github.com/madler/zlib.git
  GIT_TAG         v1.2.13
  GIT_SHALLOW     TRUE
  GIT_PROGRESS    TRUE
)

FetchContent_Declare(libharu
  GIT_REPOSITORY  https://github.com/libharu/libharu.git
  GIT_TAG         8dbcfe470581edc4bc52c3ef132d410e66cadc20
  GIT_SHALLOW     TRUE
  GIT_PROGRESS    TRUE
  OVERRIDE_FIND_PACKAGE
)

FetchContent_Declare(sciter
  GIT_REPOSITORY  https://gitlab.com/sciter-engine/sciter-js-sdk.git
  GIT_TAG         e1097e0351ca989171967e47a7fe26db4d23cc9a
  GIT_SHALLOW     TRUE
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""  
)

FetchContent_GetProperties(zlib)
if(NOT zlib_POPULATED)
  FetchContent_Populate(zlib)

  set(ZLIB_INCLUDE_DIR ${zlib_SOURCE_DIR} ${zlib_BINARY_DIR})
  set(ZLIB_LIBRARY zlibstatic)

  execute_process(
    COMMAND           ${GIT_EXECUTABLE} apply ${CMAKE_CURRENT_LIST_DIR}/cmake/zlib.patch
    WORKING_DIRECTORY ${zlib_SOURCE_DIR}
    OUTPUT_QUIET
    ERROR_QUIET
  )

  set(CMAKE_PROJECT_INCLUDE_BEFORE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/enable_cmp0048.cmake")
  add_subdirectory(${zlib_SOURCE_DIR} ${zlib_BINARY_DIR} EXCLUDE_FROM_ALL)
  unset(CMAKE_PROJECT_INCLUDE_BEFORE)
endif()

find_package(ZLIB REQUIRED)

if(NOT libpng_POPULATED)
  FetchContent_Populate(libpng)

  set(PNG_PNG_INCLUDE_DIR ${libpng_SOURCE_DIR} ${libpng_BINARY_DIR})
  set(PNG_LIBRARY png_static)

  cmake_policy(SET CMP0077 NEW)
  set(PNG_SHARED OFF)
  set(CMAKE_PROJECT_INCLUDE_BEFORE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/enable_cmp0048.cmake")
  add_subdirectory(${libpng_SOURCE_DIR} ${libpng_BINARY_DIR} EXCLUDE_FROM_ALL)
  unset(CMAKE_PROJECT_INCLUDE_BEFORE)

endif()

find_package(PNG REQUIRED)

FetchContent_GetProperties(libharu)
if(NOT libharu_POPULATED)
  FetchContent_Populate(libharu)
  set(LIBHPDF_STATIC ON)
  set(BUILD_SHARED_LIBS OFF)
  set(HPDF_LIBRARY hpdf)
  add_subdirectory(${libharu_SOURCE_DIR} ${libharu_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_MakeAvailable(sciter)

include_directories(
  ${libharu_SOURCE_DIR}/include 
  ${libharu_BINARY_DIR}/include 
  ${sciter_SOURCE_DIR}/include 
)

add_library(sciter-pdf SHARED Doc.cpp Image.cpp Page.cpp PDF.cpp PDF.h sciter-pdf.def)
target_link_libraries(sciter-pdf PUBLIC ${HPDF_LIBRARY})

add_library(sciter-pdf-static STATIC Doc.cpp Image.cpp Page.cpp PDF.cpp PDF.h sciter-pdf.def)
target_link_libraries(sciter-pdf PUBLIC ${HPDF_LIBRARY})
