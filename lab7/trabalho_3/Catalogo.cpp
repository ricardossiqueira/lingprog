/*Exercicio Avaliado 3 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: Catalogo.cpp
 *Descricao: Implementacao da classe Catalogo
 */

#include "Catalogo.hpp"

// Constructor
Catalogo::Catalogo(){};

// Friend
ostream &operator<<(ostream &out, const Catalogo &catalogo)
{
  for (auto &filme : catalogo._filmes)
    out << filme;
  return out;
}

// Getters
vector<Filme> &Catalogo::getFilmes() { return _filmes; }

// Operators
void Catalogo::operator+=(const Filme &filme)
{
  for (unsigned i = 0; i < _filmes.size(); i++)
  {
    Filme currFilme = _filmes.at(i);
    if (filme == currFilme)
    {
      cerr << "Erro: Filme '" << filme.getNome() << "' ja existe." << endl;
      return;
    }
    // Prepend
    if (filme < currFilme)
    {
      _filmes.insert(_filmes.begin() + i, filme);
      cout << "Filme '" << filme.getNome() << "' inserido com sucesso." << endl;
      return;
    }
  }
  // Append (default)
  _filmes.push_back(filme);
  cout << "Filme '" << filme.getNome() << "' inserido com sucesso." << endl;
  return;
}

void Catalogo::operator-=(const Filme &filme)
{
  for (unsigned i = 0; i < _filmes.size(); i++)
    if (filme == _filmes.at(i))
    {
      _filmes.erase(_filmes.begin() + i);
      cout << "Filme '" << filme.getNome() << "' deletado com sucesso." << endl;
      return;
    }
  cerr << "Erro: Filme '" << filme.getNome() << "' nao encontrado." << endl;
}

// Sobrecarga de operators
Filme *Catalogo::operator()(const string nome)
{
  for (Filme &filme : _filmes)
    if (filme.getNome() == nome)
      return &filme;
  return nullptr;
}

Filme *Catalogo::operator()(const string nome, const string produtora)
{
  Filme *ptrFilme = (*this)(nome);
  if (ptrFilme != nullptr)
  {
    ptrFilme->setProdutora(produtora);
    return ptrFilme;
  }
  cerr << "Erro: Filme '" << nome << "' nao encontrado" << endl;
  return nullptr;
}

Filme *Catalogo::operator()(const string nome, const double nota)
{
  Filme *ptrFilme = (*this)(nome);
  if (ptrFilme != nullptr)
  {
    ptrFilme->setNota(nota);
    return ptrFilme;
  }
  cerr << "Erro: Filme '" << nome << "' nao encontrado" << endl;
  return nullptr;
}

// Helper functions
void Catalogo::sortedPut(vector<Filme> &filmes)
{
  for (Filme &filme : filmes)
    (*this) += filme;
  filmes.clear();
}

void Catalogo::readFromDB(ifstream &file)
{
  string tmpNome, tmpProdutora, lineNota, labels;
  double tmpNota;

  while (file.good())
  {
    // Labels sao as labels de cada campo ("Nome:", "Produtora:" e "Nota:")
    file >> labels >> tmpNome >> labels >> tmpProdutora >> labels >> lineNota;

    // Se chegou ao fim do arquivo quebra antes de tentar executar a chamada
    // novamente
    if (file.eof())
      break;

    if (lineNota != "" && tmpNome != "" && tmpProdutora != "")
    {
      tmpNota = stod(lineNota);
      Filme tmpFilme(tmpNome, tmpProdutora, tmpNota);
      (*this) += tmpFilme;
    }
  }
}

void Catalogo::printBiggestScore() const
{
  if (_filmes.empty())
  {
    cerr << "Erro: Nenhum filme no catalogo." << endl;
    return;
  }

  const Filme *ptrBiggestScoreFilm = nullptr;
  double biggestScore = 0;
  for (const Filme &filme : _filmes)
    if (filme.getNota() > biggestScore)
    {
      ptrBiggestScoreFilm = &filme;
      biggestScore = filme.getNota();
    }
  cout
      << "Filme com maior nota: "
      << ptrBiggestScoreFilm->getNome()
      << " ["
      << ptrBiggestScoreFilm->getNota()
      << "]."
      << endl;
}
