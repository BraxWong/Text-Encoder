#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <fstream>
#include <vector>

class Decoder{
  public:
    void decryption(std::string fileName);
  private:
    void writeToFile(std::vector<std::string> encodeData);
    std::vector<std::string> decodeFileData(std::vector<std::string> fileData);
    std::vector<std::string> readFileData(std::string fileName);
};

void Decoder::writeToFile(std::vector<std::string> encodedData)
{
  std::ofstream newFile("decodedFile.txt");
  for(int i = 0; i < encodedData.size(); ++i)
  {
    newFile << encodedData[i] << "\n";
  }
}

std::vector<std::string> Decoder::decodeFileData(std::vector<std::string> fileData)
{
  std::vector<std::string> encodedFileData;
  std::unordered_map<char, char> umap = {
    {'z', 'a'}, {'y', 'b'}, {'x', 'c'}, {'w', 'd'}, {'v', 'e'}, {'u', 'f'},
    {'t', 'g'}, {'s', 'h'}, {'r', 'i'}, {'q', 'j'}, {'p', 'k'}, {'o', 'l'},
    {'n', 'm'}, {'m', 'n'}, {'l', 'o'}, {'k', 'p'}, {'j', 'q'}, {'i', 'r'},
    {'h', 's'}, {'g', 't'}, {'f', 'u'}, {'e', 'v'}, {'d', 'w'}, {'c', 'x'},
    {'b', 'y'}, {'a', 'z'}
};
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

std::vector<std::string> Decoder::readFileData(std::string fileName)
{
  std::vector<std::string> fileData;
  std::fstream file(fileName);
  std::string currentLine;
  while (getline (file, currentLine)) {
    fileData.push_back(currentLine);
  }
  return decodeFileData(fileData);
}

void Decoder::decryption(std::string fileName)
{
  this->readFileData(fileName);
}
