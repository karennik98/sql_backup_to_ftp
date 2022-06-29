#include "application.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cerr<<"[ERROR]: Pass the config file\n";
        exit(-1);
    }
    bck::application::initialize_instance(argv[1]);
    bck::application::instance().execute();
    return 0;
}
