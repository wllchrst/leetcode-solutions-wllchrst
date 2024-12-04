#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());
    const int length = nums.size();
    int left = 0, right = length - 1, before = INT_MAX;

    for (int i = 0; i < length; i++)
    {
      int x = nums.at(i);
      cout << "checking " << x << endl;
      if (x > 0)
        break;
      left = i + 1;
      right = length - 1;

      while (left != right && left <= right)
      {
        cout << "right " << right << endl;
        cout << "left " << left << endl;
        int y = nums.at(left), z = nums.at(right);
        int result = x + y + z;

        if (result > 0)
          right--;
        else if (result < 0)
          left++;
        else
        {
          vector<int> current;
          current.push_back(x);
          current.push_back(y);
          current.push_back(z);
          answer.push_back(current);
          break;
        }
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(-1);
  nums.push_back(-4);

  vector<vector<int>> answer = solution.threeSum(nums);
  for (int i = 0; i < answer.size(); i++)
  {
    vector<int> current = answer.at(i);

    for (int k = 0; k < current.size(); k++)
    {
      cout << current.at(k) << " ";
    }

    cout << endl;
  }
}
