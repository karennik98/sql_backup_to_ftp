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
        ~driver() = default;
        driver(const driver&) = default;
        driver(driver&&) noexcept = default;
        driver& operator=(const driver&) = default;
        driver& operator=(driver&&) noexcept = default;

        explicit driver(config cfg);

    public:
        void connect(const config& cfg);

    public:
        [[nodiscard]] bool is_connected() const noexcept { return is_connected_; }

    public:
        int execute(const std::string& cmd);
        [[nodiscard]] std::string backup() const;

    private:
        config cfg_;
        bool is_connected_{false};
        std::shared_ptr<sqlite3> db_;
    };
}