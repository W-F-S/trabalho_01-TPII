#include "matriz.h"

void testes_operador_igual()
{
  Matriz random{};
  Matriz random2{};

  cout << "Matriz1:" << endl;
  cout << random;
  cout << "matriz2:" << endl;
  cout << random2;
  cout << "Matriz2 = Matriz1" << endl;
  random2 = random;
  cout << random2;

}

void testes_operador_somar()
{
  Matriz random{};
  Matriz random2{};
  Matriz vazio{};

  cout << random;
  cout << "+" << endl;
  cout << random2;
  cout << "Matriz2 + Matriz1" << endl;
  vazio = (random + random2);
  cout << vazio;
}

void testes_operador_subtrair()
{
  Matriz random{};
  Matriz random2{};
  Matriz vazio{};

  cout << random;
  cout << "-" << endl;
  cout << random2;

  cout << "Matriz2 - Matriz1" << endl;
  vazio = (random - random2);
  cout << vazio;
}

void testes_operador_dividir()
{
  Matriz random{};
  Matriz random2{};
  Matriz vazio{};

  cout << random;
  cout << "/" << endl;
  cout << random2;

  cout << "Matriz2 / Matriz1" << endl;
  vazio = (random / random2);
  cout << vazio;
}

void testes_operador_multiplicar_matrizes()
{
  Matriz random{};
  Matriz random2{};
  Matriz vazio{};

  cout << random;
  cout << "*" << endl;
  cout << random2;
  cout << "Matriz2 * Matriz1" << endl;
  vazio = (random * random2);
  cout << vazio;
}

void testes_operador_produto_escalar()
{
  Matriz random{3, 3};
  Matriz random2{3, 3};
  int valor = 4;

  cout << random;
  cout << "*" << endl;
  cout << valor << endl;
  cout << "constante * Matriz: " << endl;
  random2 = random * valor;
  cout << random2 << endl;
}

void testes_operador_menor()
{
  Matriz teste1{};

  cout << teste1;
  cout << teste1 << endl;
}

void testes_operador_maior()
{
  Matriz teste1{};

  cout << teste1 << endl;

  cout << "cin >> matriz" << endl;
  cin >> teste1;
  cout << teste1 << endl;
}

int main()
{
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
    testes_operador_multiplicar_matrizes();
    cout << "digite para continuar: ";
    getchar();
    cout << "\033[2J\33[1;1H"; //"\033[2J\033[1;1H"

    cout << "Teste: operador * (escalar)" << endl;
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
