#pragma once

#include "sqlite3.h"

#include <string>
#include <memory>

namespace bck::sql {

    struct config {
        std::string db_name;
        std::string db_backup;
    };

    class driver {
    public:
        driver() = default;
        explicit driver(config cfg);
        ~driver();

    public:
        void connect(const config& cfg);

    public:
        [[nodiscard]] bool is_connected() const noexcept { return is_connected_; }

    public:
        int execute(const std::string& cmd);
        std::string backup() const;

    private:
        config cfg_;
        bool is_connected_{false};
        sqlite3* db_ = nullptr;
    };
}