#include "vetor.h"

void testes_operador_igual()
{
  Vetor random{};
  Vetor random2{};

  cout << "vetor1: " << endl;
  cout << random << endl;
  cout << "vetor2: " << endl;
  cout << random2 << endl;
  cout << "vetor2 = vetor1" << endl;
  random2 = random;
  cout << "resposta:" << endl;
  cout << random2 << endl;
}

void testes_operador_somar()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << "vetor1:" << endl;
  cout << random << endl;
  cout << "+" << endl;
  cout << "vetor2:" << endl;
  cout << random2 << endl;
  vazio = (random + random2);
  cout << "resposta:" << endl;
  cout << vazio << endl;
}

void testes_operador_subtrair()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << "vetor1:" << endl;
  cout << random << endl;
  cout << "-" << endl;
  cout << "vetor2:" << endl;
  cout << random2 << endl;

  cout << "resposta:" << endl;
  vazio = (random - random2);
  cout << vazio << endl;
}

void testes_operador_dividir()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << "vetor1:" << endl;
  cout << random << endl;
  cout << "/" << endl;
  cout << "vetor2:" << endl;
  cout << random2 << endl;

  cout << "resposta:" << endl;
  vazio = (random / random2);
  cout << vazio << endl;
}

void testes_operador_multiplicar_vetores()
{
  Vetor random{};
  Vetor random2{};
  Vetor vazio{};

  cout << "vetor1:" << endl;
  cout << random << endl;
  cout << "*" << endl;
  cout << "vetor2:" << endl;
  cout << random2 << endl;

  cout << "resposta:" << endl;
  vazio = (random * random2);
  cout << vazio << endl;
}


void testes_operador_multiplicacao_escalar()
{
  Vetor random{};
  int valor = 4;
  Vetor vazio{};

  cout << "vetor1:" << endl;
  cout << random << endl;
  cout << "*" << endl;
  cout << "valor:" << endl;
  cout << valor << endl;

  cout << "resposta:" << endl;
  vazio = (random * valor);
  cout << vazio << endl;
}


void testes_operador_produto_escalar()
{
  Vetor random{3};
  Vetor random2{3};
  int vazio;

  cout << "vetor1:" << endl;
  cout << random << endl;
  cout << "%" << endl;
  cout << "vetor2:" << endl;
  cout << random2 << endl;

  cout << "resposta:" << endl;
  vazio = (random % random2);
  cout << vazio << endl;
}

void testes_operador_menor()
{
  Vetor teste1{};
  cout << teste1 << endl;
}

void testes_operador_maior()
{
  Vetor teste1{};
  cout << "vetor1:" << endl;
  cout << teste1 << endl;
  cout << "cin >> vetor1:" << endl;
  cin >> teste1;
  cout << "resposta:" << endl;
  cout << teste1 << endl;
}
int main()
{
  srand((unsigned)time(NULL));
  try
  {
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"
    cout << "Teste: operador =" << endl;
    testes_operador_igual();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador +" << endl;
    testes_operador_somar();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador -" << endl;
    testes_operador_subtrair();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador /" << endl;
    testes_operador_dividir();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador *" << endl;
    testes_operador_multiplicar_vetores();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador * (produto de um vetor por uma constante)" << endl;
    testes_operador_multiplicacao_escalar();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador % (produto escalar de dois vetores)" << endl;
    testes_operador_produto_escalar();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"
                               
    cout << "Teste: operador >>" << endl;
    testes_operador_maior();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"
  }
  catch(invalid_argument& e)
  {

    cerr << e.what() << endl;
    return -1;
  }
  return 0;
}
