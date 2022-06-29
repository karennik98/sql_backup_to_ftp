#include "ftp_sender.h"

#include <stdexcept>

#include <windows.h>
#include <wininet.h>

namespace bck::ftp {
    sender::sender(config cfg)
    : cfg_(std::move(cfg)) {

    }

    void sender::init(const config &cfg) {
        cfg_ = cfg;
    }

    void sender::send_file(const std::string &file_path, const std::string& remote_file) const {
        const HINTERNET hInternet = InternetOpen(nullptr, INTERNET_OPEN_TYPE_DIRECT, nullptr, nullptr, 0);

        const HINTERNET hFtpSession = InternetConnect(hInternet
                , cfg_.hostname.c_str()
                , cfg_.port
                , cfg_.username.c_str()
                , cfg_.password.c_str()
                , INTERNET_SERVICE_FTP
                , INTERNET_FLAG_PASSIVE
                , 0);

        if (nullptr == hFtpSession)
        {
            throw std::runtime_error {"[ERROR]: Connection to FTP server failed. Error code:"
                                      + std::to_string(GetLastError())};
        }

        const auto status = FtpPutFile(hFtpSession
                , file_path.data()
                , remote_file.data()
                , FTP_TRANSFER_TYPE_BINARY
                , 0);

        if (!status)
        {
            throw std::runtime_error {"[ERROR]: File sending failed. Error code:"
                                      + std::to_string(GetLastError())};
        }

        InternetCloseHandle(hFtpSession);
        InternetCloseHandle(hInternet);
    }
}