#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item {
public:

    string name;
    int quantity = 1;
    bool isChecked = false;
    string check = "{Unchecked}";

    void checkUncheck() {
        if (isChecked == true) {
            isChecked = false;
            check = "{Unchecked}";
        }
        else {
            isChecked = true;
            check = "{Checked}";
        }
    }
};

class List {
public:

    vector<Item> items;
    string name;

    void addItem(string name1, int amount1) {
        Item tempitem;
        tempitem.name = name1;
        tempitem.quantity = amount1;
        items.push_back(tempitem);
    };

    void deleteItem(int itemId) {
        items.erase(items.begin() + itemId);
    }
};

vector<List> lists;

bool printLists() {

    if (lists.size() == 0) {
        int exit;
        cout << "You don't have a list yet!" << endl;
        cout << "Please press 9 to go back" << endl;
        cin >> exit;
        return false;
    }
    else {
        for (int i = 0; i < lists.size(); i++) {
            cout << i + 1 << " - " << lists[i].name << endl;
        }
        cout << endl;
        return true;
    }
}

bool printItems(List list) {

    int exit;

    if (list.items.size() == 0) {
        cout << "You don't have an item yet!" << endl;
        cout << "Please press 9 to go back" << endl;
        cin >> exit;
        return false;
    }
    else {
        for (int i = 0; i < list.items.size(); i++) {
            cout << i + 1 << " - " << list.items[i].name << "   " << list.items[i].quantity << "   " << list.items[i].check << endl;
        }
        cout << endl;
        return true;
    }
}

int main() {

    bool isExited = false;

    do {

        system("cls");

        cout << "Welcome to your shopping list application. Choose an operation." << endl;
        cout << "To create a list, please press 1." << endl << "To edit a list, please press 2." << endl << "To delete a list, please press 3." << endl;
        cout << "To check or uncheck an item, please press 4." << endl << "To view a list, please press 5." << endl;
        cout << "To leave the application, please press 9." << endl;

        int menu;
        int listId;
        int exit;
        char x = '0';
        string templist_name = "";
        List templist;
        cin >> menu;
        switch (menu) {
        case 1:

            cout << "Enter list name: ";
            cin.ignore();
            getline(cin, templist_name);
            templist.name = templist_name;
            lists.push_back(templist);
            break;

        case 2:

            cout << "Enter the number of the list that you want to edit" << endl;
            printLists();
            cin >> listId;
            if (listId > lists.size()) {
                cout << "Ooops. Couldn't find the list that you are looking for. Please press 9 to go back and try again." << endl;
                cin >> exit;
                break;
            }
            else {
                cout << "To add an item, please press 1" << endl << "To delete an item, please press 2" << endl;
                cout << "To edit an item, press 3" << endl << "To rename the list, please press 4." << endl << "To exit editing, please press 9" << endl;
                int operation_item;  cin >> operation_item;
                if (operation_item == 1) {
                    cout << "Enter name: ";
                    string tempname;
                    cin.ignore();
                    getline(cin, tempname);
                    cout << endl;
                    cout << "Enter amount: ";
                    int tempamount; cin >> tempamount; cout << endl;
                    lists[listId - 1].addItem(tempname, tempamount);
                }
                else if (operation_item == 2) {
                    if (printItems(lists[listId - 1])) {
                        cout << "Enter the number of an item to delete" << endl;
                        int deleteItemId;
                        cin >> deleteItemId;
                        if (deleteItemId > lists[listId - 1].items.size()) {
                            cout << "Ooops. Couldn't find the list that you are looking for. Please press 9 to go back and try again." << endl;
                            cin >> exit;
                            break;
                        }
                        else {
                            lists[listId - 1].deleteItem(deleteItemId - 1);
                            cout << "Item deleted. Please press 9 to go back." << endl;
                            cin >> exit;
                        }
                    }
                }
                else if (operation_item == 3) {
                    if (printItems(lists[listId - 1])) {
                        cout << "Enter the number of an item to edit: ";
                        int ItemId;
                        cin >> ItemId;
                        if (ItemId > lists.size()) {
                            cout << "Ooops. Couldn't find the list that you are looking for. Please press 9 to go back and try again." << endl;
                            cin >> exit;
                            break;
                        }
                        else {
                            cout << "To edit name, press 1." << endl << "To edit, amount press 2." << endl;
                            int operationEdit;
                            cin >> operationEdit;
                            if (operationEdit == 1) {
                                cout << "Enter name: ";
                                string editName;
                                cin >> editName;
                                lists[listId - 1].items[ItemId - 1].name = editName;
                            }
                            else if (operationEdit == 2) {
                                cout << "Enter amount: ";
                                int editAmount;
                                cin >> editAmount;
                                lists[listId - 1].items[ItemId - 1].quantity = editAmount;
                            }
                        }
                    }
                }
                else if (operation_item == 4) {
                    string newName;
                    cout << "Enter the new name: ";
                    cin.ignore();
                    getline(cin, newName);
                    lists[listId - 1].name = newName;
                    break;
                }
                else if (operation_item == 9) {
                    break;
                }
                break;
            }

        case 3:

            if (printLists()) {
                cout << "Enter the number of the list to delete: ";
                cin >> listId;
                if (listId > lists.size()) {
                    cout << "Ooops. Couldn't find the list that you are looking for. Please press 9 to go back and try again." << endl;
                    cin >> exit;
                    break;
                }
                else {
                    lists.erase(lists.begin() + listId - 1);
                    break;
                }
            }
            else
                break;

        case 4:

            if (printLists()) {
                cout << "Enter the number of the list that contains the item that you want to check or uncheck: ";
                cin >> listId;
                if (listId > lists.size()) {
                    cout << "Ooops. Couldn't find the list that you are looking for. Please press 9 to go back and try again." << endl;
                    cin >> exit;
                    break;
                }
                else {
                    if (printItems(lists[listId - 1])) {
                        cout << "Enter the number of the item that you want to check or uncheck: ";
                        int itemId;
                        cin >> itemId;
                        if (itemId > lists[listId - 1].items.size()) {
                            cout << "Ooops. Couldn't find the item that you are looking for. Please press 9 to go back and try again." << endl;
                            cin >> exit;
                            break;
                        }
                        else {
                            lists[listId - 1].items[itemId - 1].checkUncheck();
                        }
                    }
                    break;
                }
            }
            else
                break;

        case 5:

            if (printLists()) {
                cout << "Enter the number of the list that you want to view: ";
                cin >> listId;
                if (listId > lists.size()) {
                    cout << "Ooops. Couldn't find the list that you are looking for. Please press 9 to go back and try again." << endl;
                    cin >> exit;
                    break;
                }
                else {
                    printItems(lists[listId - 1]);
                    if (lists[listId - 1].items.size() != 0) {
                        cout << "Please press 9 to go back." << endl;
                        cin >> exit;
                    }
                    break;
                }
            }
            else
                break;

        case 9:
            isExited = true;
            cout << "Have a nice, healthy day!";
        }
    } while (isExited == !true);
    return 0;
}