## Теоретични задачи

**Задача 1:** Какво ще се отпечата на конзолата?

```c++
f(X obj) {}
g(X* ptr) {}

struct X
{
	A arr[2];
	B b;
	C c;
};

int main()
{
	X obj;
	X obj2 = obj;
	obj = obj2;
	
	X* ptr = &obj;
	
	f(*ptr);
	g(ptr);

	return 0;
}
```

**Задача 2:** Какво ще се изведе на конзолата?

```c++
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

	A& operator=(const A& other)
	{
		std::cout << "OP= A()" << std::endl;
		return *this;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

	B& operator=(const B& other)
	{
		std::cout << "OP= B()" << std::endl;
		return *this;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A obj1;
	B& obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = a;
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);

	return 0;
}
```

**Задача 3:** Какво ще се изведе на конзолата?

```c++
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

	A& operator=(const A& other)
	{
		std::cout << "OP= A()" << std::endl;
		return *this;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

	B& operator=(const B& other)
	{
		std::cout << "OP= B()" << std::endl;
		return *this;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A* obj1;
	B& obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = new A();
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);

	return 0;
}
```

**Задача 4:** Какво ще се изведе на конзолата?

```c++
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

	A& operator=(const A& other)
	{
		std::cout << "OP= A()" << std::endl;
		return *this;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

	B& operator=(const B& other)
	{
		std::cout << "OP= B()" << std::endl;
		return *this;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A* obj1;
	B obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = new A(a);
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);

	return 0;
}
```

**Задача 5:** Какво ще се изведе на конзолата?

```c++
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

	A& operator=(const A& other)
	{
		std::cout << "OP= A()" << std::endl;
		return *this;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

	B& operator=(const B& other)
	{
		std::cout << "OP= B()" << std::endl;
		return *this;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A* obj1;
	B& obj2;

public:
	X(const A& a, B* b) : obj1(new A(a)), obj2(*b)
	{
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, &obj2);

	return 0;
}
```
