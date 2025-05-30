#include <iostream>
#include <fstream>


            //Ex.1
namespace SumAndProductNS
{
    const char fileName[] = "result.txt";
    const size_t STR_LEN = 1024;

    void addToFile(int a,int  b,int  c)
    {
        std::ofstream file(fileName, std::ios::trunc);
        if (!file.is_open())
            return;
    
        file << a + b + c << " " << a * b * c;
        file.close();
    }

    void  readFromFile()
    {
        std::ifstream file(fileName);
        if (!file.is_open())
            return;

        int sum, product;
        file >> sum;
        file >> product;
        std::cout << sum - product;
        file.close();
    }

    void sumAndProductOnFile()
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        addToFile(a, b, c);
        readFromFile();
    
    }
}


            //Ex.2
namespace RelationNS
{
    const size_t PAIRS_CNT = 25;
    struct Pair
    {
        double a;
        double b;
    };
    struct Relation
    {
        Pair pairs[PAIRS_CNT];
        size_t relationSize;
    };

    void writeRelationToFile(const Relation& relation)
    {
        std::ofstream file("RelationFile.txt", std::ios::trunc);
        if (!file.is_open())
            return;

        for (size_t i = 0; i < relation.relationSize; i++)
        {
            file << "("<< relation.pairs[i].a << "," << relation.pairs[i].b <<")";
            file << "\n";
        }
        file.close();
    }
    
    void readRelationFromFile(const Relation& relation)
    {
        std::ifstream file("RelationFile.txt");
        if (!file.is_open())
            return;

        while(true)
        {
            file.get();
            if (file.eof())
                break;
            double a, b;
            file >> a;
            file.get();
            file >> b;
            std::cout << '(' << a << ", " << b  << ')' << '\n';
            file.get();
            file.get();
            
        }

        file.close();
    }

    bool inRelation(double a, double b, Relation relation)
    {
        for (size_t i = 0; i < relation.relationSize; i++)
        {
            if (a == relation.pairs[i].a && b == relation.pairs[i].b)
                return true;
        }
        return false;
    }

    void addPairToRelation(Relation& relation)
    {
        double a, b;
        std::cout << "a = ";
        std::cin >> a;
        std::cin.ignore();
        std::cout << "b = ";
        std::cin >> b;
        std::cin.ignore();
        if (relation.relationSize >= 25)
        {
            std::cout << "Over limit!";
                return;
        }
        if (inRelation(a, b, relation))
        {
            std::cout << "Already in!";
            return;
        }
        relation.pairs[relation.relationSize] = { a,b };
        relation.relationSize++;
    }

    void addGivenPairToRel(double a, double b, Relation& relation)
    {
        if (relation.relationSize >= 25)
        {
            std::cout << "Over limit!";
            return;
        }
        if (inRelation(a, b, relation))
        {
            std::cout << "Already in!";
            return;
        }
        relation.pairs[relation.relationSize] = { a,b };
        relation.relationSize++;
    }

    void sort(Relation& relation)
    {
        for (size_t i = 0; i < relation.relationSize; i++)
        {
            for (size_t j = i+1; j < relation.relationSize; j++)
            {
                if (relation.pairs[i].a > relation.pairs[j].a)
                    std::swap(relation.pairs[i], relation.pairs[j]);
                if(relation.pairs[i].a == relation.pairs[j].a)
                    if(relation.pairs[i].b > relation.pairs[j].b)
                        std::swap(relation.pairs[i], relation.pairs[j]);
            }
        }
    }

    void reflexiveClosure(Relation& relation)
    {
        for (size_t i = 0; i < relation.relationSize; i++)
        {
            if (!inRelation(relation.pairs[i].a, relation.pairs[i].a, relation))
                addGivenPairToRel(relation.pairs[i].a, relation.pairs[i].a, relation);
            if (!inRelation(relation.pairs[i].b, relation.pairs[i].b, relation))
                addGivenPairToRel(relation.pairs[i].b, relation.pairs[i].b, relation);
        }
    }

    void symetricClosure(Relation& relation)
    {
        for (size_t i = 0; i < relation.relationSize; i++)
        {
            if (!inRelation(relation.pairs[i].b, relation.pairs[i].a, relation))
                addGivenPairToRel(relation.pairs[i].b, relation.pairs[i].a, relation);
        }
    }

    void copyRel(const Relation relation, Relation& result)
    {
        result.relationSize = relation.relationSize;
        for (size_t i = 0; i < result.relationSize; i++)
        {
            result.pairs[i].a = relation.pairs[i].a;
            result.pairs[i].b = relation.pairs[i].b;
        }
    }

