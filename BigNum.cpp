#include "BigNum.h"

BigNum::BigNum(){}

BigNum::BigNum(BigNum & other){
    num = other.num;
}

BigNum::BigNum(std::string val){
    for(char c : val){
        if(c - '0' < 10){
            num.push_back(c - '0');
        }
        //ide valami exception TODO
    }
}

BigNum& BigNum::operator=(BigNum& other){
    num = other.num;
}

BigNum BigNum::operator+(BigNum& other){
    BigNum ret;
    int carry = 0;
    int idxat = 0;

    BigNum& bigger = num.size > other.num.size ? *this : other;
    BigNum& smaller = num.size <= other.num.size ? *this : other;

    for(int i : bigger.num){
        idxat = i - bigger.num.begin;
        if ((i + smaller.num[idxat] + carry) > 9){
            ret.num.push_back((i + smaller.num[idxat] + carry) % 10);
            carry = ((i + smaller.num[idxat] + carry) - ((i + smaller.num[idxat] + carry) % 10)) / 10; //insert hányós emoji
        }
    }

    if (carry != 0) {
        if (ret.num.size < idxat){
            ret.num.push_back(carry);
        }
        else {
            if(ret[idxat + 1]  carry
        }
    }
}