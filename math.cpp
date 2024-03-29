#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
#define PB push_back
#define SZ(x) ((int)x.size())
#define LEN(x) ((int)x.length())
#define REV(x) reverse(x.begin(), x.end());
#define trav(a, x) for (auto &a : x)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define SORT(x) sort(x.begin(), x.end())

// Short function start-->>
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Short function end-->>

/*
1. Print all divisors of a number
ANS :
Input : N=36  || Output :
*/
// Bruteforce ----------->
// TC :O(N)
// SC : if you want to return ans using list then here space will O(1) bcz you only using space for return a ans not for perform any calculation
void allDivisorsBruteforce(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
    cout << endl;
}
// Better ----------->
// TC :O(sqrt(N))
// SC :
void allDivisorsBetter(int n)
{
    // for (int i = 1; i <= sqrt(n); i++) //it's a stl lib so it will take lill time insteadof you can use lower one
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (n / i != i) // This line for check if number is double or not like N=36 then 6x6 we only can take one 6
                cout << n / i << " ";
        }
    }
}
// Optimal ---------->
// TC :
// SC :

/*
2. Check if a number is prime or not
ANS :
Prime number : A number which is divisible by one and itself and the total number of divisers is two
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N)
// SC :O(1)
void isPrime(int n)
{
    int cnt = 0;
    FOR1(i, n)
    {
        if (n % i == 0)
            cnt++;
    }
    if (cnt == 2)
        cout << "Yes";
    else
        cout << "No";
}
// Better ----------->
// TC :O(sqrt(N))
// SC :
bool isPrimeBetter(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
                cnt++;
        }
        if (cnt > 2)
            break;
    }
    if (cnt == 2)
        return true;
    else
        return false;
    // return cnt == 0;
}
// Optimal ---------->
// TC :
// SC :

/*
3. Print all prime factors of a number
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(Nxsqrt(N))
// SC :O(1) we're using space to return ans
vector<int> allPrimeFactors(int n)
{
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrimeBetter(i))
                ans.PB(i);
        }
    }
    return ans;
}
// Better ----------->
// TC :Near about O(sqrt(N)*2*sqrt(N)) its not for all prime check
// SC :O(1)
vector<int> allPrimeFactorsBetter(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrimeBetter(i))
                ans.PB(i);
            if (n / i != i)
                if (isPrimeBetter(n / i))
                    ans.PB(n / i);
        }
    }
    return ans;
}
// Optimal ---------->
// TC : For the large number which is prime then the complexity is still O(N)
// SC :
vector<int> allPrimeFactorsOptimal(int n)
{
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.PB(i);
            while (n % i == 0) // Here we're decreasing iterations
                n = n / i;
        }
    }
    return ans;
}
// Optimal's Optimal ---------->
// TC :O(sqrt(N)xlogN)
// SC :O(1)
vector<int> allPrimeFactorsOptimalsOptimal(int n)

{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.PB(i);
            while (n % i == 0) // Here we're decreasing iterations
                n = n / i;     // When n changes within the loop, it simply continues with the next iteration of the loop using the current value of i.
        }
    }
    if (n != 1)
        ans.PB(n);
    return ans;
}

/*
4.Power Exponentiation
ANS : x to the power n
Input :  x=2 n=21 || Output :
*/
// Bruteforce ----------->
// TC : O(logN)
// SC :
/*
If the exponent n is odd (checked with n % 2 == 1), multiply ans by the base x, and decrement n by 1.
If the exponent n is even, divide n by 2 and square the base x (i.e., ×x×x).
Repeat the process until n becomes 0.
*/
// This will work for if n is int or double or negative
// If n is double then change only ans as double and ans devide by 1.0
int powerExpo(int x, int n)
{

    int ans = 1, m = n;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
            n--;
        }
        else
        {
            n /= 2;
            x *= x;
        }
    }
    if (m < 0)
        ans = 1 / ans;
    return ans;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
5. Sieve of Eratosthenes Algorithm
ANS :Given a number N,print all primes till N
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
void printAllPrimesTillNBruteforce(int n)
{
    int prime[n + 1];
    for (int i = 2; i < n; i++)
        prime[i] = 1;
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = 2 * i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
            cout << i << " ";
    }
}

// Better ----------->
// TC :O(N)+O(Nlog(logN))+O(N)
// SC :O(n)
void printAllPrimesTillNOptimal(int n)
{
    int prime[n + 1];
    for (int i = 2; i < n; i++)
        prime[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
            cout << i << " ";
    }
}

// Optimal ---------->
// TC :
// SC :

