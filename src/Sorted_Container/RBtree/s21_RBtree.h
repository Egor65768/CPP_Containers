#ifndef S21_READ_BLACK_TREE_H
#define S21_READ_BLACK_TREE_H

#include <iostream>
#include <stdexcept>

enum RBTColor { Black, Red };

template <typename Key, typename Value>
struct Node {
  Key key;
  Value value;
  Node<Key, Value>* parent;
  Node<Key, Value>* left;
  Node<Key, Value>* right;
  RBTColor color;
};

template <typename Key, typename Value>
class RBtree {
 public:
  class Iterator;
  using size_type = size_t;

  /*
  КОНСТРУКТОРЫ
  */

  // Конструктор по умолчанию
  RBtree();

  // Конструктор для создания дерева из существующего узла
  RBtree(Node<Key, Value>* root);

  // Конструктор копирования
  RBtree(const RBtree& other);

  // Конструктор перемещения
  RBtree(RBtree&& other);

  // Деструктор
  ~RBtree();

  /*
  МЕТОДЫ ОТЧИСТКИ И УДАЛЕНИЯ
  */

  // Этот метод рекурсивно освобождает память, занятую узлами дерева
  void FreeNode(Node<Key, Value>* node);

  // Этот метод очищает все узлы в дереве
  void clear();

  // Удаляет узел из дерева
  void erase(Iterator pos);

  /*
  МЕТОДЫ ПОИСКА МИНИМАЛЬНОГО/МАКСИМАЛЬНОГО ЭЛЕМЕНТА
  */

  // Этот метод ищет минимальный узел в текущем дереве, начиная с корня.
  Node<Key, Value>* MinNode();

  // Этот метод ищет максимальный узел в текущем дереве, начиная с корня.
  Node<Key, Value>* MaxNode();

  // Этот метод ищет минимальный узел, начиная с переданного узла
  static Node<Key, Value>* MinNode(Node<Key, Value>* nodeptr);

  // Этот метод ищет максимальный узел, начиная с переданного узла
  static Node<Key, Value>* MaxNode(Node<Key, Value>* nodeptr);

  /*
  ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
  */

  // Этот метод отвечает за вставку нового узла в дерево
  void insertTree(const Key& key, const Value& value);

  // Этот метод обменивает содержимое текущего дерева с другим деревом
  void swap(RBtree& other);

  // Этот метод создает глубокую копию поддерева, начиная с указанного узла
  Node<Key, Value>* Copytree(Node<Key, Value>* ptr,
                             Node<Key, Value>* parent_ptr);

  // Этот метод возвращает указатель на первый узел по ключу
  Node<Key, Value>* findNodeByKey(const Key key);

  // Этот метод возвращает указатель на последний узел по ключу
  Node<Key, Value>* findLastMatch(const Key key);

  // Оператор [] для доступа к значению
  Value operator[](const Key key);

  /*
  БАЛАНСИРОВКА ДЕРЕВА
  */

  // Этот метод занимается балансировкой дерева
  void rebalanceRBtree(Node<Key, Value>* nodeptr);

  // Этот метод выполняет правый поворот вокруг узла x в дереве
  void right_rotate(Node<Key, Value>* x);

  // Этот метод выполняет левый поворот вокруг узла x в дереве
  void left_rotate(Node<Key, Value>* x);

  /*
  ИТЕРАТОР
  */

  class Iterator {
   protected:
    Node<Key, Value>* iter_ptr;
    Node<Key, Value>* Max_Node_it;
    Node<Key, Value>* Min_Node_it;

   public:
    // Конструктор по умолчанию
    Iterator();

    // Конструктор с указателем на узел
    Iterator(Node<Key, Value>* iter_ptr);

    // Оператор префиксного инкремента
    Iterator& operator++();

    // Оператор префиксного декремента
    Iterator& operator--();

    // Оператор постфиксного инкремента
    Iterator operator++(int);

    // Оператор постфиксного декремента
    Iterator operator--(int);

    // Оператор неравенства
    bool operator!=(Iterator other) const;

    // Оператор равенства
    bool operator==(Iterator other) const;

