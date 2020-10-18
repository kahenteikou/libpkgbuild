#include "../src/libpkgbuild.hpp"
int main(int argc,char** argv){
    PKGBUILD_INFO_STR testkun;
    int intkun=srcinfo_to_str(".SRCINFO",testkun);
    std::vector<std::string> dependskun=testkun.depends;
    for(std::string bufstr : dependskun){
        std::cout << bufstr << " " << std::flush;
    }
    return 0;
}