    Relation transitiveClosure(Relation& relation)
    {
        Relation result;
        copyRel(relation, result);
        for (size_t i = 0; i < relation.relationSize; i++)
        {
            for (size_t j = 0; j < relation.relationSize; j++)
            {
                if (relation.pairs[i].b == relation.pairs[j].a)
                {
                    if (!inRelation(relation.pairs[i].a, relation.pairs[j].b, relation))
                        addGivenPairToRel(relation.pairs[i].a, relation.pairs[j].b, result);
                }
            }
        }
        return result;
    }
}


            //Ex.3
namespace ColorNS
{
    const char fileName[] = "color.txt";
    const size_t COMB_LEN = 9;
    const size_t redDel = 65536;
    const size_t greenDel = 256;

    struct Color
    {
        short r;
        short g;
        short b;
    };

    long long getNum(char* str, size_t strLen)
    {
        long long num = 0;
        for (size_t i = 0; i < strLen; i++)
        {
            short d = str[i] - '0';
            num = num * 10 + d;
        }
        return num;
    }

    Color readNum(std::ifstream& ifs)
    {
        Color color;
        char combination[COMB_LEN+1];
        ifs.getline(combination, COMB_LEN, '|');
        size_t strLen = strlen(combination);
        long long num = getNum(combination,strLen);
        color.r = num / redDel;
        num -= color.r * redDel;
        color.g = num / greenDel;
        num -= color.g * greenDel;
        color.b = num;
        ifs.close();
        return color;
    }

    void writeInFile(std::ofstream& ofs, Color* colors,size_t colorsSize)
    {
        long long num = 0;
        for (size_t i = 0; i < colorsSize; i++)
        {
            num = colors[i].r * redDel + colors[i].g * greenDel + colors[i].b;
            ofs << num << '|';
        }
        ofs.close();
    }

    void writeRedColorsInRedFile(Color* colors, size_t colorsSize)
    {
        const char thisFileName[] = "red.txt";
        std::ofstream ofs(thisFileName, std::ios::app);
        long long num = 0;
        for (size_t i = 0; i < colorsSize; i++)
        {
            if (colors[i].r > 250)
            {
                num = colors[i].r * redDel + colors[i].g * greenDel + colors[i].b;
                ofs << num << '|';
            }
        }
        ofs.close();
    }
    
}


            //Ex.4
namespace PlaceholdersNS
{
    const char placeholder[] = "shablon.txt";
    const char infoFile[] = "info.txt";
    const char textBackFile[] = "textBack.txt";
    const size_t itemLen = 1024;
    

    void replaceWithInfo(std::ostream& ofs, std::ifstream& ifs,char* item)
    {
        size_t strLen = strlen(item);
        char compare[itemLen+1];
        while (true)
        {
            ifs.get();
            if (ifs.eof())
                break;
            ifs.seekg(-1,std::ios::cur);

            ifs.getline(compare, itemLen, ' ');
            if (!strcmp(compare, item))
            {
                ifs.getline(compare, itemLen, '\n');
                ofs << compare;
                return;
            }
            ifs.ignore('\n');
        }
    }

    void textBack()
    {
        std::ifstream ifs(placeholder);
        std::ifstream ifs2(infoFile);
        std::ofstream ofs(textBackFile,std::ios::out);
        char item[itemLen + 1];
        while (true)
        {
            ifs.get();
            if (ifs.eof())
                break;
            ifs.seekg(-1, std::ios::cur);
            while (ifs.get() != '{')
            {
                ifs.seekg(-1,std::ios::cur);
                ofs.put(ifs.get());
            }
            ifs.getline(item, itemLen, '}');
            replaceWithInfo(ofs, ifs2, item);
        }
        ifs.close();
        ifs2.close();
        ofs.close();
    }
}


            //Ex.5
namespace WarehousesNS
{
    const size_t strLen = 32;
    const size_t maxdevicesInWarehouse = 100;
    const char outputFile[] = "warehouseOutput.txt";
    const char inputFile[] = "warehouseInput.txt";

    enum DeviceType
    {
        TV, SMARTPHONE, LAPTOP, PC, CAMERA
    };
    struct Device
    {
        char name[strLen + 1];
        int stock;
        double price;
        DeviceType deviceType;
        char supplier[strLen + 1];
    };
    struct Warehouse
    {
        Device devices[maxdevicesInWarehouse];
        size_t devicesCount;
        char owner[strLen + 1];
    };

