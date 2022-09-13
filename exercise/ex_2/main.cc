#include <iostream>
#include "NamePair.h"

int main() {
  person_data::NamePair gym;
  person_data::NamePair library;

  gym.read_names();
  library.read_names();

  if (gym != library)
    std::cout << "yes they are same person list." << '\n';
}
