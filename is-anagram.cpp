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
            auto firstFinder = firstMap.find(s[i]);
            auto secondFinder = secondMap.find(t[i]);

            if (firstFinder == firstMap.end())
            {
                firstMap.insert({s[i], 1});
            }
            else
                firstMap.insert({s[i], firstFinder->second + 1});

            if (secondFinder == secondMap.end())
                secondMap.insert({t[i], 1});
            else
                secondMap.insert({t[i], secondFinder->second + 1});
        }

        for (const auto &pair : firstMap)
        {
            auto finder = secondMap.find(pair.first);
            if (finder == secondMap.end())
                return false;
            else if (finder->second != pair.second)
                return false;
        }

        return true;
    }
};

int main(void)
{
    string s = "eat", t = "ate";

    Solution solution;
    cout << solution.isAnagram(s, t) << endl;
}
