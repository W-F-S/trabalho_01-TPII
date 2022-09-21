#include <iostream>
#include <cstdlib>
#include <ctime>     /* srand, rand */
#include <exception>


#define VECTOR_D 10

using namespace std;

class Vetor
{
  private:
    int tamanho; 
    int *enderecoptr; //aponta para um array de int de tamanho this-> tamanho

    void inic_valores_aleatorios()
    {
      for(int i = 0; i < tamanho; i++){enderecoptr[i] = rand() % 100 + 1;}
    }

  public:
    Vetor()
    {
      this-> tamanho = VECTOR_D;
      this-> enderecoptr = new int[VECTOR_D];
      inic_valores_aleatorios();
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

    ~Vetor(){delete[] enderecoptr;}

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

    int get_valor(int posicao){return this-> enderecoptr[posicao];}

    int get_tamanho(){return this-> tamanho;}

    void operator = (Vetor &vec)
    { 
      try
      {
        if(vec.get_tamanho() == this-> tamanho)
        {
        
          for(int i = 0; i<this-> tamanho; i++)
          {
            this->enderecoptr[i] = vec.get_valor(i);
          }
        }
      }
      catch(int tamanho)
      {
             cout << "ERROR: vetores de tamanho diferente" << endl;
      }
    }

    void escrever_vetor()
    {
      cout << "[";
      for(int i = 0; i < tamanho; i++){cout << enderecoptr[i] << ","; }
      cout << "]" << endl;
    }

};


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



int main()
{ 


}
