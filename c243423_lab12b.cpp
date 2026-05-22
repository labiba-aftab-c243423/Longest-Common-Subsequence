#include <iostream>
using namespace std;

int lis(int arr[], int n)
{
    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maximum = dp[0];

    for (int i = 1; i < n; i++)
    {
        if (dp[i] > maximum)
            maximum = dp[i];
    }

    return maximum;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Length of LIS: " << lis(arr, n);

    return 0;
}
