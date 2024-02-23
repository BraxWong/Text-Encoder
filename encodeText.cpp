#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <fstream>
#include <vector>

class Encoder {
  public:
    void startEncryption(std::string fileName);
  private:
    void writeToFile(std::vector<std::string> encodedData);
    std::vector<std::string> encodeFileData(std::vector<std::string> fileData);
    std::vector<std::string> readFileData(std::string fileName);
};

void Encoder::writeToFile(std::vector<std::string> encodedData)
{
  std::ofstream newFile("encodedFile.txt");
  for(int i = 0; i < encodedData.size(); ++i)
  {
    newFile << encodedData[i] << "\n";
  }
}

std::vector<std::string> Encoder::encodeFileData(std::vector<std::string> fileData)
{
  std::vector<std::string> encodedFileData;
  std::unordered_map<char,char> umap = {{'a','z'},{'b','y'},{'c','x'},{'d','w'},{'e','v'},{'f','u'},
                                    {'g','t'},{'h','s'},{'i','r'},{'j','q'},{'k','p'},{'l','o'},
                                    {'m','n'},{'n','m'},{'o','l'},{'p','k'},{'q','j'},{'r','i'},
                                    {'s','h'},{'t','g'},{'u','f'},{'v','e'},{'w','d'},{'x','c'},
                                    {'y','b'},{'z','a'}};
  for(int i = 0; i < fileData.size(); ++i)
  {
    std::string dataString = fileData[i];
    std::string currentNewString = "";
    for(int j = 0; j < dataString.length(); ++j)
    {
      if(umap.find(dataString[j]) != umap.end())
      {
        currentNewString += umap[dataString[j]];
      }
      else 
      {
        currentNewString += dataString[j];
      }
    }
    encodedFileData.push_back(currentNewString);
  }
  writeToFile(encodedFileData);
  return encodedFileData;
}

std::vector<std::string> Encoder::readFileData(std::string fileName)
{
  std::vector<std::string> fileData;
  std::fstream file(fileName);
  std::string currentLine;
  while (getline (file, currentLine)) {
    fileData.push_back(currentLine);
  }
  return encodeFileData(fileData);
}

void Encoder::startEncryption(std::string file)
{
  readFileData(file);
}
