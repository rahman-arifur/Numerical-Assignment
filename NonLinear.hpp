// #include <bits/stdc++.h>
// using namespace std;
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

void bisection(vector<double> a, double left, double right) {
    int n = size(a) - 1;
    if (getval(left, a) * getval(right, a) >= 0) {
        cout << "Enter 2 valid values such that f(a) * f(b) < 0\n";
        return;
    }
    double c;
    int iterations = 100;
    while (fabs(left - right) > tolerance and --iterations) {
        c = (left + right) / 2;
        double fc = getval(c, a), fa = getval(left, a);
        if (fc == 0) break;
        else if (fa * fc < 0) right = c;
        else left = c;
    }
    printf("x = %.6lf\n", c);
}

double getnext(double x1, double x2, vector<double>& a) {
    return (x1 * getval(x2, a) - x2 * getval(x1, a)) / (getval(x2, a) - getval(x1, a));
}
void falsePosition(vector<double> a, double left, double right) {
    double c;
    int it = 100;
    if (getval(left, a) * getval(right, a) >= 0) {
        cout << "Enter 2 valid values such that f(a) * f(b) < 0\n";
        return;
    }
    while(it-- and getval(c, a) <= tolerance) {
        c = getnext(left, right, a);
        if (getval(c, a) == 0) break;
        if (getval(left, a) * getval(c, a) < 0) right = c;
        else left = c;
    }
    printf("x = %.6lf\n", c);
}
void secant(vector<double> a) {
    double x1, x2, x3;
    cout << "Two initial guess range: ";
    cin >> x1 >> x2;

    // if (getval(x1, a) * getval(x2, a) >= 0) {
    //     cout << "Secant method cannot be applied for " << x1 << " and " << x2 << '\n';
    //     return;
    // }
    int it = 100;
    while (it--) {
        double fx1 = getval(x1, a), fx2 = getval(x2, a);
        x3 = fx2 * (x2 - x1) / (fx2 - fx1);
        x3 = x2 - x3;
        if (fabs(getval(x3, a)) <= tolerance) break;
        x1 = x2;
        x2 = x3;
    }
    printf("x = %.6lf\n", x3);
}
