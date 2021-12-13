import java.util.Scanner;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        new Main().run();
    }

    private final Scanner scanner = new Scanner(System.in);

    void run() {
        double A = scanner.nextDouble(), B = scanner.nextDouble(), C = scanner.nextDouble(),
                D = scanner.nextDouble(), E = scanner.nextDouble(), F = scanner.nextDouble();
        //x, y, a, b, a2, b2, x0, y0, exc, f, A1, B1, C1, D1, E1, F1;

        if ((A == 0) && (B == 0) && (C == 0) && (D == 0) && (E == 0) && (F != 0)) {
            System.out.println("Пустое множество");
            return;
        }

        if ((A == 0) && (B == 0) and (C == 0) && (D == 0) && (E == 0) && (F == 0)){
            System.out.println("0=0 тождество");
            return;
        }

        double f = A - C == 0 ? atan(1.0) : atan(B / (A - C)) / 2;
        double
                A1 = A * (cos(f) * cos(f)) - B * cos(f) * sin(f) + C * (sin(f) * sin(f)),
                C1 = A * (sin(f) * sin(f)) + B * cos(f) * sin(f) + C * (cos(f) * cos(f)),
                B1 = 0,
                D1 = D * cos(f) - E * sin(f),
                E1 = D * sin(f) + E * cos(f),
                x0 = -D1 / (2 * A1),
                y0 = -E1 / (2 * C1),
                F1 = (x0 * x0) + (y0 * y0) + (D1 * x0) + (E1 * y0) + F,
                exc = Double.NaN,
                a2 = -(F1 / A1),
                b2 = -(F1 / C1),
                a = sqrt(a2);

        if ((A * C) - (B * B / 4) == 0) {
            if ((C != 0) && (B != (2 * sqrt(A) * sqrt(C)))) {
                exc = 1;
                System.out.println("Парабола, эксцентриситет = " + exc);
                return;
            }
            if (B == (2 * sqrt(A) * sqrt(C))) {
                if (F > 0)
                    System.out.println("Пустое множество");
                else if (F == 0)
                    System.out.println("Совпадающие прямые");
                else
                    System.out.println("Пара прямых");
                return;
            }
        }

        if ((A * C) - (B * B / 4) > 0) {
            if ((a2 > 0) && (b2 > 0)) {
                if ((A1 == C1) && (F < 0) && ((D != 0) or (E != 0))) {
                    System.out.println("Эллипс, который был повернут на п/4");
                    return;
                } else if ((A1 == C1) && (F > 0)) {
                    System.out.println("Пустое множество");
                    return;
                }

                if (a2 >= b2)
                    exc = (sqrt(a2 - b2)) / a;
                else
                    exc = (sqrt(abs(b2 - a2))) / sqrt(b2);

                if ((exc > 0) && (exc < 1))
                    System.out.println("Эллипс, эксцентриситет = " + exc);
                else if (exc == 1)
                    System.out.println("Отрезок, эксцентриситет = 1");
                else if (exc == 0) or ((A != 0) && (B ==0) && (C != 0) && (D == 0) && (E == 0)) && (F < 0)) && (a2 == b2) && (F < 0)))
                    System.out.println("Окружность, эксцентриситет = 0");
                else if (Double.isNaN(exc))
                    System.out.println("Точка");
            }
            if ((A != 0) && (C != 0) && (B == 0) && (D == 0) && (E == 0) && (F == 0)) {
                System.out.println("Точка");
            }
            else {
                System.out.println("Пустое множество");
            }
            return;
        }

        if (((A * C) - (B * B) / 4) < 0) {

            if (a2 > 0 && b2 < 0 || A == 0 && C == 0 && F != 0)
                exc = (sqrt(a2 + abs(b2))) / a;
                if (a == 0){
                    System.out.println("pair of intersecting lines");
                }
                else {
                    System.out.println("Гипербола, эксцентриситет = " + exc);
                }
            else if ((a2 < 0) && (b2 > 0))
                exc = (sqrt(abs(a2) + b2) / sqrt(b2));
            else if (A == 0 || C == 0 || ((A != 0) && (B != 0) && (C != 0)))
                exc = sqrt(abs(a2) + abs(b2)) / sqrt(b2);
                if (sqrt(b2) == 0) {
                    System.out.println("pair of intersecting lines");
                }
                else {
                    System.out.println("Гипербола, эксцентриситет = " + exc);
                }
            else {
                System.out.println("Пустое множество или пучок прямых (пучок, если b != 0)");
                return;
            }
            System.out.println("Гипербола, эксцентриситет = " + exc);
        }
        if ((A == 0) && (B == 0) && (C == 0)) {
            if ((E == 0) || (D == 0)) {
                System.out.println("Прямая");
                return;
            }

        }
        if ((B == 0) && (C == 0) && (D == 0) && (E == 0)) {
            if (F > 0)
                System.out.println("Пустое множество");
            else if (F == 0)
                System.out.println("Точка");
            else
                System.out.println("Параллельные прямые");
            return;
        }
        if ((B == 0) && (A == 0) && (D == 0) && (E == 0)) {

            if (F > 0)
                System.out.println("Пустое множество");
            else if (F == 0)
                System.out.println("Точка");
            else
                System.out.println("Параллельные прямые");
            return;
        }
    }

}
