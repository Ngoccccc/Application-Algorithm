#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long> nums;

long long remove_and_get_max(vector<long long> &nums)
{
    auto max_it = max_element(nums.begin(), nums.end());
    int max_val = *max_it;
    nums.erase(max_it);
    return max_val;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }
    string call;
    do
    {
        cin >> call;
        if (call == "delete-max")
        {
            cout << remove_and_get_max(nums) << endl;
        }
        else if (call == "insert")
        {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }
    } while (call != "*");
}