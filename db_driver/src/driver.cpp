#include <iostream>

#include "driver.h"

namespace bck {
    driver::driver(std::string db_file)
    : db_file_(std::move(db_file)) {
        connect(db_file_);
    }

    driver::~driver() {
        sqlite3_close(db_);
    }

    void driver::connect(const std::string &db_file) {
        db_file_ = db_file;
        is_connected_ = (sqlite3_open(db_file_.c_str(), &db_) == 0);
        std::cout<<"is_connected: "<<is_connected_<<std::endl;
    }

    int driver::execute(const std::string &cmd) {
        std::cout << "[INFO]: Start executing " << cmd << " command\n";

        char *err_msg;
        auto is_ok = sqlite3_exec(db_, cmd.c_str(), nullptr, nullptr, &err_msg);

        if (is_ok != SQLITE_OK) {
            std::cerr << "Error Create Table" << std::endl;
            sqlite3_free(err_msg);
        } else {
            std::cout << "Table created Successfully" << std::endl;
        }

        return is_ok;
    }
}