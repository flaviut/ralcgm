add_executable(ralcgm
    src/cgmmain.c
    src/cgmichar.c
    src/cgmitext.c
    src/cgmibin.c
    src/cgmochar.c
    src/cgmotext.c
    src/cgmobin.c
    src/cgmops.c
    src/cgmrand.c
    src/cgmprof.c
    src/cgminput.c
    src/cgmatt.c
    src/cgmgdp.c
    src/cgmpoly.c
    src/cgmtrap.c
    src/cgmfill.c
    src/cgmgraph.c
    src/cgmcolr.c
    src/cgmcell.c
    src/cgmpts.c
    src/cgmbez.c
    src/cgmher.c
    src/cgmtext.c
    src/cgmfont.c
    $<TARGET_OBJECTS:ralcgm_common>
)

target_include_directories(ralcgm PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    $<TARGET_PROPERTY:ralcgm_common,INCLUDE_DIRECTORIES>
)
target_link_libraries(ralcgm m)

install(TARGETS ralcgm DESTINATION bin)
