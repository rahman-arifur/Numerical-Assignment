// #include <bits/stdc++.h>
// Function to perform RK4 for a single equation dy/dx = f(x, y)
vector<pair<double, double>> rk4(
    function<double(double, double)> f,
    double y0, double x0, double xf, double h) {

    int n = (xf - x0) / h;  // Number of steps
    vector<pair<double, double>> result;
    result.push_back({x0, y0});

    double x = x0;
    double y = y0;

    for (int i = 0; i < n; ++i) {
        // Calculate RK4 coefficients
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        // Update y and x
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;

        result.push_back({x, y});
    }

    return result;
}

// Function 1: dy/dx = a * sin(x) + b * cos(x)
double equation1(double x, double y, double a, double b) {
    return a * sin(x) + b * cos(x);
}

// Function 2: dy/dx = a * x^2 + b * x + c
double equation2(double x, double y, double a, double b, double c) {
    return a * x * x + b * x + c;
}

// Function 3: dy/dx = e^(m * x)
double equation3(double x, double y, double m) {
    return exp(m * x);
}

// Function 4: dy/dx = p * x^a + q * y^b
double equation4(double x, double y, double p, double q, double a, double b) {
    return p * pow(x, a) + q * pow(y, b);
}

// Wrapper to handle the chosen equation and parameters
function<double(double, double)> selectEquation(int choice, vector<double> params) {
    switch (choice) {
        case 1:
            return bind(equation1, placeholders::_1, placeholders::_2, params[0], params[1]);
        case 2:
            return bind(equation2, placeholders::_1, placeholders::_2, params[0], params[1], params[2]);
        case 3:
            return bind(equation3, placeholders::_1, placeholders::_2, params[0]);
        case 4:
            return bind(equation4, placeholders::_1, placeholders::_2, params[0], params[1], params[2], params[3]);
        default:
            throw invalid_argument("Invalid choice for equation type.");
    }
}
