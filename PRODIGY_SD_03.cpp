#include <iostream>
#include<bits/stdc++.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string emailAddress;
};

// Function prototypes
void addContact(std::vector<Contact>& contacts);
void viewContacts(const std::vector<Contact>& contacts);
void editContact(std::vector<Contact>& contacts);
void deleteContact(std::vector<Contact>& contacts);
void saveContactsToFile(const std::vector<Contact>& contacts, const std::string& filename);
void loadContactsFromFile(std::vector<Contact>& contacts, const std::string& filename);

int main() {
    std::vector<Contact> contacts;
    std::string filename = "contacts.txt"; // Change the filename as needed

    loadContactsFromFile(contacts, filename);

    int choice;

    do {
        // Display menu
        cout << "\nContact Management System\n";
        cout << "1. Add a new contact\n";
        cout << "2. View contacts\n";
        cout << "3. Edit a contact\n";
        cout << "4. Delete a contact\n";
        cout << "5. Save and Exit\n";\
        cout<<endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                saveContactsToFile(contacts, filename);
                cout<<endl;
                cout << "Contacts saved. Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter the contact's name: ";
    cin.ignore(); // Ignore any newline characters in the buffer
    getline(std::cin, newContact.name);
    cout << "Enter the contact's phone number: ";
    cin >> newContact.phoneNumber;
    cout << "Enter the contact's email address: ";
    cin >> newContact.emailAddress;

    contacts.push_back(newContact);
    cout<<endl;
    cout << "Contact added successfully.\n";
}

void viewContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout<<endl;
        cout << "No contacts available.\n";
    } else {
        cout << "\nContact List:\n";
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << "\n";
            cout << "Phone Number: " << contact.phoneNumber << "\n";
            cout << "Email Address: " << contact.emailAddress << "\n";
            cout << "----------------------\n";
        }
    }
}

void editContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts available to edit.\n";
        return;
    }

    string searchName;
    cout << "Enter the name of the contact to edit: ";
    cin.ignore(); // Ignore any newline characters in the buffer
    getline(std::cin, searchName);

    for (auto& contact : contacts) {
        if (contact.name == searchName) {
            cout << "Enter the new phone number: ";
            std::cin >> contact.phoneNumber;
            cout << "Enter the new email address: ";
            cin >> contact.emailAddress;
            cout << "Contact edited successfully.\n";
            return;
        }
    }

    std::cout << "Contact not found.\n";
}

void deleteContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts available to delete.\n";
        return;
    }

    std::string searchName;
    std::cout << "Enter the name of the contact to delete: ";
    std::cin.ignore(); // Ignore any newline characters in the buffer
    std::getline(std::cin, searchName);

    auto it = std::remove_if(contacts.begin(), contacts.end(),
                             [searchName](const Contact& contact) { return contact.name == searchName; });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted successfully.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

void saveContactsToFile(const std::vector<Contact>& contacts, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto& contact : contacts) {
        outputFile << contact.name << ',' << contact.phoneNumber << ',' << contact.emailAddress << '\n';
    }

    outputFile.close();
}

void loadContactsFromFile(std::vector<Contact>& contacts, const std::string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "File not found. Creating a new file for contacts.\n";
        return;
    }

    Contact contact;
    while (getline(inputFile, contact.name, ',') &&
           getline(inputFile, contact.phoneNumber, ',') &&
           getline(inputFile, contact.emailAddress)) {
        contacts.push_back(contact);
    }

    inputFile.close();
}
