#ifndef LAB6_H
#define LAB6_H

double** NewMatrix(int m, int n);

void FillMatrixDefolt(double** A, double B[]);

void FreeMatrix(double**& A, int m);

void EnterMatrix(double** A, int m, int n, double B[]);

void MakeN(double** N, double** A, int m, int n);

void MakeC(double C[], double B[], double** A, int m, int n);

void MakeL(double ** N, double** L, double** Lt, int n);

void PrintMatrix(double** A, int m, int n);

#endif // !LAB6_H
