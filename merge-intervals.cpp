#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> answer;
    vector<int> before, current;
    const int length = intervals.size();
    int s = 0, e = 1;
    bool beforepushed = false;

    for (int i = 0; i < length; i++)
    {
      if (i == 0)
      {
        before = intervals.at(i);
        continue;
      }

      current = intervals.at(i);
      int scurrent = current.at(s), ecurrent = current.at(e),
          sbefore = before.at(s), ebefore = before.at(e);

      bool merge = ebefore >= scurrent;

      if (merge)
      {
        vector<int> newinterval;
        newinterval.push_back(sbefore);
        newinterval.push_back(ecurrent);
        answer.push_back(newinterval);
        before = newinterval;
        beforepushed = true;
        continue;
      }

      if (!beforepushed)
        answer.push_back(before);
      if (i == length - 1)
        answer.push_back(current);
      before = current;
      beforepushed = false;
    }

    return answer;
  }
};
