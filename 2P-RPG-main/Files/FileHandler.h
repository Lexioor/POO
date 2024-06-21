#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>

class FileHandler {
private:
    std::ifstream readStream;
    std::ofstream writeStream;

public:
    void writeToFile(const char* targetFilePath, const char* buffer, unsigned int bufferSize);
    void readFromFile(const char* targetFilePath, char* buffer, unsigned int bufferSize);
};

#endif // FILE_HANDLER_H
