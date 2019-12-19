#include <iostream>

#include "Message.h"

int main(void){
    Message m(16);

    m.read("TEST");
    //m.log();
    m.print();
    
}