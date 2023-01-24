#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

std::map<std::string, std::string> translator = {};
std::vector<std::string> history, commands_waitlist;
set<string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}

void file_commands(std::string input)
{
    bool for_save;
    if (input.find("save") == 0)
    {
        for_save = true;
    }
    input = input.substr(4);
    size_t pos = input.find(" ");
    std::string filename = input.substr(pos);
    std::string line;
    // return;
    if (for_save)
    {
        std::ofstream ostrm;
        ostrm.open(filename);
        for (auto line : history)
        {
            ostrm << line << "\n";
        }
        ostrm.close();
        std::cout << "History saved here : " << filename << std::endl;
    }
    else
    {
        std::ifstream istrm;
        istrm.open(filename);
        while (std::getline(istrm, line))
        {
            commands_waitlist.emplace_back(line);
        }
        istrm.close();
    }
}
int main()
{
    string input;

    set<string> exits = make_exit_commands();

    while (true)
    {
        std::cout << "-----------" << std::endl;
        if (commands_waitlist.empty())
        {
            std::getline(std::cin, input);
        }
        else
        {
            input = commands_waitlist.front();
            commands_waitlist.erase(commands_waitlist.begin());
            // proof against infinite loop with load
        }

        history.emplace_back(input);
        std::stringstream strstream(input);

        if (exits.find(input) != exits.end()) // if find() unsuccessful it returns end()
        {
            break;
        }
        if (input.find("add") == 0)
        {

            input = input.substr(4); // skip add et l'espace
            size_t pos = input.find(" ");
            auto w1 = input.substr(0, pos);
            input = input.substr(pos);
            auto w2 = input.substr(1, pos); // commence à 1 car skip l'espace

            std::cout << w1 << " => " << w2 << std::endl;
            translator[w1] = w2;
        }
        if (input.find("translate") == 0)
        {

            std::string word;
            while (strstream >> word)
            {
                std::string result = (translator.count(word) == 0) ? word
                                                                   : translator.at(word);
                std::cout << result << " ";
            }
            std::cout << std::endl;
        }
        if (input == "print")
        {
            for (auto it = translator.begin(); it != translator.end(); it++)
            {
                std::cout << it->first << " => " << it->second << std::endl;
            }
        }
        if (input.find("save") == 0 or input.find("load") == 0)
        {
            file_commands(input);
        }
        if (input == "clear")
        {
            translator.clear();
            history.clear();
        }
        if (input.find("remove") == 0)
        {
            input = input.substr(7); // skip add et l'espace
            size_t pos = input.find(" ");
            auto w1 = input.substr(0, pos);
            for (auto it = translator.begin(); it != translator.end(); it++)
            {
                if (it->first == w1 or it->second == w1)
                {
                    translator.erase(it);
                }
            }
        }
    }

    return 0;
}

/*
f(std::string str) // fais des copies

f(std::string &str) // référence lorsqu'on sait que la la fonction modifie le paramètre

f(const tsd::string &str) //référence constante
*/