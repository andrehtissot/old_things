#ifndef _UTILS_FILE_SYSTEM_DIRECTORY_H_
#define _UTILS_FILE_SYSTEM_DIRECTORY_H_

namespace Utils {
  namespace FileSystem {
    class Directory {
      private:
        std::string path;

      public:
        Directory(const std::string path);
        ~Directory();
        const bool isDir() const;
        const bool isEmpty() const;
        std::vector<std::string>* findFilePaths(std::string const fileName);
        static std::string getRootPath();
        std::string absolutePath(std::string const fileName = "", std::string const absolutePathDir = "");
    };
  }
}

#endif