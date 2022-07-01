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
        using callback_t = std::add_pointer_t<int(void*, int, char**, char**)>;

    public:
        driver() = default;
        explicit driver(config cfg);
        ~driver() = default;

        driver(const driver&) = delete;
        driver(driver&&) noexcept = delete;
        driver& operator=(const driver&) = delete;
        driver& operator=(driver&&) noexcept = delete;

    public:
        void connect(const config& cfg);

    public:
        [[nodiscard]] bool is_connected() const noexcept { return is_connected_; }

    public:
        int execute(const std::string& cmd);
        int execute(const std::string& cmd, callback_t callback);
        [[nodiscard]] std::string backup() const;

    private:
        config cfg_;
        bool is_connected_{false};
        std::shared_ptr<sqlite3> db_;
    };
}