/*
6. Count prime in a range L-R Query based
ANS :
Constrains : 0<=10^5
1<=L<=R<=10^6
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(qx(R-L+1)xsqrt(N))
// SC :
void countPrimesLR(vector<pair<int, int>> q)
{
    int n = SZ(q);
    for (int i = 0; i < n; i++)
    {
        int l = q[i].first, r = q[i].second;
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (isPrimeBetter(i))
                cnt++;
        }
        cout << cnt << " ";
    }
}
// Better ----------->
// TC :O(nlog(logN)) for get seive and O(qx(R-L+1)) for countPrime
// SC :
vector<int> getSeive(int n)
{
    // int prime[n + 1];
    vector<int> prime(n + 1); // Initialize all elements to 1
    for (int i = 2; i < n; i++)
        prime[i] = 1;
    for (int i = 2; i * i <= n; i++)
        if (prime[i] == 1)
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
    return prime;
}
void countPrimesLRBetter(vector<pair<int, int>> q)
{
    int n = SZ(q);
    vector<int> prime = getSeive(1000000);
    FOR(i, n)
    {
        int l = q[i].first, r = q[i].second;
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (prime[i] == 1)
                cnt++;
        }
        cout << cnt << " ";
    }
}
// Optimal ---------->
// TC :O(nlog(logN))+O(n)+O(q)
// SC :
// Using prefix sum method
// instedof saving prime=1 non-prime=0 we're saving total no of primes count in every prime number till t
void countPrimesLROptimal(vector<pair<int, int>> q)
{
    int t = 1000000;
    int n = SZ(q);
    vector<int> prime = getSeive(t);
    int cnt = 0;
    for (int i = 2; i < t; i++)
    {
        cnt = cnt + prime[i];
        prime[i] = cnt;
    }

    FOR(i, n)
    {
        int l = q[i].first, r = q[i].second;
        int ans = (prime[r] - prime[l - 1]);
        cout << ans << " ";
    }
}

/*
7.Smallest prime factor(SPF)(Query based)
ANS :
constrains: n=10^5
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(q)xO(sqrt(n))
// SC :
vector<int> getPrimeFactorisation(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0) // Here we're decreasing iterations
            {
                ans.PB(i);
                n = n / i; // When n changes within the loop, it simply continues with the next iteration of the loop using the current value of i.
            }
        }
    }
    if (n != 1)
        ans.PB(n);
    return ans;
}
void smallesPrimeFactor(vector<int> q)
{
    int n = SZ(q);
    FOR(i, n)
    {
        vector<int> ans = getPrimeFactorisation(q[i]);
        cout << q[i] << " = ";
        printVector(ans);
        cout << endl;
    }
}
// Better ----------->
// TC :O(Nlog(logN))+O(qxlogN)
// SC :O(N)
void smallesPrimeFactorBetter(vector<int> q)
{
    int t = 100000;
    int *spf = new int[t + 1]();
    FOR1(i, t)
    spf[i] = i;
    for (int i = 2; i * i <= t; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= t; j = j + i)
                if (spf[j] == j)
                    spf[j] = i;

    // Here  my spf is ready
    int n = SZ(q);
    FOR(i, n)
    {
        int qi = q[i];
        while (qi != 1)
        {
            cout << spf[qi] << " ";
            qi = qi / spf[qi];
        }
        cout << endl;
    }
}
// Optimal ---------->
// TC :
// SC :

/*
8.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
9.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
10.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// ================================MAIN START=================================>>
int main()
{
    /*
        Some short function
           int maxi = *max_element(arr.begin(), arr.end());
            int sum = accumulate(arr.begin(), arr.end(), 0);
    */
    // allDivisorsBruteforce(36);
    // allDivisorsBetter(36);
    // isPrime(5);
    // isPrimeBetter(5);
    // vector<int> ans = allPrimeFactors(780);
    // vector<int> ans = allPrimeFactorsBetter(780);
    // vector<int> ans = allPrimeFactorsOptimal(780);
    // vector<int> ans = allPrimeFactorsOptimalsOptimal(780);
    // printVector(ans);
    // int x = 2, n = 21;
    // cout << x << " To the power " << n << " is " << powerExpo(x, n) << endl;
    // printAllPrimesTillNBruteforce(100);
    // printAllPrimesTillNOptimal(20);
    // cout << endl;
    // vector<pair<int, int>> q = {{3, 10}, {8, 20}, {1, 5}};
    // countPrimesLR(q);
    // cout << endl;
    // countPrimesLRBetter(q);
    // cout << endl;
    // countPrimesLROptimal(q);
    vector<int> query = {3, 12, 16, 60};
    smallesPrimeFactor(query);
    cout << endl;
    smallesPrimeFactorBetter(query);
    // End code here-------->>

    return 0;
}
