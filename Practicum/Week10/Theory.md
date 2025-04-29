<h1 align="center">ООП - Практикум - 23.04.2025 - Седмица 10</h1>

## Наследяване

- Дефинираме клас, който разширява поведението и член-данните на друг базов клас
- В паметта е същото като при композиция **(has-a-relationship)**, но при наследяването имаме **(is-a-relationship)**

### Видове наследяване

- При класовете наследяването по default е **private**, докато при структурите е **public**

```c++
class Base
{
private:
        int x = 0;
protected:
        int y = 0;
public:
        int z = 0;
}
```

- **private** - всички член-данни от базовия клас придобиват видимост **private**, но наследникът има достъп до **protected** / **public** член-данните

```c++
class Der : private Base
{
        x // => няма достъп
        y, z // => private
}
```

- **protected** - член-данните от базовия клас с видимост **protected** / **public**, при наследника стават **protected**

```c++
class Der : protected Base
{
        x // => няма достъп
        y, z // => protected
}
```

- **public** - видимостта на член-данните от базовия клас си остава същата

```c++
class Der : public Base
{
        x // => няма достъп
        y // => protected
        z // => public
}
```

### Параметри на функции

- При наследяване можем да насочваме обекти от базовия клас към неговите наследници, НО обратното не можем

```c++
Der d;
Base* ptr = &d;
```

| Функция                | Base b   | Der d   |
| ---------------------- | -------- | ------- |
| f1(Base)               | f1(b)    | f1(d)   |
| f2(const Base&)        | f2(b)    | f2(d)   |
| f3(const Base*)        | f3(&b)   | f3(&d)  |
| f4(Der)                | не можем | f4(d)   |
| f5(const Der&)         | не можем | f5(d)   |
| f6(const Der*)         | не можем | f6(&d)  |

### Конструктори при наследяване

- Конструкторът трябва да укаже кои конструктори на базовия клас да се извикат, иначе по default се извиква **default** конструктор на базовия клас

```c++
class Base
{
        int x;
}

class Der : Base
{
        int y;

        Der(int x, int y) : Base(x)
        {
                this->y = y;
        }
}
```

#### Копиращ конструктор

```c++
Der(const Der& other): Base(other), y(other.y) {}
```

#### Оператор=

```c++
Der& operator=(const Der& other)
{
        if (this != &other)
        {
                Base::operator=(other);
                this->y = other.y;
        }

        return *this;
}
```

#### Move конструктор

```c++
Der(Der&& other) noexcept :
        Base(std::move(other)),
        y(std::move(other.y)) {}
```

#### Move оператор=

```c++
Der& operator=(Der&& other) noexcept
{
        if (this != &other)
        {
                Base::operator=(std::move(other));
                this->y = std::move(other.y);
        }

        return *this;
}
```



#### Извикване на конструктори

```c++
class Der : Base
{
        A a;
        B b;
        C c;
}
```

```c++
Base(), A(), B(), C(), Der()
```

- В наследниците се разписва голяма четворка / шестица само ако в тях имаме външни ресурси

### Деструктори при наследяване

- Деструкторът на наследника извиква деструктора на базовия клас
- Деструкторите се извикват в обратен ред на конструкторите


#### Извикване на деструктори

```c++
~Der(), ~C(), ~B(), ~A(), ~Base()
```

## Дефиниране на изключения

- Можем да дефинираме нашe **custom** изключение, като наследим даден вид изключение: `std::exception`, `std::runtime_error`, `std::logic_error`

```c++
class CustomException : public std::exception
{
public:
        CustomException(const char* errorMessage) : std::exception(errorMessage) {}
}
```
