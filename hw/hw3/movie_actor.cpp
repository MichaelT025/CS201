/*
Name: Michael Tesfaye
Email:mktesfaye@crimson.ua.edu
Course Section: Spring 2026 CS 201 – 002    
Homework #3
To Compile: g++ movie_actor.cpp -o movie_actor
To Run: ./movie_actor <db_file> <query_file>
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>
#include <vector>
#include <chrono>
using namespace std;

void print(vector<string> &names){
    for(const auto& name : names){
        cout << name << endl;
    }
}

int main(int argc, char* argv[]){
    if(argc<3){
        cout<<"Usage: "<<argv[0]<<" <db_file> <query_file>"<<endl;
        return 1;
    }
    ifstream db_file(argv[1]);
    ifstream query_file(argv[2]);
    if(!db_file.is_open()){
        cout<<"Error opening "<<argv[1]<<endl;
        return 1;
    }
    if(!query_file.is_open()){
        cout<<"Error opening "<<argv[2]<<endl;
        return 1;
    }
    unordered_map<string, vector<string>> byactor;// map to track actors and their movies
    unordered_map<string, vector<string>> bymovie;// map to track movies and their actors
    string line;
    regex delim("/");

    //see time to build maps
    auto start_time= chrono::high_resolution_clock::now();
    int count=0; //count to keep track of records
    while(getline(db_file, line)){
        auto begin=sregex_token_iterator(line.begin(),line.end(), delim, -1);
        auto end=sregex_token_iterator();
        string movie="";
        for(auto it=begin; it!=end;++it){
            if(movie.empty()){ //first value is movie name
                movie=*it;
            } else { //subsequent values are actor names
                byactor[*it].push_back(movie);
                bymovie[movie].push_back(*it);
            }
        }
        count++;
    }
    auto end_time=chrono::high_resolution_clock::now();
    chrono::duration<double> build_time = end_time - start_time;

    db_file.close();
    start_time=chrono::high_resolution_clock::now();
    while(getline(query_file, line)){
        bool found=0;       //to check if value exists
        if(byactor.find(line)!=byactor.end()){
            found=1;
            print(byactor[line]);
        }
        if(bymovie.find(line)!=bymovie.end()){
            found=1;
            print(bymovie[line]);
        }
        if(!found){
            cout<<line<<" Not Found"<<endl;
        }
    }
    end_time=chrono::high_resolution_clock::now();
    chrono::duration<double> query_time = end_time - start_time;
    cout<<"Number of records: "<<count<<endl;
    cout<<"Time to build maps: "<<build_time.count()<<" seconds"<<endl;
    cout<<"Time to answer queries: "<<query_time.count()<<" seconds"<<endl;
    cout<<"Total time taken: "<<build_time.count() + query_time.count()<<" seconds"<<endl;
    query_file.close();
    return 0;
}