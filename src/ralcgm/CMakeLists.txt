add_executable(ralcgm
        src/cgmmain.c
        src/cgmichar.c
        src/cgmitext.c
        src/cgmibin.c
        src/cgmochar.c
        src/cgmotext.c
        src/cgmobin.c
        src/cgmrand.c
        src/cgmprof.c
        src/cgminput.c
        src/cgmfile.c
        src/cgmerr.c
        )

target_include_directories(ralcgm PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
target_link_libraries(ralcgm m)

install(TARGETS ralcgm DESTINATION bin)
