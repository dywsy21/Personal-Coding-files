#include <bits/stdc++.h>
using namespace std;

//calculate the smallest number in a vector and also its index
int vec_min(const vector<int>& vec, int* index) {
    if (vec.empty()) return 0;
    int minnum = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (minnum >= vec[i]) {
            minnum = vec[i];
            *index = i;
        }
    }
    return minnum;
}

//string内置了find函数，可以直接用！！！！！
int main() {
    int p, k, s, ans = 0;
    string str;
    vector<int> str_state(200, 0); //str_state[i] stands for the number of valid words reduced if cut between str[i] and str[i+1]
    vector<int> minlen(200, 1000); //(a,b): insert a copies of b into a vector
    unordered_set<string> words;

//input all the necessary data
    cin >> p >> k;
    cin.ignore(); // Ignore newline character after reading k

    for (int i = 0; i < p; i++) {
        string line;
        getline(cin, line);
        str += line;
    }

    cin >> s;
    cin.ignore(); // Ignore newline character after reading s

    for (int i = 0; i < s; i++) {
        string word;
        getline(cin, word);
        words.insert(word);
    }

    unordered_set<int> word_lengths;
    for (const string& word : words) word_lengths.insert(word.length());
        
//calculate ans(before cut) and str_state, for one index 'i', choose the shortest word to avoid ans reducing induced by cutting to the greatest extent
    for (int i = 0; i < str.length(); i++) {
        int flag = 0;
        for (int len : word_lengths) {
            if (i + len <= str.length() && words.find(str.substr(i, len)) != words.end()) {
                flag = 1;
                minlen[i] = min(minlen[i], len);
            }
        }
        if (flag) {
            ans++;
            for (int j = 0; j < minlen[i] - 1; j++) str_state[j + i]++;
        }
    }

//reduce ans to the right value: always choose the minimum str_state(namely str_state[index]), cut between str[index] and str[index+1], update all other str_state and loop through this process
//(probably is greedy algorithm?)
    for (int i = 0; i < k; i++) {
        int index = -1;
        ans -= vec_min(str_state, &index);
        str_state[index] = 1000;
        for (int j = 1; j < minlen[index] - 1 && index + j <str_state.size(); j++) str_state[index + j]--;
    }

    cout << ans;

    system("pause");
    return 0;
}
