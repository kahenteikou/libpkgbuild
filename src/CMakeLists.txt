ADD_LIBRARY(pkgbuild SHARED libpkgbuild.cpp)
set_target_properties(pkgbuild PROPERTIES
    PUBLIC_HEADER src/libpkgbuild.hpp
)

