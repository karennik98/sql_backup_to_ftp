#pragma once

#include "config.h"
#include "driver.h"
#include "ftp_sender.h"

#include <string>
#include <mutex>

namespace bck {
    class application {
    public:
        ~application() = default;

    public:
        application& operator=(const application&) = delete;
        application(const application& other) = delete;

    public:
        static application& instance();

    protected:
        application() = default;

    private:
        void initialize(const std::string& config);

    public:
        static void initialize_instance(const std::string& config);

    private:
        static std::once_flag init_instance_once;
        static application app_instance;

    public:
        void execute();

    private:
        sql::driver driver_;
        ftp::sender sender_;
        json::config_parser config_;
    };
}