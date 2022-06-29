#include <iostream>
#include <fstream>

#include "driver.h"

namespace bck::sql {
    driver::driver(config cfg)
    : cfg_(std::move(cfg)) {
        connect(cfg_);
    }

    driver::~driver() {
        sqlite3_close(db_);
    }

    void driver::connect(const config &cfg) {
        cfg_ = cfg;
        is_connected_ = (sqlite3_open(cfg_.db_name.c_str(), &db_) == 0);
        std::cout<<"is_connected: "<<is_connected_<<std::endl;
    }

    int driver::execute(const std::string &cmd) {
        std::cout << "[INFO]: Start executing " << cmd << " command\n";

        char *err_msg;
        auto is_ok = sqlite3_exec(db_, cmd.c_str(), nullptr, nullptr, &err_msg);

        if (is_ok != SQLITE_OK) {
            std::cerr << "[ERROR]: Cant execute command" << std::endl;
            sqlite3_free(err_msg);
        }

        return is_ok;
    }

    std::string driver::backup() const {
        std::string line;

        std::ofstream bck_file(cfg_.db_backup);
        if(!bck_file.is_open()) {
            std::cerr<<"[ERROR]: Cant open backup file: "<<cfg_.db_backup<<std::endl;
            return {};
        }

        std::ifstream db_file (cfg_.db_name);
        if(!db_file.is_open()) {
            std::cerr<<"[ERROR]: Cant open db file: "<<cfg_.db_name<<std::endl;
            return {};
        }

        while ( getline (db_file,line) ) {
            bck_file<<line<<std::endl;
        }

        db_file.close();
        bck_file.close();

        return cfg_.db_backup;
    }
}