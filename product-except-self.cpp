#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    vector<int> answer, prefix, postfix;
    const int length = nums.size();
    int i = 0, j = length - 1;

    while (i < length && j >= 0)
    {
      if (i == 0)
      {
        prefix.push_back(nums.at(i));
      }
      else
      {
        prefix.push_back(nums.at(i) * prefix.at(i - 1));
        cout << "prefix else" << endl;
      }

      if (j == length - 1)
      {
        postfix.push_back(nums.at(j));
      }
      else
      {
        postfix.push_back(nums.at(j) * postfix.at(i - 1));
        cout << "postfix else" << endl;
      }

      i++;
      j--;
    }

    i = 0, j = length - 1;

    for (int i = 0; i < length; i++, j--)
    {
      int currentAnswer = 1;
      if (i == 0)
      {
        currentAnswer = postfix.at(j - 1);
      }
      else if (i == length - 1)
      {
        currentAnswer = prefix.at(i - 1);
      }
      else
      {
        currentAnswer = prefix.at(i - 1) * postfix.at(j - 1);
      }

      answer.push_back(currentAnswer);
    }

    return answer;
  }
};

int main(void)
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);

  Solution solution;
  vector<int> ans = solution.productExceptSelf(nums);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans.at(i) << " ";
  }
  return 0;
}
