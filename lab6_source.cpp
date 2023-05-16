#include <iostream>
#include <cmath>
#include "lab6.h"
#include "D:\NGR\כאבט ׳ּ\lab_4\lab4\lab4.h"
#include "D:\NGR\כאבט ׳ּ\lab_3\lab03\lab3.h"

#define SIZE 100

using namespace std;

//--------------------------------------------------------------------------------
//Make New Matrix m*n in heap, return poiner on this
double** NewMatrix(int m, int n) {
  double** M = ( double** ) new double* [m];

  for(int i = 0; i < m; i++) {
    double* Line = new double[n];
    M[i] = Line;
  }
  return M;
}

//--------------------------------------------------------------------------------
//fill matrix defolt value
void FillMatrixDefolt(double** A, double B[]) {
  double M[5][3] = {
    {2, -1, 3},
    {1, 1, -4},
    {1, 2, -3},
    {2, -1, -2},
    {-1, -2, -1}
  };
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 3; j++) {
      A[i][j] = M[i][j];
    }
  }
  double b[] = { -2, -3, -1, 4, 6 };
  for(int i = 0; i < 5; i++) B[i] = b[i];
}

//--------------------------------------------------------------------------------
//free memory from martrix
void FreeMatrix(double**& A, int m) {
  for(int i = 0; i < m; i++) {
    delete[] A[i];
  }
  delete[] A;
  A = nullptr;
}

//--------------------------------------------------------------------------------
void EnterMatrix(double** A, int m, int n, double B[]) {
  cout << "Enter matrix" << endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  cout << "Enter column free member" << endl;
  for(int i = 0; i < m; i++) {
    cin >> B[i];
  }
}

//--------------------------------------------------------------------------------
void MakeN(double** N, double** A, int m, int n) {

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      double dSum = 0;
      for(int t = 0; t < m; t++) {
        dSum += A[t][i] * A[t][j];
      }
      N[i][j] = dSum;
    }
  }
}

//--------------------------------------------------------------------------------
void MakeC(double C[], double B[], double** A, int m, int n) {

  for(int i = 0; i < n; i++) {
    double dSum = 0;
    for(int j = 0; j < m; j++) {
      dSum += A[j][i] * B[j];
    }
    C[i] = dSum;
  }
}

//--------------------------------------------------------------------------------
void MakeL(double** N, double** L, double** Lt, int n) {
  L[0][0] = sqrt(N[0][0]);
  for(int i = 1; i < n; i++) L[i][0] = ( N[i][0] / L[0][0] );

  for(int i = 1; i < n; i++) {
    double dSumForDiagonal = N[i][i];
    for(int j = 0; j < i; j++) {
      dSumForDiagonal -= L[i][j] * L[i][j];
    }
    L[i][i] = sqrt(dSumForDiagonal);

    for(int j = i + 1; j < n; j++) {
      double dSum = N[j][i];
      for(int k = 0; k < i; k++) {
        dSum -= L[i][k] * L[j][k];
      }
      L[j][i] = dSum / L[i][i];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      Lt[i][j] = L[j][i];
    }
  }
}

//--------------------------------------------------------------------------------
void PrintMatrix(double** A, int m, int n) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cout.precision(3);
      cout.width(5);
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}


