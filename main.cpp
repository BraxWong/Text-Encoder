#include "decodeText.cpp"
#include "encodeText.cpp"
#include "file.cpp"
#include <iostream>
#include <limits>

std::string getFileName() {
  std::string fileName;
  std::cout << "Please provide the name of the file:\n";
  std::getline(std::cin, fileName);
  return fileName;
}
int main() {
  std::cout << "Welcome to the Text Encryption Program.\n";
  while (1) {
    int num;
    std::cout << "Encryption(Press 1):\nDecryption(Press 2):\nAdd Content To "
                 "File(Press 3):\nQuit The Program(Press 4):\n";
    std::cin >> num;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (num == 1) {
      Encoder encoder;
      encoder.startEncryption(getFileName());
      std::cout << "Encryption Complete...\n";
    } else if (num == 2) {
      Decoder decoder;
      decoder.decryption(getFileName());
      std::cout << "Decryption Complete...\n";
    } else if (num == 3) {
      File file;
      file.appendToFile(getFileName());
    } else if (num == 4) {
      break;
    }
  }
  return 1;
}
