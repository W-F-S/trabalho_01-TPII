#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> /* srand, rand */
#include <exception>

#define VECTOR_D 10

using namespace std;

class Vetor
{
  private:
    int tamanho;
    int *enderecoptr; // aponta para um array de int de tamanho this-> tamanho
    void inic_valores_aleatorios()
    {
      for (int i = 0; i < tamanho; i++)
      {
        enderecoptr[i] = rand() % 101;
      }
    }

  public:
    Vetor()
    {
      this->tamanho = VECTOR_D;
      this->enderecoptr = new int[VECTOR_D];
      inic_valores_aleatorios();
    }

    Vetor(int tamanho)
    {
      try
      {
        if (tamanho < 0){
          throw tamanho;

          this->tamanho = tamanho;
          this->enderecoptr = new int[tamanho];

          inic_valores_aleatorios();}
      }
      catch (int tamanho)
      {
        cout << "ERRO: TAMANHO " << tamanho << " inválido" << endl;
      }
    }

    ~Vetor() { delete[] enderecoptr; }

    void set_valor(int posicao, int valor)
    {
      try
      {
        if (posicao > tamanho)
          throw tamanho;
        this->enderecoptr[posicao] = valor;
      }
      catch (int tamanho)
      {
        cout << "ERROR: posicao invalida" << endl;
      }
    }

    int get_valor(int posicao) { return this->enderecoptr[posicao]; }

    int get_tamanho() { return this->tamanho; }
    void set_tamanho (int tamanho){tamanho=this->tamanho;}

    void operator=(Vetor &vec)
    {
      try
      {
        if (vec.get_tamanho() == this->tamanho)
        {
          for (int i = 0; i < this->tamanho; i++)
          {
            this->enderecoptr[i] = vec.get_valor(i);
          }
        }
      }
      catch (int tamanho)
      {
        cout << "ERROR: vetores de tamanho diferente" << endl;
      }
    }

    Vetor &operator+(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] + vec1.get_valor(i)));
      }
      return *retornar;
    }


    int operator%(Vetor &vec1)
    {
      int retornar = 0;
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar += (this-> enderecoptr[i] * vec1.get_valor(i));
      }
      return retornar;
    }

    Vetor &operator-(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] - vec1.get_valor(i)));
      }
      return *retornar;
    }

    Vetor &operator/(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] / vec1.get_valor(i)));
      }
      return *retornar;
    }

    Vetor &operator*(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] * vec1.get_valor(i)));
      }
      return *retornar;
    }

    Vetor &operator*(int &vec1)
    {
      Vetor *retornar = new Vetor{};
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] * vec1));
      }
      return *retornar;
    }

    friend std::ostream& operator<<(std::ostream& stream, Vetor &vec)
    {
      int tamanho = vec.get_tamanho();
      string retornar = "";

      for(int i = 0; i< tamanho; i++ )
      {
        retornar += to_string(vec.get_valor(i)) + ",";  
      }
      stream << retornar;

      return stream;
    }


    void escrever_vetor()
    {
      cout << "[";
      for (int i = 0; i < tamanho; i++)
      {
        cout << enderecoptr[i] << ",";
      }
      cout << "]" << endl;
    }
};

