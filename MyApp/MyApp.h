#ifndef MYAPP_H
#define MYAPP_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <future>
#include <thread>
#include <shared_mutex>

using std::string;
using std::map;
using std::vector;
using std::pair;
using std::ifstream;
using std::ios;
using std::ios_base;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;

string punctuation_marks_filter(const string& pu_marks);

void read_from_file(const string& name_file, map<string,int>& words);

void write_to_file(const string& name_file, const vector<pair<string, int>>& word_to_file);

void sort_words(map<string, int>& words, vector<pair<string, int>>& sort_word);


#endif // MYAPP_H
