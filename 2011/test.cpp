#include <bits/stdc++.h>
using namespace std;
 
bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
 
int main()
{
	long long tc;
	cin >> tc;
	for (long long itc = 0; itc < tc; itc++)
	{

		long long n;
		cin >> n;
		vector <long long> vec;
		for (int i = 0 ; i < n; i++)
		{
			long long tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		long long c = 0;
		

		for (int i = 0 ; i < n; i++)
			for (int j = i ; j < n; j++)
			{
				long long res = vec[i];
				for (int ii = i+1 ; ii <= j; ii++)
					res = res^vec[ii];
				long double x = res;
				// cout << i << "," <<j <<","<<res << ","<<isPerfectSquare(x)<<endl;	
				if (not(isPerfectSquare(x)))
				{
					c++;
					// for (int ii = i ; ii <= j; ii++)
					// cout << vec[ii] << " " ; 
					// cout << endl;
				}
			}
		cout << c;
	}
    return 0;
}