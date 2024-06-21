#include "FileHandler.h"
#include <stdexcept>

void FileHandler::writeToFile(const char* targetFilePath, const char* buffer, unsigned int bufferSize) {
    writeStream.open(targetFilePath, std::ios::binary);
    if (writeStream.is_open()) {
        writeStream.write(buffer, bufferSize);
        writeStream.close();
    } else {
        throw std::runtime_error("No se pudo abrir el archivo para escritura.");
    }
}

void FileHandler::readFromFile(const char* targetFilePath, char* buffer, unsigned int bufferSize) {
    readStream.open(targetFilePath, std::ios::binary);
    if (readStream.is_open()) {
        readStream.read(buffer, bufferSize);
        readStream.close();
    } else {
        throw std::runtime_error("No se pudo abrir el archivo para lectura.");
    }
}
