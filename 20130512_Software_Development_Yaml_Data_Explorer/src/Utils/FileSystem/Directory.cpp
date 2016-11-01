#ifndef _UTILS_FILE_SYSTEM_DIRECTORY_CPP_
#define _UTILS_FILE_SYSTEM_DIRECTORY_CPP_

#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <list>
#include "Directory.h"
using namespace Utils::FileSystem;

Directory::Directory(const std::string path){
  this->path = path;
};
Directory::~Directory(){};
const bool Directory::isDir() const {
  std::stringstream absolutePathStream;
  absolutePathStream << Directory::getRootPath() << '/' << this->path << "/..";
  std::string absolutePathString = absolutePathStream.str();
  char* absolutePathCharArray = new char[absolutePathString.length() + 1];
  strcpy(absolutePathCharArray, absolutePathString.c_str());

  DIR *dir;
  struct dirent *dent;
  dir = opendir(absolutePathCharArray);
  bool isDir = false;
  if(dir!=NULL)
    isDir = true;
  closedir(dir);
  delete [] absolutePathCharArray;
  return isDir;
}
const bool Directory::isEmpty() const {
  std::stringstream absolutePathStream;
  absolutePathStream << Directory::getRootPath() << '/' << this->path;
  std::string absolutePathString = absolutePathStream.str();
  char* absolutePathCharArray = new char[absolutePathString.length() + 1];
  strcpy(absolutePathCharArray, absolutePathString.c_str());

  DIR *dir;
  struct dirent *dent;
  dir = opendir(absolutePathCharArray);
  bool isEmpty = true;
  if(dir!=NULL)
    while((dent=readdir(dir))!=NULL)
      if(std::strcmp(dent->d_name, ".") != 0 && std::strcmp(dent->d_name, "..") != 0) {
        isEmpty = false;
        break;
      }
  closedir(dir);
  delete [] absolutePathCharArray;
  return isEmpty;
}
std::string Directory::getRootPath() {
  char *real_path = realpath(".", NULL);
  std::string result = std::string(real_path);
  free(real_path);  
  return result;
}

std::vector<std::string>* Directory::findFilePaths(std::string const fileName){
  std::vector<std::string>* foundFiles = new std::vector<std::string>;
  std::list<std::string>* foundDirectories = new std::list<std::string>;
  foundDirectories->push_front(this->absolutePath());
  DIR *dir;
  struct dirent *dent;

  while(!foundDirectories->empty()) {
    dir = opendir(foundDirectories->front().c_str());
    if(dir==NULL){
      std::string filePath = foundDirectories->front();
      if(filePath.compare(filePath.find_last_of('/') + 1, fileName.length(), fileName) == 0)
        foundFiles->push_back(filePath);
    } else {
      while((dent=readdir(dir))!=NULL)
        if(std::strcmp(dent->d_name, ".") != 0 && std::strcmp(dent->d_name, "..") != 0 && std::strcmp(dent->d_name, ".svn") != 0) {
          foundDirectories->push_back(this->absolutePath(dent->d_name, foundDirectories->front()));
        }
    }
    foundDirectories->pop_front();
    closedir(dir);
  }
  delete(foundDirectories);
  return foundFiles;
}

std::string Directory::absolutePath(std::string const fileName, std::string const absolutePathDir){
  std::stringstream absolutePathStream;
  if(absolutePathDir.compare("") == 0)
    absolutePathStream << Directory::getRootPath() << '/' << this->path;
  else
    absolutePathStream << absolutePathDir;
  if(fileName.compare("") != 0)
    absolutePathStream << '/' << fileName;
  return absolutePathStream.str();
}
#endif