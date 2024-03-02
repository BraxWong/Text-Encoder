#include "file.cpp"
#include <unordered_map>
#include <vector>

class Decoder {
public:
  void decryption(std::string fileName);

private:
  File file;
  std::vector<std::string> decodeFileData(std::vector<std::string> fileData);
};

std::vector<std::string>
Decoder::decodeFileData(std::vector<std::string> fileData) {
  std::vector<std::string> decodedFileData;
  std::unordered_map<char, char> umap = {
      {'z', 'a'}, {'y', 'b'}, {'x', 'c'}, {'w', 'd'}, {'v', 'e'}, {'u', 'f'},
      {'t', 'g'}, {'s', 'h'}, {'r', 'i'}, {'q', 'j'}, {'p', 'k'}, {'o', 'l'},
      {'n', 'm'}, {'m', 'n'}, {'l', 'o'}, {'k', 'p'}, {'j', 'q'}, {'i', 'r'},
      {'h', 's'}, {'g', 't'}, {'f', 'u'}, {'e', 'v'}, {'d', 'w'}, {'c', 'x'},
      {'b', 'y'}, {'a', 'z'}};
  for (int i = 0; i < fileData.size(); ++i) {
    std::string dataString = fileData[i];
    std::string currentNewString = "";
    for (int j = 0; j < dataString.length(); ++j) {
      if (umap.find(dataString[j]) != umap.end()) {
        currentNewString += umap[dataString[j]];
      } else {
        currentNewString += dataString[j];
      }
    }
    decodedFileData.push_back(currentNewString);
  }
  file.writeToFile(decodedFileData, "decodedFile.txt");
  return decodedFileData;
}

void Decoder::decryption(std::string fileName) {
  std::vector<std::string> fileData = file.readFileData(fileName);
  decodeFileData(fileData);
}
