#include <iostream>
#pragma warning 
class ChocolateBar {
    char* brand = nullptr;
    double weight = 0.0;
    double priceInBulk = 0.0;
    double priceForSale = 0.0;

public:
    ChocolateBar() = default;

    ChocolateBar(const ChocolateBar& other) {
        copyFrom(other);
    }

    ChocolateBar& operator=(const ChocolateBar& other) {
        free();
        copyFrom(other);
    }

    ~ChocolateBar() {
        delete[] brand;
    }

    void setBrand(const char* brand) {
        if (brand == nullptr) {
            std::cout << "Err" << std::endl;
            return;
        }

        if (this->brand == brand) {
            return;
        }

        if (this->brand != nullptr) {
            free();
        }

        this->brand = new char[strlen(brand)+1];
        strcpy(this->brand, brand);

    }

    void setWeight(double weight) {
        if (weight < 0) {
            std::cout << "Invalid weight" << std::endl;
            return;
        }
        this->weight = weight;
    }

    void setPriceInBulk(double priceInBulk) {
        if (weight < 0) {
            std::cout << "Invalid price" << std::endl;
            return;
        }
        this->priceInBulk = priceInBulk;
    }

    void setPriceForSale(double priceForSale) {
        if (weight < 0) {
            std::cout << "Invalid price" << std::endl;
            return;
        }
        this->priceForSale = priceForSale;
    }

    char* getBrand() const {
        return brand;
    }

    double getWeight() const{
        return weight;
    }
    double getPriceInBulk() const{
        return priceInBulk;
    }
    
    double getPriceForSale() const{
        return priceForSale;
    }
private:
    void free() {
        delete[] brand;
    }
    void copyFrom(const ChocolateBar& other) {
        setBrand(other.brand);
        setWeight(other.weight);
        setPriceForSale(other.priceForSale);
        setPriceInBulk(other.priceInBulk);
    }
};

class Shop {
    ChocolateBar* bars = nullptr;
    size_t curNumOfBars = 0;
    size_t maxNumOfBars = 0;
    double revenue=0.0;
    double expenses=0.0;
public:
    Shop() = default;

    Shop(const Shop& other) {

    }

    void setBars(ChocolateBar* bars, size_t curNumOfBars) {
        if (curNumOfBars > maxNumOfBars) {
            std::cout << "Exceeds size" << std::endl;
            return;
        }
        if (bars == nullptr) {
            std::cout << "Err" << std::endl;
            return;
        }

        bars = new ChocolateBar[curNumOfBars+1];

        for (int i = 0; i < curNumOfBars; i++) {
            this->bars[i] = bars[i];
        }
        this->curNumOfBars = curNumOfBars;
    }
    void setMaxNumOfBars(size_t maxNumOfBars) {
        this->maxNumOfBars = maxNumOfBars;
    }
    void setRevenue(double revenue) {
        this->revenue = revenue;
    }
    
private:
    copyFrom(const Shop& other) {
        setBars(other.bars, other.curNumOfBars);
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
