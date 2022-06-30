#pragma once

#include <string>

namespace bck::ftp {
    struct config {
        std::string hostname;
        int port;
        std::string username;
        std::string password;
        std::string upload_folder;
    };

    class sender {
    public:
        sender() = default;
        explicit sender(config cfg);
    public:
        void init(const config& cfg);
    public:
        void send_file(const std::string &file_path, const std::string& remote_file) const;
    private:
        config cfg_;
    };
}