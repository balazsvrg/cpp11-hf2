#include <iostream>

#include "rsa.h"


int main(void){
    rsa::Key k = rsa::generate_key();
    rsa::Message m;

    m.read("TEST");
    m.print();
    
    rsa::encrypt(m, k, "encrypted");

    //std::cout << "Decrypted: ";
    m = rsa::decrypt(k, "encrypted");
    //m.log();
    //m.print();
    

    return 0;
}