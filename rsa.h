#ifndef RSA_H
#define RSA_H

#include <iostream>

#include "Key.h"
#include "Message.h"

namespace rsa{
    Key generate_key();
    void encrypt(Message, Key, std::string);
    Message decrypt(Key, std::string);

    uint32_t bit8_randomprime();
    bool is_prime(uint64_t);
    bool overflow(uint64_t, uint64_t);
    bool miller_rabin(uint64_t , int );
    uint64_t modulo(uint64_t , uint64_t , uint64_t );
    uint64_t mulmod(uint64_t , uint64_t , uint64_t );
};

#endif