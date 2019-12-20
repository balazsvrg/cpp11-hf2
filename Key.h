#ifndef KEY_H
#define KEY_H

namespace rsa{
    struct Key{
        uint64_t n;
        uint64_t e;
        int d;
        int key_size = 64;

        Key();
        Key(Key&);
        Key(Key&&) noexcept;
        Key(uint64_t, uint64_t, int);
    };
}
#endif