# Множествено наследяване

<slidebreak/>

- Множествено наследяване (multiple inheritance) - наследяване от повече от един родителски клас.
- C++ е един от малкото езици, които поддържат множествено наследяване на класове.
- Множественото наследяване започва да създава проблеми, когато наследяваме от два или повече родителски класа, които имат общ родител или пра-родител - т.нар. "diamond problem"
- В такива случаи имаме две копия на базови клас в проблемния наследник. Като още по-сериозен проблем може да идентифицираме факта, че всяко от двете копия на базовия клас може да бъде инициализирано по различен начин, което води до неочаквани резултати. Работата с функции декларирани в съответния наследник на предно ниво, ще достъпва различно копие на член-данните.

<slidebreak/>

```
         Base
         /  \
        /    \
       A      B
        \    /
         \  /
        Derived
```

<slidebreak/>

```cpp
#include <iostream>

class Base {
protected:
    int x;
public:
    static int counter;
    Base() {
        this->x = counter++;
        std::cout << "Base()\n";
    }
};

int Base::counter = 0;

class A : public Base {
public:
    A() {
        std::cout << "A()\n";
    }

    void aTellX() {
        std::cout << "A::x = " << this->x << "\n";
    }
};

class B : public Base {
public:
    B() {
        std::cout << "B()\n";
    }

    void bTellX() {
        std::cout << "B::x = " << this->x << "\n";
    }
};

class Derived : public A, public B {
public:
    Derived() {
        std::cout << "Derived()\n";
    }
};

int main() {
    Derived obj;

    obj.aTellX(); // A::x = 0
    obj.bTellX(); // B::x = 1
}
```

<slidebreak/>

## Виртуално наследяване

- Виртуалното наследяване (virtual inheritance) е механизъм, който позволява да се избегне диамантеният проблем.
- При виртуално наследяване, базовият клас се наследява само веднъж, независимо от йерархията.
- Виртуално наследяваме базовия клас с многото родители, а не наследяваме родителите виртуално.
- В този случай обаче трябва да се внимава, тъй като прародителите се инициализират от наследника, а не от родителите. В този случай наследникът трябва да извика експлицитно кои конструктори от базовия клас да се извикат (независимо в родителите какво е указано), в противен случай се извиква конструктор по подразбиране.

<slidebreak/>

```cpp
#include <iostream>

class Base {
protected:
    int x;
public:
    static int counter;
    Base() {
        this->x = counter++;
        std::cout << "Base()\n";
    }
};

int Base::counter = 0;

class A : public Base {
public:
    A() {
        std::cout << "A()\n";
    }

    void aTellX() {
        std::cout << "A::x = " << this->x << "\n";
    }
};

class B : virtual public Base {
public:
    B() {
        std::cout << "B()\n";
    }

    void bTellX() {
        std::cout << "B::x = " << this->x << "\n";
    }
};

class Derived : public A, public B {
public:
    Derived() {
        std::cout << "Derived()\n";
    }
};

int main() {
    Derived obj;

    obj.aTellX(); // A::x = 0
    obj.bTellX(); // B::x = 0
}
```

- При множественото наследяване трябва всички родителски класове да имат виртуален деструктор, тъй като с обекти от наследения тип можем да работим през кой да е от базовите класове.

<slidebreak/>

## Задача

Да се моделира класова йерархия за различни видове устройства, сред които Phone, FitnessTracker и SmartWatch.