    Device createDevice()
    {
        Device device;
        std::cout << "Device name: ";
        std::cin.getline(device.name,strLen,'\n');

        std::cout << "Quantity on stock: ";
        std::cin >> device.stock;

        std::cout << "Price: ";
        std::cin >> device.price;

        std::cout << "Device Type: ";
        int type;
        std::cin >> type;
        device.deviceType = DeviceType(type);
        std::cin.ignore();

        std::cout << "Supplier: ";
        std::cin.getline(device.supplier, strLen, '\n');

        return device;
    }

    Warehouse createWarehouse()
    {
        Warehouse warehouse;
        std::cout << "Type warehouse owner: ";
        std::cin.getline(warehouse.owner, strLen, '\n');
        return warehouse;
    }

    void addDeviceInWarehouse(Warehouse& warehouse,Device device)
    {
        if (warehouse.devicesCount + 1 > maxdevicesInWarehouse)
        {
            std::cout << "Over limit!";
        }
            warehouse.devices[warehouse.devicesCount++] = device;
    }

    void addToFile(Warehouse warehouse)
    {
        std::ofstream ofs(outputFile, std::ios::out);
        ofs << '\t' << warehouse.owner << ":\n";
        for (size_t i = 0; i < warehouse.devicesCount; i++)
        {
            ofs<< warehouse.devices[i].name << ", " << warehouse.devices[i].stock << ", " << warehouse.devices[i].price << ", " << warehouse.devices[i].deviceType << ", " << warehouse.devices[i].supplier <<'\n';
        }
        ofs.close();
    }

    void readFromFile(std::ifstream& ifs)
    {
        Warehouse warehouse;
        while (true)
        {
            ifs.get();
            if (ifs.eof())
                return;
            ifs.seekg(-1, std::ios::cur);

            while (ifs.get() != '\t');
            std::cin.getline(warehouse.owner, strLen,'\n');
            ifs.ignore('\n');

        }
    }

    void addSpecificDevices(Warehouse warehouse,DeviceType devType)
    {
        std::ofstream ofs(outputFile, std::ios::out);
        ofs << '\t' << warehouse.owner << ":\n";
        for (size_t i = 0; i < warehouse.devicesCount; i++)
        {
            if (warehouse.devices[i].deviceType == devType)
            {
                ofs << warehouse.devices[i].name << ", " << warehouse.devices[i].stock << ", " << warehouse.devices[i].price << ", " << warehouse.devices[i].deviceType << ", " << warehouse.devices[i].supplier << '\n';
            }
        }
        ofs.close();
    }

    void printWarehouse(Warehouse warehouse)
    {
        for (size_t i = 0; i < warehouse.devicesCount; i++)
        {
            std::cout << "Oner: " << warehouse.owner;
            std::cout << "DevicesCount: " << warehouse.devicesCount;
            for (size_t i = 0; i < warehouse.devicesCount; i++)
            {
                std::cout << "Device name: " << warehouse.devices[i].name;
                std::cout << "\tDevice stock: " << warehouse.devices[i].stock;
                std::cout << "\tDevice price: " << warehouse.devices[i].price;
                std::cout << "\tDevice type: " << warehouse.devices[i].deviceType;
                std::cout << "\tDevice supplier: " << warehouse.devices[i].supplier;
            }
        }
    }

    void sortByPrice(Warehouse& warehouse)
    {
        for (size_t i = 0; i < warehouse.devicesCount; i++)
        {
            for (size_t j = i + 1; j < warehouse.devicesCount; j++)
            {
                if (warehouse.devices[i].price > warehouse.devices[j].price)
                    std::swap(warehouse.devices[i].price, warehouse.devices[j].price);
            }
        }
    }

    void sortByStock(Warehouse& warehouse)
    {
        for (size_t i = 0; i < warehouse.devicesCount; i++)
        {
            for (size_t j = i + 1; j < warehouse.devicesCount; j++)
            {
                if (warehouse.devices[i].stock > warehouse.devices[j].stock)
                    std::swap(warehouse.devices[i].stock, warehouse.devices[j].stock);
            }
        }
    }

    Device findCheapest(Warehouse warehouse)
    {
        sortByPrice(warehouse);
        return warehouse.devices[0];
    }

    void printDevice(Device d)
    {
        std::cout << d.name << ", " << d.stock << ", " << d.price << ", " << d.deviceType << ", " << d.supplier;
    }
}

    
int main()
{

}
