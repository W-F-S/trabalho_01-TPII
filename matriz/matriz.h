#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime> /* srand, rand */
#include <exception>
#include <stdexcept>

#define MATRIZ_X 3
#define MATRIZ_Y 3

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
      for(int i = 0; i < x; i++)
      {
        delete[] enderecoptr[i];
      }
    }

    void mostrar_matriz()
    {
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          cout << " |" << enderecoptr[i][j] << "| ";
        }
        cout << endl;
      }
    }

    int get_tam_x()
    {
      return this-> x;
    }

    int get_tam_y()
    {
      return this-> y;
    }

    void set_tam_x(int nx){
      x=nx;
    }

    void set_tam_y(int ny){
      y=ny;
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
      if (mat.get_tam_x() != this->x && mat.get_tam_y() != this->y)
      {
        throw  invalid_argument("ERROR: matrizes de tamanhos diferentes");
      }
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          enderecoptr[i][j] = mat.get_valor(i, j);
        }
      }
    }

    Matriz &operator+(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};
      if (mat.get_tam_x() != this->x && mat.get_tam_y() != this->y)
      {
        throw  invalid_argument("ERROR: matrizes de tamanhos diferentes");
      }
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, enderecoptr[i][j] + mat.get_valor(i, j));
        }
      }

      return *retornar;
    }

    Matriz &operator-(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};

      if (mat.get_tam_x() != this->x && mat.get_tam_y() != this->y)
      {
        throw  invalid_argument("ERROR: matrizes de tamanhos diferentes");
      }
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, enderecoptr[i][j] - mat.get_valor(i, j));
        }
      }
      return *retornar;
    }

    Matriz &operator*(int mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};

      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, retornar->get_valor(i, j)*mat);
        }
      }
      return *retornar;
    }

    Matriz &operator*(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};

      if (mat.get_tam_x() != this->x && mat.get_tam_y() != this->y)
      {
        throw  invalid_argument("ERROR: matrizes de tamanhos diferentes");
      }
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, enderecoptr[i][j]*mat.get_valor(i, j));
        }
      }
      return *retornar;
    }

    Matriz &operator/(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, this-> y};

      if (mat.get_tam_x() != this->x && mat.get_tam_y() != this->y)
      {
        throw  invalid_argument("ERROR: matrizes de tamanhos diferentes");
      }
      for (int i = 0; i < x; i++)
      { 
        for(int j=0; j<y;j++)
        {
          retornar-> set_valor(i, j, floor(enderecoptr[i][j] / mat.get_valor(i, j)));
        }
      }
      return *retornar;
    }

    friend std::ostream& operator<<(std::ostream& stream, Matriz &mat)
    {
      string retornar = "";

      for(int i = 0; i < mat.get_tam_x(); i++ )
      {
        for(int j = 0; j < mat.get_tam_y(); j++)
        {
          retornar += "[" + to_string(mat.get_valor(i, j)) + "] ";  
        }
        retornar += '\n';
      }
      stream << retornar;
      return stream;
    }

    friend std::istream& operator>>(std::istream &entrada, Matriz &mat){
      int x;
      int y;

      cout<<"Determine a Quantidade de linhas: "<<endl;
      entrada >> x;
      mat.set_tam_x(x);
      cout<<"Determine a Quantidade de colunas: "<<endl;
      entrada>>y;
      mat.set_tam_y(y);
      for(int i = 0; i < mat.get_tam_x(); i++ )
      {
        for(int j = 0; j <mat.get_tam_y(); j++)
        {
          int valor;
          entrada>>valor;
          mat.set_valor(i, j, valor);
        }
      }
      return entrada;
    }
};


