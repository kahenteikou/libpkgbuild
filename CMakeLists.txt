cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "/usr/bin/clang" CACHE string "clang compiler" FORCE)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE string "clang++ compiler" FORCE)
project(libpkgbuild CPP)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON) 
add_subdirectory(src)
add_subdirectory(test)

install(TARGETS pkgbuild
    EXPORT pkgbuild-export
    LIBRARY        DESTINATION lib
    INCLUDES       DESTINATION include
    PUBLIC_HEADER  DESTINATION include/libpkgbuild)

install(EXPORT pkgbuild-export
    FILE libpkgbuild-config.cmake
    DESTINATION share/cmake/libpkgbuild/
    EXPORT_LINK_INTERFACE_LIBRARIES)
