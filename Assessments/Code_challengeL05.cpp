#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>

// Task 1: Managing Products with std::map
// - Adds products with quantities, updates them, and displays the inventory.
void manageInventory() {
    std::map<std::string, int> inventory;
    // Adding or updating products
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 20;
    inventory["Keyboard"] = 10;
    
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

// Task 2: Tracking Unique Product Categories with std::set
// - Adds unique categories and displays them.
void trackCategories() {
    std::set<std::string> productCategories;
    productCategories.insert("Electronics");
    productCategories.insert("Accessories");
    productCategories.insert("Peripherals");
    
    std::cout << "Product Categories:\n";
    for (const auto& category : productCategories) {
        std::cout << "- " << category << "\n";
    }
    std::cout << std::endl;
}

// Task 3: Processing Orders with std::queue
// - Uses FIFO ordering to process customer orders.
void processOrders() {
    std::queue<std::string> orders;
    orders.push("Order#1: Laptop");
    orders.push("Order#2: Mouse");
    orders.push("Order#3: Keyboard");
    
    std::cout << "Processing Orders:\n";
    while (!orders.empty()) {
        std::cout << "Processing " << orders.front() << "\n";
        orders.pop();
    }
    std::cout << std::endl;
}

// Task 4: Handling Restocks with std::stack
// - Uses LIFO ordering to manage restock batches.
void processRestocks() {
    std::stack<std::pair<std::string, int>> restocks;
    restocks.push({"Mouse", 10});
    restocks.push({"Laptop", 2});
    restocks.push({"Keyboard", 5});
    
    std::cout << "Processing Restocks:\n";
    while (!restocks.empty()) {
        auto item = restocks.top();
        std::cout << "Restocking " << item.second << " units of " << item.first << "\n";
        restocks.pop();
    }
    std::cout << std::endl;
}

// Task 5: Storing Customer Purchases with std::vector
// - Adds items to a customer’s cart and displays them.
void customerPurchases() {
    std::vector<std::string> customerCart;
    customerCart.push_back("Laptop");
    customerCart.push_back("Mouse");
    customerCart.push_back("Keyboard");
    
    std::cout << "Customer Cart:\n";
    for (const auto& item : customerCart) {
        std::cout << "- " << item << "\n";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "C++ Inventory Management System Demo\n";
    std::cout << "-------------------------------------\n\n";
    
    // Demonstrate each task:
    manageInventory();
    trackCategories();
    processOrders();
    processRestocks();
    customerPurchases();
    
    return 0;
}
