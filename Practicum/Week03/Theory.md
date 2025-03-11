<h1 align="center">ООП - Практикум - 05.03.2025 - Седмица 03</h1>

## Двоични файлове

- Файлове, готови за зареждане в паметта
- Без точна дефиниция

## Четене и писане в двоичен файл

- `istream& read(char* str, size)` - четене от двоичен файл
- `ostream& write(const char* str, size)` - писане в двоичен файл

**Пример:**

```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream ofs("test.dat", std::ios::out | std::ios::binary);

	int x = 21;
	
	if (!ofs.is_open()) return 0;

	ofs.write((const char*)&x, sizeof(int));

	ofs.close();

	return 0;
}
```

```c++
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ifs("test.dat", std::ios::in | std::ios::binary);

	int x;
	
	if (!ifs.is_open()) return 0;

	ifs.read((char*)&x, sizeof(int));

	std::cout << x << std::endl; // 21

	ifs.close();

	return 0;
}
```

## Четене и писане на структури в двоичен файл

### Без динамична памет

```c++
#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>

namespace Constants
{
	constexpr size_t MAX_NAME_SIZE = 128;
}

namespace DeviceNS
{
	using namespace Constants;

	enum class DeviceType : uint8_t
	{
		PC,
		LAPTOP,
		GAMING,
		SMARTPHONE
	};

	struct Device
	{
		char brand[MAX_NAME_SIZE + 1];
		DeviceType deviceType;
		size_t speed;
		double price;
	};

	Device initDevice(const char* brand, DeviceType deviceType, size_t speed, double price)
	{
		if (!brand) return {};
		if (strlen(brand) > MAX_NAME_SIZE) return {};

		Device toReturn;

		strcpy(toReturn.brand, brand);
		toReturn.deviceType = deviceType;
		toReturn.speed = speed;
		toReturn.price = price;

		return toReturn;
	}

	Device readDevice(std::ifstream& ifs)
	{
		Device toReturn;
		ifs.read((char*)&toReturn, sizeof(Device));
		return toReturn;
	}

	Device readDevice(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) return {};

		return readDevice(ifs);
	}

	void writeDevice(std::ofstream& ofs, const Device& obj)
	{
		ofs.write((const char*)&obj, sizeof(Device));
	}

	void writeDevice(const char* fileName, const Device& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) return;

		return writeDevice(ofs, obj);
	}

	void printDevice(const Device& obj)
	{
		std::cout << obj.brand << " " << (int)obj.deviceType << " " << obj.speed << " " << obj.price << std::endl;
	}
}

int main()
{
	using namespace DeviceNS;

	Device device = initDevice("Balkan", DeviceType::PC, 1024, 1200);

	writeDevice("device.dat", device);

	Device returnedDevice = readDevice("device.dat");

	printDevice(returnedDevice);

	return 0;
}
```

### Динамична памет

```c++
#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>

namespace DeviceNS
{
	enum class DeviceType : uint8_t
	{
		PC,
		LAPTOP,
		GAMING,
		SMARTPHONE
	};

	struct Device
	{
		char* brand;
		DeviceType deviceType;
		size_t speed;
		double price;
	};

	Device initDevice(const char* brand, DeviceType deviceType, size_t speed, double price)
	{
		if (!brand) return {};

		Device toReturn;

		toReturn.brand = new char[strlen(brand) + 1] { '\0' };
		strcpy(toReturn.brand, brand);

		toReturn.deviceType = deviceType;
		toReturn.speed = speed;
		toReturn.price = price;

		return toReturn;
	}

	Device readDevice(std::ifstream& ifs)
	{
		Device toReturn;

		size_t brandLength = 0;
		ifs.read((char*)&brandLength, sizeof(size_t));

		toReturn.brand = new char[brandLength + 1] { '\0' };
		ifs.read((char*)toReturn.brand, sizeof(char) * brandLength);

		ifs.read((char*)&toReturn.deviceType, sizeof(DeviceType));

		ifs.read((char*)&toReturn.speed, sizeof(size_t));
		ifs.read((char*)&toReturn.price, sizeof(double));

		return toReturn;
	}

	Device readDevice(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) return {};

		return readDevice(ifs);
	}

	void writeDevice(std::ofstream& ofs, const Device& obj)
	{
		size_t brandLength = strlen(obj.brand);

		ofs.write((const char*)&brandLength, sizeof(size_t));
		ofs.write((const char*)obj.brand, sizeof(char) * brandLength);

		ofs.write((const char*)&obj.deviceType, sizeof(DeviceType));

		ofs.write((const char*)&obj.speed, sizeof(size_t));
		ofs.write((const char*)&obj.price, sizeof(double));
	}

	void writeDevice(const char* fileName, const Device& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) return;

		return writeDevice(ofs, obj);
	}

	void printDevice(const Device& obj)
	{
		std::cout << obj.brand << " " << (int)obj.deviceType << " " << obj.speed << " " << obj.price << std::endl;
	}
	
	void freeDevice(Device& obj)
	{
		delete[] obj.brand;
		obj.brand = nullptr;
	}
}

int main()
{
	using namespace DeviceNS;

	Device device = initDevice("Balkan", DeviceType::PC, 1024, 1200);

	writeDevice("device.dat", device);

	Device returnedDevice = readDevice("device.dat");

	printDevice(returnedDevice);
	
	freeDevice(device);
	freeDevice(returnedDevice);

	return 0;
}
```

