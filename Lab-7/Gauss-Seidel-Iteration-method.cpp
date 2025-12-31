 #include <bits/stdc++.h>
using namespace std;

#define tol 0.0001

int main()
{
    int n;
    cin >> n;

    double a[n][n], c[n], x[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        cin >> c[i];

    memset(x, 0, sizeof(x));  // Initialize x to zero

    int iter = 0;
    bool converged = false;

    while(iter < 100)
    {
        double x_old[n];
        for(int i = 0; i < n; i++)
            x_old[i] = x[i];

        for(int i = 0; i < n; i++)
        {
            double cnst = c[i];
            // Subtract sum of a[i][j] * x[j] for all j != i
            for(int j = 0; j < n; j++)
            {
                if(j != i)
                    cnst -= a[i][j] * x[j];
            }
            x[i] =  cnst / a[i][i];   // Calculate new x[i]
        }

                // Check if solution has converged by comparing old and new values
        bool allClose = true;
        for(int i = 0; i < n; i++)
        {
            if(fabs(x[i] - x_old[i]) > tol)
            {
                allClose = false;
                break;
            }
        }

        if(allClose)
        {
            converged = true;
            break;
        }

        iter++;
    }

    if(converged)
    {
        for(int i = 0; i < n; i++)
            cout << fixed << setprecision(6) << x[i] << endl;
    }
    else
    {
        cout << "Did not converge within 100 iterations." << endl;
    }

    return 0;
}

