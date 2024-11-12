#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int length = nums.size(), starting = 0, ending = 0, finder = 0, maximumAnswer = nums.at(0), finderMaximumNumber = nums.at(0);

    if (length == 1)
      return nums.at(0);

    bool continueLoop = true;

    while (continueLoop)
    {
      int sValue = nums.at(starting), eValue = nums.at(ending), fValue = nums.at(finder);
      bool fSameIndex = (starting == finder && (finder + 1) > length);
      bool evaluateStarting = (maximumAnswer - sValue > maximumAnswer);
      bool moveFinder = (fSameIndex || !evaluateStarting);

      if (moveFinder)
      {
        finder++;
        fValue = nums.at(finder);
        finderMaximumNumber += fValue;

        if (fValue > maximumAnswer)
        {
          starting = ending = finder;
          maximumAnswer = fValue;
          finderMaximumNumber = fValue;
        }
        else if (finderMaximumNumber > maximumAnswer)
        {
          ending = finder;
          maximumAnswer = finderMaximumNumber;
        }
      }

      if (evaluateStarting && !moveFinder)
      {
        // ilangin starting
        starting++;
        maximumAnswer += sValue;
        finderMaximumNumber += sValue;
      }

      continueLoop = (finder + 1 < length);
    }

    return maximumAnswer;
  }
};

// [-2,1,-3,4,-1,2,1,-5,4]
// [4,-1,2,1]

int main(void)
{
  vector<int> nums;
  nums.push_back(-2);
  nums.push_back(1);
  nums.push_back(-3);
  nums.push_back(4);
  nums.push_back(-1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(-5);
  nums.push_back(4);

  Solution solution;
  cout << "Maximum subarray value : " << solution.maxSubArray(nums) << endl;
}
