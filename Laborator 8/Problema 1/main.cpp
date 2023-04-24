#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

string sep = "?!. ,";
ifstream file("Text.txt");

string lower_cuv(const string& s) {
    string aux;
    for (int i = 0;i < s.size();i++)
        aux.push_back(tolower(s[i]));
    return aux;
}

vector<string> taie(const string& s) {
    vector<string> cuvinte;
    string aux;
    for (int i = 0;i < s.size();i++) {
        if (sep.find_first_of(s[i]) != s.npos)
        {
            if (!aux.empty())
            {
                cuvinte.push_back(lower_cuv(aux));
                aux.clear();
            }
        }
        else aux.push_back(s[i]);
    }
    if (!aux.empty())
        cuvinte.push_back(aux);
    return cuvinte;
}

class Compare {
public:
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};


int main() {
    string s;
    getline(file, s);
    vector<string>cuvinte = taie(s);
    map<string, int>s_map;
    for (string cuv : cuvinte)
        s_map[cuv]++;

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> coada;
    for (auto i = s_map.begin();i != s_map.end();i++)
    {
        coada.push(make_pair(i->first, i->second));
    }
    while (!coada.empty())
    {
        auto& pair = coada.top();
        cout << "\"" << pair.first << "\"" << " => " << pair.second << "\n";
        coada.pop();
    }
}
