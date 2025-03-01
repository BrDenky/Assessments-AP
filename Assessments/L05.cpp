#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>

// =======================
// Inventory Management (std::map)
// =======================
void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

void addProduct(std::map<std::string, int>& inventory, const std::string& productName, int quantity) {
    if (inventory.find(productName) == inventory.end()) {
        inventory[productName] = quantity;
        std::cout << "Added product: " << productName << " with quantity: " << quantity << std::endl;
    } else {
        std::cout << "Product '" << productName << "' already exists. Use updateProduct to modify its quantity." << std::endl;
    }
}

void updateProduct(std::map<std::string, int>& inventory, const std::string& productName, int quantity) {
    if (inventory.find(productName) != inventory.end()) {
        inventory[productName] = quantity;
        std::cout << "Updated product: " << productName << " to new quantity: " << quantity << std::endl;
    } else {
        std::cout << "Product '" << productName << "' not found. Use addProduct to add it first." << std::endl;
    }
}

// =======================
// Category Management (std::set)
// =======================
void displayCategories(const std::set<std::string>& categories) {
    std::cout << "Product Categories:\n";
    for (const auto& category : categories) {
        std::cout << "- " << category << "\n";
    }
    std::cout << std::endl;
}

void addCategory(std::set<std::string>& categories, const std::string& categoryName) {
    if (categories.find(categoryName) == categories.end()) {
        categories.insert(categoryName);
        std::cout << "Added category: " << categoryName << std::endl;
    } else {
        std::cout << "Category '" << categoryName << "' already exists." << std::endl;
    }
}

// =======================
// Order Management (std::queue)
// =======================
void addOrder(std::queue<std::string>& orders, const std::string& order) {
    orders.push(order);
    std::cout << "Added order: " << order << std::endl;
}

void processOrder(std::queue<std::string>& orders) {
    if (!orders.empty()) {
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    } else {
        std::cout << "No orders to process." << std::endl;
    }
}

void processAllOrders(std::queue<std::string>& orders) {
    std::cout << "Processing all orders:" << std::endl;
    while (!orders.empty()) {
        processOrder(orders);
    }
    std::cout << std::endl;
}

// =======================
// Restock Management (std::stack)
// =======================
void addRestockBatch(std::stack<std::pair<std::string, int>>& restocks, const std::string& product, int quantity) {
    restocks.push({product, quantity});
    std::cout << "Added restock batch for " << product << " with quantity " << quantity << std::endl;
}

void processRestockBatch(std::stack<std::pair<std::string, int>>& restocks) {
    if (!restocks.empty()) {
        auto batch = restocks.top();
        std::cout << "Processing restock: " << batch.second << " units of " << batch.first << std::endl;
        restocks.pop();
    } else {
        std::cout << "No restock batches to process." << std::endl;
    }
}

void processAllRestocks(std::stack<std::pair<std::string, int>>& restocks) {
    std::cout << "Processing all restock batches:" << std::endl;
    while (!restocks.empty()) {
        processRestockBatch(restocks);
    }
    std::cout << std::endl;
}

// =======================
// Customer Cart Management (std::vector)
// =======================
void addItemToCart(std::vector<std::string>& cart, const std::string& item) {
    cart.push_back(item);
    std::cout << "Added to cart: " << item << std::endl;
}

void displayCart(const std::vector<std::string>& cart) {
    std::cout << "Items in customer cart:\n";
    for (const auto& item : cart) {
        std::cout << "- " << item << "\n";
    }
    std::cout << std::endl;
}

int main() {
    // -----------------------
    // Inventory Management
    // -----------------------
    std::map<std::string, int> inventory;
    addProduct(inventory, "Laptop", 5);
    addProduct(inventory, "Mouse", 20);
    addProduct(inventory, "Keyboard", 10);
    displayInventory(inventory);
    
    // Attempt to add duplicate product and update quantity
    addProduct(inventory, "Laptop", 3);
    updateProduct(inventory, "Laptop", 8);
    displayInventory(inventory);

    // -----------------------
    // Category Management
    // -----------------------
    std::set<std::string> productCategories;
    addCategory(productCategories, "Electronics");
    addCategory(productCategories, "Accessories");
    addCategory(productCategories, "Peripherals");
    displayCategories(productCategories);
    
    // Attempt to add duplicate category
    addCategory(productCategories, "Electronics");

    // -----------------------
    // Order Management
    // -----------------------
    std::queue<std::string> orders;
    addOrder(orders, "Order#1: Laptop");
    addOrder(orders, "Order#2: Mouse");
    addOrder(orders, "Order#3: Keyboard");
    processAllOrders(orders);

    // -----------------------
    // Restock Management
    // -----------------------
    std::stack<std::pair<std::string, int>> restocks;
    addRestockBatch(restocks, "Mouse", 10);
    addRestockBatch(restocks, "Laptop", 2);
    addRestockBatch(restocks, "Keyboard", 5);
    processAllRestocks(restocks);

    // -----------------------
    // Customer Cart Management
    // -----------------------
    std::vector<std::string> customerCart;
    addItemToCart(customerCart, "Laptop");
    addItemToCart(customerCart, "Mouse");
    addItemToCart(customerCart, "Keyboard");
    displayCart(customerCart);

    return 0;
}
