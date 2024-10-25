#include <bits/stdc++.h>
using namespace std;
const double tolerance = 1e-5;

double getval(double x, vector<double>& a) {
    double res = 0, xx = 1;
    for (int i = 0; i < size(a); ++i) {
        res += xx * a[i];
        xx *= x;
    }
    return res;
}

double fprimex(double x, vector<double>& a) {
    double res = 0, xx = 1;
    for (int i = 1; i < size(a); ++i) {
        res += xx * a[i] * i;
        xx *= x;
    }
    return res;
}

void bisection(vector<double>& a) {
    int n = size(a) - 1;
    double val = pow(a[n-1] / a[n], 2) - 2 * a[n - 2] / a[n]; 
    val = fabs(val);
    double left = sqrt(val), right = -left, c;
    int iterations = 1000;
    while (fabs(left - right) > tolerance and --iterations) {
        c = (left + right) / 2;
        double fc = getval(c, a), fa = getval(left, a);
        if (fc == 0) break;
        else if (fa * fc < 0) right = c;
        else left = c;
    }
    printf("%.6lf\n", c);
}