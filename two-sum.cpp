#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int length = prices.size();
        int buyingValue = 0, sellingValue = 0, i = 0, k = 0, maximumProfitValue = 0;

        while (i < length && k < length)
        {
            buyingValue = prices.at(i);
            sellingValue = prices.at(k);

            if (buyingValue > sellingValue)
            {
                i++;
                continue;
            }

            int currentProfitValue = sellingValue - buyingValue;
            maximumProfitValue =
                currentProfitValue > maximumProfitValue ? currentProfitValue : maximumProfitValue;

            k++;
        }
        return maximumProfitValue;
    }
};

int main(void)
{
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);

    Solution solution;
    cout << solution.maxProfit(v);
}
