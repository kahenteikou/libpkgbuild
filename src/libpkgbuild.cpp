#include "libpkgbuild.hpp"
std::string trim_before_after(const std::string& srcstr){
    std::string trim_char=" ";   //remove space
    size_t poskun=srcstr.find_first_not_of(trim_char);
    return srcstr.substr(poskun);
}
bool start_with(std::string target,std::string prefix){
    auto szkun=prefix.size();
    if(target.size() < szkun) return false;
    return std::equal(std::begin(prefix),std::end(prefix),std::begin(target));
}

std::string replace_strkun(std::string src,std::string from,std::string to){
    std::string str_copykun(src.c_str(),src.length());
    const unsigned int pos=str_copykun.find(from);
    const int len=from.length();
    if(pos == std::string::npos || from.empty()) {
        return str_copykun;
    }
    return str_copykun.replace(pos,len,to);
}
int srcinfo_to_str(std::string srcinfo_filename,PKGBUILD_INFO_STR& return_obj){
    std::string buff;
    std::string work_strline;
    std::ifstream ifs(srcinfo_filename.c_str());
    if(!ifs.is_open()){
        return -1;
    }
    while(std::getline(ifs,buff)){
        work_strline=trim_before_after(buff);
        if(start_with(work_strline,"pkgname")){
            return_obj.pkgname=replace_strkun(work_strline,"pkgbase = ","");
        }else
        if(start_with(work_strline,"pkgver")){
            return_obj.pkgver=replace_strkun(work_strline,"pkgver = ","");
        }else
        if(start_with(work_strline,"pkgrel")){
            return_obj.pkgrel=replace_strkun(work_strline,"pkgrel = ","");
        }else
        if(start_with(work_strline,"pkgdesc")){
            return_obj.pkgdesc=replace_strkun(work_strline,"pkgdesc = ","");
        }else
        if(start_with(work_strline,"license")){
            return_obj.license.push_back(replace_strkun(work_strline,"license = ",""));
        }else
        if(start_with(work_strline,"depends")){
            return_obj.depends.push_back(replace_strkun(work_strline,"depends = ",""));
        }else
        if(start_with(work_strline,"makedepends")){
            return_obj.makedepends.push_back(replace_strkun(work_strline,"makedepends = ",""));
        }else
        if(start_with(work_strline,"checkdepends")){
            return_obj.checkdepends.push_back(replace_strkun(work_strline,"checkdepends = ",""));
        }else
        if(start_with(work_strline,"conflicts")){
            return_obj.conflicts.push_back(replace_strkun(work_strline,"conflicts = ",""));
        }else
        if(start_with(work_strline,"provides")){
            return_obj.provides.push_back(replace_strkun(work_strline,"provides = ",""));
        }else
        if(start_with(work_strline,"replaces")){
            return_obj.replaces.push_back(replace_strkun(work_strline,"replaces = ",""));
        }else
        if(start_with(work_strline,"arch")){
            return_obj.pkg_arch.push_back(replace_strkun(work_strline,"arch = ",""));
        }else
        if(start_with(work_strline,"groups")){
            return_obj.groups.push_back(replace_strkun(work_strline,"groups = ",""));
        }
    }
    return 0;
}