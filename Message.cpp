#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Message.h"

Message::Message(int key_size) : frag_size{(key_size / 3) - 1} {}

void Message::read(std::string input_file){
    std::ifstream ifs(input_file);
    char* tmp = new char[frag_size];
    std::stringstream ss;

    while(ifs.read(tmp, frag_size-1)){
        for(char *c = tmp; c < tmp + frag_size-1; ++c ){
            ss << std::setfill('0') << std::setw(3) << std::dec << (int) *c;
        }
        std::string fragment;
        fragment += "999";
        ss >> fragment;
        fragments.push_back(std::stoi(fragment));
    }
}

void Message::log(){
    for (unsigned long long int f : fragments){
        std::cout << f << std::endl;
    }
}

void Message::print(){
    for (unsigned long long int f : fragments){
        std::string tmp = std::to_string(f);
        std::string back;
        for (int i = 1; i < frag_size-1; ++i){
            std::string letter;
            for(int j = 0; j < 3; ++j){
                letter.push_back(tmp[3*i + j]);
            }
            std::cout << "boo";
            back += std::stoi(letter);
        }
        std::cout << back << std::endl;
    }
}