    // Оператор вызова для итератора
    Iterator& operator()(Node<Key, Value>* ptr);

    // Этот метод возвращает следующий элемент в дереве
    Node<Key, Value>* getNextNode(Node<Key, Value>* ptr);

    // Этот метод возвращает предыдущий элемент в дереве
    Node<Key, Value>* getPreviousNode(Node<Key, Value>* ptr);

    // Этот метод проверяет равняется ли текущий элемент null
    bool iter_is_nullptr();

    // Этот метод возвращает ключ обьекта
    Key getKey();

    // Этот метод возвращает значение обьекта
    Value& getValue();

    friend class RBtree<Key, Value>;
    Value& operator*() { return getValue(); }
  };

  // Этот метод возвращает итератор на первый элемент
  Iterator begin();

  // Этот метод возвращает итератор на последний элемент
  Iterator end();

  // Этот метод возвращает итератор на первый элемент, который не меньше ключа
  Iterator lower_bound(const Key& key) noexcept;

  // Этот метод возвращает итератор на первый элемент, который строго больше
  // ключа
  Iterator upper_bound(const Key& key) noexcept;

  // Этот метод возвращает общее количество узлов в дереве
  size_type size();

  // Этот метод возвращает общее количество узлов в поддереве
  size_t RecursiveSize(Node<Key, Value>* node);

  // Этот метод проверяет, является ли дерево пустым.
  bool empty();

 protected:
  Node<Key, Value>* root;
};

/*
  КОНСТРУКТОРЫ
*/

template <typename Key, typename Value>
RBtree<Key, Value>::RBtree() : root(nullptr) {}

template <typename Key, typename Value>
RBtree<Key, Value>::RBtree(Node<Key, Value>* root) : root(root) {}

template <typename Key, typename Value>
RBtree<Key, Value>::RBtree(const RBtree& other) {
  this->root = Copytree(other.root, nullptr);
}

template <typename Key, typename Value>
RBtree<Key, Value>::RBtree(RBtree&& other) : root(other.root) {
  other.root = nullptr;
}

template <typename Key, typename Value>
RBtree<Key, Value>::~RBtree() {
  clear();
}

/*
  ФУНКЦИИ ОТЧИСТКИ И УДАЛЕНИЯ
*/

template <typename Key, typename Value>
void RBtree<Key, Value>::FreeNode(Node<Key, Value>* node) {
  if (node != nullptr) {
    FreeNode(node->left);
    FreeNode(node->right);
    delete node;
  }
}

template <typename Key, typename Value>
void RBtree<Key, Value>::clear() {
  if (this->root != nullptr) {
    FreeNode(root);
    this->root = nullptr;
  }
}

template <typename Key, typename Value>
void RBtree<Key, Value>::erase(RBtree<Key, Value>::Iterator pos) {
  Node<Key, Value>* son;
  // Случай если нет предков
  if (pos.iter_ptr->right == nullptr && pos.iter_ptr->left == nullptr) {
    if (root != pos.iter_ptr) {
      if (pos.iter_ptr->parent->left == pos.iter_ptr) {
        pos.iter_ptr->parent->left = nullptr;
      } else {
        pos.iter_ptr->parent->right = nullptr;
      }
    } else {
      root = nullptr;
    }
  }  // Случай если только один предок
  else if (pos.iter_ptr->right == nullptr || pos.iter_ptr->left == nullptr) {
    if (pos.iter_ptr->right != nullptr) {
      son = pos.iter_ptr->right;
    } else {
      son = pos.iter_ptr->left;
    }
    if (pos.iter_ptr->parent != nullptr) {
      if (pos.iter_ptr->parent->right == pos.iter_ptr) {
        pos.iter_ptr->parent->right = son;
      } else {
        pos.iter_ptr->parent->left = son;
      }
      son->parent = pos.iter_ptr->parent;
    } else {
      root = son;
    }
  }  // Случай если два предка
  else {
    son = pos.iter_ptr->left;
    if (pos.iter_ptr->parent != nullptr) {
      if (pos.iter_ptr->parent->right == pos.iter_ptr) {
        pos.iter_ptr->parent->right = son;
      } else {
        pos.iter_ptr->parent->left = son;
      }
      son->parent = pos.iter_ptr->parent;
    } else {
      root = son;
      son->parent = nullptr;
    }
    if (son->right != nullptr) {
      Node<Key, Value>* buf = MinNode(pos.iter_ptr->right);
      buf->left = son->right;
      son->right = pos.iter_ptr->right;
      son->right->parent = son;
      buf->left->parent = buf;
    } else {
      son->right = pos.iter_ptr->right;
    }
  }
  delete pos.iter_ptr;
}

