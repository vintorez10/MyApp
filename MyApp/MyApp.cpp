#include "MyApp.h"



void read_from_file(const string& name_file, map<string, int>& words)
{
    string temp_str;

    ifstream fin;
    fin.open(name_file, ios_base::in);

    if(fin.is_open()){

        while(fin >> temp_str){

            auto filtered_words(punctuation_marks_filter(temp_str));

            ++words[filtered_words];
        }
        fin.close();
    }
    else{
        cerr << "Can not open file for output" << endl;
        exit(EXIT_FAILURE);
    }

}

void sort_words(map<string, int>& words, vector<pair<string, int>>& sort_word )
{
    /**< reserver memory for a vector "sort_word" */
    sort_word.reserve(words.size());

    /**< fill the" sort_word" array with the key-value data in the order
     they were in the associative array "words" */
    move(begin(words), end(words), back_inserter(sort_word));

    /**< let's sort the array "sort_word" in descending order */
    sort(begin(sort_word), end(sort_word), [](const auto& key, const auto& val){

         return key.second > val.second;
    });
}

void write_to_file(const string& name_file, const vector<pair<string, int>>& word_to_file)
{
    ofstream fout(name_file, ios::out);

    if(!fout.is_open()){
        cerr << "Can not open file for output" << endl;
        exit(EXIT_FAILURE);
    }

    for(const auto & a: word_to_file){
        fout << a.first << "- " << a.second << endl;
    }

    fout.close();

}

/**< this function helps to trim punctuation marks in text */
string punctuation_marks_filter(const string& pu_marks)
{
    /**< string with punctuation marks, that need to be trimmed */
    const char* unnecessary {".,:;-/0123456789 "};

    /**< run the filter and find the first occurrence of a character,
     not defined in the unnecessary string */
    const auto start_filter(pu_marks.find_first_not_of(unnecessary));

    const auto end_filter(pu_marks.find_last_not_of(unnecessary));

    if(start_filter == string::npos){
        return {};
    }

    /**< return a string with clipped punctuation marks */
    return pu_marks.substr(start_filter, end_filter - start_filter + 1);
}




