#include "driver.h"
#include "ftp_sender.h"
#include "config.h"

#include <iostream>

int main() {
//    bck::sql::driver driver;
//    driver.connect({"example.db"});
//    if(!driver.is_connected()) {
//        std::cerr<<"[ERROR]: Cant open DB file\n";
//        exit(-1);
//    }
//
//    std::string create = "CREATE TABLE PERSON("
//                      "ID INT PRIMARY KEY     NOT NULL, "
//                      "NAME           TEXT    NOT NULL, "
//                      "SURNAME          TEXT     NOT NULL, "
//                      "AGE            INT     NOT NULL, "
//                      "ADDRESS        CHAR(50), "
//                      "SALARY         REAL );";
//    driver.execute(create);
//
//    std::string insert("INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
//               "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
//               "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);");
//
//    driver.execute(insert);

    bck::json::config parser;
    parser.parse("C:\\Users\\karen\\CLionProjects\\SQL2FTP\\config.json");
    return 0;
}
