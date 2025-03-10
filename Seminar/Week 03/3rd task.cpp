#include <iostream>
#include <fstream>
#include <cstring>

namespace Constants {
    const int MAX_NAME_SIZE = 50;
    const int MAX_PHONE_SIZE = 20;
    const int MAX_ADRESS_SIZE = 100;
    const int MAX_ORDRE_SIZE = 20;
}

namespace PizaHouseNS {
    using namespace Constants;
    


    enum class PizaType
    {
        Margarita, Calcone, Vurata, Zverska
    };


    enum class PizaSize
    {
        S, M, L
    };


    struct Piza {
        PizaType type;
        PizaSize size;
        double pricePiza;
    };

    struct Order {
        char name[MAX_NAME_SIZE];
        char phoneNumber[MAX_PHONE_SIZE];
        char adress[MAX_ADRESS_SIZE];
        double priceOfOrder;
        int numberOfPizas;
        Piza* pizas;
    };

    struct Delivery {
        int numberOfOrdres;
        Order* orders;
    };

    void saveOrdersBinary(std::ofstream& ofs, Delivery& d) {
        ofs.write((const char*)&d.numberOfOrdres, sizeof(d.numberOfOrdres));
        for (size_t i = 0; i < d.numberOfOrdres; i++) {
            ofs.write((const char*)d.orders[i].name, sizeof(d.orders[i].name));
            ofs.write((const char*)d.orders[i].phoneNumber, sizeof(d.orders[i].phoneNumber));
            ofs.write((const char*)d.orders[i].adress, sizeof(d.orders[i].adress));
            ofs.write((const char*)&d.orders[i].priceOfOrder, sizeof(d.orders[i].priceOfOrder));
            ofs.write((const char*)&d.orders[i].numberOfPizas, sizeof(d.orders[i].numberOfPizas));
            for (size_t j = 0; j < d.orders[i].numberOfPizas; j++) {
                ofs.write((const char*)&d.orders[i].pizas[j].pricePiza, sizeof(d.orders[i].pizas[j].pricePiza));
                ofs.write((const char*)&d.orders[i].pizas[j].size, sizeof(d.orders[i].pizas[j].size));
                ofs.write((const char*)&d.orders[i].pizas[j].type, sizeof(d.orders[i].pizas[j].type));
            }
        }
    }

    void cleanupDelivery(Delivery& d) {
        for (int i = 0; i < d.numberOfOrdres; i++) {
            delete[] d.orders[i].pizas;
        }
        delete[] d.orders;
    }

    void saveOrdersBinary(const char* filename, Delivery& d) {
        if (!filename) return;
        std::ofstream ofs(filename, std::ios::binary);
        if (!ofs.is_open()) return;
        saveOrdersBinary(ofs, d);
    }

    Delivery readOrdersBinary(std::ifstream& ifs) {
        Delivery d;
        ifs.read((char*)&d.numberOfOrdres, sizeof(d.numberOfOrdres));
        d.orders = new Order[d.numberOfOrdres];  
        for (size_t i = 0; i < d.numberOfOrdres; i++) {
            ifs.read((char*)d.orders[i].name, sizeof(d.orders[i].name));
            ifs.read((char*)d.orders[i].phoneNumber, sizeof(d.orders[i].phoneNumber));
            ifs.read((char*)d.orders[i].adress, sizeof(d.orders[i].adress));
            ifs.read((char*)&d.orders[i].priceOfOrder, sizeof(d.orders[i].priceOfOrder));
            ifs.read((char*)&d.orders[i].numberOfPizas, sizeof(d.orders[i].numberOfPizas));
            d.orders[i].pizas = new Piza[d.orders[i].numberOfPizas]; 
            for (size_t j = 0; j < d.orders[i].numberOfPizas; j++) {
                ifs.read((char*)&d.orders[i].pizas[j].pricePiza, sizeof(d.orders[i].pizas[j].pricePiza));
                ifs.read((char*)&d.orders[i].pizas[j].size, sizeof(d.orders[i].pizas[j].size));
                ifs.read((char*)&d.orders[i].pizas[j].type, sizeof(d.orders[i].pizas[j].type));
            }
        }
        return d;
    }

    Delivery readOrdersBinary(const char* filename) {
        if (!filename) return Delivery();
        std::ifstream ifs(filename, std::ios::binary);
        if (!ifs.is_open()) return Delivery();
        return readOrdersBinary(ifs);
    }

    void swapOrders(Order& o1, Order& o2) {
        Order tmp = o1;
        o1 = o2;
        o2 = tmp;
    }

    bool (*sortByAdress)(const char*, const char*) = [](const char* a, const char* b) -> bool {
        return std::strcmp(a, b) < 0;
        };


    void sortOrdersByAdress(Delivery& d, bool(*sortCriteria)(const char* a, const char* b)) {
        for (size_t i = 0; i < d.numberOfOrdres - 1; i++) {
            int minIdx = i;
            for (size_t j = i + 1; j < d.numberOfOrdres; j++) {
                if (sortCriteria(d.orders[minIdx].adress, d.orders[j].adress)) {
                    minIdx = j;
                }
            }
            swapOrders(d.orders[i], d.orders[minIdx]);
        }
    }
}

int main412412() {
    using namespace PizaHouseNS;

    Delivery delivery;
    delivery.numberOfOrdres = 3;
    delivery.orders = new Order[delivery.numberOfOrdres];

    return 0;
}

