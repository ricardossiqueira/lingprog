/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: BinaryTree.hpp
*/

#if !defined(BINARYTREE_HPP)
#define BINARYTREE_HPP

#include <iostream>
#include <ostream>
#include "Paciente.hpp"

using namespace std;

template <class T>
class BinaryTree
{
  // Friends
  template <class O>
  friend ostream &operator<<(ostream &out, const BinaryTree<O> &node);

private:
  T *_ptrSelf = NULL;
  BinaryTree *_ptrLeft = NULL, *_ptrRight = NULL;

public:
  // Constructor
  BinaryTree(
      T *ptrSelf = NULL,
      BinaryTree *ptrLeft = NULL,
      BinaryTree *ptrRight = NULL)
  {
    _ptrSelf = ptrSelf;
    _ptrLeft = ptrLeft;
    _ptrRight = ptrRight;
  };

  // Destructor
  ~BinaryTree()
  {
    delete _ptrLeft;
    delete _ptrRight;
    delete _ptrSelf;
  };

  // Operators
  BinaryTree *operator+=(T *newNode);
  BinaryTree *operator()(const string name);

  // Getters
  T *getSelf() { return _ptrSelf; };
  BinaryTree *getLeft() { return _ptrLeft; };
  BinaryTree *getRight() { return _ptrRight; };
};

// Friend
template <class O>
ostream &operator<<(ostream &out, const BinaryTree<O> &node)
{
  if (node._ptrLeft != NULL)
    out << (*node._ptrLeft);

  // Pacient *ptr = node._ptrSelf;

  if (node._ptrRight != NULL)
    out << (*node._ptrRight);

  out << (*node._ptrSelf);

  return out;
}

// Operators
template <class T>
BinaryTree<T> *BinaryTree<T>::operator+=(T *newNode)
{
  BinaryTree *ptr = NULL;
  if (_ptrSelf == NULL)
  {
    _ptrSelf = newNode;
    ptr = this;
  }
  else // if (_ptrSelf != NULL)
  {
    if (newNode->getName() == _ptrSelf->getName())
      return ptr;
    if (newNode->getName() < _ptrSelf->getName())
      if (_ptrRight == NULL)
      {
        _ptrRight = new BinaryTree<T>(newNode);
        ptr = _ptrRight;
      }
      else // if (_ptrRight != NULL)
        ptr = (*_ptrRight) += newNode;
    else // if (newNode->getName() > _ptrSelf->getName())
    {
      if (_ptrLeft == NULL)
      {
        _ptrLeft = new BinaryTree<T>(newNode);
        ptr = _ptrLeft;
      }
      else // if (_ptrLeft != NULL)
        ptr = (*_ptrLeft) += newNode;
    }
  }
  return ptr;
}

template <class T>
BinaryTree<T> *BinaryTree<T>::operator()(const string name)
{
  if (name < _ptrSelf->getName())
    return _ptrRight == NULL ? NULL : (*_ptrRight)(name);
  if (name > _ptrSelf->getName())
    return _ptrLeft == NULL ? NULL : (*_ptrLeft)(name);
  return this;
}

#endif // BINARYTREE_HPP
