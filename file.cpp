#pragma once
#include <fstream>
#include <iostream>
#include <vector>

class File {
public:
  std::vector<std::string> readFileData(std::string fileName);
  void writeToFile(std::vector<std::string> fileData, std::string fileName);
  void appendToFile(std::string fileName);
};

std::vector<std::string> File::readFileData(std::string fileName) {
  std::fstream file(fileName);
  std::vector<std::string> fileData;
  std::string currentLine;
  while (getline(file, currentLine)) {
    fileData.push_back(currentLine);
  }
  return fileData;
}

void File::writeToFile(std::vector<std::string> fileData,
                       std::string fileName) {
  std::ofstream file(fileName);
  for (int i = 0; i < fileData.size(); ++i) {
    file << fileData[i] << "\n";
  }
}

void File::appendToFile(std::string fileName) {
  while (true) {
    std::vector<std::string> fileData = readFileData(fileName);
    std::cout
        << "Please enter the content you would like to append to the file.\n";
    std::string content;
    std::getline(std::cin, content);
    for (int i = 0; i < fileData.size(); ++i) {
      if (fileData[i] == content) {
        std::cout << "The content already exists within the file, please try "
                     "again.\n";
        break;
      }
    }
    std::ofstream file(fileName, std::ios_base::app);
    file << content << "\n";
    std::cout << "Would you like to continue(Y/N)\n";
    std::getline(std::cin, content);
    if (content == "N" || content == "n") {
      break;
    }
  }
}
