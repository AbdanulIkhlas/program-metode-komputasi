#include <iostream>
#include <iomanip>  // Untuk format tabel
#include <cmath>    // Untuk fungsi matematika
#include <cctype>   // Untuk toupper()

using namespace std;

// Fungsi f(x) = e^x - 5x^2
double f(double x) {
    return exp(x) - 5 * x * x;
}

// Metode Bisection
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Salah satu nilai fungsi di batas tidak valid untuk metode bisection.\n";
        return;
    }

    double c = a;
    int iterasi = 0;

    // Header tabel
    cout << setw(5) << "Iter" << setw(10) << "a" << setw(10) << "b" << setw(10) << "c"
         << setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15) << "f(c)" << setw(15) << "Lebar Selang\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    while ((b - a) >= tol) {
        c = (a + b) / 2;

        // Cetak nilai iterasi dalam tabel
        cout << setw(5) << iterasi++ << setw(10) << a << setw(10) << b << setw(10) << c
             << setw(15) << f(a) << setw(15) << f(b) << setw(15) << f(c) << setw(15) << b - a << endl;

        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }

    cout << "\nAkar yang ditemukan menggunakan metode Bisection: " << c << endl;
}

// Metode Regula Falsi
void regulaFalsi(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Salah satu nilai fungsi di batas tidak valid untuk metode Regula Falsi.\n";
        return;
    }

    double c = a;
    int iterasi = 0;

    // Header tabel
    cout << setw(5) << "Iter" << setw(10) << "a" << setw(10) << "b" << setw(10) << "c"
         << setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15) << "f(c)" << setw(15) << "Lebar Selang\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    while ((b - a) >= tol) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Cetak nilai iterasi dalam tabel
        cout << setw(5) << iterasi++ << setw(10) << a << setw(10) << b << setw(10) << c
             << setw(15) << f(a) << setw(15) << f(b) << setw(15) << f(c) << setw(15) << b - a << endl;

        if (f(c) == 0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }

    cout << "\nAkar yang ditemukan menggunakan metode Regula Falsi: " << c << endl;
}

// Metode Secant
void secant(double x0, double x1, double tol) {
    double x2;
    int iterasi = 0;

    // Header tabel seperti pada gambar
    cout << "-------------------------------------------\n";
    cout << setw(5) << "i" << setw(15) << "xr" << setw(20) << "|xr+1 - xr|\n";
    cout << "-------------------------------------------\n";

    while (true) {
        // Menghitung x2
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        // Output iterasi pertama tidak perlu selisih (|xr+1 - xr|), sesuai contoh
        if (iterasi == 0) {
            cout << setw(5) << iterasi << setw(15) << x1 << setw(20) << "-" << endl;
        } else {
            cout << setw(5) << iterasi << setw(15) << x1 << setw(20) << fabs(x2 - x1) << endl;
        }

        // Cek jika selisih kurang dari toleransi, maka berhenti
        if (fabs(x2 - x1) < tol) break;

        // Update nilai untuk iterasi berikutnya
        x0 = x1;
        x1 = x2;
        iterasi++;
    }

    // Output hasil akar yang ditemukan
    cout << "-------------------------------------------\n";
    cout << "\nAkar yang ditemukan menggunakan metode Secant : " << x2 << endl;
}

// Metode Fixed Point
double g(double x) {
    return sqrt((exp(x)) / 5);  // Transformasi untuk fixed point
}

void fixedPoint(double x0, double tol, int maxIter) {
    double x1;
    int iterasi = 0;

    // Header tabel
    cout << setw(5) << "Iter" << setw(10) << "x0" << setw(10) << "x1" << setw(15) << "|x1 - x0|\n";
    cout << "-----------------------------------------------------\n";

    for (int i = 0; i < maxIter; i++) {
        x1 = g(x0);

        // Cetak nilai iterasi dalam tabel
        cout << setw(5) << iterasi++ << setw(10) << x0 << setw(10) << x1 << setw(15) << fabs(x1 - x0) << endl;

        if (fabs(x1 - x0) < tol) break;
        x0 = x1;
    }

    cout << "\nAkar yang ditemukan menggunakan metode Fixed Point: " << x1 << endl;
}

// Metode Newton-Raphson
double df(double x) {
    return exp(x) - 10 * x;  // Turunan dari f(x) = e^x - 5x^2
}

void newtonRaphson(double x0, double tol, int maxIter) {
    double x1;
    int iterasi = 0;

    // Header tabel
    cout << setw(5) << "Iter" << setw(10) << "x0" << setw(10) << "x1" << setw(15) << "|x1 - x0|\n";
    cout << "-----------------------------------------------------\n";

    for (int i = 0; i < maxIter; i++) {
        x1 = x0 - f(x0) / df(x0);

        // Cetak nilai iterasi dalam tabel
        cout << setw(5) << iterasi++ << setw(10) << x0 << setw(10) << x1 << setw(15) << fabs(x1 - x0) << endl;

        if (fabs(x1 - x0) < tol) break;
        x0 = x1;
    }

    cout << "\nAkar yang ditemukan menggunakan metode Newton-Raphson: " << x1 << endl;
}

int main() {
    int choice;
    double a, b, x0, tol;
    int maxIter;
    char loopingAgain;

    do {
        system("cls");
        cout << "\nMenu Komputasi Numerik:\n";
        cout << "1. Bisection\n";
        cout << "2. Regula Falsi\n";
        cout << "3. Secant\n";
        cout << "4. Fixed Point\n";
        cout << "5. Newton Raphson\n";
        cout << "6. Keluar\n";
        cout << "Pilih metode: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai a: ";
                cin >> a;
                cout << "Masukkan nilai b: ";
                cin >> b;
                cout << "Masukkan toleransi: ";
                cin >> tol;
                cout<<endl<<endl;
                cout<<"Menggunakan f(x) = e^x - 5x^2"<<endl<<endl;
                bisection(a, b, tol);
                break;
            case 2:
                cout << "Masukkan nilai a: ";
                cin >> a;
                cout << "Masukkan nilai b: ";
                cin >> b;
                cout << "Masukkan toleransi: ";
                cin >> tol;
                cout<<endl<<endl;
                cout<<"Menggunakan f(x) = e^x - 5x^2"<<endl<<endl;
                regulaFalsi(a, b, tol);
                break;
            case 3:
                cout << "Masukkan nilai x0: ";
                cin >> x0;
                cout << "Masukkan nilai x1: ";
                cin >> b;
                cout << "Masukkan toleransi: ";
                cin >> tol;
                // cout << "Masukkan iterasi maksimal: ";
                // cin >> maxIter;
                cout<<endl<<endl;
                cout<<"Menggunakan f(x) = e^x - 5x^2"<<endl<<endl;
                secant(x0, b, tol);
                break;
            case 4:
                cout << "Masukkan nilai x0: ";
                cin >> x0;
                cout << "Masukkan toleransi: ";
                cin >> tol;
                cout << "Masukkan iterasi maksimal: ";
                cin >> maxIter;
                fixedPoint(x0, tol, maxIter);
                break;
            case 5:
                cout << "Masukkan nilai x0: ";
                cin >> x0;
                cout << "Masukkan toleransi: ";
                cin >> tol;
                cout << "Masukkan iterasi maksimal: ";
                cin >> maxIter;
                newtonRaphson(x0, tol, maxIter);
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

        if(choice != 6) {
            cout << endl;
            cout << "Kembali ke menu utama? (y/n): ";
            cin >> loopingAgain;
            cout << endl;
            loopingAgain = toupper(loopingAgain);
        }

    } while (choice != 6 && loopingAgain == 'Y');

    return 0;
}
