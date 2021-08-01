#include <iostream>
#include <fstream>
#include <sstream>
#include "scanner.h"


void run(std::string source)
{
    std::cout<<source<<std::endl;
    auto scanner = Scanner(source);
    auto tokens = scanner.scan_tokens();
    for(const auto& token: tokens)
    {
        std::cout<<token.to_str()<<std::endl;
    }
}

int run_file(std::string filename)
{
    std::ifstream f(filename);
    std::string source((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    run(source);
    return EXIT_SUCCESS;
};

int run_prompt()
{
    std::string line;
    std::cout << "> ";
    while (std::getline(std::cin, line))
    {
        run(line);
        std::cout << "> ";
}
    return EXIT_SUCCESS;
};
int main(int argc, char** argv){
    if(argc > 2)
    {
        std::cerr << std::endl;
        std::cout << "Usage ./Lox filename" << std::endl;
        return 65;
    }
    if(argc == 2)
    {
        return run_file(argv[1]);
    }
    else
    {
        return run_prompt();
    }
 }