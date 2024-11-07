#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> firstMap;
        unordered_map<char, int> secondMap;

        const int sLength = s.length();
        for (int i = 0; i < sLength; i++)
        {
            int value = firstMap.at(s[i]);
        }
    }
};

int main(void)
{
    string s = "eat", t = "ate";

    Solution solution;
    cout << solution.isAnagram(s, t) << endl;
}
