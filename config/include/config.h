#pragma once

#include "json.h"
#include "driver.h"
#include "ftp_sender.h"

#include <string>

namespace bck::json {
    class config {
    public:
        void parse(const std::string& path);
    private:
        nlohmann::json parse_file(const std::string& path);
    public:
        sql::config db_config_;
        ftp::config ftp_confog_;
    };

}