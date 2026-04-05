//
// Created by ser09 on 28.02.2026.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "Order.h"
#include "Product.h"
#include "Customer.h"
#include "VIPCustomer.h"
#include "ElectronicProduct.h"
#include "FoodProduct.h"
#include "Item.h"
#include "StaticDemo.h"

vector<Product*> products;
vector<string> adminHistory;

void saveProducts() {
    ofstream file("products.txt");
    for(auto p : products) {
        if(auto e = dynamic_cast<ElectronicProduct*>(p)) {
            file << "E " << e->getName() << " " << e->getPrice() << " " << e->getWarranty() << endl;
        } else if(auto f = dynamic_cast<FoodProduct*>(p)) {
            file << "F " << f->getName() << " " << f->getPrice() << " " << f->getCalories() << endl;
        }
    }
}

void loadProducts() {
    ifstream file("products.txt");
    char type;
    string name;
    double price;
    while(file >> type >> name >> price) {
        if(type=='E') { int w; file >> w; products.push_back(new ElectronicProduct(name,price,w)); }
        else if(type=='F') { int c; file >> c; products.push_back(new FoodProduct(name,price,c)); }
    }
}

void saveAdminHistory(const string& action) {
    adminHistory.push_back(action);
    ofstream file("admin_history.txt", ios::app);
    file << action << endl;
}

void showProducts() {
    if(products.empty()) { cout << "No products available!" << endl; return; }
    for(int i=0;i<products.size();i++) {
        cout << i << ". ";
        products[i]->showInfo();
    }
}

void addProduct() {
    int type;
    cout << "1. Electronic\n2. Food\nChoice: "; cin >> type;

    string name; double price;
    cout << "Name: "; cin >> name;
    cout << "Price: "; cin >> price;

    if(type==1) {
        int w; cout << "Warranty months: "; cin >> w;
        products.push_back(new ElectronicProduct(name,price,w));
        saveAdminHistory("Admin added ElectronicProduct: " + name + " Price: " + to_string(price) + " Warranty: " + to_string(w));
    } else {
        int c; cout << "Calories: "; cin >> c;
        products.push_back(new FoodProduct(name,price,c));
        saveAdminHistory("Admin added FoodProduct: " + name + " Price: " + to_string(price) + " Calories: " + to_string(c));
    }
    saveProducts();
}

void buyProduct(const Customer& user) {
    try {
        if(products.empty()) throw runtime_error("No products to buy!");
        showProducts();
        int id, qty; cout << "Select product: "; cin >> id;
        if(id<0 || id>=products.size()) throw runtime_error("Invalid product ID!");
        cout << "Quantity: "; cin >> qty;
        double total = products[id]->getPrice()*qty;
        cout << "Total: " << total << endl;
    } catch(exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void adminMenu() {
    string password; cout << "Enter admin password: "; cin >> password;
    if(password!="1234") { cout << "Wrong password!\n"; return; }

    int ch;
    do {
        cout << "\n--- ADMIN MENU ---\n1.Add product\n2.Show products\n3.Show history\n0.Back\nChoice: ";
        cin >> ch;
        if(ch==1) addProduct();
        if(ch==2) showProducts();
        if(ch==3) {
            cout << "--- Admin history ---\n";
            for(const auto &entry : adminHistory) cout << entry << endl;
        }
    } while(ch!=0);
}

void userMenu() {
    string userName; cout << "Enter your name: "; cin >> userName;
    Customer currentUser(userName);
    int ch;
    do {
        cout << "\n--- USER MENU ---\n1.Show products\n2.Buy\n0.Back\nChoice: "; cin >> ch;
        if(ch==1) showProducts();
        if(ch==2) buyProduct(currentUser);
    } while(ch!=0);
}

int main() {
    loadProducts();
    int choice;
    do {
        cout << "\n1.Admin\n2.User\n0.Exit\nChoice: "; cin >> choice;
        if(choice==1) adminMenu();
        if(choice==2) userMenu();
    } while(choice!=0);
    return 0;
}