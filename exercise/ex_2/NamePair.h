#include <string>
#include <vector>

namespace person_data {

class NamePair {
  public:
    void print();
    
    const std::string& name(int i)  const { return name_[i];     }
    const double& age(int i)        const { return age_[i];      }
    int NameSize()                  const { return name_.size(); }
    int AgeSize()                   const { return age_.size();  }           

    void read_names();
    void read_ages();
    void sort();

  private:
    std::vector<std::string> name_;
    std::vector<double> age_;
};

std::ostream& operator<<(std::ostream&, const NamePair&);
bool operator==(const NamePair&, const NamePair&);
bool operator!=(const NamePair&, const NamePair&);

} // namespace person_data 
