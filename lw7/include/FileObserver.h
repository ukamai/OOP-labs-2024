#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "Observer.h"
#include <fstream>

class FileObserver : public Observer {
public:
    FileObserver();
    void update(const std::string& event) override;

private:
    std::ofstream logFile;
};

#endif // FILEOBSERVER_H