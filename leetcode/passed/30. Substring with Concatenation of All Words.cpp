

/*   TLE VERSION
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.length()<words.size()*words[0].length()) return {};
        unordered_set<string> hashtable;
        unordered_map<string, int> wordCount;  // To keep track of the count of each word
        for (auto i : words) {
            hashtable.insert(i);
            wordCount[i]++;
        }

        int single_word_length = words[0].length();
        int words_size = words.size();
        int flag = 0;
        string substr;
        vector<int> answer;

        for (int i = 0; i <= s.length() - words_size * single_word_length; i++) {
            flag = 0;
            unordered_map<string, int> check_duplicate_table;  // To keep track of the count of each word in the current substring

            auto temp = i;
            for (int j = 0; j < words_size; j++) {
                substr = s.substr(temp, single_word_length);
                if (hashtable.find(substr) == hashtable.end() || check_duplicate_table[substr] >= wordCount[substr]) {
                    flag = 1;
                    break;
                } else {
                    check_duplicate_table[substr]++;
                }
                temp += single_word_length;
            }

            if (!flag) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};
*/

//GPT generated: using slide window to optimize the algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;  // 缓存每个单词的出现次数
        int single_word_length = words[0].length();
        int words_size = words.size();
        int total_length = single_word_length * words_size;
        vector<int> answer;
        
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < single_word_length; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> check_duplicate_table;

            while (right + single_word_length <= s.length()) {
                string word = s.substr(right, single_word_length);
                right += single_word_length;

                if (wordCount.find(word) == wordCount.end()) {
                    left = right;
                    check_duplicate_table.clear();
                } else {
                    check_duplicate_table[word]++;

                    while (check_duplicate_table[word] > wordCount[word]) {
                        string left_word = s.substr(left, single_word_length);
                        check_duplicate_table[left_word]--;
                        left += single_word_length;
                    }

                    if (right - left == total_length) {
                        answer.push_back(left);
                    }
                }
            }
        }

        return answer;
    }
};
