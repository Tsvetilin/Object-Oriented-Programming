# Предефиниране на елементи. Полиморфизъм.

<slidebreak/>

## Видове свързване

- Статично свързване (compile time / static / early binding) - свързването на методите с техните реализации (тоест изборът на функция, която да се извика) се извършва по време на компилация. 
- Динамично свързване (run time / dynamic / late binding) - свързването на методите с техните реализации (тоест изборът на функция, която да се извика) се извършва по време на изпълнение на програмата.

<slidebreak/>

## Статично свързване

```cpp
#include <iostream>

class Base 
{
public: 
    void f() const  
    {
        std::cout << "Base::f()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void f() const 
    {
        std::cout << "Derived::f()" << std::endl;
    }
};

void func(const Base& obj) 
{
    obj.f();
}

int main()
{
    Derived* der = new Derived();
    Base* base = der;

    //Early binding - Compile time
    func(*base); // Base::f()
    func(*der); // Base::f()
}
```

<slidebreak/>

## Динамично свързване

- За постигане на динамично свързване, трябва да имаме виртуални функции (член-функция в базовия клас, декларирана като виртуална), които да предефинираме в наследника и да работим с указатели или референции към базовия клас.

```cpp
#include <iostream>

class Base 
{
public: 
    virtual void f() const  
    {
        std::cout << "Base::f()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void f() const override 
    {
        std::cout << "Derived::f()" << std::endl;
    }
};

void func(const Base& obj) 
{
    obj.f();
}

int main() {
    Base* ptrs[2];
    ptrs[0] = new Base(); //Base pointer to Base class object
    ptrs[1] = new Derived(); //Base pointer to Derived class object

    //Dynamic/Late Binding - Runtime
    ptrs[0]->f(); // Base::f()
    ptrs[1]->f(); // Derived::f()

    func(*base); // Base::f()
    func(*der);  // Derivative::f()
}
```

<slidebreak/>

## Виртуални функции

- Виртуалните функции се декларират с ключовата дума `virtual` в базовия клас.
- Виртуалните функции могат да бъдат предефинирани в наследниците, като в тях не е задължително да се използва ключовата дума `virtual`, но функциите по подразбиране си остават виртуални. За да забраним наследника да предефинира функцията, можем да я декларираме като `final`.
- Важно е прототипът на функцията в наследника да е същият като този в базовия клас. За да гарантира компилаторът, че функцията, която мислим че предефинираме, наистина е вирутална в базовия клас, можем да използваме ключовата дума `override` в наследника. Тя не е задължителна, но е добра практика да я използваме, за да избегнем грешки.
- Статичките функции не могат да бъдат виртуални.
- Не е задължително в базовия клас да имаме виртуални функции, за да можем да имаме виртуални функции в наследниците.
- Не е задължително наследниците да предефинират виртуалните функции.

```cpp

class Base {
public:
    virtual void func1();
    virtual void func2();
    void func3();
};

class Derived : public Base {
public:
    void func1() override; // OK
    void func2() override final; // OK
    void func3(); // OK
    //void func3() override; // NOT OK -> func3 is not virtual in Base
    virtual void func4(); // OK
};

class Derived2 : public Derived {

public:
    void func1() override; // OK
    //void func2() override; // Compile error! (func2 is final in Derived)
    void func3(); // OK
    // We are not obliged to override func4, but we can
};
```

<slidebreak/>

## Чисто виртуални функции

- Виртуални функции без тяло, които изискват задължителна имплементация в наследника, за да може да се създават обекти от него.
- Ако даден наследник не имплементира чисто виртуална функция, то той също не може да се инстанцира.
- Декларират се с `= 0` в базовия клас.
- По принцип тези функции нямат имплементации, но може да имат и някаква default-на имплементация. 

```cpp
class Base {
public:
    virtual void func1() = 0; // pure virtual function
    virtual void func2() = 0; // pure virtual function
    virtual void func3() = 0; // pure virtual function
};

// Default implementation (optional)
void Base::func1() {
    
}

class Derived : public Base {
public:
    void func1() override {
        // We can make use of the default implementation (not obligatory)
        Base::func1();

        // Custom implementation .... 
    }

    void func2() override {
        // Custom implementation .... 
    }
};

// Here only func3 is pure virtual as we have already supplied implementations for func1 and func2
class Derived2 : public Derived {
    //...
}
```

<slidebreak/>

## Някои правила относно виртуалните елементи

- Не можем да имаме виртуални конструктори. От конструктора можем да извикаме съответните конструктори от родителите.
- Задължително е да имаме виртуален деструктор в базовия клас (дори там да нямаме нужда от деструктор), защото ако не е виртуален, деструкторът на наследника няма да се извика при работа с указател/референция от типа на базовия клас и ще имаме memory leak.
- Ако имаме нужда от предефиниране на оператор= и копиращ конструктор, следваме правилата от наследяването - не забравяме да извикаме родителския оператор= или копиращ конструктор. Те не са виртуални.

