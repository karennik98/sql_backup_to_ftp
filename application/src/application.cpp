#include "application.h"

#include <iostream>

namespace bck {
    std::once_flag application::init_instance_once;
    application application::app_instance;

    application &application::instance() {
        return app_instance;
    }

    void application::initialize_instance(const std::string& config)
    {
        std::call_once(init_instance_once, [&] {
            app_instance.initialize(config);
        });
    }

    void application::initialize(const std::string& config) {
        config_.parse(config);
        driver_.connect(config_.get_db_config());
        sender_.init(config_.get_ftp_config());
    }

    void application::run() {
        try {
            if(!driver_.is_connected()) {
                std::cerr<<"[ERROR]: Cant connect to the db\n";
                return;
            }

            std::string create = "CREATE TABLE IF NOT EXISTS PERSON("
                  "ID INT PRIMARY KEY     NOT NULL, "
                  "NAME           TEXT    NOT NULL, "
                  "SURNAME        TEXT    NOT NULL, "
                  "AGE            INT     NOT NULL, "
                  "ADDRESS        CHAR(50), "
                  "SALARY         REAL );";
            driver_.execute(create);

            int rows_count = 1;
            while(rows_count <= 100) {
                std::string insert("INSERT INTO PERSON VALUES(" + std::to_string(rows_count++) + ", 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);");
                auto code = driver_.execute(insert);
            }

            std::string select = "SELECT * FROM PERSON;";
            driver_.execute(select, callback);

            auto backup_file = driver_.backup();

            sender_.send_file(backup_file, "test.txt");

        } catch (const std::exception& ex) {
            std::cerr<<"[EXCEPTION]: "<<ex.what()<<std::endl;
        } catch(...) {
            std::cerr<<"[EXCEPTION]: ?????\n";
        }
    }

}