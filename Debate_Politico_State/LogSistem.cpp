#include <iostream>

#include "LogSistem.hpp"

using namespace std;

LogSistem*
LogSistem::instance =
nullptr;

LogSistem::LogSistem(
    string file
)
{
    file_path = file;
}

LogSistem*
LogSistem::get_instance(
    string file
)
{
    if(instance == nullptr)
    {
        instance =
            new LogSistem(file);

        instance->register_log(
            "Sistema de log iniciado"
        );
    }

    return instance;
}

void LogSistem::register_log(
    string msg
)
{
    cout
        << "[LOG] "
        << msg
        << endl;
}