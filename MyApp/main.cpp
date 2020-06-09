#include "MyApp.h"


int main()
{
    map<string, int> words_from_file;
    vector<pair<string, int>> to_sort_words;

    read_from_file("London_Jack-South_Sea_Tales_In.txt", words_from_file);

    sort_words(words_from_file, to_sort_words);

    write_to_file("London_Jack-South_Sea_Tales_Out.txt", to_sort_words);


   return 0;
}
