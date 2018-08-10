add_library(ralcgm_common OBJECT
    src/cgmfile.c
    src/cgmerr.c
)

target_include_directories(ralcgm_common PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)
