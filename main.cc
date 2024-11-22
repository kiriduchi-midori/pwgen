#include <iostream>
#include <random>
#include <string>

int main(int argc, char ** argv) {
  std::random_device seed;
  std::mt19937 random(seed());
  constexpr auto default_len = 128, min_len = 16;
  uint32_t length = default_len;
  if(argc < 2) {
    std::cerr << "arg[1]: length of password" << std::endl;
    length = (random() % default_len) + min_len;
  }
  else {
    length = std::stoi(argv[1]);
  }
  std::string res(length, 0);

  for (int i = 0; i < res.size(); ++i) {
    res[i] = random() % 0x7f;
    while(res[i] < 0x21) {
        res[i] = random() % 0x7f;
    }
  }
  std::cout << res;
  return EXIT_SUCCESS;
}
