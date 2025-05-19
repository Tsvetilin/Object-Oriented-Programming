# Шаблони.

<slidebreak/>

- Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас
- При дефиниране на шаблонна функция/клас, вместо конкретен тип, се използва параметър от шаблона, обикновено с името T, деклариран като typename или class
- При работа с шаблонна функция/клас, типът се указва в <> след името на функцията/класa
- Може да имаме повече от един типов параметър

<slidebreak/>

## Шаблонни функции

- Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.
- При извикването на функцията може да се укаже типа на параметрите, но не е задължително. Компилаторът сам може да определи типа на параметрите. Когато това не е еднозначно, трябва експлицитно да укажем с какъв тип искаме да работи функцията.

```cpp
#include <iostream>

template <class T>
T sum(const T& a, const T& b) {
    return a + b;
}

template <class T, typename V>
T sum(const T& a, const V& b) {
    return a + b;
}

int main() {
    int a = 4;
    int b = 9;
    std::cout << sum<int>(a, b) << std::endl;

    double c = 3.14;
    double d = 4.5;
    std::cout << sum<double>(c,d) << std::endl;
	
    std::cout << sum(a, c) << std::endl;
    
    return 0;
}
```

<slidebreak/>

## Специализация

- Темплейтна специализация e създаването на различно поведение на темплейтния клас/функция за определени типове

```cpp
#include <iostream>

template<typename T>
void print(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<> // !!!
void print(char* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ---- ";
	}
	std::cout << std::endl;
}

int main() {
	int arr1[] = { 1, 2 };
	print<int>(arr1, 2);
	char arr2[] = { 'a', 'b' };
	print<char>(arr2, 2);
}

// This is not a specialization
// void print(char* arr, size_t size) {
// 	for (size_t i = 0; i < size; i++) {
// 		std::cout << arr[i] << " ---- ";
// 	}
// 	std::cout << std::endl;
// }

```

<slidebreak/>

## Необходима функция

- Ако типът, с който викаме параметризирана функция, не дефинира необходимата функция, компилаторът ще генерира грешка

```cpp
struct Test {
	void func() {}
}

template<typename T>
void f1(Test& t) {
	t.func();
}

template<typename T>
void f2(T& t) {
	t.func1();
}

int main() {
	Test t;
	f1<Test>(t); // ok
	f2<Test>(t); // compile error
}
```

<slidebreak/>

## Шаблонни класове

- Шаблонните класове работят по същия начин, както шаблонните функции
- Шаблонните класове могат да имат шаблонни член-функции и шаблонни член-променливи от типа на шаблона. Може да имат също и други шаблонни член-функции.

```cpp
template <typename T>
class Test {
    T value;

public:
    Test(T val) : value(val) {}

    T getValue() const {
        return value;
    }

    void setValue(T val) {
        value = val;
    }

    template <typename U>
    void printValue(U prefix) const {
        std::cout << prefix << value << std::endl;
    }
}
```

> [!IMPORTANT]
> Когато използваме шаблони не можем да използваме разделна компилация, т.е. не можем да разделим кода на header и cpp файлове. Причината е, че компилаторът не знае какъв тип ще му подадем при извикването на шаблонната функция/клас. Затова е необходимо да имаме целия шаблонен код в един файл, за да може компилаторът да генерира необходимия код.

<slidebreak/>

## Примери за шаблони в stl

Функции
- std::sort
- std::swap

Структури
- std::vector
- std::queue
- std::stack
- std::optional
- std::pair
- std::unique_ptr, std::shared_ptr, std::weak_ptr (aka smart pointers)

<slidebreak/>

## Задачи

Задача 1: Реализирайте динамичен масив

Задача 2: Реализирайте Pair

Задача 3: Реализирайте Optional

Задача 4: Реализирайте Function
