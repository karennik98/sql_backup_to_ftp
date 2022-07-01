#pragma once

#include "config.h"
#include "driver.h"
#include "ftp_sender.h"

#include <string>
#include <mutex>

namespace bck {
    static int callback(void* data, int argc, char** argv, char** azColName)
    {
        int i;
        fprintf(stderr, "%s: ", (const char*)data);

        for (i = 0; i < argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }

        printf("\n");
        return 0;
    }

    class application {
    public:
        ~application() = default;

    public:
        application(application&& other) = delete;
        application(const application& other) = delete;
        application& operator=(const application&) = delete;
        application& operator=(application&&) = delete;

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
        void run();

    private:
        sql::driver driver_;
        ftp::sender sender_;
        json::config_parser config_;
    };
}