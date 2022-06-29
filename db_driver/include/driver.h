#pragma once

#include "sqlite3.h"

#include <string>
#include <memory>

namespace bck {
    class driver {
    public:
        driver() = default;
        explicit driver(std::string db_file);
        ~driver();

    public:
        void connect(const std::string& db_file);

    public:
        [[nodiscard]] bool is_connected() const noexcept { return is_connected_; }

    public:
        int execute(const std::string& cmd);

    private:
        std::string db_file_{};
        bool is_connected_{false};
        sqlite3* db_ = nullptr;
    };
}