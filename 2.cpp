#include "bits/stdc++.h"

using namespace std;

#define ITER 500
 
// Extended Euclidean Theorem
// returns x_inverse where (num1 * x_inverse) % num2 == 1
long long mul_inv(long long num1, long long num2)
{
    long long b0 = num2, t, q;
    long long x0 = 0, x1 = 1;
    if (num2 == 0){
        return -1;
    }
    if (num2 == 1) return 1;
    while (num1 > 1) {
        // Error Handling if the numbers are not co-prime
        if (num2 == 0){
            return -1;
        }

        q = num1 / num2;
        t = num2, num2 = num1 % num2, num1 = t;
        t = x0, x0 = x1 - q * x0, x1 = t;

    }
    if (x1 < 0) x1 += b0;
    return x1;
}
 
void chinese_remainder(long long *n_aka_lastpos, long long *num1, size_t len)
{
    long long p, iterI, product_num = 1, sum_of_all_nums = 0;
 
    for (iterI = 0; iterI < len; iterI++) product_num *= n_aka_lastpos[iterI];
 
    for (iterI = 0; iterI < len; iterI++) {
        p = product_num / n_aka_lastpos[iterI];
        if(mul_inv(p, n_aka_lastpos[iterI]) == -1){
            cout << "-1" << endl;
            return;
        }
        sum_of_all_nums += num1[iterI] * mul_inv(p, n_aka_lastpos[iterI]) * p;
    }
 
    cout << sum_of_all_nums%product_num << " " << product_num << endl;
}

long long gcd(long long num1, long long num2)
{
    long long t;
    
    while(num2!=0)
    {
        t = num2;
        num2 = num1%num2; 
        num1 = t;
    } 
    
    return num1;
}
 

int main(){

	freopen("input","r",stdin);
	freopen("output","w",stdout);

	size_t toost_cases;
	cin >> toost_cases;

    long long tp[toost_cases];
    long long num1[toost_cases];
    long long n_aka_lastpos[toost_cases];

	for(int iterI = 0;iterI < toost_cases;iterI++){
		cin >> tp[iterI] >> num1[iterI] >> n_aka_lastpos[iterI];

        if(tp[iterI] != 1){

            // This will remove the possiblity of the cases like
            /*
                4 = 2 mod 6
                2 = 1 mod 3
                both of them are equivalent
            */
            long long temp_gcd = gcd(tp[iterI],gcd(num1[iterI],n_aka_lastpos[iterI]));
            if(temp_gcd != 1){
                tp[iterI] /= temp_gcd;
                n_aka_lastpos[iterI] /= temp_gcd;
                num1[iterI] /= temp_gcd;
            }

            long long temp = mul_inv(tp[iterI],n_aka_lastpos[iterI]);
            tp[iterI] = 1;
            num1[iterI] = (num1[iterI]*temp)%n_aka_lastpos[iterI];
        }

	}

    chinese_remainder(n_aka_lastpos,num1,toost_cases);

	return 0;
}