# Колекции от обекти в полиморфна йерархия

<slidebreak/>

## Масив от указатели към обекти. Копиране и триене.
- Когато имаме полиморфна йерархия от класове, обикновено искаме да съхраняваме на единно място обектите от различните класове.
- За тази цел можем да използваме колекции от обекти в йерархията, реализирайки я чрез масив от указатели от базовия клас.
- Важно в случая е реализацията на голямата четворка - тоест освобождаването и копирането.
- За осовобождаването на паметта е важно да се извика деструктора на всеки от обектите в масива. Когато базовия клас има виртуален деструктор, то при освобождаването на паметта чрез указател на базовия клас, автоматично ще се извикат и деструкторите на производните класове. 
- За копирането е необходимо да заделяме памет за нови обекти, а не да копираме указателите. Удобно е да се реализира виртуален метод clone, който да прави копие на обекта и да връща указател от базовия клас.

<slidebreak/>

```cpp
class Base {
public:
    virtual void print() const = 0;
    virtual Base* clone() const = 0;
    virtual ~Base() {}
}

class Derived1 : public Base {
public:
    void print() const override {
        std::cout << "Derived 1" << std::endl;
    }
    
    Base* clone() const override {
        return new Derived1(*this);
    }
};

class Derived2 : public Base {
public:
    void print() const override {
        std::cout << "Derived 2" << std::endl;
    }
    
    Base* clone() const override {
        return new Derived2(*this);
    }
};

class Collection {
private:
    Base** objects;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        Base** newObjects = new Base*[capacity];
        for (int i = 0; i < size; ++i) {
            newObjects[i] = objects[i];
        }
        delete[] objects;
        objects = newObjects;
    }

    void free() {
        for (int i = 0; i < size; ++i) {
            delete objects[i];
        }
        delete[] objects;
    }

    void copyFrom(const Collection& other) {
        size = other.size;
        capacity = other.capacity;
        objects = new Base*[capacity];
        for (int i = 0; i < size; ++i) {
            objects[i] = other.objects[i]->clone();
        }
    }

public:
    Collection() : size(0), capacity(10) {
        objects = new Base*[capacity];
    }
    
    // Default implementation of copy constructor, assignment operator and destructor ...

    void add(Base* obj) {
        if (size == capacity) {
            resize();
        }
        objects[size++] = obj->clone();
    }
    
    void print() const {
        for (int i = 0; i < size; ++i) {
            objects[i]->print();
        }
    }
};
```

<slidebreak/>

## Нарушаване на абстракцията
- Когато работим с указатели от базовия клас, ние не знаем какъв точно тип е обектът, на който сочи указателя.
- Когато имаме полиморфни действия, то ние нямаме проблем да ги изпълняваме.
- Понякога обаче е необходимо да извършим действия, които не са полиморфни. Например, ако искаме да извикаме метод, който е специфичен за производен клас.
- В тези случаи може да се наложи да превърнем указателя от базовия клас в указател от производния клас.
- За целта можем да използваме `dynamic_cast`, който проверява дали указателя от базовия клас сочи към обект от производния клас. Ако не е, то `dynamic_cast` ще върне nullptr, иначе ще върне указател от производния клас.
- Важно е да се отбележи, че `dynamic_cast` работи само с полиморфни класове, тоест класове, които имат поне една виртуална функция.

<slidebreak/>

```cpp
class Base {
public:
    virtual void print() const = 0;
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void print() const override {
        std::cout << "Derived" << std::endl;
    }
    
    void specificMethod() const {
        std::cout << "Specific method of Derived" << std::endl;
    }
};

class AnotherDerived : public Base {
public:
    void print() const override {
        std::cout << "AnotherDerived" << std::endl;
    }
};

class Another {
public:
    void print() const {
        std::cout << "Another" << std::endl;
    }
};

int main() {
    Base* basePtrDerived = new Derived();
    Base* basePtrAnotherDerived = new AnotherDerived();
    Another* another = new Another();

    Derived* derived = dynamic_cast<class Derived*>(basePtrDerived); // OK
    Derived* anoteherDerived = dynamic_cast<class Derived*>(basePtrAnotherDerived); // nullptr
    Derived* another = dynamic_cast<class Derived*>(another); //nullptr
}
```

<slidebreak/>

## Работа с обектите в колекцията върху абстрактен контекст
- Когато работим с обектите в колекцията, ние не знаем какъв точно тип е всеки от тях. 
- Често се налага да имаме някакво взаимодействие, изискващо повече контекст от просто извикване на метод.
- Лоша практика е да правим върволици от if-ове за проверка за всички възможни типове на обектите.
- За да можем да получим допълнителна информация за вида на обекта, може да имплементираме виртуален метод getType, който да връща стойност от изброим тип, който да указва типа на обекта.
- Това би било удобно ако искаме да извършим неполиморфни действия върху обектите от някой конкретен тип. Тогава може да работим с точно тези обекти, знаейки от какъв тип са.

<slidebreak/>

- Друг подход, при който не е необходимо да знаем типа на обектите, е да реализираме Visitor шаблона. Той е подходящ когато имаме абстракция и при извикването и при реализация. Тоест използваме базовия клас при извикване на функционалността и използваме абстракция при параметрите, тоест не знаем с какъв конкретен обект извикваме функцията.
- Пример за такъв случай е работа с фигури (Shape), които реализират метод intersectWith (приемащ друг Shape). При проверка за пресичане на две фигури са необходими различни проверки, които е трудно да се генерализират. Тук понеже нямаме информация за фигурата, с която пресичаме, може да реализираме различната логика в конкретни функции, имащи знание за пресичането. Този подход обаче нарушава други принципи, тъй като изисква при добавяне на нов наследник създаване на нови функции в базовия клас.

<slidebreak/>

## Задача

Да се реализира банкова система, която поддържа различни видове сметки (разплащателна (обикновена сметка), спестовна (която не позволява тегления, а единствено закриване на сметката) и привилигирована (която позволява overdraft до определена сума в зависимост от клиента)) и потребители - клиенти на банката (физически лица (обикновени и дългогодишни клиенти на банката) и юридически лица (малки и големи фирми)).