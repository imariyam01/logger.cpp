#ifndef MYLOGGER_H
#define MYLOGGER_H

#include <string>
#include <mutex>
#include <fstream>

class MyLogger {
public:
    static void init(const std::string& filename);
    static void log(const char* format, ...);
    static void close();

private:
    static std::ofstream file;
    static std::mutex mtx;
    static bool initialized;
};

#endif // MYLOGGER_H
