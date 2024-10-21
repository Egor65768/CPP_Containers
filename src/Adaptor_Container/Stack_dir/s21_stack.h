#ifndef S21_STACK_H
#define S21_STACK_H

#include <iostream>

#include "../../Sequence_Container/deque_dir/s21_deque.h"

namespace s21 {
template <class Type, class Container = s21::deque<Type>>
class stack {
 public:
  using value_type = Type;
  using reference = Type &;
  using const_reference = const Type &;
  using size_type = std::size_t;

  /*
  Публичные методы для взаимодействия с классом
  */

  // Конструктор по умолчанию
  stack();

  // Конструктора, который принимает список инициализации и создает объект
  stack(std::initializer_list<value_type> const &items);

  // Конструктор копирования
  stack(const stack &s);

  // Конструктор перемещения
  stack(stack &&s);

  // Оператор перемещающего присваивания
  stack operator=(stack &&s);

  // Оператор копирующего присваивания
  stack &operator=(const stack &other);

  // Деструктор
  ~stack();

  /*
  Публичные методы для доступа к информации о наполнении контейнера:
  */

  // Проверяет контейнер на пустоту
  bool empty();

  // Возвращает количество элементов в контейнере
  size_type size();

  /*
  Публичные методы для доступа к элементам класса:
  */

  // Этот метод возвращает ссылку на последний элемент
  const_reference top() const;

  /*
  Публичные методы для изменения контейнера:
  */

  // Добавляет элемент в конец
  void push(const_reference value);

  // Удаляет последний элемент из очереди
  void pop();

  // Этот метод меняет содержимое текущего объекта с other
  void swap(stack &other);

  // Этот метод добавляет несколько элементов в начало контейнера за один вызов
  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  Container realstack;
};

template <class Type, class Container>
stack<Type, Container>::stack() : realstack() {}

template <class Type, class Container>
stack<Type, Container>::stack(std::initializer_list<value_type> const &items)
    : stack() {
  for (auto &element : items) {
    push(element);
  }
}

template <class Type, class Container>
stack<Type, Container>::stack(const stack &s) : realstack(s.realstack) {}

template <class Type, class Container>
stack<Type, Container>::stack(stack &&s) : realstack(std::move(s.realstack)) {}

template <class Type, class Container>
stack<Type, Container> &stack<Type, Container>::operator=(const stack &other) {
  if (&other != this) {
    realstack = other.realstack;
  }
  return *this;
}

template <class Type, class Container>
stack<Type, Container> stack<Type, Container>::operator=(stack &&s) {
  if (&s != this) {
    this->swap(s);
  }
  return *this;
}

template <class Type, class Container>
stack<Type, Container>::~stack() {}

template <class Type, class Container>
bool stack<Type, Container>::empty() {
  return realstack.empty();
}

template <class Type, class Container>
typename stack<Type, Container>::size_type stack<Type, Container>::size() {
  return realstack.size();
}

template <class Type, class Container>
typename stack<Type, Container>::const_reference stack<Type, Container>::top()
    const {
  return realstack.back();
}

template <class Type, class Container>
void stack<Type, Container>::push(const_reference value) {
  realstack.push_back(value);
}

template <class Type, class Container>
void stack<Type, Container>::pop() {
  realstack.pop_back();
}

template <class Type, class Container>
void stack<Type, Container>::swap(stack &other) {
  std::swap(this->realstack, other.realstack);
}

template <class T, class Container>
template <class... Args>
void stack<T, Container>::insert_many_front(Args &&...args) {
  (realstack.push_back(args), ...);
}

}  // namespace s21

#endif