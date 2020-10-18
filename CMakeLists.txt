cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "/usr/bin/clang" CACHE string "clang compiler" FORCE)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE string "clang++ compiler" FORCE)
project(libpkgbuild CXX)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON) 
add_subdirectory(src)
add_subdirectory(test)

install(TARGETS pkgbuild
    EXPORT pkgbuild-export
    LIBRARY        DESTINATION usr/lib
    INCLUDES       DESTINATION usr/include
    PUBLIC_HEADER  DESTINATION usr/include/libpkgbuild)

install(EXPORT pkgbuild-export
    FILE libpkgbuild-config.cmake
    DESTINATION usr/share/cmake/libpkgbuild/
    )
