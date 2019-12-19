#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Message.h"

Message::Message(int key_size) : frag_size{(key_size / 3) - 1} {}

void Message::read(std::string input_file){
    std::string tmp = read_content(input_file);
    std::vector<std::string> stringfrags = fragment_input(tmp);

    for (std::string s : stringfrags){
        std::stringstream ss;
        for (unsigned char c : s){
            ss << std::setfill('0') << std::setw(3) << std::dec << (int) c;
        }
        std::string fragment;
        fragment += "111";
        std::string ize;
        ss >> ize;
        fragment += ize;
        fragments.push_back(std::stoull(fragment));
    }
}

void Message::log(){
    for (unsigned long long int f : fragments){
        std::cout << f << std::endl;
    }
}

void Message::print(){
    std::string back;
    for (unsigned long long int f : fragments){
        std::string tmp = std::to_string(f);
        for (size_t i = 1; i < tmp.size()/3; ++i){
            std::string letter;
            letter = tmp.substr(3*i, 3);
            back.push_back((char)std::stoi(letter));
        }
    }
    std::cout << back << std::endl;
}

std::string Message::read_content(std::string input_file){
    std::ifstream ifs(input_file);
    std::stringstream ss;

    unsigned char c;
    std::string filecontent;
    while(ifs >> std::noskipws >> c){
        filecontent.push_back(c);
    }
    return filecontent;
}

std::vector<std::string> Message::fragment_input(std::string content){
    std::vector<std::string> result;
    for (size_t i = 0; i < content.length(); i += (frag_size-1)) {
        result.push_back(content.substr(i, frag_size-1));
    }
    return result;
}