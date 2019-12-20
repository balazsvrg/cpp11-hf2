#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Message.h"

rsa::Message::Message() : frag_size_bytes{4} {}

void rsa::Message::read(std::string input_file){
    std::string tmp = read_content(input_file);
    std::vector<std::string> stringfrags = fragment_input(tmp);

    for (std::string s : stringfrags){
        std::stringstream ss;
        for (unsigned char c : s){
            ss << std::setfill('0') << std::setw(3) << std::dec << (int) c;
        }
        std::string fragment;
        fragment += "111";
        std::string data;
        ss >> data;
        fragment += data;
        fragments.push_back(stoull(fragment));
    }
}

void rsa::Message::log(){
    for (uint64_t f : fragments){
        std::cout << f << std::endl;
    }
}

void rsa::Message::print(){
    std::string back;
    for (uint64_t f : fragments){
        std::string tmp = std::to_string(f);
        for (size_t i = 1; i < tmp.size()/3; ++i){
            std::string letter;
            letter = tmp.substr(3*i, 3);
            back.push_back((char)std::stoi(letter));
        }
    }
    std::cout << back << std::endl;
}

size_t rsa::Message::fragcount(){
    return fragments.size();
}

void rsa::Message::add_fragment(uint64_t f){
    fragments.push_back(f);
}

std::string rsa::Message::read_content(std::string input_file){
    std::ifstream ifs(input_file);
    std::stringstream ss;

    unsigned char c;
    std::string filecontent;
    while(ifs >> std::noskipws >> c){
        filecontent.push_back(c);
    }
    return filecontent;
}

std::vector<std::string> rsa::Message::fragment_input(std::string content){
    std::vector<std::string> result;
    for (size_t i = 0; i < content.length(); i += (frag_size_bytes-1)) {
        result.push_back(content.substr(i, frag_size_bytes-1));
    }
    return result;
}

uint64_t rsa::Message::operator[](size_t idx) {
    if(idx > 0 && idx < fragments.size())
        return fragments[idx];
    return -1;
}