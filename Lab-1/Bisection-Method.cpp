#include<bits/stdc++.h>
using namespace std;
#define tol 0.001
double f(double x)
{
    return x*x*x - x - 2;
}

void bisection(double a, double b)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "Invalid interval" << endl;
        return;
    }
    double c,c0=a;
    int i=0;
    while (i <= 100)   
    {
        c = (a+b)/2;

        if((f(c) == 0) || (fabs(c0 - c) <=tol))
        {
            cout << "root = " << c << endl;
            return;
        }
        if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
        
        c=c0;
        i++;
    }
    cout << "Did not converge within 100 iterations." << endl;
}

int main()
{
    int a,b;
    cin >> a >> b;
    bisection(a, b);
    return 0;
}

// Converged = Successfully found the root.
// Not Converged = Did not find the root / method failed.


// if f(x) is a continuous function on the interval [a, b] and f(a) and f(b) have opposite signs (i.e., f(a)⋅f(b)<0), then there is 
// at least one root of the equation f(x)=0 in the interval (a,b).

// Guaranteed Convergence: It always converges to a root 
// if the function is continuous and f(a)⋅f(b) < 0.

// What happens if f(a)⋅f(b) ≥ 0 ?
// If f(a)⋅f(b) ≥ 0, the method cannot be applied because it indicates that either no root exists in the interval or there may be
//  multiple roots or the root might not be in the interval.

// How does the bisection method compare to other root-finding methods?
// The bisection method is slower compared to methods like Newton's method or secant method, but it is more robust and simple to implement, especially for 
// functions where derivatives are difficult to compute.

