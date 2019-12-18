#include <iostream>

#include "Message.h"

int main(void){
    Message m(12);

    m.read("TEST");
    //m.print();
    m.log();
}