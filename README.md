# CPP_Containers

В рамках данного проекта была реализована собственная библиотека, реализующая основные контейнерные классы языка стандарта С++: list(список), map(словарь), queue(очередь), set(множество), stack(стек) и vector(вектор). Реализация предоставляет весь набор стандартных методов и атрибутов для работы с элементами, проверки заполненности контейнера и итерации. В качестве дополнительных заданий были реализованы еще несколько не так часто используемых, но различающихся деталей реализации контейнерных классов из контейнерной библиотеки C++.

Список реализованных контейнеров: list(список), map(словарь), queue(очередь), set(множество), stack(стек), vector(вектор), array(массив), multiset(мультимножество).

Так же была реализованная дополнительная функция `insert_many`

| Modifiers      | Definition                                      | Containers |
|----------------|-------------------------------------------------| -------------------------------------------|
| `iterator insert_many(const_iterator pos, Args&&... args)`          | Inserts new elements into the container directly before `pos`.  | List, Vector. |
| `void insert_many_back(Args&&... args)`          | Appends new elements to the end of the container.  | List, Vector, Queue. |
| `void insert_many_front(Args&&... args)`          | Appends new elements to the top of the container.  | List, Stack. |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | Inserts new elements into the container.  | Map, Set, Multiset. |

## Руководство по использованию

### Для форматирования кода по гугл стилю и запуска тестов:

```make all```

### Для запуска тестов:

```make test```

### Для запуска тестов и проверки утечек памяти:

```make leaks```

### Для отчистки проекта от всех временных и промежуточных файлов:

```make clean```

### Для создания отчета о покрытии кода:

```make gcov_report```

### Для проверки стиля кода:

```make style```

### Для применения стиля форматирования Google к коду:

```make format```


На диограмме представленна структура проекта 

![s21_containers](img/Diagramme_UML_de_STL.png)

## Adaptor_Container
<details>
  <summary>Список контейнеров</summary>
<br />

### Queue
<details>
  <summary>Общая информация</summary>
<br />

Queue (очередь) - это контейнер с элементами, организованными по принцнипу FIFO (First-In, First-Out). Так же как список, объект контейнерного класса очереди содержит в себе указатели на "хвост" и "голову" очереди, однако удаление производится строго из "головы", а запись, то есть добавление новых элементов, строго в "хвост". Очередь удобно представлять как своего рода трубу, в один конец которой попадают элементы, и убывают с другого конца.

