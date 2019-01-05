#pragma once


class Serialization
{
public:

    static bool obj2file(const WebSite &website, const ::std::string &target_dirpath);

    static WebSite file2obj(const ::std::string &src_path);
};
