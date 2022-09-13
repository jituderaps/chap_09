#include <ostream>
#include <string>
#include "chrono.h"

namespace lib {

struct ISBN {
  public:
    ISBN() { }
    ISBN(int, int, int, char); 
    
    int  isbn_1_;
    int  isbn_2_;
    int  isbn_3_;
    char isbn_4_;
};

bool operator==(const ISBN&, const ISBN&);
bool operator!=(const ISBN&, const ISBN&);
std::ostream& operator<<(std::ostream& os, const ISBN&);

enum class Genre {
  fiction, nonfiction, periodical, biography, children 
};

class Book {
  public:
    Book() { }
    Book(std::string, std::string, chrono::Date, ISBN, Genre);

    std::string  title()          const { return title_;          }
    std::string  author()         const { return author_;         }
    chrono::Date copyright_date() const { return copyright_date_; }
    ISBN         isbn()           const { return isbn_;           }
    Genre        genre()          const { return genre_;          }
    
    void CheckedOut();
    bool BookStatus();

  private:
    std::string  title_;
    std::string  author_;
    chrono::Date copyright_date_;
    ISBN         isbn_;
    Genre        genre_;
    bool         is_available_ = true;
};

bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
std::ostream& operator<<(std::ostream&, const Book&);

class Patron {
  public:
    Patron();
    Patron(std::string, int, double); 

    std::string user_name()           const { return user_name_;           }
    int         library_card_number() const { return library_card_number_; }
    double      fee()                 const { return fee_;                 }

    void set_fee(double);
    
    bool PendingFee();

  private:
    std::string user_name_;
    int         library_card_number_;
    double      fee_;
};

bool operator==(const Patron&, const Patron&);
std::ostream& operator<<(std::ostream&, const Patron&);

struct Transaction {
  Book         bk;
  Patron       pt;
  chrono::Date dt;
};

std::ostream& operator<<(std::ostream&, const Transaction&);

class Library {
  public:
    const std::vector<Transaction>& get_transactions()     const { return transaction_; }
    const std::vector<Book>&        get_books()            const { return book_;        }
    const std::vector<Patron>&      get_patrons()          const { return patron_;      }

    void add_book(const Book&);
    void add_patron(const Patron&);
    void add_transaction(const Transaction&);

    void AddFeeToPatron(const Patron&, double);
    bool IsBookAvailable(const Book&);
    bool IsPatronValid(const Patron&);
    void CheckOutBook(Book&, Patron&);
    void PendingFeeList();
    const std::vector<Patron>& GetPendingFeeList();

  private:
    std::vector<Book>        book_;
    std::vector<Patron>      patron_;
    std::vector<Transaction> transaction_;
    std::vector<Patron>      pending_fee_list_;
};

} // namspace lib
