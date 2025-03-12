# Разделна компилация. Композиция и агрегация. Голяма четворка.

<slidebreak/>

## Компилация

- Преди процесът по компилация, се извършва препроцесиране на кода, където се изпълняват всички директиви като `#include`, `#define`, `#ifdef`, `#endif` и други. 
- Следващата стъпка е компилацията, където се превръща кода на програмата в машинен код. На тази стъпка се създават обектни файлове (`.o` или `.obj`).
- Накрая се извършва свързване (linking), където се събират всички компилирани файлове в един изпълним файл. Тук, ако липсват имплементации извън обектните файлове (например ползваме `#include <iostream>`), се претърсват стандартните C++ и C библиотеки (libcp.lib и libc.lib), както и всички ръчно специфицирани нестандартни библиотеки.

<slidebreak/>

## Разделна компилация

- Една програма може да се състои от множество файлове с код, които се компилират поотделно и независимо един от друг.
- Препроцесорът, изпълнявайки директивите `#include`, вмъква съдържанието на един файл в друг.
- За да позволим независимото компилиране на кода, разделяйки интерфейсите от имплементацията, тоест класовете от тяхната реализация, функциите от тяхната имплементация, използваме разделна компилация.
- Това става като декларациите на класовете и функциите се пишат в `.h` файлове, а техните имплементации(дефинициите) в `.cpp` файлове.
- По този начин, навсякъде където ползваме дадена функция или клас, вместо да вмъкваме дефиницията, ползваме само декларацията на функцията или класа.
- Така при промяна на имплементацията има нужда да компилираме само съответния `.cpp` файл, а не цялата програма.
- В хедърните файлове не включваме библиотеки, които са необходими за имплементацията, а само такива необходими за декларацията.
- Всеки хедърен файл трябва да започва с директива за еднократно включване на файла(`#pragma once`), която да предотвратява многократното включване на един и същ файл, което би довело до проблеми поради дублиране на имена.

<slidebreak/>

## Композиция
- Композицията е вид асоциация, при която едни обекти са част от други обекти.
- Например, ако имаме клас `Triangle` и клас `Point`, то можем да кажем, че три обекта `Point` са част от един обект `Triangle`.
- Композицията се използва, когато композираните обекти смислово не съществуват без обекта, който ги съдържа, като самостоятелни и значещи обекти, използвани в други глобални контексти. Това обуславя и жизнения цикъл на композираните обекти - той е същият като този на съдържащият обект.
- `A` ***притежава*** `B` (has-a relationship).

```cpp
class A {/*...*/};
class B {
    A a;
};
```

<slidebreak/>

## Агрегация
- Агрегацията е друг аналогичен вид асоциация, при която едни обекти са част от други обекти, но с различен жизнен цикъл от съдържащия обект.
- Например, ако имаме клас `Car` и клас `Person`, то можем да кажем, че един обект `Person` е част от един обект `Car` в контекста на това, че той е шофьорът на колата. Тук обаче `Person` може да съществува и без `Car` и това е задължително дори, понеже един човек не е обвързан само с една кола и една кола не е обръзана с един човек през целия си живот. Това обуславя и жизнения цикъл на агрегираните обекти - той е различен от този на съдържащият обект.
- Агрегацията се използва, когато агрегираните обекти смислово могат да съществуват и бъдат използвани без обекта, който ги съдържа, като самостоятелни и значещи обекти.
- Агрегираните обекти могат да бъдат споделени между различни съдържащи обекти, могат да бъдат създадени и унищожени независимо от съдържащият обект. Тук временно реферираме някаква информация, която ползваме, а не я притежаваме ние, за разликата от композицията.
- `A` ***използва*** `B` (has-a relationship).

```cpp
class A {/*...*/};
class B {
    A& a;
};
class C {
    A* a;
};
```

<slidebreak/>

## Голяма четворка
- Голямата четворка е шаблон за дефиниране на методите на клас, които управляват динамично заделени ресурси.
- Тя се състои от следните четири метода:
    - Конструктор по подразбиране
    - Конструктор за копиране
    - Оператор за присвояване
    - Деструктор

> [!IMPORTANT]
> Ако не създадем кой да е от тези четири метода, компилаторът ще го създаде автоматично. Ако обаче създадем поне един конструктор, независимо какъв - компилаторът няма да създаде конструктор по подразбирате.

