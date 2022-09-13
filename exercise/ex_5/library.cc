#include <iostream>
#include <vector>
#include "library.h"

namespace lib {

ISBN::ISBN(int isbn_1, int isbn_2, int isbn_3, char isbn_4) 
    : isbn_1_(isbn_1), isbn_2_(isbn_2), isbn_3_(isbn_3), isbn_4_(isbn_4) { } 

bool operator==(const ISBN& a, const ISBN& b) {
  if (a.isbn_1_ == b.isbn_1_ 
      && a.isbn_2_ == b.isbn_2_
      && a.isbn_3_ == b.isbn_3_
      && a.isbn_4_ == b.isbn_4_)
    return true;
  else
    return false;
}

bool operator!=(const ISBN& a, const ISBN& b) {
  return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const ISBN& isbn) {
  return os << isbn.isbn_1_ << '-'
            << isbn.isbn_2_ << '-'
            << isbn.isbn_3_ << '-'
            << isbn.isbn_4_;
}

Book::Book(std::string title, std::string author, 
           chrono::Date copyright_date, ISBN isbn, Genre genre)
    : title_(title), author_(author), 
      copyright_date_(copyright_date), 
      isbn_(isbn), genre_(genre) { }

void Book::CheckedOut() {
  is_available_ = false;
}

bool Book::BookStatus() {
  return is_available_;
}

bool operator==(const Book& a, const Book& b) {
  if (a.isbn() == b.isbn())
    return true;
  else
    return false;
}

bool operator!=(const Book& a, const Book& b) {
    return !(a == b);
}

std::vector<std::string> genre_list = {"fiction", "nonfinction", "periodical", "biography", "children"};
std::ostream& operator<<(std::ostream& os, const Book& book) {
  return os << "===============================================" << '\n'
            << "Title            : " << book.title()             << '\n'
            << "Author           : " << book.author()            << '\n'
            << "copyright        : " << book.copyright_date()    << '\n'
            << "ISBN             : " << book.isbn()              << '\n'
            << "Genre            : " << genre_list[int(book.genre())];
} 


Patron::Patron()
    : user_name_("noname"), library_card_number_(0000), fee_(0.0) { }

Patron::Patron(std::string name, int card_num, double fee)
    : user_name_(name), library_card_number_(card_num), fee_(fee) { }

void Patron::set_fee(double d) {
  if (d < 0)
    std::cerr << "Fee should be greater than 0" << '\n';
  
  fee_ += d;
}

bool Patron::PendingFee() {
  if (fee_ > 15.0)
    return true;
  else
    return false;
}

bool operator==(const Patron& a, const Patron& b) {
  if (a.user_name() == b.user_name() 
      && a.library_card_number() == b.library_card_number())
    return true;

  return false;
}
std::ostream& operator<<(std::ostream& os, const Patron& pt) {
  return os << "===============================================" << '\n'
            << "Name             : " << pt.user_name()           << '\n'
            << "Library Card no. : " << pt.library_card_number() << '\n'
            << "Fee              : " << pt.fee();
}

std::ostream& operator<<(std::ostream& os, const Transaction& ts) {
  return os << "Book   :- " << '\n' << ts.bk << '\n'
            << "Patron :- " << '\n' << ts.pt << '\n';
}

void Library::add_book(const Book& bk) {
  book_.push_back(bk);
}

void Library::add_patron(const Patron& pt) {
  patron_.push_back(pt);
}

void Library::add_transaction(const Transaction& ts) {
    transaction_.push_back(ts);
}

bool Library::IsBookAvailable(const Book& bk) {
  for (int i = 0; i < int(book_.size()); ++i) {
    if (bk == book_[i])
      return true;
  }
  return false;
}

bool Library::IsPatronValid(const Patron& pt) {
  for (int i = 0; i < int(patron_.size()); ++i) {
    if (pt == patron_[i])
      return true;
  }
  return false;
}

void Library::AddFeeToPatron(const Patron& pt, double d) {
  for (int i = 0; i < int(patron_.size()); ++i) {
    if (pt == patron_[i])
      patron_[i].set_fee(d);
  }
  
}
void Library::CheckOutBook(Book& bk, Patron& pt) {
  Transaction ts;
  if (IsBookAvailable(bk)) {
    if (IsPatronValid(pt)) {
      if (bk.BookStatus()) {
        if (!pt.PendingFee()) {
          bk.CheckedOut();
          
          AddFeeToPatron(pt, 5.25);
          ts.bk = bk;
          ts.pt = pt;
          ts.dt = {23, chrono::Month::feb, 2022};

          add_transaction(ts);
        }
        else {
          std::cerr << "patron have a pending fee" << '\n';
        }
      }
      else {
        std::cerr << "this book is already checked out" << '\n';
      }
    }
    else {
      std::cout << "this student doesn't exist" << '\n'; 
    }
  }
  else {
    std::cerr << "this book is not available " << '\n';
  }
}

void Library::PendingFeeList() {
  for (int i = 0; i < int(patron_.size()); ++i) {
    if (patron_[i].fee() > 0)
      pending_fee_list_.push_back(patron_[i]);
  }
}

const std::vector<Patron>& Library::GetPendingFeeList() {
  PendingFeeList();
  return pending_fee_list_;
}

} // namespace lib


