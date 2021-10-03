/*Exercicio Avaliado 4 - Linguagens de Programacao
 *Aluno: Ricardo Santos Siqueira
 *DRE: 118167558
 *Periodo: 2021.1
 *Arquivo: BinaryTree.hpp
 *Descricao: foo
 */

#if !defined(BINARYTREE_HPP)
#define BINARYTREE_HPP

#include <iostream>
#include <ostream>
#include "Paciente.hpp"

using namespace std;

/*
 *Declaracao
 */

template <class T>
class BinaryTree
{
  // Friends
  template <class O>
  friend ostream &operator<<(ostream &out, const BinaryTree<O> &node);

private:
  T *_ptrSelf;
  BinaryTree *_ptrLeft, *_ptrRight;

public:
  // Constructor
  BinaryTree(
      T *ptrSelf = nullptr,
      BinaryTree *ptrLeft = nullptr,
      BinaryTree *ptrRight = nullptr);

  // Destructor
  ~BinaryTree();

  // Operators
  BinaryTree *operator+=(T *newNode);
  BinaryTree *operator()(const string name);

  // Getters
  T *getSelf();
  BinaryTree *getLeft(), *getRight();
};

/*
 *Implementacao
 */

// Friend
template <class O>
ostream &operator<<(ostream &out, const BinaryTree<O> &node)
{
  if (node._ptrLeft != nullptr)
    out << (*node._ptrLeft);

  // Pacient *ptr = node._ptrSelf;
  out << (*node._ptrSelf);

  if (node._ptrRight != nullptr)
    out << (*node._ptrRight);

  return out;
}

// Constructor
template <class T>
BinaryTree<T>::BinaryTree(
    T *ptrSelf,
    BinaryTree *ptrLeft,
    BinaryTree *ptrRight)
{
  _ptrSelf = ptrSelf;
  _ptrRight = ptrRight;
  _ptrLeft = ptrLeft;
}

// Destructor
template <class T>
BinaryTree<T>::~BinaryTree()
{
  delete _ptrLeft;
  delete _ptrRight;
  delete _ptrSelf;
}

// Operators
template <class T>
BinaryTree<T> *BinaryTree<T>::operator+=(T *newNode)
{
  BinaryTree *ptr = nullptr;
  if (_ptrSelf == nullptr)
  {
    _ptrSelf = newNode;
    ptr = this;
  }
  else // if (_ptrSelf != nullptr)
  {
    if (newNode->getName() == _ptrSelf->getName())
      return nullptr;
    if (newNode->getName() < _ptrSelf->getName())
      if (_ptrRight == nullptr)
      {
        _ptrRight = new BinaryTree<T>(newNode);
        ptr = _ptrRight;
      }
      else // if (_ptrRight != nullptr)
        ptr = (*_ptrRight) += newNode;
    else // if (newNode->getName() > _ptrSelf->getName())
    {
      if (_ptrLeft == nullptr)
      {
        _ptrLeft = new BinaryTree<T>(newNode);
        ptr = _ptrLeft;
      }
      else // if (_ptrLeft != nullptr)
        ptr = (*_ptrLeft) += newNode;
    }
  }
  return ptr;
}

template <class T>
BinaryTree<T> *BinaryTree<T>::operator()(const string name)
{
  if (name < _ptrSelf->getName())
    return _ptrRight == nullptr ? nullptr : (*_ptrRight)(name);
  if (name > _ptrSelf->getName())
    return _ptrLeft == nullptr ? nullptr : (*_ptrLeft)(name);
  return this;
}

// Getters
template <class T>
T *BinaryTree<T>::getSelf() { return _ptrSelf; }
template <class T>
BinaryTree<T> *BinaryTree<T>::getRight() { return _ptrRight; }
template <class T>
BinaryTree<T> *BinaryTree<T>::getLeft() { return _ptrLeft; }

#endif // BINARYTREE_HPP