```cpp
class Base {
public:
	Base() {
		std::cout << "Base::Base()\n";
	}

	virtual ~Base() {
		std::cout << "Base::~Base()\n";
	}
};

class Derived : public Base {
public:
	Derived() {
		std::cout << "Derived::Derived()\n";
	}

	~Derived() {
		std::cout << "Derived::~Derived()\n";
	}
};

int main() {
	Base* ptr = new Derived();
	delete ptr;
}
```

<slidebreak/>

## Виртуалната таблица (или как работи динамичното свързване)

```cpp
class Base {
public:
	Base() {
		std::cout << "Base::Base()\n";
	}

	virtual ~Base() {
		std::cout << "Base::~Base()\n";
	}
};

int main() {
	std::cout << sizeof(Base);
}
```

- Виртуалната таблица (vtable) е структура, която съдържа указатели към виртуалните функции на класа. Всяка функция стои на точно определен индекс в таблицата и при поява на нова виртуална функция в йерархията, тя се добавя на нов индекс в края.
- Всеки обект от клас с виртуални функции има указател (vptr) към своята виртуална таблица (без да е ясно къде точно се намира той в подредбата на член-данните).
- Когато извикваме виртуална функция, компилаторът проверява vptr на обекта и намира правилната функция в таблицата.
- Работейки с указател от тип базовия клас, при извикване на виртуална функция първо намираме обекта в паметта (1*), после намираме vptr на обекта, после намираме vtable на класа (2*), намираме функцията като знаем индекса ѝ (3*) и накрая извикваме функцията, подавайки съответния аргумент this.

<slidebreak/>

## Полиморфизъм

- **Полиморфизъм** - използване на наследници, без да се интересуваме от техния специфичен контекст
- Едни и същи действия се реализират по различен начин в зависимост от обектите, върху които се прилагат.
- За постигане на полиморфизъм е необходимо да имаме виртуални функции и указатели/референции от базовия клас.
- В контекста на полиморизма, виртуалните функции се наричат **полиморфни функции**.
- Работата с указатели от базовия клас, които сочат към наследници, предполага и задължителното наличие на виртуален деструктор, тъй като обектите ще се унищожават чрез указатели от базовия клас.

```cpp
#include <iostream>

class Animal {
public:
    virtual void sayHello() const {
        std::cout << "Hello, I am a random animal\n";
    }

  virtual ~Animal() = default; //virtual destructor
};

class Dog : public Animal {
public:
    void sayHello() const override {
        std::cout << "Hello, I am a dog!\n";
    }
};

class Cat : public Animal {
public:
    void sayHello() const override {
        std::cout << "Hello, I am a cat!\n";
    }
};

class Mouse : public Animal {};

int main() {
    Animal** animals = new Animal*[3];
    
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Mouse();
    
    animals[0]->sayHello(); // Hello, I am a dog!
    animals[1]->sayHello(); // Hello, I am a cat!
    animals[2]->sayHello(); // Hello, I am a random animal!
    
    for(size_t i = 0; i < 3; ++i) delete animals[i];
    delete[] animals;
}
```

<slidebreak/>

## Интерфейси и абстрактни класове

- Абстрактен клас - клас, който съдържа поне една чисто виртуална функция. Не може да се инстанцира. Такива класове предоставят основна функционалност и служат за базови класове, но конкретни полиморфни функции се реализират в наследниците. Това не пречи в базовия клас да имаме и виртуални функции с default-на имплементация.
- Интерфейс - клас, който съдържа само чисто виртуални функции. Не може да се инстанцира. Служи за шаблон на функционалност, която трябва да бъде реализирана в наследниците.
- Ако имаме клас, който наследява абстрактен клас и не имплементира всички чисто виртуални функции, то той също е абстрактен клас.
- Ако имаме клас, който наследява интерфейс и не имплементира всички чисто виртуални функции, то той става абстрактен клас.
- В другите езици за програмиране обикновено има отделни ключови думи за декларация на абстрактен клас и интерфейс.
- Ако искаме да създадем абстрактен клас, но нямаме функция, която да бъде необходимо дефинирана като чисто виртуална, може да създадем чисто виртуален деструктор (който обикновено е просто виртуален).

<slidebreak/>

## Задачи

1. Да се реализира йерархия от класове, която да поддържа записване на данни в различни среди - стандартен изход, текстови файл, двоичен файл. 

2. Да се моделират класове, описващи геометричните обекти Circle, Elipse, Rectange, Triangle, Square, Rombe, Hexagon. Всеки от тях има методи за изчисляване на периметър и лице.