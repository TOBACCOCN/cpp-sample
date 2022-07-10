#include<iostream>
#include<vector>
using namespace std;
int max(int m, int n)
{
    return m > n ? m : n;
}
int dp[3200];
int main()
{
    int N, n, v, p, q;
    cin >> N >> n;
    N = N / 10;

    int* ZJ_Pri = new int[n + 1]();  int* ZJ_Imp = new int[n + 1]();
    int* FJ1_Pri = new int[n + 1](); int* FJ1_Imp = new int[n + 1]();
    int* FJ2_Pri = new int[n + 1](); int* FJ2_Imp = new int[n + 1]();

    for (int i = 1; i <= n; i++)
    {
        cin >> v >> p >> q;
        v = v / 10;
        if (q == 0)
        {
            ZJ_Pri[i] = v;
            ZJ_Imp[i] = v * p;
        }
        else if (FJ1_Pri[q] == 0)
        {
            FJ1_Pri[q] = v;
            FJ1_Imp[q] = v * p;
        }
        else
        {
            FJ2_Pri[q] = v;
            FJ2_Imp[q] = v * p;
        }
    }
    for (int i = 1; i <= n; i++)//i---前i个物品
    {
        for (int j = N; j >= 1; j--)//j--当前的钱数
        {

            if (j >= ZJ_Pri[i])
                dp[j] = max(dp[j], dp[j - ZJ_Pri[i]] + ZJ_Imp[i]);
            if (j >= ZJ_Pri[i] + FJ1_Pri[i])
                dp[j] = max(dp[j], dp[j - ZJ_Pri[i] - FJ1_Pri[i]] + ZJ_Imp[i] + FJ1_Imp[i]);
            if (j >= ZJ_Pri[i] + FJ2_Pri[i])
                dp[j] = max(dp[j], dp[j - ZJ_Pri[i] - FJ2_Pri[i]] + ZJ_Imp[i] + FJ2_Imp[i]);
            if (j >= ZJ_Pri[i] + FJ1_Pri[i] + FJ2_Pri[i])
                dp[j] = max(dp[j], dp[j - ZJ_Pri[i] - FJ1_Pri[i] - FJ2_Pri[i]] + ZJ_Imp[i] + FJ1_Imp[i] + FJ2_Imp[i]);
        }
    }
    cout << dp[N] * 10 << endl;

    delete[] ZJ_Pri;
    delete[] ZJ_Imp;
    delete[] FJ1_Pri;
    delete[] FJ1_Imp;
    delete[] FJ2_Pri;
    delete[] FJ2_Imp;

    system("pause");
    return 0;
}