/*
ФУНКЦИИ ПОИСКА МИНИМАЛЬНОГО/МАКСИМАЛЬНОГО ЭЛЕМЕНТА
*/

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::MinNode(Node<Key, Value>* nodeptr) {
  Node<Key, Value>* buf = nodeptr;
  while (nodeptr != nullptr) {
    buf = nodeptr;
    nodeptr = buf->left;
  }
  return buf;
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::MaxNode(Node<Key, Value>* nodeptr) {
  Node<Key, Value>* buf = nodeptr;
  while (nodeptr != nullptr) {
    buf = nodeptr;
    nodeptr = buf->right;
  }
  return buf;
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::MinNode() {
  return MinNode(this->root);
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::MaxNode() {
  return MaxNode(this->root);
}

/*
  ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
*/

template <typename Key, typename Value>
void RBtree<Key, Value>::insertTree(const Key& key, const Value& value) {
  Node<Key, Value>* new_elem = new Node<Key, Value>;
  new_elem->key = key;
  new_elem->value = value;
  new_elem->left = nullptr;
  new_elem->right = nullptr;
  new_elem->parent = nullptr;
  new_elem->color = Red;
  Node<Key, Value>* buf_node = this->root;
  Node<Key, Value>* buf_parent = NULL;
  if (buf_node == nullptr) {
    this->root = new_elem;
  } else {
    while (buf_node != nullptr) {
      buf_parent = buf_node;
      if (buf_node->key > new_elem->key) {
        buf_node = buf_node->left;
      } else {
        buf_node = buf_node->right;
      }
    }
    new_elem->parent = buf_parent;
    if (buf_parent->key > new_elem->key) {
      buf_parent->left = new_elem;
    } else {
      buf_parent->right = new_elem;
    }
  }
  if (new_elem != root) {
    rebalanceRBtree(new_elem);
  }
}

template <typename Key, typename Value>
void RBtree<Key, Value>::swap(RBtree<Key, Value>& other) {
  std::swap(other.root, this->root);
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::Copytree(Node<Key, Value>* ptr,
                                               Node<Key, Value>* parent_ptr) {
  Node<Key, Value>* new_node = nullptr;
  if (ptr != nullptr) {
    new_node = new Node<Key, Value>;
    new_node->color = ptr->color;
    new_node->key = ptr->key;
    new_node->value = ptr->value;
    new_node->parent = parent_ptr;
    new_node->left = Copytree(ptr->left, new_node);
    new_node->right = Copytree(ptr->right, new_node);
  }
  return new_node;
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::findNodeByKey(const Key key) {
  Node<Key, Value>* buf_Node = this->root;
  while (buf_Node != nullptr && buf_Node->key != key) {
    if (buf_Node->key > key) {
      buf_Node = buf_Node->left;
    } else {
      buf_Node = buf_Node->right;
    }
  }
  if (buf_Node != nullptr && key != buf_Node->key) {
    buf_Node = nullptr;
  }
  return buf_Node;
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::findLastMatch(const Key key) {
  Node<Key, Value>* buf = this->root;
  Node<Key, Value>* res = buf;
  while (buf != nullptr) {
    if (buf->key == key) {
      res = buf;
    }
    if (buf->key > key) {
      buf = buf->left;
    } else {
      buf = buf->right;
    }
  }
  if (res != nullptr && key != res->key) {
    res = nullptr;
  }
  return res;
}

template <typename Key, typename Value>
Value RBtree<Key, Value>::operator[](const Key key) {
  return findNodeByKey(key)->value;
}

template <typename Key, typename Value>
void RBtree<Key, Value>::rebalanceRBtree(Node<Key, Value>* nodeptr) {
  Node<Key, Value>* father = nodeptr->parent;
  if (father == nullptr) {
    return;
  }
  if (father->parent != nullptr) {
    Node<Key, Value>* uncle = (father->parent->right != father)
                                  ? father->parent->right
                                  : father->parent->left;
    if (uncle != nullptr && father->parent != this->root &&
        father->color == Red && uncle->color == Red) {
      father->parent->color = Red;
      father->color = Black;
      uncle->color = Black;
      rebalanceRBtree(father->parent);
    } else if (uncle != nullptr && father->color == Red &&
               uncle->color == Black && father->parent->left->left == nodeptr) {
      father->parent->color = Red;
      father->color = Black;
      right_rotate(father->parent);
      rebalanceRBtree(father->right->right);
    } else if (uncle != nullptr && father->color == Red &&
               uncle->color == Black &&
               father->parent->left->right == nodeptr) {
      nodeptr->color = Black;
      father->parent->color = Red;
      left_rotate(father);
      right_rotate(nodeptr->parent);
      rebalanceRBtree(nodeptr->right->right);
    } else if (uncle != nullptr && father->color == Red &&
               uncle->color == Black &&
               father->parent->right->right == nodeptr) {
      father->parent->color = Red;
      father->color = Black;
      left_rotate(father->parent);
      rebalanceRBtree(father->left);
    } else if (uncle != nullptr && father->color == Red &&
               uncle->color == Black &&
               father->parent->right->left == nodeptr) {
      father->parent->color = Red;
      nodeptr->color = Black;
      right_rotate(father);
      left_rotate(nodeptr->parent);
      rebalanceRBtree(nodeptr->left->left);
    }
  }
}

template <typename Key, typename Value>
void RBtree<Key, Value>::right_rotate(Node<Key, Value>* x) {
  Node<Key, Value>* left_child = x->left;
  x->left = left_child->right;
  if (left_child->right != nullptr) {
    left_child->right->parent = x;
  }
  left_child->parent = x->parent;
  if (x->parent == nullptr) {
    this->root = left_child;
  } else if (x == x->parent->right) {
    x->parent->right = left_child;
  } else {
    x->parent->left = left_child;
  }
  left_child->right = x;
  x->parent = left_child;
}

template <typename Key, typename Value>
void RBtree<Key, Value>::left_rotate(Node<Key, Value>* x) {
  Node<Key, Value>* right_child = x->right;
  x->right = right_child->left;
  if (right_child->left != nullptr) {
    right_child->left->parent = x;
  }
  right_child->parent = x->parent;
  if (x->parent == nullptr) {
    this->root = right_child;
  } else if (x->parent->right == x) {
    x->parent->right = right_child;
  } else {
    x->parent->left = right_child;
  }
  right_child->left = x;
  x->parent = right_child;
}

/*
  ИТЕРАТОР
*/

template <typename Key, typename Value>
RBtree<Key, Value>::Iterator::Iterator()
    : iter_ptr(nullptr), Max_Node_it(nullptr), Min_Node_it(nullptr) {}

template <typename Key, typename Value>
RBtree<Key, Value>::Iterator::Iterator(Node<Key, Value>* iter_ptr)
    : iter_ptr(iter_ptr), Max_Node_it(nullptr), Min_Node_it(nullptr) {
  Node<Key, Value>* buf = iter_ptr;
  if (buf != nullptr) {
    while (buf->parent != nullptr) {
      buf = buf->parent;
    }
    Max_Node_it = MaxNode(buf);
    Min_Node_it = MinNode(buf);
  }
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator&
RBtree<Key, Value>::Iterator::operator++() {
  this->iter_ptr = this->getNextNode(iter_ptr);
  return *this;
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator&
RBtree<Key, Value>::Iterator::operator--() {
  this->iter_ptr = this->getPreviousNode(iter_ptr);
  return *this;
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator RBtree<Key, Value>::Iterator::operator++(
    int) {
  Iterator buf(this->iter_ptr);
  this->iter_ptr = this->getNextNode(iter_ptr);
  return buf;
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator RBtree<Key, Value>::Iterator::operator--(
    int) {
  Iterator buf(this->iter_ptr);
  this->iter_ptr = this->getPreviousNode(iter_ptr);
  return buf;
}

template <typename Key, typename Value>
bool RBtree<Key, Value>::Iterator::operator!=(Iterator other) const {
  return other.iter_ptr != this->iter_ptr;
}

template <typename Key, typename Value>
bool RBtree<Key, Value>::Iterator::operator==(Iterator other) const {
  return other.iter_ptr == this->iter_ptr;
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator& RBtree<Key, Value>::Iterator::operator()(
    Node<Key, Value>* ptr) {
  this->iter_ptr = ptr;
  return *this;
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::Iterator::getNextNode(
    Node<Key, Value>* ptr) {
  Node<Key, Value>* res = nullptr;
  if (ptr == Max_Node_it) {
    res = Min_Node_it;
  } else if (ptr->right != nullptr) {
    res = RBtree<Key, Value>::MinNode(ptr->right);
  } else {
    Node<Key, Value>* buf_parent = ptr->parent;
    while (buf_parent != nullptr && buf_parent->right == ptr) {
      ptr = buf_parent;
      buf_parent = ptr->parent;
    }
    res = (buf_parent != nullptr) ? buf_parent : ptr;
  }
  return res;
}

template <typename Key, typename Value>
Node<Key, Value>* RBtree<Key, Value>::Iterator::getPreviousNode(
    Node<Key, Value>* ptr) {
  Node<Key, Value>* res = nullptr;
  if (ptr == Min_Node_it) {
    res = Max_Node_it;
  } else if (ptr->left != nullptr) {
    res = RBtree<Key, Value>::MaxNode(ptr->left);
  } else {
    Node<Key, Value>* buf_parent = ptr->parent;
    while (buf_parent != nullptr && buf_parent->left == ptr) {
      ptr = buf_parent;
      buf_parent = ptr->parent;
    }
    res = (buf_parent != nullptr) ? buf_parent : ptr;
  }
  return res;
}

template <typename Key, typename Value>
bool RBtree<Key, Value>::Iterator::iter_is_nullptr() {
  bool res = false;
  if (this->iter_ptr == nullptr) {
    res = true;
  }
  return res;
}

template <typename Key, typename Value>
Key RBtree<Key, Value>::Iterator::getKey() {
  return this->iter_ptr->key;
}

template <typename Key, typename Value>
Value& RBtree<Key, Value>::Iterator::getValue() {
  return this->iter_ptr->value;
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator RBtree<Key, Value>::begin() {
  return RBtree<Key, Value>::Iterator(MinNode());
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator RBtree<Key, Value>::end() {
  return RBtree<Key, Value>::Iterator(MaxNode());
}

template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator RBtree<Key, Value>::lower_bound(
    const Key& key) noexcept {
  Node<Key, Value>* search = root;
  Node<Key, Value>* result = nullptr;

  while (search != nullptr) {
    if (search->value >= key) {
      result = search;
      search = search->left;
    } else {
      search = search->right;
    }
  }
  return (result == nullptr ? end() : Iterator(result));
}
template <typename Key, typename Value>
typename RBtree<Key, Value>::Iterator RBtree<Key, Value>::upper_bound(
    const Key& key) noexcept {
  Node<Key, Value>* search = root;
  Node<Key, Value>* result = nullptr;

  while (search != nullptr) {
    if (search->value > key) {
      result = search;
      search = search->left;
    } else {
      search = search->right;
    }
  }
  return (result == nullptr ? end() : Iterator(result));
}

template <typename Key, typename Value>
size_t RBtree<Key, Value>::size() {
  return RecursiveSize(root);
}

template <typename Key, typename Value>
size_t RBtree<Key, Value>::RecursiveSize(Node<Key, Value>* node) {
  if (node == nullptr) return 0;
  size_t left_size = RecursiveSize(node->left);
  size_t right_size = RecursiveSize(node->right);
  return 1 + left_size + right_size;
}

template <typename Key, typename Value>
bool RBtree<Key, Value>::empty() {
  return root == nullptr;
}

#endif