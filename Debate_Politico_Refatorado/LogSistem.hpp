#ifndef LOGSISTEM_HPP
#define LOGSISTEM_HPP

#include <iostream>
#include <string>

using namespace std;

class LogSistem {

private:

    static LogSistem* instance;

    string file_path;

    LogSistem(string file);

public:

    static LogSistem* get_instance(string file);

    void register_log(string msg);
};

#endif
