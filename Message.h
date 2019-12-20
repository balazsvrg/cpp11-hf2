#ifndef MESSAGE_H
#define MESSAGE_H

#include <vector>
#include <string>
#include <cstdint>


namespace rsa{ 
    class Message{
    private:
        std::vector<uint64_t> fragments;
        size_t frag_size_bytes;
        
    public:
        Message();

        void read(std::string input_file);
        void log();
        void print();

        size_t fragcount();

        void add_fragment(uint64_t f);

        uint64_t operator[](size_t idx);
        //Message operator=(Message& other);
    private:
        std::string read_content(std::string input_file);
        std::vector<std::string> fragment_input(std::string content);
    };
}
#endif