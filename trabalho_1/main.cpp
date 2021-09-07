#include <iostream>
#include <string>

using namespace std;

// Crop rostos na imagem
//     Aplicar algum filtro
//     Aspect ratio 3:4
// Filter SMOOTH
// Filter DETAIL
// Enhance COLOR
// Enhance CONTRAST

int main(int argc, char *argv[])
{
  string options1 = "Opcoes:\n\t1 - Cortar apenas rostos\n\t2 - Prosseguir sem cortar";
  string uri = "";
  string selections;

  enum optionsMap
  {
    To3x4,
    Smooth,
    Detail,
    Color,
    Contrast
  };

  cout << "Entre com a url da imagem: ";
  cin >> uri;
  cout << endl;

  while (uri != "")
  {
    cout << options1 << endl;
    cout << ">> ";
    cin >> selections;
    uri = "";
  }

  return 0;
}
