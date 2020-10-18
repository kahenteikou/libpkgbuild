#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
struct PKGBUILD_INFO_STR{
    std::string pkgname;
    std::string pkgver;
    std::string pkgrel;
    std::string pkgdesc;
    std::vector<std::string> license;
    std::vector<std::string> groups;
    std::vector<std::string> pkg_arch;
    std::vector<std::string> depends;
    std::vector<std::string> makedepends;
    std::vector<std::string> checkdepends;
    std::vector<std::string> conflicts;
    std::vector<std::string> provides;
    std::vector<std::string> replaces;
};
int srcinfo_to_str(std::string srcinfo_filename,PKGBUILD_INFO_STR& return_obj);
