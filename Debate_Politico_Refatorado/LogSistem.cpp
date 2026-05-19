#include "LogSistem.hpp"

LogSistem* LogSistem::instance = nullptr;

LogSistem::LogSistem(string file) {

    file_path = file;
}

LogSistem* LogSistem::get_instance(string file) {

    if(instance == nullptr) {

        instance = new LogSistem(file);

        instance->register_log(
            "Sistema de log iniciado"
        );
    }

    return instance;
}

void LogSistem::register_log(string msg) {
    
    cout << "\033[36m";
    cout << "[LOG] " << msg << endl;
    cout << "\033[0m";

}
