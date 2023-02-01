#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <map>

using Dictionary = std::map<std::string, std::string>;
std::set<std::string> make_exit_commands() { return {"q", "quit", "e", "exit"}; }
Dictionary map{};

int main()
{
    auto exit = make_exit_commands();
    std::string input;
    std::string cmd;
    while (true)
    {
        std::cout
            << "-----" << std::endl;
        std::getline(std::cin, input);
        auto inpt = std::stringstream(input);
        inpt >> cmd;
        if (exit.count(cmd) != 0)
        {
            return 0;
        }
        if (cmd == "add")
        {
            std::string key;
            std::string value;
            inpt >> key;
            inpt >> value;
            if (!value.empty())
            {
                map[key] = value;
                std::cout << key << " => " << value << std::endl;
            }
        }
        if (cmd == "translate")
        {
            std::string word;
            inpt >> word;
            if (map.count(word) != 0)
            {
                std::cout << map[word] << std::endl;
            }
            else
            {
                std::cout << "???" << std::endl;
            }
        }
        if (cmd == "print")
        {
            for (auto it = map.begin(); it != map.end(); it++)
            {
                std::cout << it->first << " => " << it->second << std::endl;
            }
            for (const auto &p : map)
            {
                std::cout << p.first << '\t' << p.second << std::endl;
            }
        }
    }
    return 0;
}