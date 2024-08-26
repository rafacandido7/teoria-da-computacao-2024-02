#include <bits/stdc++.h>

using namespace std;

bool isBinaryString(string &str) {
  for (char c : str) {
    if (c != '0' && c != '1') {
      return false;
    }
  }
  return true;
}

string q1 = "q1: O número de 0's vistos e o número de 1's vistos até agora são pares (PAR|PAR)";
string q2 = "q2: O número de 0's vistos é par e o número de 1's visto até agora é ímpar (PAR|IMPAR)";
string q3 = "q3: O número de 0's vistos é ímpar e o número de 1's visto até agora é par (IMPAR|PAR)";
string q4 = "q4: O número de 0's vistos e o número de 1's vistos até agora são ímpares (IMPAR|IMPAR)";


int main() {
  cout << "Automato Finito Deterministico\n";
  cout << "Automato: L = { w | W tem ao mesmo tempo um número par de 0's e um "
          "número par de 1's}"
       << '\n';

  cout << q1 << '\n';
  cout << q2 << '\n';
  cout << q3 << '\n';
  cout << q4 << '\n';

  cout << "Digite uma string compostas somente por 0 ou 1 para que o automato fale pertence ou não à linguagem L" << "\n\n";

  string w;
  vector<string> states;

  cin >> w;

  if (!isBinaryString(w)) {
    cout << "A string contém outros caracteres além de 1 e 0." << '\n';
    exit(1);
  }

  long long zeros = 0;
  long long ones = 0;

  for (char w0 : w) {
    cout << w0 << '\n';

    if (w0 == '0') {
      zeros +=1;
    }

    if (w0 == '1') {
      ones +=1;
    }

    bool zerosStates = zeros % 2 == 0; // if true is pair, else is even
    bool onesStates = ones % 2 == 0; // if true is pair, else is even

    if (zerosStates && onesStates) {
      states.push_back("q1");
    }

    if (zerosStates && !onesStates) {
      states.push_back("q2");
    }

    if (!zerosStates && onesStates) {
      states.push_back("q3");
    }

    if (!zerosStates && !onesStates) {
      states.push_back("q4");
    }
    // verify states

    // if (w == "") {
    //   states.push_back("q0");
    // }
  }

  // define

  // printar estados e verificar se o ultimo elemento é o q0; se for ele
  // pertence a L, cc não pertence.

  return 0;
}
