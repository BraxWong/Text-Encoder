#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

class File{
  public:
    std::vector<std::string> readFileData(std::string fileName);
    void writeToFile(std::vector<std::string> fileData, std::string fileName);
};

std::vector<std::string> File::readFileData(std::string fileName)
{
  std::fstream file(fileName);
  std::vector<std::string> fileData;
  std::string currentLine;
  while(getline(file,currentLine))
  {
    fileData.push_back(currentLine);
  }
  return fileData;
}

void File::writeToFile(std::vector<std::string> fileData, std::string fileName)
{
  std::ofstream file(fileName);
  for(int i = 0; i < fileData.size(); ++i)
  {
    file << fileData[i] << "\n";
  }
}
