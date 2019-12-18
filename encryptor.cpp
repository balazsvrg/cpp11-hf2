#include <iostream>
#include <cmath>

class RSA{
private:
    int e;
    int n;
    int d;

public:
    RSA(int e_, int n_) : e{e_}, n{n_} {}

    Message encrypt(Message m){
        Message encrypted = new Message();
        for (int i = 0; i < m.fragment_count(); ++i){
            int enc = pow(m[i], e);
            enc = enc % n;
            encrypted.add_fragment(enc);
        }
    }

    Message decrypt(Message m){
        Message decrypted = new Message();
        for (int i = 0; i < m.fragment_count(); ++i){
            int dec = pow(m[i], d);
            dec = dec % n;
            decrypted.add_fragment(dec);
        }
    }
};
