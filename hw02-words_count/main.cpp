#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

string LeftOnlyLetters(const string& word)
{
    string res;
    for (char c : word)
        if ((c >= 'a') && (c <= 'z'))
            res += c;
    return res;
}

vector<string> Separate(string& line)
{
    string word;
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    istringstream iss(line);
    vector<string> v;
    while (iss >> word)
    {
        string final_word = LeftOnlyLetters(word);
        if (final_word != "")
            v.push_back(LeftOnlyLetters(word));
    }
    return v;
}


void AddWord(const vector<string>& words, map<string, int>& words_count)
{
    for(string word : words)
    {
        words_count[word]++;
    }
}

map<int, string> ReverseMap(map<string, int>& words_count)
{
    map<int, string> count_words;
    for (const auto& [word, count] : words_count)
    {
        if (count_words[count] == "")
        {
            count_words[count] = word;
        }
        else
            count_words[count] = count_words[count] + ", " + word;
    }
    return count_words;
}

void PrintReversedMap (const map<int, string>& count_words, int N)
{
    int i = 0;
    for (auto iter = count_words.rbegin(); iter != count_words.rend(); ++iter)
    {
        if (i++ == N)
            break;
        cout << iter->first << ": " << iter->second << endl;
    }
}

int main()
{
    const string path = "Pushkin-Onegin.txt";
    ifstream input(path);
    string line;
    map<string, int> words_count;
    if (input.is_open())
        while (getline(input, line))
        {
            vector<string> v = Separate(line);
            AddWord(v, words_count);
        }
    else
        cout << "error!" << endl;
    map<int, string> count_words = ReverseMap(words_count);
    cout << "How many the most popular words should be printed?";
    int N;
    cin >> N;
    N = (N > count_words.size()) ? (int)count_words.size() : N;
    PrintReversedMap(count_words, N);
    return 0;
}
