#include "vetor.h"

void testes_operador_igual()
{
  Vetor random{};
  Vetor random2{};

  cout << "vetor1:" << endl;
  cout << random;
  cout << "vetor2:" << endl;
  cout << random2;
  cout << "vetor2 = vetor1" << endl;
  random2 = random;
  cout << random2;
}

void testes_operador_somar()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << random;
  cout << "+" << endl;
  cout << random2;
  vazio = (random + random2);
  cout << vazio;
}

void testes_operador_subtrair()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << random;
  cout << "-" << endl;
  cout << random2;

  vazio = (random - random2);
  cout << vazio;
}

void testes_operador_dividir()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << random;
  cout << "/" << endl;
  cout << random2;

  vazio = (random / random2);
  cout << vazio;
}

void testes_operador_multiplicacao_vetores()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << random;
  cout << "*" << endl;
  cout << random2;

  vazio = (random * random2);
  cout << vazio;
}


void testes_operador_multiplicacao_escalar()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << random;
  cout << "*" << endl;
  cout << random2;

  vazio = (random * random2);
  cout << vazio;
}


void testes_operador_produto_escalar()
{
  Vetor random{3};
  Vetor random2{3};
  int vazio;

  cout << random;
  cout << "%" << endl;
  cout << random2;

  vazio = (random % random2);
  cout << vazio << endl;
}

void testes_operador_menor()
{
  Vetor teste1{};
  cout << teste1;
  cout << teste1 << endl;
}

void testes_operador_maior()
{
  Vetor teste1{};
  cout << teste1 << endl;
  cin >> teste1;
  cout << teste1 << endl;
}
int main()
{
  srand((unsigned)time(NULL));
}
