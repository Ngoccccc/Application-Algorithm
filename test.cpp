#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 2;

int n;
int a[MAXN];

int findLeftMidMax(int start, int end)
{
    int maxSum = a[end];  
    int currSum = 0;
    for (int i = end; i >= start; i--)
    {
        currSum += a[i];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int findRightMidMax(int start, int end)
{
    int maxSum = a[start];
    int currSum = 0;
    for (int i = start; i <= end; i++)
    {
        currSum += a[i];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int findMaxSubsequence(int start, int end)
{
    if (start == end)
        return a[start];
    int mid = (start + end) / 2;
    int leftMax = findMaxSubsequence(start, mid);
    int rightMax = findMaxSubsequence(mid + 1, end);
    int leftMidMax = findLeftMidMax(start, mid);
    int rightMidMax = findRightMidMax(mid + 1, end);
    int midMax = leftMidMax + rightMidMax;

    return max(max(leftMax, rightMax), midMax);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findMaxSubsequence(0, n - 1) << endl;
    return 0;
}