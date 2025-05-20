#include <iostream>
#include <string>
#include <limits> 
#include <cctype> 

using namespace std;

struct Address {
    string street;
    string city;
    string zipCode;
};


struct Customer {
    string name;
    Address address;
};


string getStringInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            cout << "Input cannot be empty. Please try again.\n";
        }
        else {
            break;
        }
    }
    return input;
}


string getZipCodeInput(const string& prompt) {
    string zipCode;
    while (true) {
        zipCode = getStringInput(prompt);
        if (zipCode.length() != 5) {
            cout << "Zip code must be 5 digits long. Please try again.\n";
        }
        else {
            bool allDigits = true;
            for (char c : zipCode) {
                if (!isdigit(c)) {
                    allDigits = false;
                    break;
                }
            }
            if (!allDigits) {
                cout << "Zip code must contain only digits. Please try again.\n";
            }
            else {
                break;
            }
        }
    }
    return zipCode;
}


Customer getCustomerInfo() {
    Customer customer;
    customer.name = getStringInput("Enter customer name: ");
    customer.address.street = getStringInput("Enter street address: ");
    customer.address.city = getStringInput("Enter city: ");
    customer.address.zipCode = getZipCodeInput("Enter zip code: ");
    return customer;
}

int main() {
    
    Customer customer = getCustomerInfo();

    
   cout << "\nCustomer Information:\n";
   cout << "Name: " << customer.name << std::endl;
   cout << "Address:\n";
   cout << "  Street: " << customer.address.street << std::endl;
   cout << "  City: " << customer.address.city << std::endl;
   cout << "  Zip Code: " << customer.address.zipCode << std::endl;

    return 0;
}
