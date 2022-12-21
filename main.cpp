#include <iostream>

using namespace std;

class Sneakers {
private:
    string brand_;
    int size_;
    string color_;
    string material_;
    double price_;
    int quantity_;
    int numberOfSales_;

public:
    Sneakers() {}
    Sneakers(string brand, int size, string color, string material, double price,
        int quantity, int numberOfSales) {
        brand_ = brand;
        size_ = size;
        color_ = color;
        material_ = material;
        price_ = price;
        quantity_ = quantity;
        numberOfSales_ = numberOfSales;
    }

    string getBrand() { return brand_; }

    string getColor() { return color_; }

    string getMaterial() { return material_; }

    int getSize() { return size_; }

    double getPrice() { return price_; }

    void setPrice(double value) { price_ = value; }

    int getQuantity() { return quantity_; }

    int getNumberOfSales() { return numberOfSales_; }

    void setNumberOfSales(double value) { numberOfSales_ = value; }
};

class SportShoesStore {
public:
    Sneakers assortment[5]{};

    void PriceSorting() {
        double temporaryVariableForSorting;
        cout << " " << endl;
        cout << "SORTING BY PRICE" << endl;cout << " " << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (assortment[j].getPrice() < assortment[i].getPrice()) {
                    temporaryVariableForSorting = assortment[i].getPrice();
                    assortment[i].setPrice(assortment[j].getPrice());
                    assortment[j].setPrice(temporaryVariableForSorting);
                }
            }
        };
        for (int i = 4; i >= 0; i--) {
            cout << assortment[i].getBrand()
                << "   Price: " << assortment[i].getPrice()
                << "   Quantity: " << assortment[i].getQuantity() << endl;
        }
    }

    void NumberOfSalesSorting() {
        double temporaryVariableForSorting;
        cout << " " << endl;cout << " " << endl;cout << " " << endl;
        cout << "TOP 3 BY NUMBER OF SALES" << endl;
        cout << " " << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (assortment[j].getNumberOfSales() <
                    assortment[i].getNumberOfSales()) {
                    temporaryVariableForSorting = assortment[i].getNumberOfSales();
                    assortment[i].setNumberOfSales(assortment[j].getNumberOfSales());
                    assortment[j].setNumberOfSales(temporaryVariableForSorting);
                }
            }
        };

        for (int i = 4; i >= 2; i--) {
            cout << assortment[i].getBrand()
                << "   Number of sales: " << assortment[i].getNumberOfSales()
                << "   Price: " << assortment[i].getPrice()
                << "   Quantity: " << assortment[i].getQuantity() << endl;
        }
    }
};

int main() {
    SportShoesStore a = SportShoesStore();
    a.assortment[0] = Sneakers("Nike", 40, "White", "Plastic", 1499.9, 300, 100);
    a.assortment[1] = Sneakers("Abibas", 41, "Blue", "Plastic", 1399.9, 250, 99);
    a.assortment[2] =
        Sneakers("Adidas", 45, "Black", "Plastic", 1999.9, 350, 101);
    a.assortment[3] = Sneakers("Feele", 84, "White", "Plastic", 5999.9, 301, 150);
    a.assortment[4] = Sneakers("Noike", 10, "Pink", "Metal", 3999.9, 199, 10);

    a.PriceSorting();
    a.NumberOfSalesSorting();

    return 0;
}