<slidebreak/>

## Копиращ конструктор и оператор за присвояване
- Копиращият конструктор се извиква при инициализация на нов обект със стойностите на друг обект от същия клас.
- Операторът за присвояване се извиква при присвояване на стойностите на един обект на друг обект от същия клас.
- Ако не се дефинират, компилаторът автоматично генерира такива методи.
- По подразбиране те правят плитки копия на обектите (shallow copy) - копират стойностите на член данните (буквално заделената памет за обекта). При динамично заделени ресурси това води до проблеми, понеже при копирането се дублират адресите в паметта и така промяна по единия обект ще се отразява и на другия обект.
- За да се избегнат тези проблеми, трябва да се дефинират копиращият конструктор и операторът за присвояване, така че да се извърши дълбоко копиране на динамично заделените ресурси.

```cpp
int x = 5; // Copy constructor
int y = x; // Copy constructor
y = x; // Assignment operator
y = 6; // Assignment operator
```

> [!IMPORTANT]
> Копиращият конструктор създава обекти, а операторът за присвояване присвоява стойности на вече съществуващи обекти.

<slidebreak/>

## Пример за голяма четворка

```cpp
#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Default constructor\n";
    }

    Test(const Test& other) {
        std::cout << "Copy constructor\n";
    }

    Test& operator=(const Test& other) {
        std::cout << "operator=\n";
	    return *this;
    }

    ~Test() {
        std::cout << "Destructor\n";
    }
};

void f(Test object) {
    //do Stuff
}

void g(Test& object) {
    //do Stuff
}

int main() {
    Test t;      // Default constructor

    Test t2(t);  // Copy constructor
    Test t3(t2); // Copy constructor	
    t2 = t3;     // operator=
    t3 = t;      // operator=

    Test newTest = t; // IMPORTANT: Copy constructor 

    f(t);   // Copy constructor	
    g(t);   // nothing -> passing it as a reference, not copying it

    Test* ptr = new Test();  // Default constructor

    delete ptr; // Destructor	

} //Destructor Destructor Destructor Destructor
```

<slidebreak/>

## Нуждата от голяма четворка - shallow copy vs deep copy

```cpp
class Person {
public:

    // NOTE: should be private
    char* name;
    int age;

    Person(const char* name, int age) {
   	    this->name = new char[strlen(name) + 1];
   	    strcpy(this->name, name);
   	    this->age = age;
    }
};

int main() {
    // Person p1; -> Default constructor does not exist
    Person p1("Test", 20);
    Person p2(p1);

    std::cout << p1.name << std::endl;
    std::cout << p2.name << std::endl;

    strcpy(p1.name, "foo");

    std::cout << p1.name << std::endl;
    std::cout << p2.name << std::endl;
}
```

<slidebreak/>

## Стандартна имплементация на голяма четворка

```cpp
class Person
{
	char* name;
	int age;

public:

   // Custom constrctor
	Person(const char* name, int age) : Person() {
		setName(name);
		setAge(age);
	}

#pragma region Big Four
    // Default constructor
    Person() : name(nullptr), age(0) { }

    // Copy constructor
	Person(const Person& other) {
		copyFrom(other);
	}

    // Assignment operator
	Person& operator=(const Person& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

    // Destructor
	~Person() {
		free();
	}
#pragma endregion

    // Setter: name
    void setName(const char* name) {
        if(name == nullptr) {
            return;
        }

        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Setter: age
    void setAge(int age) {
        if(age < 0 || age > 150) {
            return;
        }

        this->age = age;
    }

private:
    // As we are copying from another instance (which shall be valid), we do not actually need the overhead of setters' validation
    void copyFrom(const Person& other) {
        this->age = other.age;

        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    void free() {
        delete[] name;
    }
};
```

> [!IMPORTANT]
> Четирите метода на голямата четворка за всеки клас са еднакви. Различават се имплементациите на методите `copyFrom` и `free`.

<slidebreak/>

> [!IMPORTANT]
> Ако в реализацията на класа нямаме заделяне на динамична памет, която в последствие трябва да се освободи, НЯМА НУЖДА от имплементация на голяма четворка.

> [!NOTE]
> Конструкторът по подразбиране не винаги е необходим - зависи от нашия контекст.

