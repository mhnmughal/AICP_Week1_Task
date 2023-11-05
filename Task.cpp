#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_ITEMS = 13;
const int BASIC_ITEMS = 3;

string itemCodes[NUM_ITEMS] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3"};
string itemDescriptions[NUM_ITEMS] = {"Compact Case", "Tower Case", "8 GB RAM", "16 GB RAM", "32 GB RAM",
                                      "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD", "480 GB SSD",
                                      "1 TB HDD (2nd)", "2 TB HDD (2nd)", "4 TB HDD (2nd)"};
double itemPrices[NUM_ITEMS] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99};

void displayItems() {
    cout << "Category\tItem Code\tDescription\tPrice ($)" << endl;
    for (int i = 0; i < NUM_ITEMS; i++) {
        cout << char('A' + i) << i + 1 << "\t" << itemCodes[i] << "\t" << itemDescriptions[i] << "\t" << itemPrices[i] << endl;
    }
}

int main() {
    string caseChoice, ramChoice, hddChoice;
    double totalCost = 200.0;
    int numAdditionalItems = 0;

    cout << "Welcome to the Online Computer Shop!" << endl;
    cout << "Please choose one case, one RAM, and one Main Hard Disk Drive." << endl;

    displayItems();

    do {
        cout << "Case (Enter Item Code, e.g., A1): ";
        cin >> caseChoice;
    } while (caseChoice != "A1" && caseChoice != "A2");

    do {
        cout << "RAM (Enter Item Code, e.g., B1): ";
        cin >> ramChoice;
    } while (ramChoice != "B1" && ramChoice != "B2" && ramChoice != "B3");

    do {
        cout << "Main Hard Disk Drive (Enter Item Code, e.g., C1): ";
        cin >> hddChoice;
    } while (hddChoice != "C1" && hddChoice != "C2" && hddChoice != "C3");

    for (int i = 0; i < NUM_ITEMS; i++) {
        if (itemCodes[i] == caseChoice || itemCodes[i] == ramChoice || itemCodes[i] == hddChoice) {
            totalCost += itemPrices[i];
        }
    }

    cout << "You have chosen the following items:" << endl;
    cout << "Case: " << itemDescriptions[caseChoice[1] - '1'] << endl;
    cout << "RAM: " << itemDescriptions[ramChoice[1] - '1'] << endl;
    cout << "Main Hard Disk Drive: " << itemDescriptions[hddChoice[1] - '1'] << endl;

    char additionalChoice;
    do {
        cout << "Do you want to purchase additional items (Y/N)? ";
        cin >> additionalChoice;
        if (additionalChoice == 'Y' || additionalChoice == 'y') {
            displayItems();
            string additionalItemChoice;
            cout << "Enter the item code of the additional item you want to purchase: ";
            cin >> additionalItemChoice;
            for (int i = 0; i < NUM_ITEMS; i++) {
                if (itemCodes[i] == additionalItemChoice) {
                    totalCost += itemPrices[i];
                    numAdditionalItems++;
                }
            }
        }
    } while (additionalChoice == 'Y' || additionalChoice == 'y');

    cout << "Total Price: $" << fixed << setprecision(2) << totalCost << endl;

    // Task 3: Apply discounts
    if (numAdditionalItems == 1) {
        double discount = totalCost * 0.05;
        totalCost -= discount;
        cout << "You've received a 5% discount, saving $" << discount << endl;
    } else if (numAdditionalItems >= 2) {
        double discount = totalCost * 0.10;
        totalCost -= discount;
        cout << "You've received a 10% discount, saving $" << discount << endl;
    }

    cout << "Final Price (after discounts): $" << fixed << setprecision(2) << totalCost << endl;

    return 0;
}

