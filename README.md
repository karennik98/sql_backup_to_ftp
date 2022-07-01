# SQL Backup to FTP server.

### Dependencies ###
* sqlite3
* nlohmann json
* googletest

### What is this repository for? ###

* Windows console application, that is designed for generating data for a SQLite database and send backup file to a FTP server.
* version 1.0.0

### Build ###
```bash
mkdir build
cd ./build
cmake ..
make -j <job count>
```

### Build unit tests ###
```bash
mkdir build
cd ./build
cmake -DUNIT_TEST=ON ..
make -j <job count>
```

### Config file example ###
```json
{
  "db": {
    "name": "test.db",
    "backup_file": "test_backup.txt"
  },
  "ftp": {
    "hostname": "127.0.0.1",
    "port": 21,
    "username": "user",
    "password": "something",
    "upload_folder": "C:\\FTP"
  }
}
```

### Who do I talk to? ###

* Karen Nikoghosyan