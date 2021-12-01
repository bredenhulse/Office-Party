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

    int n, m;
    double cash;
    string gifts, temp, name;
    vector<string> info;
    map<string, double> people;
    getline(fin, temp);
    n = stoi(temp);
    
    for(int i = 0; i < n; i++){
        getline(fin, temp);
        m = stoi(temp);
        for(int j = 0; j < m; j++){
            getline(fin, gifts);
            stringstream prices(gifts);
            //fill vector with strings
            info.clear();
            while(prices >> temp){
                info.push_back(temp);
            }
            //create new entry if needed, and take away expense
            if(people.find(info[0]) == people.end()){
                people.insert(pair<string, double>(info[0],0));
            }
            people[info[0]] -= stod(info[1]);

            //add value to each user
            for(int x = 2; x < info.size(); x++){
                if(people.find(info[x]) != people.end()){
                    people.insert(pair<string, double>(info[x], 0));
                }
                people[info[x]] += (stod(info[1])/(info.size() - 2));
            }
        }
        //print
        for(const auto &elem : people){
            fout << elem.first << " " << elem.second << endl;
        }
        fout << endl;
        people.clear();
    }
}