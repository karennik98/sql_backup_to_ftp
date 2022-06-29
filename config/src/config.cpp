#include "config.h"

#include <fstream>
#include <iostream>

namespace bck::json {
    void config::parse(const std::string& path) {
        auto jobj = parse_file(path);

        db_config_.db_name = jobj["db"]["name"];

        ftp_confog_.hostname = jobj["ftp"]["hostname"];
        ftp_confog_.port = jobj["ftp"]["port"];
        ftp_confog_.username = jobj["ftp"]["username"];
        ftp_confog_.password = jobj["ftp"]["password"];
    }

    nlohmann::json config::parse_file(const std::string &path) {
        std::ifstream ifile(path);
        std::string line;
        std::string json_text;
        while (std::getline(ifile, line)) {
            json_text += (line + '\n');
        }
        ifile.close();
        return nlohmann::json::parse(json_text);
    }
}
