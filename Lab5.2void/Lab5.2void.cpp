#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

void Sum(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double x, xp, xk, dx, eps, S = 0;
    int n = 0;

    cout << "Введіть початкове значення x: ";
    cin >> xp;
    cout << "Введіть кінцеве значення x: ";
    cin >> xk;
    cout << "Введіть крок x: ";
    cin >> dx;
    cout << "Введіть точність eps: ";
    cin >> eps;

    cout << fixed;
    cout << "--------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
        << setw(14) << "exp(x^2)" << " |"
        << setw(23) << "Сума ряду" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "--------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        Sum(x, eps, n, S);
        cout << "|" << setw(8) << setprecision(3) << x << " |"
            << setw(14) << setprecision(5) << exp(x * x) << " |"
            << setw(14) << setprecision(5) << S << " |"
            << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "--------------------------------------------------" << endl;

    return 0;
}

void Sum(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = 1.0; // Перший доданок ряду (n = 0)
    s = a;
    do
    {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    double r = (x * x) / n; // Коефіцієнт рекурентності R = x^2 / n
    a *= r;
}