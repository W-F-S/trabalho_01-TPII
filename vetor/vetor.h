#include <iostream> //cin, cout
#include <algorithm> //fgets
#include <string>
#include <cmath> //floor
#include <cstdlib>
#include <ctime> //srand, rand 
#include <exception>
#include <stdexcept>

#define VECTOR_D 10

using namespace std;

class Vetor
{
  private:
    int tamanho;
    int *enderecoptr; // aponta para um array de int de tamanho this-> tamanho
                      //
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
      if (tamanho < 0)
      {
        throw invalid_argument("Tamanho inválido.");
      }
      this->tamanho = tamanho;
      this->enderecoptr = new int[tamanho];

      inic_valores_aleatorios();
    }

    ~Vetor() { delete[] enderecoptr; }

    void set_valor(int posicao, int valor)
    {
      if (posicao > tamanho)
      {
        throw invalid_argument("Posição inválida.");
      }
      this->enderecoptr[posicao] = valor;
    }

    int get_valor(int posicao) { return this->enderecoptr[posicao]; }

    int get_tamanho() { return this->tamanho; }

    void operator=(Vetor &vec)
    {
      if (vec.get_tamanho() != this->tamanho)
      {
        throw  invalid_argument("ERROR: vetores de tamanhos diferentes");
      }
      for (int i = 0; i < this->tamanho; i++)
      {
        this->enderecoptr[i] = vec.get_valor(i);
      }
    }

    Vetor &operator+(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{this-> tamanho};

      if (vec1.get_tamanho() != this->tamanho)
      {
        throw  invalid_argument("ERROR: vetores de tamanhos diferentes");
      }
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] + vec1.get_valor(i)));
      }
      return *retornar;
    }

    Vetor &operator-(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      if (vec1.get_tamanho() != this->tamanho)
      {
        throw  invalid_argument("ERROR: vetores de tamanhos diferentes");
      }
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i] - vec1.get_valor(i)));
      }
      return *retornar;
    }

    Vetor &operator/(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};

      if (vec1.get_tamanho() != this->tamanho)
      {
        throw  invalid_argument("ERROR: vetores de tamanhos diferentes");
      }
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, floor(this->enderecoptr[i] / vec1.get_valor(i)));
      }
      return *retornar;
    }

    Vetor &operator*(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      if (vec1.get_tamanho() != this->tamanho)
      {
        throw  invalid_argument("ERROR: vetores de tamanhos diferentes");
      }
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

    int operator%(Vetor &vec1)
    {
      int retornar = 0;
      if (vec1.get_tamanho() != this->tamanho)
      {
        throw  invalid_argument("ERROR: vetores de tamanhos diferentes");
      }
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar += (this-> enderecoptr[i] * vec1.get_valor(i));
      }
      return retornar;
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

    friend std::istream& operator>>(istream &Entrada, Vetor &vet)
    {
      string inp;
      string temp = "";
      int indx_vec = 0;
      cout << "Insira os valores separados por espaços. Tam_max do vetor: " <<  vet.get_tamanho() << endl;
      getline(cin, inp); //getline para pegar espaços

      if(inp[inp.size()-1] != ' ') //verificação para pegar o ultimo valor
      {
        inp += " ";
      }
      for(int i = 0; i < inp.size();i++)
      {
        if(inp[i] == ' ')
        {
          if(indx_vec < vet.get_tamanho())
          {
            vet.set_valor(indx_vec, stoi(temp));
            indx_vec++;
            temp = "";
          }
          else
          {
            cout << "ATENÇÃO: valores inseridos excedem o tamanho do vetor" << endl;
          }
        }
        else
        {
          temp += inp[i];
        }
      }
      return Entrada;
    }
};

