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

      return *retornar;
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
      return *retornar;
    }

    Matriz &operator*(int &mat)
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
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        { 
          retornar-> set_valor(i, j, enderecoptr[i][j]*mat.get_valor(i, j));
        }
      }
      return *retornar;
    }

/**
    Matriz &operator*(Matriz &mat)
    {
      Matriz *retornar = new Matriz{this-> x, mat.get_tam_y()};
      int i = 0; int j = 0; int h=0; int k =0;
      int var1 = 0;
      int soma = 0;
      int var2 = 0;

      string saida = "";
      if(this-> y != mat.get_tam_x())
      {
        //erro
      }

      while(i < this-> x)
      {
        for(j = 0; j < this-> y; j++)
        {
          soma += enderecoptr[i][j] * mat.get_valor(j, var2);
          //          saida = "this[" + to_string(i) + "," + to_string(j) + "]" + ":" + to_string(enderecoptr[i][j]) + " " + "mat[" + to_string(j) + "," + to_string(i) + "]" + ":" + to_string(mat.get_valor(j, var2)) + " ";

          cout << saida << endl;
        }
        cout << endl;
        //cout << "soma:" << soma << endl;
        retornar-> set_valor( k, h, soma);
        h++;
        soma = 0; 
        var1++;
        var2++;

        if (h == retornar-> get_tam_y())
        {
          k++; h=0;
        }
        if(var1 == mat.get_tam_y())
        {
          i++; var1 = 0;
        }
        if(var2 == this->x)
        {
          var2=0;
        }
      }
      return *retornar;
    }
*/

    friend std::ostream& operator<<(std::ostream& stream, Matriz &mat)
    {
      string retornar = "";

      for(int i = 0; i < mat.get_tam_x(); i++ )
      {
        for(int j = 0; j < mat.get_tam_y(); j++)
        {
          retornar += to_string(mat.get_valor(i, j)) + ", ";  
        }
        retornar += '\n';
      }
      stream << retornar;

      return stream;
    }
};


