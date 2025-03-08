#include "Menu.h"

Menu::Menu()
{
    cout<<"object is created"<<endl;
}

// Load menu items from a file
void Menu::loadFromFile()
{
    ifstream inputFile;

    // Open the file
    inputFile.open("menu.txt");
    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file " << endl;
        return;
    }
    cout << "Loading" << endl;
    int id;
    string name, description;
    double price;

    while (inputFile >> id)
    {                       // Read ID
        inputFile.ignore(); // Ignore the comma after the ID

        getline(inputFile, name, ',');        // Read Name
        getline(inputFile, description, ','); // Read Description
        inputFile >> price;                   // Read Price

        inputFile.ignore(); // Ignore the newline character at the end of the line

        cout << name << endl;
        items.insertatend(MenuItem(id, name, description, price));
    }

    inputFile.close();
    cout << "Menu loaded successfully from " << endl;
}

// Save menu items to a file
void Menu::saveToFile() const
{
    ofstream outputFile;

    // Open the file
    outputFile.open("menu.txt");
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file " << endl;
        return;
    }

    // Write all menu items to the file
    for (int i = 0; i < items.getSize(); i++)
    {
        const MenuItem &item = items.getItem(i);
        outputFile << item.getId() << ","
                   << item.getName() << ","
                   << item.getDescription() << ","
                   << item.getPrice() << endl;
    }

    outputFile.close();
    cout << "Menu saved successfully to " << endl;
}

// Add a menu item
void Menu::addMenuItem()
{
    int id;
    string name, description;
    double price;

    cout << "Enter item ID: ";
    cin >> id;
    cin.ignore(); // Clear input buffer
    cout << "Enter item name: ";
    getline(cin, name);
    cout << "Enter item description: ";
    getline(cin, description);
    cout << "Enter item price: ";
    cin >> price;

    items.insertatend(MenuItem(id, name, description, price));
    cout << "Menu item added successfully!" << endl;
}

// Delete a menu item
void Menu::deleteMenuItem()
{
    int id;
    cout << "Enter the ID of the item to delete: ";
    cin >> id;

    items.erase(id);
    cout << "If the item existed, it has been deleted." << endl;
}

// Reset the menu
void Menu::resetMenu()
{
    items.clear();
    cout << "Menu has been reset!" << endl;
}

// Display all menu items
void Menu::displayMenu(ostream &out) const
{
    cout << "\n--- Menu ---" << endl;
    items.display(out);
}

MenuItem *Menu::getItems() const {
    return items.getItems();
}

MenuItem Menu::menuFindById(int index) const {
    return items.findById(index);
}

bool Menu::isEmpty() const {
    return items.empty();
}

ostream &operator<<(ostream &out, const Menu &menu)
{
    menu.displayMenu(out); 
    return out;
}
