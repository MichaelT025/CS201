#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <regex>
#include <map>
#include <sstream>

using namespace std;

void parseText(const string& text, vector<string>& tokens) {
    
    string word;
    const regex delim("\\s+");
    
    istringstream ss(text);
    while (ss >> word) {
        auto begin = sregex_token_iterator(word.begin(), word.end(), delim, -1);   
        auto end = sregex_token_iterator();
        for (sregex_token_iterator it = begin; it != end; it++)
            tokens.push_back(*it);
    }
    
}


int main(int argc, char* argv[]){
    string text;
    string file=argv[1];
    vector<string> tokens;
    ifstream inputfile(file);

    if (!inputfile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    while(getline(inputfile, text)){
        parseText(text, tokens);
    }
    inputfile.close();

    //map to count the frequency of each word
    map<string, int> wordcount;
    for(const auto& token: tokens){
        wordcount[token]++;
    }

    //map to store each word with its frequency
    map<int, vector<string>> words_by_count;
    for(const auto& word: wordcount){
        words_by_count[word.second].push_back(word.first);
    }

    //sort each vector of words
    for(auto& it: words_by_count){
        sort(it.second.begin(), it.second.end());
    }

    //iterate through the map in reverse order
    for (auto it = words_by_count.rbegin(); it != words_by_count.rend(); ++it) {
        for(const auto& word: it->second){
            cout<<word<<": "<<it->first<<endl;
        }
    }
}

