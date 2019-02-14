#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool Compare(const string& lhs, const string& rhs)
{
    return (lhs.size() != rhs.size()) ? lhs.size() < rhs.size() : lhs < rhs;
}

int main() {
    int N;
    cin >> N;
    vector<string> strings(N);
    for (int i = 0; i < N; i++)
        cin >> strings[i];
    sort(strings.begin(), strings.end(), Compare);
    for (int i = 0; i < N; i++)
        cout << strings[i] << endl;
    return 0;
}