#include "../src/libpkgbuild.hpp"
int main(int argc,char** argv){
    PKGBUILD_INFO_STR testkun;
    int intkun=srcinfo_to_str(".SRCINFO",testkun);
    std::cout << testkun.pkgname << std::endl;
    return 0;
}