## Четене и писане на масиви от структури в двоичен файл

### Без динамична памет

```c++
#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);

	return size;
}

namespace Constants
{
	constexpr size_t MAX_NAME_SIZE = 128;
}

namespace DeviceNS
{
	using namespace Constants;

	enum class DeviceType : uint8_t
	{
		PC,
		LAPTOP,
		GAMING,
		SMARTPHONE
	};

	struct Device
	{
		char brand[MAX_NAME_SIZE + 1];
		DeviceType deviceType;
		size_t speed;
		double price;
	};

	Device initDevice(const char* brand, DeviceType deviceType, size_t speed, double price)
	{
		if (!brand) return {};
		if (strlen(brand) > MAX_NAME_SIZE) return {};

		Device toReturn;

		strcpy(toReturn.brand, brand);
		toReturn.deviceType = deviceType;
		toReturn.speed = speed;
		toReturn.price = price;

		return toReturn;
	}

	Device readDevice(std::ifstream& ifs)
	{
		Device toReturn;
		ifs.read((char*)&toReturn, sizeof(Device));
		return toReturn;
	}

	Device readDevice(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) return {};

		return readDevice(ifs);
	}

	void writeDevice(std::ofstream& ofs, const Device& obj)
	{
		ofs.write((const char*)&obj, sizeof(Device));
	}

	void writeDevice(const char* fileName, const Device& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) return;

		return writeDevice(ofs, obj);
	}

	void printDevice(const Device& obj)
	{
		std::cout << obj.brand << " " << (int)obj.deviceType << " " << obj.speed << " " << obj.price << std::endl;
	}
}

namespace StoreNS
{
	using namespace DeviceNS;

	struct Store
	{
		Device* devices;
		size_t size;
	};

	Store initStore(size_t size)
	{
		Store toReturn;

		toReturn.size = size;
		toReturn.devices = new Device[toReturn.size];

		return toReturn;
	}

	Store readStore(std::ifstream& ifs)
	{
		Store toReturn;

		toReturn.size = getFileSize(ifs) / sizeof(Device);
		toReturn.devices = new Device[toReturn.size];

		for (size_t i = 0; i < toReturn.size; i++)
		{
			toReturn.devices[i] = readDevice(ifs);
		}

		ifs.close();
		return toReturn;
	}

	Store readStore(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) return {};

		return readStore(ifs);
	}

	void writeStore(std::ofstream& ofs, const Store& obj)
	{
		for (size_t i = 0; i < obj.size; i++)
		{
			writeDevice(ofs, obj.devices[i]);
		}

		ofs.close();
	}

	void writeStore(const char* fileName, const Store& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) return;

		return writeStore(ofs, obj);
	}

	void printStore(const Store& obj)
	{
		std::cout << obj.size << std::endl;

		for (size_t i = 0; i < obj.size; i++)
		{
			printDevice(obj.devices[i]);
		}
	}
	
	void freeStore(Store& obj)
	{
		delete[] obj.devices;
	}
}

int main()
{
	using namespace StoreNS;

	Store store = initStore(3);
	store.devices[0] = initDevice("Balkan", DeviceType::PC, 1024, 1200);
	store.devices[1] = initDevice("Apple", DeviceType::LAPTOP, 2048, 2500);
	store.devices[2] = initDevice("Asus", DeviceType::LAPTOP, 1500, 1600);

	writeStore("store.dat", store);

	Store stored = readStore("store.dat");

	printStore(stored);
	
	freeStore(store);
	freeStore(stored);

	return 0;
}
```

### Динамична памет

