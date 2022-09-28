#include "matriz.h"

int main()
{
  Matriz mat{2, 2};
  mat.mostrar_matriz();
cout << "------------------------------------------------" << endl;
  Matriz mat2{2, 2};
  mat2.mostrar_matriz();
  
cout << "------------------------------------------------" << endl;
  Matriz mat3{mat.get_tam_x(), mat2.get_tam_y()};
  mat3 = mat * mat2;
  mat3.mostrar_matriz();
    cout << "------------------------------------------------" << endl;
}
