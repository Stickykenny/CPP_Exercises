#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}
int main()
{
    string input, w1, w2;
    set<string> s = make_exit_commands();
    while (true)
    {
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        std::cin >> input;
        // if (input == "q" || input == "quit" || input == "e" || input == "exit")
        // {
        //     break;
        // }
        if (s.find(input) != s.end())
        {
            break;
        }
        // if (input == "add")
        // {
        //     cin >> w1;
        //     cin >> w2;
        //     cout << w1 << " => " << w2 << endl;
        // }
    }

    return 0;
}

/*
f(std::string str) // fais des copies

f(std::string &str) // référence lorsqu'on sait que cela la fonction modifie le paramètre

f(const tsd::string &str) //référence constante
*/