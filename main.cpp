#include <iostream>
#include <string>

using namespace std;

class Order
{
private:
    int orderID;
    string product;
    int quantity;

public:
    // Numatytasis konstruktorius
    Order() : orderID(0), product("Unknown"), quantity(0) {}

    // Konstruktorius su parametrais
    Order(int orderID, const string &product, int quantity)
        : orderID(orderID), product(product), quantity(quantity) {}

    // Kopijavimo konstruktorius
    Order(const Order &other) : orderID(other.orderID), product(other.product), quantity(other.quantity) {}

    // Viešas metodas be parametrų užsakymo informacijos spausdinimui
    void printInfo() const
    {
        cout << "Order ID: " << orderID << ", Product: " << product << ", Quantity: " << quantity << endl;
    }

    // Viešas metodas su parametru kiekiui nustatyti
    void setQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }

    // Viešas metodas grąžinantis bendrą kainą
    double getTotalPrice(double unitPrice) const
    {
        return unitPrice * quantity;
    }
};

int main()
{
    // Sukuriame užsakymą naudodami numatytąjį konstruktorių
    Order defaultOrder;
    defaultOrder.printInfo();

    // Sukuriame užsakymą naudodami konstruktorių su parametrais
    Order specificOrder(1, "Laptop", 1);
    specificOrder.printInfo();

    // Naudojame kopijavimo konstruktorių
    Order copiedOrder(specificOrder);
    copiedOrder.printInfo();

    // Naudojame metodą su parametrais, kad nustatytume naują kiekį
    specificOrder.setQuantity(2);
    specificOrder.printInfo();

    // Naudojame metodą, kuris grąžina bendrą kainą
    double unitPrice = 1099.99;
    cout << "Total price for specificOrder: $" << specificOrder.getTotalPrice(unitPrice) << endl;

    return 0;
}
