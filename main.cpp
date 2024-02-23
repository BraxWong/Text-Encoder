#include "encodeText.cpp"
#include "decodeText.cpp"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>

int main()
{
  std::cout << "Welcome to the Text Encryption Program.\n";
  while(1)
  {
    int num;
    std::string fileName;
    std::cout << "Encryption(Press 1): \nDecryption(Press 2):\nQuit The Program(Press 3):\n";
    std::cin >> num; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(num==1)
    {
      Encoder encoder;
      std::cout << "Please provide the name of the file:\n";
      std::getline(std::cin, fileName);
      encoder.startEncryption(fileName);
      std::cout << "Encryption Complete...\n";
    }
    else if(num == 2)
    {
      std::cout << "Please provide the name of the file:\n";
      std::getline(std::cin, fileName);
      Decoder decoder;
      decoder.decryption(fileName);
      std::cout << "Decryption Complete...\n";
    }
    else if(num == 3)
    {
      break;
    }
  }
  return 1;
}
