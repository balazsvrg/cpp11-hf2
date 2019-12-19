#include <vector>
#include <string>

class BigNum{
private:
    std::vector<int> num;
public:
    BigNum();
    BigNum(BigNum & other);
    BigNum(std::string val);

    BigNum& operator=(BigNum& other);
    BigNum operator+(BigNum& other);
    BigNum operator+(int other);
    
};