#include <iostream>
#include "NamePair.h"

namespace person_data {

void NamePair::read_names() {
  std::cout << "\nplease enter names : " << '\n';
  
  for (std::string name; std::cin >> name;) {
    if (name == "exit")
      break;

    name_.push_back(name);
  }
}

void NamePair::read_ages() {
  std::cout << "\nplease enter the age with respect their names: " << '\n';

  double age = 0;
  for (int i = 0; i < int(name_.size()); ++i) {
    std::cout << name_[i] << " : ";
    std::cin >> age;
    
    age_.push_back(age); 
  }
}

void NamePair::print() {
  std::cout << "\nnames with their ages are written below " << '\n';
  
  for (int i = 0; i < int(name_.size()); ++i) {
    std::cout << name_[i] << " : " << age_[i] << '\n';
  }
}

void NamePair::sort() {
  std::vector<std::string> sorted_names = name_;
  std::string temp;

  // sorting names
  for (int i = 0; i < int(sorted_names.size()); ++i) {
    for (int j = i; j < int(sorted_names.size()); ++j) {
      if (sorted_names[i] > sorted_names[j]) {
        temp = sorted_names[j];
        sorted_names[j] = sorted_names[i];
        sorted_names[i] = temp;
      }
    }
  }

  // assigning age with their sorted names
  std::vector<double> sorted_age = age_;
  for (int i = 0; i < int(name_.size()); ++i) {
    for (int j = 0; j < int(name_.size()); ++j) {
      if (sorted_names[i] == name_[j]) {
        sorted_age[i] = age_[j];
      }
    }
  }

  age_ = sorted_age;
  name_ = sorted_names;
}

std::ostream& operator<<(std::ostream& os, const NamePair& np) {
  for (int i = 0; i < np.NameSize(); ++i) {
    os << np.name(i) << ' ';
  }
  return os;
}

bool operator==(const NamePair& a, const NamePair& b) {
  if (a.NameSize() != b.NameSize() || a.AgeSize() != b.AgeSize())  
    return false;

  for (int i = 0; i < a.NameSize(); ++i) {
    if (a.name(i) != b.name(i)) {
      return false;
    }
  }
  
  for (int i = 0; i < a.AgeSize(); ++i) {
    if (a.age(i) != b.age(i)) {
      return false;
    }
  }
  
  return true;
}

bool operator!=(const NamePair& a, const NamePair& b) {
  return !(a == b);
}

} // namespace person_data 
