#include "fileDispatcher.h"

FileDispatcher::FileDispatcher(std::filesystem::path inPath)
{
    setFilePath(inPath);
}

void FileDispatcher::setFilePath(std::filesystem::path inPath)
{
    filePath = inPath;
}

bool FileDispatcher::initFileList()
{
    std::string fileName;
    for (const std::filesystem::directory_entry &dirEntry : std::filesystem::recursive_directory_iterator(filePath))
    {
        if (dirEntry.is_regular_file())
        {
            fileName = dirEntry.path().string();
            if (fileName.find(".4bpp.lz") == std::string::npos)
                continue;
        }
        else
        {
            continue;
        }
        fileList.push_back(fileName);
    }

    if (fileList.size() == 0)
        return false;
    else
        return true;
}

std::string FileDispatcher::requestFileName()
{
    if (currentIndex >= fileList.size())
        return "";
    std::string returnString = fileList[currentIndex];
    std::cout << "Dispatching index " << currentIndex << ": " << returnString << "\n";
    currentIndex++;
    return returnString;
}
