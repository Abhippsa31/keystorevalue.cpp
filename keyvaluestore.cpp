#include <iostream>
#include <map>
#include <string>
using namespace std;

// Base class for the key-value store
class KeyValueStore 
{
protected:
  map< string, string> data;

public:
    // Function to store a key-value pair
    void storeValue(const string& key, const string& value)
    {
        data[key] = value;
        cout << "Stored: " << key << " = " << value << endl;
    }

    // Function to retrieve the value associated with a key
string retrieveValue(const string& key) 
    {
        if (data.find(key) != data.end()) 
        {
            return data[key];
        } else 
        {
            return "Key not found";
        }
    }

    // Function to delete a key-value pair
    void deleteValue(const std::string& key) 
    {
        if (data.find(key) != data.end()) 
        {
            data.erase(key);
            cout << "Deleted: " << key <<endl;
        } 
        else 
        {
            cout << "Key not found, nothing to delete" << endl;
        }
    }
};

// Derived class to enhance the key-value store with additional functionality
class EnhancedKeyValueStore : public KeyValueStore 
{
public:
    // Function to clear all data
    void clearData() 
    {
        data.clear();
cout << "All data cleared." << endl;
    }
};

int main() 
{
    int choice;
    string key, value;

    // Create an instance of the EnhancedKeyValueStore
    EnhancedKeyValueStore store;

    while (true) 
    {
cout << "Key-Value Store Menu:" << endl;
        cout << "1. Store a key-value pair" << endl;
        cout << "2. Retrieve a value by key" << endl;
        cout << "3. Delete a key-value pair" << endl;
        cout << "4. Clear all data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                store.storeValue(key, value);
                break;

            case 2:
                cout << "Enter key to retrieve: ";
                cin >> key;
                cout << "Value: " << store.retrieveValue(key) <<endl;
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                store.deleteValue(key);
                break;

            case 4:
                store.clearData();
                break;

            case 5:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
