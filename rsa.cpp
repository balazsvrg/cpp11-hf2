#include <ctime>
#include <random>
#include <cstdint>
#include <fstream>
#include <iomanip>

#include "rsa.h"

rsa::Key rsa::generate_key(){
   uint64_t p = bit8_randomprime();
   uint64_t q = bit8_randomprime();
   uint64_t n = p*q;
   int e = 3;
   int k = 2;
   uint64_t phi = (p-1)*(q-1);
   uint64_t d = (k*phi +1) / e;

   return Key(n, e, d);
}

void rsa::encrypt(Message m, Key k, std::string of){
   std::ofstream ofs(of);
   for (size_t i = 0; i < m.fragcount(); ++i){
      uint64_t enc = pow(m[i], k.e);
      std::cout <<enc;
      enc = enc % k.n;
      const char * tmp = reinterpret_cast<const char *>(&enc);
      std::cout << "encrypted to : " << enc << std::endl;
      ofs.write(tmp, 8);
   }

}

rsa::Message rsa::decrypt(Key k, std::string encrypted){
   std::ifstream ifs(encrypted);
   Message decrypted;
   char data[8];

   while (ifs.get(data, 8)){
      uint64_t encnum = reinterpret_cast<uint64_t>(data);
      std::cout << "encrypted fragment: " << encnum << std::endl;
      uint64_t dec = pow(encnum, k.d);
      dec = dec % k.n;
      decrypted.add_fragment(dec);
   }
   return decrypted;
}

uint32_t rsa::bit8_randomprime(){
    uint8_t p = 1;

    srand(time(0));
    p = (uint8_t)rand();
    while (!rsa::miller_rabin(p, 100)){
        p = p-1;
    }
    return p;
}

//-------------Miller-Rabin teszt-----------------------------------------
//Forrás: https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
uint64_t rsa::mulmod(uint64_t a, uint64_t b, uint64_t m){
   uint64_t x = 0,y = a % m;
   while (b > 0) {
        if (b % 2 == 1) {
            x = (x + y) % m;
        }
    y = (y * 2) % m;
    b /= 2;
   }
   return x % m;
}

uint64_t rsa::modulo(uint64_t base, uint64_t e, uint64_t m) {
   uint64_t x = 1;
   uint64_t y = base;
   while (e > 0) {
        if (e % 2 == 1)
            x = (x * y) % m;
        y = (y * y) % m;
        e = e / 2;
   }
   return x % m;
}

bool rsa::miller_rabin(uint64_t p, int iteration) {
   if (p < 2) {
      return false;
   }
   if (p != 2 && p % 2==0) {
      return false;
   }
   uint64_t s = p - 1;
   while (s % 2 == 0) {
      s /= 2;
   }
   for (int i = 0; i < iteration; i++) {
      uint64_t a = rand() % (p - 1) + 1, temp = s;
      uint64_t mod = modulo(a, temp, p);
      while (temp != p - 1 && mod != 1 && mod != p - 1) {
         mod = mulmod(mod, mod, p);
         temp *= 2;
      }
      if (mod != p - 1 && temp % 2 == 0) {
         return false;
      }
   }
   return true;
}

//----------------------------Miller-Rabin Vége---------------------------------