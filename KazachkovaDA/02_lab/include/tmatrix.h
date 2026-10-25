// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <cassert>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
      throw out_of_range("Vector size is too great");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v): sz(v.sz)
  {
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept: sz(v.sz)
  {
      pMem = v.pMem;
      v.pMem = nullptr;
      v.sz = 0;
  }
  ~TDynamicVector()
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz) 
      {
          sz = v.sz;
          T* newpMem = new T[sz];
          delete[] pMem;
          pMem = newpMem;
      }
      for (int i = 0; i < sz; i++)
          pMem[i] = v.pMem[i];
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  { 
      if (this == &v)
          return *this;
      delete[] pMem;
      pMem = v.pMem;
      sz = v.sz;
      v.pMem = nullptr;
      v.sz = 0;

      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return at(ind);
  }
  const T& operator[](size_t ind) const
  {
      return at(ind);
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= sz)
          throw out_of_range("Invalid index");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind >= sz)
          throw out_of_range("Invalid index");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return false;
      for (int i = 0; i < sz; i++)
      {
          if (pMem[i] != v.pMem[i])
              return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return (!(*this == v));
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + val;
      return res;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - val;
      return res;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] * val;
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw out_of_range("Invalid arguments");
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + v.pMem[i];
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw out_of_range("Invalid arguments");
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - v.pMem[i];
      return res;
  }
  T operator*(const TDynamicVector& v) //noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw out_of_range("Invalid arguments");
      T res{};
      for (int i = 0; i < sz; i++)
          res += pMem[i] * v.pMem[i];
      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if (sz == 0)
            throw exception("Can't create a zero sized matrix");
        if (sz > MAX_MATRIX_SIZE)
            throw exception("Can't create a matrix this great");
        for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
    }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  //размер
  size_t size()
  {
      return sz;
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz)
          return false;
      for (int i = 0; i < sz; i++)
      {
          if (pMem[i] != m.pMem[i])
              return false;
      }
      return true;

  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicVector<int>res(sz);
      if (sz != v.size())
          throw invalid_argument("Invalid argument");
      for (int i = 0; i < sz; i++)
      {
          for (int j = 0; j < sz; j++)
              res[i] += pMem[i][j] * v[j];
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("Sizes don't match");
      TDynamicMatrix<int> res(sz);
      for (int i = 0; i < sz; i++)
          for (int j = 0; j < sz; j++)
              res.pMem[i][j] = pMem[i][j] + m.pMem[i][j];
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("Sizes don't match");
      TDynamicMatrix<int> res(sz);
      for (int i = 0; i < sz; i++)
          for (int j = 0; j < sz; j++)
              res.pMem[i][j] = pMem[i][j] - m.pMem[i][j];
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("Sizes don't match");
      TDynamicMatrix<int> res(sz);
      for (int i = 0; i < sz; i++)
      {
          for (int j = 0; j < sz; j++)
          {
              T sum = T{};
              for (int k = 0; k < sz; k++)
              {
                  sum += pMem[i][k] * m.pMem[k][j];
              }
              res.pMem[i][j] = sum;
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      throw "Method is not implemented";
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      throw "Method is not implemented";
  }
};

#endif
