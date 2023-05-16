#include <iostream>
#include "lab6.h"
#include "D:\NGR\כאבט ׳ּ\lab_4\lab4\lab4.h"
#include "D:\NGR\כאבט ׳ּ\lab_3\lab03\lab3.h"

#define SIZE 100
using namespace std;

int main() {
  int m = 5, n = 3;
  double** A;
  double B[SIZE];
  cout << "Use defolt matrix? (1 - YES, 0 - NO)" << endl;
  int a;
  cin >> a;
  if(a == 0) {
    cout << "Enter m and n" << endl;
    cin >> m >> n;
    A = NewMatrix(m, n);
    EnterMatrix(A, m, n, B);

  } else {
    A = NewMatrix(m, n);
    FillMatrixDefolt(A, B);
  }
  cout << endl << "Start matrix" << endl;
  PrintMatrix(A, m, n);
  cout << endl;

  cout << "Column free member" << endl;
  for(int i = 0; i < m; i++) cout << B[i] << endl;
  cout << endl;

  double** N = NewMatrix(n, n);
  MakeN(N, A, m, n);

  cout << "Matrix N" << endl;
  PrintMatrix(N, n, n);
  cout << endl;
  cout << "Det = " << DetM(N, n);
  cout << endl;
  cout << endl;
  if(DetM(N, n) < 0) {
    cout << "There is no result by sqare root";
    return 0;
  }
  double C[SIZE] = {};
  double Y[SIZE] = {};
  double X[SIZE] = {};
  MakeC(C, B, A, m, n);

  cout << "Column free member" << endl;
  for(int i = 0; i < n; i++) cout << C[i] << endl;
  cout << endl;


  double** L = NewMatrix(n, n);
  double** Lt = NewMatrix(n, n);
  FillZero(L, n);
  FillZero(Lt, n);

  MakeL(N, L, Lt, n);

  cout << "Matrix L" << endl;
  PrintMatrix(L, n, n);
  cout << endl;

  LUStraight(L, n, C, Y);
  cout << "Column Y" << endl;
  for(int i = 0; i < n; i++) cout << Y[i] << endl;
  cout << endl;

  Reverse(Lt, n, Y, X);

  cout << "Answers" << endl;
  for(int i = 0; i < n; i++) cout << X[i] << endl;


  FreeMatrix(A, m);
}