![](img/queue01.png)

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Queue Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Queue Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `queue()`  | default constructor, creates empty queue                                 |
| `queue(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates queue initizialized using std::initializer_list<T>    |
| `queue(const queue &q)`  | copy constructor  |
| `queue(queue &&q)`  | move constructor  |
| `~queue()`  | destructor  |
| `operator=(queue &&q)`      | assignment operator overload for moving object                                |

*Queue Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Queue Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Queue Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts element at the end                       |
| `void pop()`              | removes the first element                        |
| `void swap(queue& other)`             | swaps the contents                               |

</details>

### Stack

<details>
  <summary>Общая ифнормация</summary>
<br />

Stack (стек) - это контейнер с элементами, организованными по принцнипу LIFO (Last-In, First-Out). Объект контейнерного класса стека содержит в себе указатели на "голову" стека, удаление и добавление элементов производится строго из "головы". Стек удобно представлять как стакан или трубу с одним запаянным концом: для того чтобы добраться до элемента, помещенного в контейнер первым, требуется сначала вынуть все элементы, находящиеся сверху.

![](img/stack01.png)

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Stack Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Stack Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `stack()`  | default constructor, creates empty stack                                 |
| `stack(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates stack initizialized using std::initializer_list<T>    |
| `stack(const stack &s)`  | copy constructor  |
| `stack(stack &&s)`  | move constructor  |
| `~stack()`  | destructor  |
| `operator=(stack &&s)`      | assignment operator overload for moving object                                |

*Stack Element access*   

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access   | Definition                                       |
|------------------|--------------------------------------------------|
| `const_reference top()`              | accesses the top element                         |

*Stack Capacity*   

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Stack Modifiers*        

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts element at the top                       |
| `void pop()`              | removes the top element                        |
| `void swap(stack& other)`             | swaps the contents                               |

</details>

</details>

## Additional_Container
<details>
  <summary>Список контейнеров</summary>
<br />

### Array

<details>
  <summary>Общая информация</summary>
<br />

Array (массив) - это последовательный контейнер, инкапсулирующий в себе статический массив. В контейнер array нельзя добавить новый элементы, можно только модифицировать значение заданных изначально. В плане взаимодействия, контейнер array сочетает в себе очевидные свойства статического массива с основным достоинством контейнерных классов - более четкой организацией данных. Например, контейнер Array хранит размер массива и предоставляет итераторы. Так же как и vector, array занимает последовательную часть памяти и может быть передан в функцию как стандартный массив в Си. Вторым шаблонным аргументом класса array является его фактический размер.

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Array Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | `T *` defines the type for iterating through the container                                                 |
| `const_iterator`         | `const T *` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Array Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `array()`  | default constructor, creates empty array                                 |
| `array(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates array initizialized using std::initializer_list<T>    |
| `array(const array &a)`  | copy constructor  |
| `array(array &&a)`  | move constructor  |
| `~array()`  | destructor  |
| `operator=(array &&a)`      | assignment operator overload for moving object                                |

*Array Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos)`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `iterator data()`                   | direct access to the underlying array                                                  |

*Array Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Array Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Array Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void swap(array& other)`                   | swaps the contents                                |
| `void fill(const_reference value);`         | assigns the given value value to all elements in the container. |

</details>

</details>

## Sequence_Container

<details>
  <summary>Список контейнеров</summary>
<br />

### Deque

<details>
  <summary>Общая информация</summary>
<br />

Deque (double-ended queue) - это контейнер из стандартной библиотеки C++, который представляет собой двустороннюю очередь. Он позволяет эффективно добавлять и удалять элементы как с начала, так и с конца. 

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Deque Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Deque Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `deque()`  | default constructor, creates empty deque                                 |
| `deque(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates deque initizialized using std::initializer_list<T>    |
| `deque(const deque &q)`  | copy constructor  |
| `deque(deque &&q)`  | move constructor  |
| `~deque()`  | destructor  |
| `operator=(deque &&q)`      | assignment operator overload for moving object                                |
| `operator=(const deque &q)`      | assignment operator overload for copy object                                |

*Deque Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Deque Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Queue Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push_back(const_reference value)`             | inserts element at the end                       |
| `void pop_back()`              | removes the last element                        |
| `void push_front(const_reference value)`             | inserts an element to the beginning                       |
| `void pop_front()`              | removes the first element                        |
| `void swap(queue& other)`             | swaps the contents                               |

</details>

### List

<details>
  <summary>Общая информация</summary>
<br />

List (список) - это последовательный контейнер, хранящий набор элементов произвольного размера в виде узлов, последовательно связанных указателями. Каждый узел хранит значение, соответствующее элементу списка, и указатель на следующий элемент. Такое устройство контейнера позволяет уйти от жестко фиксированного рамера, как, например, в статическом массиве, и делает более интуитивно понятным процесс добавления нового элемента в контейнер. 

![](img/list_01.png)

![](img/list_02.png)

![](img/list_03.png)

В объекте класса контейнера хранятся указатели на "голову" и "хвост" списка, указывающие на первый и последний элементы списка. Контейнер List предоставляет прямой доступ только к "голове" и "хвосту", но позволяет добавлять и удалять элементы в любой части списка.
</details>

<details>
  <summary>Спецификация</summary>
<br />

*List Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | internal class `ListIterator<T>` defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `ListConstIterator<T>` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*List Functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `list()`  | default constructor, creates empty list                                  |
| `list(size_type n)`  | parameterized constructor, creates the list of size n                                 |
| `list(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates list initizialized using std::initializer_list<T>    |
| `list(const list &l)`  | copy constructor  |
| `list(list &&l)`  | move constructor  |
| `~list()`  | destructor  |
| `operator=(list &&l)`      | assignment operator overload for moving object                                |

*List Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*List Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*List Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*List Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts element into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void push_front(const_reference value)`      | adds an element to the head                      |
| `void pop_front()`   | removes the first element        |
| `void swap(list& other)`                   | swaps the contents                                                                     |
| `void merge(list& other)`                   | merges two sorted lists                                                                      |
| `void splice(const_iterator pos, list& other)`                   | transfers elements from list other starting from pos             |
| `void reverse()`                   | reverses the order of the elements              |
| `void unique()`                   | removes consecutive duplicate elements               |
| `void sort()`                   | sorts the elements                |

</details>

### Vector

<details>
  <summary>Общая информация</summary>
<br />

Vector (вектор) - это последовательный контейнер, инкапсулируюший в себе динамический массив для более интуитивной работы. Данный контейнер не требует ручного контроля памяти, как стандартные динамические массивы, вместо этого он позволяет добавлять через методы `push_back()` и `insert()` произвольное количество элементов, и, в отличие от списка, позволяет обратиться к любому элементу контейнера напрямую, по индексу. Элементы в векторе хранятся последовательно, что позволяет итерировать по вектору не только через предоставляемый итератор, но также и вручную смещая указатель на элемент вектора. Таким образом, указатель на первый элемент вектора может быть передан в качестве аргумента в любую функцию, ожидающую в качестве аргумента обыкновенный массив. Динамическое изменение размера массива происходит не при каждом добавлении или удалении элемента, а только в случае превышения размера заданного буфера. Таким образом, вектор хранит два значения, отвечающих за размер: размер хранимого массива (метод `size()`) и размер буффера (метод `capacity()`). 

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Vector Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | `T *` or internal class `VectorIterator<T>` defines the type for iterating through the container                                                 |
| `const_iterator`         | `const T *` or internal class `VectorConstIterator<T>` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Vector Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `vector()`  | default constructor, creates empty vector                                 |
| `vector(size_type n)`  | parameterized constructor, creates the vector of size n                                 |
| `vector(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates vector initizialized using std::initializer_list<T>    |
| `vector(const vector &v)`  | copy constructor  |
| `vector(vector &&v)`  | move constructor  |
| `~vector()`  | destructor  |
| `operator=(vector &&v)`      | assignment operator overload for moving object                                |

*Vector Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos);`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `T* data()`                   | direct access to the underlying array                                                  |

*Vector Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Vector Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:


| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |
| `void reserve(size_type size)`                | allocate storage of size elements and copies current array elements to a newely allocated array                                     |
| `size_type capacity()`               | returns the number of elements that can be held in currently allocated storage         |
| `void shrink_to_fit()`          | reduces memory usage by freeing unused memory                                          |

*Vector Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts elements into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void swap(vector& other)`                   | swaps the contents                                                                     |

</details>

</details>

## Sorted_Container

<details>
  <summary>Список контейнеров</summary>
<br />

### Associative_Container

<details>
  <summary>Список контейнеров</summary>
<br />

### Map
<details>
  <summary>Общая информация</summary>
<br />

Map (словарь) - это ассоциативный контейнер, содержащий отсортированные по возрастанию ключа пары ключ-значение. То есть каждый элемент ассоциирован с некоторым уникальным ключом, и его положение в словаре определяется его ключом. Словари удобно применять, когда необходимо ассоциировать элементы с некоторым другим значением (не индексом). Например, предприятие осуществляет закупку оборудования, причем каждую позицию приходится закупать неоднократно. В таком случае удобно использовать словарь с парой идентификатор позиции - объем закупки. Здесь идентификатором может выступать не только число, но и строка. Таким образом, поиск в словаре осуществляется не по индексу, как в массиве, а по идентификатору - слову. 

![](img/map_01.png)

Но каким образом словарь позволяет обращаться к парам по ключу и при этом оказывается всегда отсортированным? На самом деле, словарь имеет структуру бинарного дерева поиска (в реализации C++ это дерево - красно-черное), что позволяет сразу добавлять элементы в словарь согласно прямому порядку и находить элементы более эффективно, чем прямой просмотр всех элементов словаря. 

![](img/map_02.png)

Бинарное дерево поиска - это структура состоящая также и узлов, но каждый узел обладает двумя указателями на двух других узлов - "потомков". В этом случае, текущей узел называется "родительским". В общем виде, бинарное дерево поиска гарантирует, что если у текущего узла есть потомки, то левый "потомок" содержит в себе элемент с меньшим значением, а правый - с большим. Таким образом, для поиска в дереве некоторого элемента, достаточно сравнивать специальной функцией компоратором (в случае со словарем, эта функция зависит от типа ключа) искомое значение со значением текущего узла. Если оно оказалось больше - следует переходить к "правому" потомку, меньше - к левому, а если значение оказалось равным, тогда искомый элемент найден.

![](img/map_03.png)

</details>

<details>
  <summary>Спецификация</summary>
  <br />

*Map Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `mapped_type`           | `T` the second template parameter (T)                                                      |
| `value_type`             | `std::pair<const key_type,mapped_type>` Key-value pair                                                      |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `MapIterator<K, T>` or `BinaryTree::iterator` as internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `MapConstIterator<K, T>` or `BinaryTree::const_iterator` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Map Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `map()`  | default constructor, creates empty map                                 |
| `map(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the map initizialized using std::initializer_list<T>    |
| `map(const map &m)`  | copy constructor  |
| `map(map &&m)`  | move constructor  |
| `~map()`  | destructor  |
| `operator=(map &&m)`      | assignment operator overload for moving object                                |

*Map Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `T& at(const Key& key)`                     | access specified element with bounds checking                                          |
| `T& operator[](const Key& key)`             | access or insert specified element                                                     |

*Map Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |

*Map Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`                  | checks whether the container is empty                                                  |
| `size_type size()`                   | returns the number of elements                                                         |
| `size_type max_size()`               | returns the maximum possible number of elements                                        |

*Map Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `std::pair<iterator, bool> insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place                                        |
| `std::pair<iterator, bool> insert(const Key& key, const T& obj)`                 | inserts value by key and returns iterator to where the element is in the container and bool denoting whether the insertion took place    |
| `std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);`       | inserts an element or assigns to the current element if the key already exists         |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(map& other)`                   | swaps the contents                                                                     |
| `void merge(map& other);`                  | splices nodes from another container                                                   |

*Map Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool contains(const Key& key)`                  | checks if there is an element with key equivalent to key in the container                                   |

</details>

</details>

### Set_Container

<details>
  <summary>Список контейнеров</summary>
<br />

### Set

<details>
  <summary>Общая информация</summary>
<br />

Set (множество) - это ассоциативный контейнер уникальных элементов. Это означает, что в множество нельзя добавить один и тот же элемент дважды. Контейнер множество является ассоциативным, так как внутри он также представлен в виде дерева, как и контейнер map (словарь), и, соответственно, также хранит элементы в отсортированном порядке. Разница между словарем и множеством заключается в том, что уникальным в множестве является, не ключ а само значение, ровно как и поиск значения в дереве проверяется не по ключу, а по самому значению. При добавлении уже существующего элемента в множество возникает соответствующее исключение. 

В стандартной реализации, математические операции над множествами (пересечение, объединение, вычитание и т. д.) не реализуются на уровне класса. 

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Set Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `value_type`             | `Key` value type (the value itself is a key)                                                    |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `SetIterator<T>` or `BinaryTree::iterator` as the internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `SetConstIterator<T>` or `BinaryTree::const_iterator` as the internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Set Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `set()`  | default constructor, creates empty set                                 |
| `set(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `set(const set &s)`  | copy constructor  |
| `set(set &&s)`  | move constructor  |
| `~set()`  | destructor  |
| `operator=(set &&s)`      | assignment operator overload for moving object                                |


*Set Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |


*Set Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Set Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `std::pair<iterator, bool> insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place                                        |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(set& other)`                   | swaps the contents                                                                     |
| `void merge(set& other);`                  | splices nodes from another container                                                   |

*Set Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator find(const Key& key)`                   | finds element with specific key                                                        |
| `bool contains(const Key& key)`               | checks if the container contains element with specific key                             |

</details>

### Multiset 

<details>
  <summary>Общая информация</summary>
<br />

Multiset (мультимножество) - это ассоциативный контейнер, повторяющий логику множества, но позволяющий хранить идентичные элементы. Такой контейнер отличается от списка или вектора тем, что элементы при попадании в мультимножество так же, как и в множестве, сортируются на лету. Однако так же, как и множество, мультимножество не позволяет обратиться к элементу по индексу, а требует обращения по значению, которое в мультимножестве может повторяться.

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Multiset Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `key_type`               | `Key` the first template parameter (Key)                                                     |
| `value_type`             | `Key` value type (the value itself is a key)                                                    |
| `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| `iterator`               | internal class `MultisetIterator<T>` or `BinaryTree::iterator` as internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `MultisetConstIterator<T>` or `BinaryTree::const_iterator` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Multiset Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `multiset()`  | default constructor, creates empty set                                 |
| `multiset(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `multiset(const multiset &ms)`  | copy constructor  |
| `multiset(multiset &&ms)`  | move constructor  |
| `~multiset()`  | destructor  |
| `operator=(multiset &&ms)`      | assignment operator overload for moving object                                |

*Multiset Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |


*Multiset Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Multiset Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `void clear()`                  | clears the contents                                                                    |
| `iterator insert(const value_type& value)`                 | inserts node and returns iterator to where the element is in the container                                        |
| `void erase(iterator pos)`                  | erases element at pos                                                                        |
| `void swap(multiset& other)`                   | swaps the contents                                                                     |
| `void merge(multiset& other)`                  | splices nodes from another container                                                   |

*Multiset Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                 | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `size_type count(const Key& key)`                  | returns the number of elements matching specific key                                   |
| `iterator find(const Key& key)`                   | finds element with specific key                                                        |
| `bool contains(const Key& key)`               | checks if the container contains element with specific key                             |
| `std::pair<iterator,iterator> equal_range(const Key& key)`            | returns range of elements matching a specific key                                      |
| `iterator lower_bound(const Key& key)`            | returns an iterator to the first element not less than the given key                   |
| `iterator upper_bound(const Key& key)`            | returns an iterator to the first element greater than the given key                    |

</details>

</details>

### RBtree

<details>
  <summary>Спецификация</summary>
<br />

Красно -черное дерево — это тип самобалансирующегося бинарного дерева поиска. Оно поддерживает почти идеальный баланс, окрашивая каждый узел в красный или черный цвет и применяя набор свойств, которые гарантируют, что самый глубокий путь в дереве не более чем в два раза длиннее самого поверхностного пути.

#### Свойства красно-черных деревьев
- Каждый узел либо красный, либо черный.
- Корневой узел всегда черный.
- Каждый лист (NIL или нулевой узел) черный.
- Если узел красный, то оба его дочерних узла черные.
- Для каждого узла все простые пути от узла до дочерних листьев содержат одинаковое количество черных узлов.

Красно-черное дерево может быть реализовано как расширение двоичного дерева поиска . Каждый узел в дереве будет иметь дополнительный атрибут для хранения своего цвета.

#### Представление красно-черного дерева в C++
```cpp
enum Color { RED, BLACK }; 

template <typename T> 
class RedBlackTree { 
private: 
    struct Node { 
        T data; 
        Color color; 
        Node *left; 
        Node*right; 
        Node*parent;    
    };
```
date: сохраняет значение в узле.
color: перечисление, хранящее цвет узла (КРАСНЫЙ или ЧЕРНЫЙ).
left, right и parent: хранят указатели на левый дочерний, правый дочерний и родительский узлы соответственно.

![s21_containers](img/Red-black-tree.png)

#### Реализация функции вставки

1) Выполните стандартную вставку BST и окрасьте вновь вставленный узел в красный цвет.
2) Если вновь вставленный узел является корнем, окрасьте его в черный цвет и выполните возврат.
3) Пока родительский узел вновь вставленного узла красный, выполните следующие действия:
- Если родитель является левым ребенком бабушки или дедушки:
- - Если правый потомок прародителя красный, перекрасьте его и поднимитесь по дереву.
- - В противном случае выполните повороты и перекрасьте.
- Если родитель является правым ребенком бабушки или дедушки:
- - Если левый потомок прародителя красный, перекрасьте его и поднимитесь по дереву.
- - В противном случае выполните повороты и перекрасьте.
4) Покрасьте корень в черный цвет.

#### Реализация функции удаления узла

1) Выполните стандартное удаление BST.
2) Если удаленный узел был красным, то все готово.
3) Если удаленный узел был черным, нам нужно исправить двойное черное нарушение:
- Если родственный элемент красный, выполните повороты и перекрасьте.
- Если брат или сестра чёрного цвета и оба их потомка чёрные, перекрасьте его и поднимитесь по дереву.
- Если родной элемент черный и имеет хотя бы один красный дочерний элемент, выполните повороты и перекрасьте.

#### Реализация функции поиска

1) Начните с корневого узла.
2) Сравните искомое значение со значением текущего узла.
3) Если значение меньше текущего узла, переходим к левому дочернему узлу.
4) Если значение больше текущего узла, переходим к правому дочернему узлу.
5) Если значение равно текущему узлу, вернуть true.
7) Если достигнут конечный узел и значение не найдено, вернуть false.

#### Реализация функций вращения

1) Левое вращение:
- Сделать правый дочерний узел текущего узла новым корнем поддерева.
- Сделайте старый корень левым дочерним элементом нового корня.
- Обновите родительские указатели соответствующим образом.
2) Правое вращение:
- Сделать левый дочерний узел текущего узла новым корнем поддерева.
- Сделайте старый корень правым дочерним элементом нового корня.
- Обновите родительские указатели соответствующим образом.

</details>

</details>
