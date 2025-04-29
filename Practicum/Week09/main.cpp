#include<iostream>
#include<stdexcept>
#include<cstring>

#include "String.h"
#include "Order.h"
#include "Restaurant.h"
#include "Foodpanda.h"

int main(){
    //Check after writing String.h
	/*String str1("fish", 5);
	str1.print();

	String str2("kiwi");
	str2.print();

	bool t = str1 == str2;
	std::cout << t << std::endl;*/

    //check after writing class Order
    /*try {
        String product1("Pizza");
        String product2("Burger");
        String product3("Pasta");

        String products[] = { product1, product2 };

        Order order("Italiano Restaurant", 2, products, 2);

        order.printOrder();

        order.addNewProduct(product3);

        std::cout << "After adding a new product:\n";
        order.printOrder();

        size_t deliveryTime = order.calcDeliveryTime();
        std::cout << "Calculated delivery time: " << deliveryTime << " minutes" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }*/

    //check after Restaurant class
    /*String product1("Pizza", 5);
    String product2("Burger", 6);
    String product3("Pasta", 5);

    String products[] = { product1, product2, product3 };

    Restaurant restaurant("FoodPlace", products, 3, 5);

    std::cout << "Restaurant: " << restaurant.getName() << std::endl;
    std::cout << "Products offered by the restaurant:" << std::endl;
    for (size_t i = 0; i < restaurant.getProductListSize(); ++i) {
        std::cout << "  - " << restaurant.getProductList()[i].getString() << std::endl;
    }

    String orderProduct1("Pizza", 5);
    String orderProduct2("Pasta", 5);
    String orderProducts[] = { orderProduct1, orderProduct2 };

    Order order("FoodPlace", 2, orderProducts, 5);

    std::cout << "Order details:" << std::endl;
    order.printOrder();

    try {
        restaurant.receiveOrder(order);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    String newProduct("Salad", 5);
    restaurant.addNewProductToList(newProduct);

    std::cout << std::endl;

    std::cout << "Updated product list after adding a new product:" << std::endl;
    for (size_t i = 0; i < restaurant.getProductListSize(); ++i) {
        std::cout << "  - " << restaurant.getProductList()[i].getString() << std::endl;
    }

    String invalidOrderProduct("Sushi", 5);
    String invalidOrderProducts[] = { invalidOrderProduct };

    Order invalidOrder("FoodPlace", 1, invalidOrderProducts, 5);

    try {
        restaurant.receiveOrder(invalidOrder);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }*/

    String products[] = { String("Burger"), String("Fries"), String("Cola") };

    Restaurant myRestaurant("BestBurgers", products, 3, 5);

    Foodpanda app;
    Restaurant restaurantList[] = { myRestaurant };
    app.setRestaurants(restaurantList, 1, 3);

    String orderProducts[] = { String("Burger"), String("Cola") };

    Order myOrder("BestBurgers", 2, orderProducts, 4);

    try {
        app.addNewOrder(myOrder);
        std::cout << "Order added successfully!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Failed to add order: " << e.what() << std::endl;
    }

    return 0;
}