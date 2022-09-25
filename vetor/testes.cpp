#include "vetor.h"

void testes_operador_igual()
{
  Vetor random{};
  cout << "vetor1:" << endl;
  random.escrever_vetor();

  cout << "vetor2:" << endl;
  Vetor random2{};
  random2.escrever_vetor();

  cout << "vetor2 = vetor1" << endl;
  random2 = random;
  random2.escrever_vetor();
}

void testes_operador_somar()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  random.escrever_vetor();
  cout << "+" << endl;
  random2.escrever_vetor();

  vazio = (random + random2);
  vazio.escrever_vetor();
}

void testes_operador_subtrair()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  random.escrever_vetor();
  cout << "-" << endl;
  random2.escrever_vetor();

  vazio = (random - random2);
  vazio.escrever_vetor();
}

void testes_operador_dividir()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  random.escrever_vetor();
  cout << "/" << endl;
  random2.escrever_vetor();

  vazio = (random / random2);
  vazio.escrever_vetor();
}

void testes_operador_multiplicacao_vetores()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  random.escrever_vetor();
  cout << "*" << endl;
  random2.escrever_vetor();

  vazio = (random * random2);
  vazio.escrever_vetor();
}


void testes_operador_multiplicacao_escalar()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  random.escrever_vetor();
  cout << "*" << endl;
  random2.escrever_vetor();

  vazio = (random * random2);
  vazio.escrever_vetor();
}


void testes_operador_produto_escalar()
{
  Vetor random{3};
  Vetor random2{3};
  int vazio;

  random.escrever_vetor();
  cout << "%" << endl;
  random2.escrever_vetor();

  vazio = (random % random2);
  cout << vazio << endl;
}

void testes_operador_maior()
{
  Vetor teste1{};
  teste1.escrever_vetor();
  cout << teste1 << endl;
}

int main()
{
  srand((unsigned)time(NULL));
}
