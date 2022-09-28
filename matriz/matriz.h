#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> /* srand, rand */
#include <exception>

#define MATRIZ_X 10
#define MATRIZ_Y 10

using namespace std;

class Matriz
{
  private:
    int x, y;
    int** enderecoptr;

    void inic_valores_aleatorios()
    {
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          enderecoptr[i][j] = rand() % 101;
        }
      }
    }

  public: 
    Matriz()
    {
      try
      {
      this-> x = MATRIZ_X;
      this-> y = MATRIZ_Y; 

      enderecoptr = new int* [x];
      for(int i = 0; i < x; i++)
      {
        enderecoptr[i] = new int[y]; 
      }
      inic_valores_aleatorios();
      }
     catch(bad_alloc)
     {
     cout<<"Não há espaço o suficiente";
     }
    }

    Matriz(int x, int y)
    {
      try
      {
      this-> x = x;
      this-> y = y;

      enderecoptr = new int* [x];
      for(int i = 0; i < x; i++)
      {
        enderecoptr[i] = new int[y]; 
      }
      inic_valores_aleatorios();
      }
      catch(bad_alloc){
      cout<<"Não há espaço o suficiente";
      }
    }

    ~Matriz() 
    {
  /*    for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
        }
      }*/
      delete[] enderecoptr;
    }

    int get_tam_x()
    {
      return this-> x;
    }

    int get_tam_y()
    {
      return this-> y;
    }

    int get_valor(int x, int y)
    {
      return enderecoptr[x][y];
    }

    void set_valor(int x, int y, int valor)
    {

     enderecoptr[x][y] = valor;
    }

    void operator=(Matriz &mat)
    {
      try
      {
        if (mat.get_tam_x() == this->x && mat.get_tam_y() == this->y)
        {
          for(int i = 0; i < x; i++)
          {
            for(int j = 0; j < y; j++)
            { 
              enderecoptr[i][j] = mat.get_valor(i, j);
            }
          }
        }
        else{ throw 0; }
      }
      catch (int)
      {
        cout << "ERROR: matrizes de tamanho diferente" << endl;
      }
    }
   
    Matriz &operator+(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, enderecoptr[i][j] + mat.get_valor(i, j));
        }
      }

      return retornar;
    }

    Matriz &operator-(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, enderecoptr[i][j] - mat.get_valor(i, j));
        }
      }

      return retornar;
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
  Vetor &operator/(Vetor &vec1)
    {
      Vetor *retornar = new Vetor{};
      for (int i = 0; i < this->tamanho; i++)
      {
        retornar->set_valor(i, (this->enderecoptr[i]/vec1.get_valor(i)));
      }
      return *retornar;
    }


};
