#include <vector>
#include <string>

class Message{
private:
    std::vector<unsigned long long int> fragments;
    int frag_size;
    
public:
    Message(int key_size);

    void read(std::string input_file);
    void log();
    void print();
};