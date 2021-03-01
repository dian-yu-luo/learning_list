//
// Created by dianyuluo on 2021/1/31.
//
#include"iostream"
#include "map"
#include "vector"

using namespace std;

void printHighChangeables(const map<string, vector<string>> &adjacentWords,
                          int minWords = 15) {
    for (auto &entry:adjacentWords) {
        const vector<string> &words = entry.second;
        if (words.size() >= minWords) {
            cout << entry.first << "(" << words.size() << ")";
            for (auto &str:words) {
                cout << " " << str;
                cout << endl;
            }
        }
    }
}

bool oneCharOff(const string &word1, const string &word2) {
    if (word1.length() != word2.length()) {
        return false;
    }
    int number = 0;
    int i = 0;
    for (char c:word1) {
        if (c == word2[i]) {
            number++;
        }
        i++;

    }
    if (number == 1) {
        return true;
    } else {
        return false;
    }
}

map<string, vector<string>> computeAdjacentW(const vector<string> &words) {
    map<string, vector<string>> adjWords;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (oneCharOff(words[i], words[j])) {
                adjWords[words[i]].push_back(words[j]);
                adjWords[words[j]].push_back(words[i]);

            }
        }
    }
    return adjWords;
}

map<string, vector<string>> computeAdjword(const vector<string> &words) {
    map<string, vector<string>> adjWords;
    map<int, vector<string>> wordsByLength;
    for (auto &thisWord:words) {
        wordsByLength[thisWord.length()].push_back(thisWord);
    }
    for (auto &entry:wordsByLength) {
        const vector<string> &groupWords = entry.second;
        for (int i = 0; i < groupWords.size(); ++i) {
            for (int j = j+1; j < groupWords.size(); ++j) {
                if (oneCharOff(groupWords[i],groupWords[j])){
                    adjWords[groupWords[i]].push_back(groupWords[j]);
                    adjWords[groupWords[j]].push_back(groupWords[i]);

                }
            }
        }
    }
}
map<string, vector<string>> computeAdjword3(const vector<string> &words){
    map<string, vector<string>> adjWords;
    map<int, vector<string>> wordsByLength;
    for (auto &thisWord:words) {
        wordsByLength[thisWord.length()].push_back(thisWord);
    }
    for (auto &entry:wordsByLength){
        const vector<string>&groupWords=entry.second;
        map<string,vector<string>>repToword;
        int groupNum=entry.first;
        for (int i = 0; i < groupNum; ++i) {

            for(auto &str:groupWords){
                string rep=str;
                rep.erase(i,1);
                repToword[rep].push_back(str);
            }
        }
        for(auto &entry:repToword){
            const vector<string>&clique=entry.second;
            if (clique.size()>=2){
                for (int p = 0; p < clique.size(); ++p) {
                    for (int q = 0; q < clique.size(); ++q) {

                    }
                }
            }
        }
    }
}

int main() {

}

