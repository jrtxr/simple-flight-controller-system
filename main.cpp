#include <iostream>

using namespace std;

class Voo{
  private:
  unsigned Nvoo;
  string origem;
  string destino;
  int horaPartida;
  int horaChegada;

  public:
  Voo(): Nvoo(0), origem(""),destino(""), horaPartida(0), horaChegada(0) {}
  friend ostream &operator<<(ostream &O, const Voo &v);
  friend istream &operator>>(istream &I, Voo &v);
  unsigned get_voo();
  string get_origem();
  string get_destino();
  int get_partida();
  int get_chegada();

};

istream &operator>>(istream &I, Voo &v) // faltou fazer as verificaçoes
{
  cout << "informe o numero do voo: ";
  I >> v.Nvoo;
  cout << "informe a origem: ";
  I >> v.origem;
  cout << "informe o destino: ";
  I >> v.destino;
  cout << "informe a hora da partida: ";
  I >> v.horaPartida;
    cout << "informe a hora da chegada: ";
  I >> v.horaChegada;
  return I;
}

ostream &operator<<(ostream &O, const Voo &v)
{
  O << "Voo de " << v.origem << " a " << v.destino << ". Hora de chagada: " << v.horaChegada;
  return O;
}

unsigned Voo::get_voo(){
  return Nvoo;
}

string Voo::get_origem(){
  return origem;
}
string Voo::get_destino(){
  return destino;
}

int Voo::get_partida(){
  return horaPartida;
}

int Voo::get_chegada(){
  return horaChegada;
}


class ListadeVoos{
  private:
  Voo *lista;
  int N;

  public:
  ListadeVoos(): N(0) {}
  void inserir(const Voo  &P);
  ~ListadeVoos(void);
  void imprimir();
  void imprimir(string const &x);
};

void ListadeVoos::inserir(const Voo  &P)
{
  Voo *prov = new Voo[N+1];

  for (unsigned i=0; i<N; i++) prov[i]=lista[i];
  prov[N] = P;
  if (N>0) delete[] lista;
  N++;
  lista = prov;
}

ListadeVoos::~ListadeVoos(void)
{
  if (N>0) delete[] lista;
}

void ListadeVoos::imprimir()
{
  for (unsigned i=0; i<N; i++)
    cout << "voo " << i+1 << ": " << lista[i] << endl;
}

void ListadeVoos::imprimir(string const &x){
  for (unsigned i = 0; i < N; i++){
    if (x == lista[i].get_origem()){
      cout << "Voos saindo de "<< x << ": " <<" vou numero: " <<lista[i].get_voo() << " Destino: "<< lista[i].get_destino() << " Saida: "<< lista[i].get_partida()
      << " chegada: "<< lista[i].get_chegada() << endl;
    }
  }
  
}



int main(void)
{
  ListadeVoos LV;
  Voo V;
  string codigo;
  int opcao;
  cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VOOS\n";
  do
  {
  do
    {
      cout << "1 - Inserir um novo voo na lista\n";
      cout << "2 - Imprimir todos os voos da lista\n";
      cout << "3 - Procurar um voo a partir da origem\n";
      cout << "0 - Terminar o programa\n";
      cin >> opcao;
    } while (opcao<0 || opcao>3);
    switch (opcao)
    {
      case 1:
      cout << "Voo a ser inserido:\n";
      cin >> V;
      LV.inserir(V);
      break;
      case 2:
      LV.imprimir();
      break;
      case 3:
      cout << "Aeroporto de origem a pesquisar:\n";
      cin >> codigo;
      LV.imprimir(codigo);
      break;
      default:
      break;
    }
  } while (opcao!=0);
  return 0;
}