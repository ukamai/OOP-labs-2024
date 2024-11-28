#include "FileObserver.h"
#include <fstream>

FileObserver::FileObserver() : logFile("log.txt", std::ios::app) {}

void FileObserver::update(const std::string& event) {
    if (logFile.is_open()) {
        logFile << event << std::endl;
    }
}