> [!NOTE]
> Ако искаме да забраним на компилатора да генерира някой от четирите метода, можем да го направим като го декларираме като `delete`, например `Person(const Person& other) = delete;`

<slidebreak/>

## Return value optimization (RVO)

- Return Value Optimization (RVO) e оптимизация, която компилаторът може да направи, за да оптимизира използването на временни обекти при връщане на стойности от функции.

```cpp
struct Test {
	Test() {
		std::cout << "Constructor\n";
	}
	
	Test(const Test& other) {
		std::cout << "Copy constructor\n";
	}
	
	Test& operator=(const Test& other) {
		std::cout << "operator=\n";
		return *this;
	}
	
	~Test() {
		std::cout << "Destructor\n";
	}
};

Test create1() {
    Test t = Test();
	return t; 
}

Test create2() {
	return Test();
}

int main() {
    // One constructor only called for each t1 and t2 due to optimizations
    // Copy elision (RVO)
    // No copy constructor + destructor called in the create functions

	Test t1 = create1(); 
	Test t2 = create1(); 
} // destructor is called 2 times
```

<slidebreak/>

## Композиция и агрегация в контекста на голямата четворка

- При композицията използваме копиращи конструктори и оператори за присвояване на композирания клас, като по този начин ние отговаряме за неговия живот, понеже пазим наш обект.
- При агрегацията имаме два случая:
    - Ако използваме референции, то привидно извикване на копиращ конструктор е задължително в member initializer list-a, като това задава стойност на референцията. Тук трябва да се внимава дали в конструктура параметъра е подаден наистина по референция или по копие, което би довело до грешно поведение. Този метод може да се ползва само когато можем да подадем агрегирания обект в конструктора, понеже не може да съществува неинициализирана референция, което означава и че не можем да имаме конструктор по подразбиране.
    - Ако използваме указатели, то може да се задаваме по всяко време стойности, като при указателите имаме неутрална стойност `nullptr`, която служи за разграничаване на неинициализиран агрегиран обект.

> [!IMPORTANT]
> При агрегация винаги предпочитаме указатели пред референции. 

<slidebreak/>

```cpp
class A {/* ... */}
class B {/* ... */}
class C {/* ... */}
class D {/* ... */}

class Test
{
    // composеd
    A a;
    B* b;

    // aggregated
    C& c;
    D* d;

public:
    // Test(A a, B* b, C& c, D* d) : a(a), b(b), c(c), d(d) {} -> wrong assumption


    // Copy constructor for A and B
    // Nothing invoked for C and D
    Test(const A& a, const B& b, const C& c, const D& d) : a(a), b(new B(b)), c(c), d(&d) {}

    // In case of composition invoke copy constructor of composed A
    Test(const Test& other) : a(other.a), b(new B(*other.b)), c(other.c), d(other.d) {}

    Test& operator=(const Test& other) {
        if (this != &other) {
            
            // In case of composition invoke operator= of composed A
            a = other.a;
            
            *b = *other.b; // invoking operator=
            // OR (less preffered):
            // delete b;
            // b = new B(*other.b); // invoking copy contructor

            //c = other.c; -> CANNOT REBOUND REFERECES! THIS WILL INVOKE operator= OF C (and change the originally passed object)
			// => when using references for aggregation should have Test& operator=(const Test& other) = delete;

            d = other.d;
        }

        return *this;
    }

    ~Test() {
        delete b;
    }
};
```

- Когато имаме указател като член-данна имаме два случая, които се обработват по различен начин:
    - Да е указател към динамична памет на композиран обект (или масив) -> трябва ни голяма четворка заради динамичната памет
    - Да е указател към агрегиран обект -> няма нужда от голяма четворка, защото нашият обект не е заделял динамична памет
- Указателите към агрегирани обекти ни позволяват доста повече гъвкавост, поради което и са предпочитаният вариант.

<slidebreak/>

## Задачи

**Задача 1:** Имплементация на низ

**Задача 2:** Имплементация на контейнер (масив)

**Задача 3:** Моделирайте клас UniversityMajor, който съдържа име, направление, университет, факултет и описание на специалност. Моделирайте клас Student, който има име, факултетен номер, специалност и оценки. Нека има възможност за добавяне на оценки, извеждане на оценките и среден успех.
