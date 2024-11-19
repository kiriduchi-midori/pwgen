#include <iostream>
#include <random>
#include <string>

int main(int argc, char ** argv) {
  if(argc < 2) {
    std::cout << "arg[1]: length of password" << std::endl;
    return EXIT_FAILURE;
  }
  std::random_device seed;
  std::mt19937 random(seed());
  std::string res(std::stoi(argv[1]), 0);

  for (int i = 0; i < res.size(); ++i) {
    res[i] = random() % 0x7f;
    while(res[i] < 0x21) {
      res[i] = random() % 0x7f;
    }
  }
  std::cout << res;
  return EXIT_SUCCESS;
}
