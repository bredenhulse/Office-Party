/*
Name: Breden Hulse
Class: Computer Science 2
Description: It solves the problem for Office Party question.
*/
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("outfile");


    //all variables
    int a, b;
    double cash;
    string gifts, temp, name;
    vector<string> info;
    map<string, double> people;
    getline(fin, temp);
    a = stoi(temp);
    

    //tells how many groups there are
    for(int i = 0; i < a; i++){
        getline(fin, temp);
        b = stoi(temp);
        //tells how many people are in each group
        for(int j = 0; j < b; j++){
            getline(fin, gifts);
            stringstream prices(gifts);
            //fill vector with strings
            info.clear();
            while(prices >> temp){
                info.push_back(temp);
            }
            //creates new person if neccesary and subtract how much they spent
            if(people.find(info[0]) == people.end()){
                people.insert(pair<string, double>(info[0],0));
            }
            people[info[0]] -= stod(info[1]);

            //add values to each persons net
            for(int x = 2; x < info.size(); x++){
                if(people.find(info[x]) != people.end()){
                    people.insert(pair<string, double>(info[x], 0));
                }
                people[info[x]] += (stod(info[1])/(info.size() - 2));
            }
        }
        //prints everybody in outfile
        for(const auto &elem : people){
            fout << elem.first << " " << elem.second << endl;
        }
        fout << endl;
        people.clear();
    }
}