```c++
#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>

namespace DeviceNS
{
	enum class DeviceType : uint8_t
	{
		PC,
		LAPTOP,
		GAMING,
		SMARTPHONE
	};

	struct Device
	{
		char* brand;
		DeviceType deviceType;
		size_t speed;
		double price;
	};

	Device initDevice(const char* brand, DeviceType deviceType, size_t speed, double price)
	{
		if (!brand) return {};

		Device toReturn;

		toReturn.brand = new char[strlen(brand) + 1] { '\0' };
		strcpy(toReturn.brand, brand);

		toReturn.deviceType = deviceType;
		toReturn.speed = speed;
		toReturn.price = price;

		return toReturn;
	}

	Device readDevice(std::ifstream& ifs)
	{
		Device toReturn;

		size_t brandLength = 0;
		ifs.read((char*)&brandLength, sizeof(size_t));

		toReturn.brand = new char[brandLength + 1] { '\0' };
		ifs.read((char*)toReturn.brand, sizeof(char) * brandLength);

		ifs.read((char*)&toReturn.deviceType, sizeof(DeviceType));

		ifs.read((char*)&toReturn.speed, sizeof(size_t));
		ifs.read((char*)&toReturn.price, sizeof(double));

		return toReturn;
	}

	Device readDevice(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) return {};

		return readDevice(ifs);
	}

	void writeDevice(std::ofstream& ofs, const Device& obj)
	{
		size_t brandLength = strlen(obj.brand);

		ofs.write((const char*)&brandLength, sizeof(size_t));
		ofs.write((const char*)obj.brand, sizeof(char) * brandLength);

		ofs.write((const char*)&obj.deviceType, sizeof(DeviceType));

		ofs.write((const char*)&obj.speed, sizeof(size_t));
		ofs.write((const char*)&obj.price, sizeof(double));
	}

	void writeDevice(const char* fileName, const Device& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) return;

		return writeDevice(ofs, obj);
	}

	void printDevice(const Device& obj)
	{
		std::cout << obj.brand << " " << (int)obj.deviceType << " " << obj.speed << " " << obj.price << std::endl;
	}
	
	void freeDevice(Device& obj)
	{
		delete[] obj.brand;
		obj.brand = nullptr;
	}
}

namespace StoreNS
{
	using namespace DeviceNS;

	struct Store
	{
		Device* devices;
		size_t size;
	};

	Store initStore(size_t size)
	{
		Store toReturn;

		toReturn.size = size;
		toReturn.devices = new Device[toReturn.size];

		return toReturn;
	}

	Store readStore(std::ifstream& ifs)
	{
		Store toReturn;

		ifs.read((char*)&toReturn.size, sizeof(size_t));
		toReturn.devices = new Device[toReturn.size];

		for (size_t i = 0; i < toReturn.size; i++)
		{
			toReturn.devices[i] = readDevice(ifs);
		}

		ifs.close();
		return toReturn;
	}

	Store readStore(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) return {};

		return readStore(ifs);
	}

	void writeStore(std::ofstream& ofs, const Store& obj)
	{
		ofs.write((const char*)&obj.size, sizeof(size_t));

		for (size_t i = 0; i < obj.size; i++)
		{
			writeDevice(ofs, obj.devices[i]);
		}

		ofs.close();
	}

	void writeStore(const char* fileName, const Store& obj)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) return;

		return writeStore(ofs, obj);
	}

	void printStore(const Store& obj)
	{
		std::cout << obj.size << std::endl;

		for (size_t i = 0; i < obj.size; i++)
		{
			printDevice(obj.devices[i]);
		}
	}
	
	void freeStore(Store& obj)
	{
		for (size_t i = 0; i < obj.size; i++)
		{
			freeDevice(obj.devices[i]);
		}
	
		delete[] obj.devices;
	}
}

int main()
{
	using namespace StoreNS;

	Store store = initStore(3);
	store.devices[0] = initDevice("Balkan", DeviceType::PC, 1024, 1200);
	store.devices[1] = initDevice("Apple", DeviceType::LAPTOP, 2048, 2500);
	store.devices[2] = initDevice("Asus", DeviceType::LAPTOP, 1500, 1600);

	writeStore("store.dat", store);

	Store stored = readStore("store.dat");

	printStore(stored);
	
	freeStore(store);
	freeStore(stored);

	return 0;
}
```

## fstream

- Съдържа в себе си **get** и **put** указатели
- Наследник на `istream` и `ostream`
- При операции `.seekg()` и `.seekp()`, **get** и **put** указателите се местят едновременно

**ВАЖНО!!!** При входна операция, след изходна, трябва да се прави синхронизация на потока: `.flush() <=> .seekg(tellg())`

**Задача:** Да се напише програма, която приема име на файл, два символа `ch1` и `ch2`, и замества всяко срещане на `ch1` с `ch2`

```c++
#include <iostream>
#include <fstream>

void replace(std::fstream& fs, char ch1, char ch2)
{
	while (!fs.eof())
	{
		char symbol = fs.get();

		if (symbol == ch1)
		{
			fs.seekg(-1, std::ios::cur);
			fs.put(ch2);
			fs.flush();
		}
	}

	fs.close();
}

void replace(const char* fileName, char ch1, char ch2)
{
	if (!fileName) return;

	std::fstream fs(fileName);

	if (!fs.is_open()) return;

	return replace(fs, ch1, ch2);
}
```

## stringstream

- Достъп до всички методи на `iostream`
- Автоматично **"string"**-ване

**Пример:**

```c++
#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss("ABC");
	ss << 3;
	std::cout << ss.str() << std::endl; // 3BC

	return 0;
}
```
