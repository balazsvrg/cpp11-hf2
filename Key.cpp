#include <cstdint>
#include <iostream>
#include "Key.h"

rsa::Key::Key() {}

rsa::Key::Key(Key& other) : n{other.n}, e{other.e}, d{other.d}, key_size{other.key_size} {}
rsa::Key::Key(Key&& other) noexcept{
    n = other.n;
    e = other.e;
    d = other.d;
    key_size = other.key_size;
}

rsa::Key::Key(uint64_t n_, uint64_t e_, int d_) : n{n_}, e{e_}, d{d_} {
    uint64_t tmp = 1;
    int ks = 0;
    while(tmp < n_){
        tmp *= 2;
        ks++;
    }
    key_size = ks / 8 + 1;
}