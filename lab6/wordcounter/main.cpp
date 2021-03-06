//
// Created by dawid on 06.04.17.
//

#include "WordCounter.h"
#include <string>

using namespace std;
using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;

int main()
{
    /*WordCounter test("/home/dawid/Desktop/nowy.txt");
    WordCounter test2{Word("raz"),Word("dwa"),Word("trzy"),Word("raz")};
    cout<<test;*/

    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};

    std::set<Word> abc;

    abc = counter.Words();

    for(auto n: abc)
    {
        cout<<n.GetWord()<<" ";
    }

    return 0;
}
