#ifndef FILE_DISPATCHER
#define FILE_DISPATCHER
#include <stdio.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <mutex>

class FileDispatcher {
    std::vector<std::string> fileList;
    int currentIndex = 0;
    std::mutex requestMutex;
    std::filesystem::path filePath;
public:
    FileDispatcher();
    FileDispatcher(std::filesystem::path inPath);
    void setFilePath(std::filesystem::path inPath);
    bool initFileList();
    std::string requestFileName();
};
#endif
