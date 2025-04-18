# Наследяване.

<slidebreak/>

## Същност
- Наследяването е механизъм, който позволява на един клас да придобие свойства и методи на друг клас. Това позволява повторната употреба на вече съществуващи дефиниции. 
- Наследяването е една от основните концепции на ООП. То позволява семантичното създаване на клас-наследник, който разширява родителските характеристики и произлиза смислово от родителя си.
- Има два вида наследяване: единично (singe inheritance, при което един клас наследява само от един родител) и множествено (multiple inheritance, при което един клас наследява от няколко родителя).
- Винаги имаме един основен клас (base class, родителски клас), който се наследява (разширява) от друг клас (derived class, наследник).
- Тук релацацията е от тип `is-a`, т.е. наследникът е от вида на родителя си. Например, ако имаме клас `Person` и клас `Student`, то `Student` е `Person`. Наследяването, за разлика от композицията се случва по време на изпълнение, а не по време на компилация. Тук за разлика от композицията, имаме видимост не само до публичните, но и до защитените членове на родителя.
- Наследяват се всички член-данни и методи на основните класове. Когато създаваме обекти от наследниците, създаваме и обекти от основните класове, които живеят в наследниците (подобно на композицията от гледна точка на памет).

<slidebreak/>

```cpp

class Base
{
public:
    void foo() { std::cout << "Base::foo()" << std::endl; }
};

class Derived : public Base
{
public:
    void bar() { std::cout << "Derived::bar()" << std::endl; }
};

int main()
{
    Derived d;
    d.foo();
    d.bar();
}
```

> [!IMPORTANT]
> Разликата между композиция и наследяване е, че при композиция имаме обект от друг клас в нашия клас, докато при наследяване получаваме член-данните и методите на друг клас като наши. Макар и в паметта нещата да изглеждат подобно, най-съществена е СЕМАНТИЧНАТА разлика.

<slidebreak/>

## Видове наследяване

- При публичното наследяване наследникът придобива public и protected членовете на родителя си по начина, по който са декларирани.
- При protected наследяването наследникът придобива protected и public членовете на родителя си като protected членове.
- При private наследяването наследникът придобива protected и public членовете на родителя си като private членове.

```cpp
class A  {
private:
    int x;
protected:
	int y;
public:
    int z;
};

class B : public A {
    // x is not accessible from B
    // y is protected
    // z is public
};

class C : protected A {
    // x is not accessible from C
    // y is protected
    // z is protected
};

class D : private A { // 'private' is default for classes
    // x is not accessible from D
    // y is private
    // z is private
};
```

<slidebreak/>

## Работа с наследени класове

Може да се използват наследници в контекста на родителския клас, но тогава имаме достъп само до родителските характеристики на наследения обект.

```cpp
class A 
{
public:
	int a;
};

class B : public A 
{
public:
	int b;
};

void f(A& obj) 
{
	obj.a++;
}

int main()
{
	A obj1;
	B obj2;

    A& obj2Proxy = obj2; //OK! (B is an A)
    //B& obj1Proxy = obj1; //Compile error!
	
	f(obj1); //OK! 
	f(obj2); //OK! (B is an A)
}
```

<slidebreak/>

## Голямата четворка в контекста на наследяването
- От конструктора на наследникът се извиква конструктора на родителя.
- Първо се инициализират родителските членове (base class-a), след това наследническите (derived class-a).
- Всеки деструктор освобождава само ресурсите, които са заделени от неговите собствени конструктори (и неговите собствени членове като цяло).
- Първо се извикват деструкторите на наследниците, след това на родителите.
- Деструкторите се извикват по точно обратната последовалетност, в която са извикани конструкторите.
- При копиращия конструктор, винаги извикваме експлицитно копиращия конструктор на родителя.
- При оператор=, винаги извикваме експлицитно оператор= на родителя. Ако не предефинираме оператор=, ще се използва този на компилатора, който ще се погрижи за извикването на оператор= на родителя. Ако предефинираме оператор=, трябва ЗАДЪЛЖИТЕЛНО да се погрижим за извикването на оператор= на родителя.

<slidebreak/>

```cpp
class Base {
private:
	int value;
public:
	Base() : value(0) {
		std::cout << "Base default constructor called\n";
	}

	Base(int x) : value(x) {
		std::cout << "Base (int) constructor called\n";
	}

	~Base() {
		std::cout << "Base destructor called\n";
	}
};

class Derived : public Base {
private:
	int doubledValue;
public:
	Derived() : Base(0), doubledValue(0) {
		std::cout << "Derived default constructor called\n";
	}

	Derived(int x) : Base(x), doubledValue(2*x) {
		std::cout << "Derived (int) constructor called\n";
	}

        
    Derived(const Derived& other) : Base(other) { // (copy constructor of Base class
        copyFrom(other);
    }

    Derived& Derived::operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other); //operator= of Base class
            free();
            copyFrom(other);
        }
        return *this;
    }

	~Derived() {
		std::cout << "Derived destructor called\n";
	}
};
```

<slidebreak/>

## Задачи

1. Да се реализират класове, моделиращи `Student` и `Teacher`, където те се характеризират както следва:
- `Student` - име, фамилия, възраст, факултетен номер.
- `Teacher` - име, фамилия, възраст, учебни дисциплини които води.

2. Да се моделират класове, описващи геометричните обекти Circle, Elipse, Rectange, Triangle, Square, Rombe, Hexagon. Всеки от тях има методи за изчисляване на периметър и лице.