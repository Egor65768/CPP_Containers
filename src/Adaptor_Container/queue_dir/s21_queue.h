#ifndef S21_QUEUE_H
#define S21_QUEUE_H

namespace s21 {
template <class Type, class Container = s21::deque<Type>>
class queue {
 public:
  using value_type = Type;
  using reference = Type &;
  using const_reference = const Type &;
  using size_type = std::size_t;

  /*
  Публичные методы для взаимодействия с классом
  */

  // Конструктор по умолчанию
  queue();

  // Конструктора, который принимает список инициализации и создает объект
  queue(std::initializer_list<value_type> const &items);

  // Конструктор копирования
  queue(const queue &q);

  // Конструктор перемещения
  queue(queue &&q);

  // Деструктор
  ~queue();

  // Оператор перемещающего присваивания
  queue operator=(queue &&q);

  // Оператор копирующего присваивания
  queue &operator=(const queue &other) noexcept;

  /*
  Публичные методы для доступа к элементам класса:
  */

  // Этот метод возвращает ссылку на первый элемент очереди
  const_reference front();

  // Этот метод возвращает ссылку на последний элемент очереди
  const_reference back();

  /*
  Публичные методы для доступа к информации о наполнении контейнера:
  */

  // Проверяет контейнер на пустоту
  bool empty();

  // Возвращает количество элементов в контейнере
  size_type size();

  /*
  Публичные методы для изменения контейнера:
  */

  // Добавляет элемент в конец очереди
  void push(const_reference value);

  // Удаляет элемент из начала очереди
  void pop();

  // Этот метод меняет содержимое текущего объекта с other
  void swap(queue &other);

  // Этот метод добавляет несколько элементов в конец контейнера за один вызов.
  template <class... Args>
  void insert_many_back(Args &&...args);

 private:
  Container realqueue;
};

template <class Type, class Container>
queue<Type, Container>::queue() : realqueue() {}

template <class Type, class Container>
queue<Type, Container>::queue(std::initializer_list<value_type> const &items)
    : queue() {
  for (auto &element : items) {
    push(element);
  }
}

template <class Type, class Container>
queue<Type, Container>::queue(const queue &q) : realqueue(q.realqueue) {}

template <class Type, class Container>
queue<Type, Container>::queue(queue &&q) : realqueue(std::move(q.realqueue)) {}

template <class Type, class Container>
queue<Type, Container>::~queue() {}

template <class Type, class Container>
queue<Type, Container> queue<Type, Container>::operator=(queue &&q) {
  this->realqueue = std::move(q.realqueue);
  return *this;
}

template <class Type, class Container>
queue<Type, Container> &queue<Type, Container>::operator=(
    const queue &other) noexcept {
  this->realqueue = other.realqueue;

  return *this;
}

template <class Type, class Container>
typename queue<Type, Container>::const_reference
queue<Type, Container>::front() {
  return realqueue.front();
}

template <class Type, class Container>
typename queue<Type, Container>::const_reference
queue<Type, Container>::back() {
  return realqueue.back();
}

template <class Type, class Container>
bool queue<Type, Container>::empty() {
  return realqueue.empty();
}

template <class Type, class Container>
typename queue<Type, Container>::size_type queue<Type, Container>::size() {
  return realqueue.size();
}

template <class Type, class Container>
void queue<Type, Container>::push(const_reference value) {
  realqueue.push_back(value);
}

template <class Type, class Container>
void queue<Type, Container>::pop() {
  realqueue.pop_front();
}

template <class Type, class Container>
void queue<Type, Container>::swap(queue &other) {
  std::swap(this->realqueue, other.realqueue);
}

template <class Type, class Container>
template <class... Args>
void queue<Type, Container>::insert_many_back(Args &&...args) {
  (realqueue.push_back(args), ...);
}

}  // namespace s21

#endif