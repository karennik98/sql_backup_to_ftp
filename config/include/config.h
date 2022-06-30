#pragma once

#include "json.h"
#include "driver.h"
#include "ftp_sender.h"

#include <string>

namespace bck::json {
    class config_parser {
    public:
        void parse(const std::string& path);

    public:
        ftp::config get_ftp_config() { return ftp_confog_; };
        sql::config get_db_config()  { return db_config_;  };
    private:
        static static static nlohmann::json parse_file(const std::string& path);
    private:
        sql::config db_config_;
        ftp::config ftp_confog_;
    };

}