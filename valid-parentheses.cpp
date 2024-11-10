#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    bool action(char c, stack<char> *s)
    {
        char all[] = {'(', ')', '{', '}', '[', ']'};
        char end[] = {')', '}', ']'};
        char start[] = {'(', '{', '['};

        for (int i = 0; i < 3; i++)
        {
            if (c == start[i])
            {
                s->push(c);
                return true;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (c == end[i] && s->empty())
            {
                return false;
            }
            else if (c == end[i])
            {
                char top = s->top();
                if ((top == '(' && c == ')') || (top == '{' && c == '}') || (top == '[' && c == ']'))
                {
                    s->pop();
                    return true;
                }
                else
                    return false;
            }
        }

        return true;
    }

    bool isValid(string s)
    {
        unordered_map<char, char> characterMapping;
        stack<char> data;

        int length = s.length();

        for (int i = 0; i < length; i++)
        {
            char current = s[i];
            bool actionResult = this->action(current, &data);

            if (!actionResult)
                return actionResult;
        }

        return true;
    }
};

int main(void)
{
    Solution solution;
    string input = "[]";
    bool result = solution.isValid(input);
    cout << result;
    return 0;
}
