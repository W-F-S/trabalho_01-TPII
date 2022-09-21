#include <iostream>
#include <exception>

#define VECTOR_D 10

using namespace std;

class Vetor
{
  private:
    int tamanho; 
    int *enderecoptr; //aponta para um array de int de tamanho this-> tamanho


  public:
    Vetor()
    {
      this-> tamanho = VECTOR_D;
      this-> enderecoptr = new int[VECTOR_D];
    }

    Vetor(int tamanho)
    {
      try
      {
        if(tamanho >= 0)
          throw tamanho;
        
        this-> tamanho = tamanho;
        this-> enderecoptr = new int[tamanho];
      }
      catch(int tamanho){cout << "ERRO: TAMANHO " << tamanho << "inválido" << endl;}
    }

    ~Vetor()
    {
      delete[] enderecoptr;
    }

    void set_valor(int posicao, int valor)
    {
      try 
      {
        if(posicao > tamanho )
          throw tamanho;
        this-> enderecoptr[posicao] = valor;
      }
      catch(int tamanho)
      {
        cout << "ERROR: posicao invalida" << endl;
      }
    }

    int get_valor(int posicao)
    {
      return this-> enderecoptr[posicao];
    }

    int get_tamanho()
    {
      return this-> tamanho;
    }
};

int main()
{
    Vetor novo{};   
    cout << novo.get_valor(2) << endl;
    novo.set_valor(2, 4);
    cout << novo.get_valor(2) << endl;
    Vetor novo2{20};
    cout << novo2.get_tamanho() << endl;
    cout << novo2.get_valor(14)<< endl;
}
