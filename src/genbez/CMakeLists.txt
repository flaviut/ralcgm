add_executable(genbez
    genbez.c
    $<TARGET_OBJECTS:ralcgm_common>
)

target_include_directories(genbez PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    $<TARGET_PROPERTY:ralcgm_common,INCLUDE_DIRECTORIES>
)
