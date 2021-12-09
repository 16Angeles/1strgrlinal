#define ret(cmd) { cmd; return 0; }
#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
int main() {
    float A, B, C, D, E, F, x, y, a, b, a2, b2, x0, y0, exc, f, A1, B1, C1, D1, E1, F1;
    cin >> A >> B >> C >> D >> E >> F;

    if ((A == 0) and (B == 0) and (C == 0) and (D == 0) and (E == 0) and (F != 0))
    {
        ret(cout << "Pustoe mnojestvo " << endl;)
    }
    if ((A == 0) and (B == 0) and (C == 0) and (D == 0) and (E == 0) and (F == 0))
    {
        ret(cout << "Tojdestvo " << endl;)
    }

    if (A - C == 0)
        f = atan(1.0);
    else
        f = atan(B / (A - C)) / 2;

    A1 = A * (cos(f) * cos(f)) - B * cos(f) * sin(f) + C * (sin(f) * sin(f));
    C1 = A * (sin(f) * sin(f)) + B * cos(f) * sin(f) + C * (cos(f) * cos(f));
    B1 = 0;
    D1 = D * cos(f) - E * sin(f);
    E1 = D * sin(f) + E * cos(f);
    x0 = -D1 / (2 * A1);
    y0 = -E1 / (2 * C1);
    F1 = (x0 * x0) + (y0 * y0) + (D1 * x0) + (E1 * y0) + F;
    exc = 123;
    a2 = -(F1 / A1);
    b2 = -(F1 / C1);
    a = sqrt(a2);

   if ((A*C) - (B*B/4) == 0)
    {
        if ((C != 0) and (B != (2 * sqrt(A) * sqrt(C)))) {
            exc = 1;
            ret(cout << "Parabola, " << "Excenticitet = " << exc << endl;)
        }
        if (B == (2 * sqrt(A) * sqrt(C))) {
            if (F > 0)
            ret(cout << "Pustoe mnojestvo");
            if (F == 0)
            ret(cout << "Pryamie kotorie sovpali ili prosto pryamaya(esli v itoge chto-to vrode 2x = 0 or same shit)");
            if (F < 0)
            ret(cout << "Para pryamih");
        }
    }

    if ((A*C) - (B * B /4) > 0) {
        if ((a2 > 0) and (b2 > 0)) {
            if ((A1 == C1) and (F < 0) and ((A != 1) and (C != 1))) {
                ret(cout << "Ellipse, kotoriy povorotom bil povernut na 45, 90, 135, 180 gradusov");
            }
            if ((A1 == C1) and (F > 0)){
                ret(cout << "Pustoe mnojestvo");
            }
            if (a2 >= b2) {
                exc = (sqrt(a2 - b2)) / a;
            }
            if (b2 > a2){
                exc = (sqrt(abs(b2 - a2)))/sqrt(b2);
            }
            if ((exc > 0) and (exc < 1)) {
                ret(cout << "Ellipse " << "Excenticitet = " << exc << endl;)
            }
            if (exc == 1) {
                ret(cout << "Otrezok " << 1 << endl;)
            }
            if ((exc == 0) or ((A != 0) and (B ==0) and (C != 0) and (D == 0) and (E == 0) and (F < 0))) {
                ret(cout << "Okruzhost " << 0 << endl;)
            }
            if (exc == 123) {
                ret(cout << "Tochka" << endl;)
            }
        }
        if ((A != 0) and (C != 0) and (B == 0) and (D == 0) and (E == 0) and (F == 0))
            ret(cout << "Tochka" << endl;)
        else {
            ret(printf("Pustoe mnozhestvo");)
        }
    }

    if (((A*C) - (B * B)/4) < 0)
    {
        if ((((a2 > 0) and (b2 < 0)) or ((a2 == 1) and (b2 == -1))) or ((A == 0) and (C == 0) and (F != 0))) {
            exc = (sqrt(a2 + abs(b2))) / a;
            if (a == 0)
                ret(cout << "pair of intersecting lines " << endl;)
            else
                ret(cout << "Hyperbola, " << "Excenticitet = " << exc << endl;)
        }
        if ((a2 < 0) and (b2 > 0)) {
            exc = (sqrt(abs(a2) + b2) / sqrt(b2));
            if (sqrt(b2) == 0)
                ret(cout << "pair of intersecting lines " << endl;)
            else
                ret(cout << "Hyperbola, " << "Excenticitet = " << exc << endl;)
        }
        if (((A == 0) or (C == 0)) or ((A != 0) and (B != 0) and (C != 0)))
        {
            exc = sqrt(abs(a2) + abs(b2))/ sqrt(b2);
            if (sqrt(b2) == 0)
                ret(cout << "pair of intersecting lines " << endl;)
            else
                ret( cout << "Hyperbola, " << "Excentricitet = " << exc << endl;)
        }
        else {
            ret(cout << "Pustoe mnojestvo ili puchok pryamih (puchok esli b != 0)";)
        }
    }
    if ((A == 0) and (B == 0) and (C == 0)){
        if ((E == 0) or (D == 0)){
            ret(cout << "Pryamaya " << endl;)
        }
    }
    if ((B == 0) and (C == 0) and (D == 0) and (E == 0))
    {
        if (F > 0)
        {
            ret(cout << "Pustoe mnojestvo" << endl;)
        }
        if (F == 0) {
            ret(cout << "Tochka " << endl;)
        }
        if (F < 0)
        ret(cout << "Parallelnie pryamie" << endl;)
    }

    if ((B == 0 ) and (A == 0) and (D == 0) and (E == 0)) {
        if (F > 0) {
            ret(cout << "Pustoe mnojestvo" << endl;)
        }
        if (F == 0) {
            ret(cout << "Tochka " << endl;)
        }
        if (F < 0)
        ret(cout << "Parallelnie pryamie" << endl;)
    }
    return 0;
}
