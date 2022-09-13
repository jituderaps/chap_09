#include <iostream>
#include <vector>

#include "library.h"

int main() {
  lib::Library med;

  lib::Book x = {"mahabharat", "krishna", 
                 chrono::Date(15, chrono::Month::jan, 1005), 
                 lib::ISBN(232, 523, 23, 'a'), 
                 lib::Genre::fiction};

  lib::Book y = {"rich dady, poor dady", "jonny sins",
                 chrono::Date(1, chrono::Month::feb, 1069),
                 lib::ISBN(232, 523, 73, 97),
                 lib::Genre::nonfiction};

  lib::Patron p1 = {"rahul" , 23423, 0.00};
  lib::Patron p2 = {"manish", 63453, 0.00};
  lib::Patron p3 = {"vishal", 23453, 0.00};

  med.lib::Library::add_book(x);
  med.lib::Library::add_book(y);
  
  med.lib::Library::add_patron(p1);
  med.lib::Library::add_patron(p2);
  med.lib::Library::add_patron(p3);

  med.lib::Library::CheckOutBook(x, p1);
  med.lib::Library::CheckOutBook(y, p3);

  std::vector<lib::Transaction> ts  = med.lib::Library::get_transactions();
  std::vector<lib::Book>        bks = med.get_books();
  std::vector<lib::Patron>      pt = med.get_patrons();
//  med.lib::Library::PendingFeeList();
  std::vector<lib::Patron>      pts = med.GetPendingFeeList();

  int count = 0;
  for (int i = 0; i < int(pts.size()); ++i) {
    std::cout << "Patron  : " << ++count << '\n';
    std::cout << pts[i] << '\n' << '\n';
  }

  return 0;
}
