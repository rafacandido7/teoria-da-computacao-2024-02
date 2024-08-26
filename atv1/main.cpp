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

string nextState(string currentState, char input) {
  if (currentState == "q0") {
    if (input == '0')
      return "q2";
    else
      return "q1";
  }

  if (currentState == "q1") {
    if (input == '0')
      return "q3";
    else
      return "q0";
  }

  if (currentState == "q2") {
    if (input == '0')
      return "q0";
    else
      return "q3";
  }

  if (currentState == "q3") {
    if (input == '0')
      return "q1";
    else
      return "q2";
  }
}

string q0 = "q1: O número de 0's vistos e o número de 1's vistos até agora são "
            "pares (PAR|PAR)";
string q1 = "q2: O número de 0's vistos é par e o número de 1's visto até "
            "agora é ímpar (PAR|IMPAR)";
string q2 = "q3: O número de 0's vistos é ímpar e o número de 1's visto até "
            "agora é par (IMPAR|PAR)";
string q3 = "q4: O número de 0's vistos e o número de 1's vistos até agora são "
            "ímpares (IMPAR|IMPAR)";

int main() {
  cout << "Automato Finito Deterministico\n";
  cout << "Automato: L = { w | W tem ao mesmo tempo um número par de 0's e um "
          "número par de 1's}"
       << '\n';

  cout << q0 << '\n';
  cout << q1 << '\n';
  cout << q2 << '\n';
  cout << q3 << '\n';

  cout << "Digite uma string compostas somente por 0 ou 1 para que o automato "
          "fale pertence ou não à linguagem L"
       << "\n\n";

  string w;

  cin >> w;

  if (!isBinaryString(w)) {
    cout << "A string contém outros caracteres além de 1 e 0." << '\n';
    exit(1);
  }

  string currentState = "q0";
  vector<string> states;

  states.push_back(currentState);

  for (auto w0 : w) {
    currentState = nextState(currentState, w0);
    states.push_back(currentState);
  }

  cout << "Estados Percorridos:" << '\n';

  for (auto state : states) {
    cout << state << " ";
  }

  cout << '\n';

  if (currentState == "q0") {
    cout << "A string pertence à linguagem L." << '\n';
  } else {
    cout << "A string NÃO pertence à linguagem L." << '\n';
  }

  return 0;
}
