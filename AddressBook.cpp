#include <iostream>
#include <string>

using namespace std;

struct AddressBook
{
	string name;
	string surname;
	long long int phone;
	AddressBook* next;
};

void delPerson(AddressBook*& head, string pName)
{
	if (head == NULL)
	{
		cout << "There are no persons in my book\n";
	}
	else
	{
		AddressBook* temp = head;
		AddressBook* curr = NULL;
		while (temp != NULL)
		{
			if (temp->name == pName)
			{
				break;
			}
			else
			{
				curr = temp;
				temp = temp->next;
			}
		}
		if (temp == NULL)
		{
			cout << "There are no person with this name\n";
		}
		else
		{
			if (temp == head)
			{
				head = head->next;
				delete temp;
			}
			else
			{
				curr->next = temp->next;
				delete temp;
			}
			cout << pName << " was deleted from the book\n";
		}
	}
}

void display(AddressBook* head)
{
	if (head == NULL)
	{
		cout << "My book is empty\n";
	}
	else
	{
		AddressBook* temp = head;
		while (temp != NULL)
		{
			cout << endl;
			cout << "Name: " << temp->name << endl;
			cout << "Surname: " << temp->surname << endl;
			cout << "Phone: " << temp->phone << endl;
			temp = temp->next;
		}
	}
}

void search(AddressBook* head, string pName)
{
	if (head == NULL)
	{
		cout << "My book is empty\n";
	}
	else
	{
		AddressBook* temp = head;
		while (temp != NULL)
		{
			if (temp->name == pName)
			{
				cout << temp->name << " is found\n\n";
				cout << "Name: " << temp->name << endl;
				cout << "Surname: " << temp->surname << endl;
				cout << "Phone: " << temp->phone << endl;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		if (temp == NULL)
		{
			cout << pName << " isn't found in my book\n";
		}
	}
}

void delMemory(AddressBook* head)
{
	while (head != NULL)
	{
		AddressBook* temp = head;
		head = head->next;
		delete temp;
	}
}


int main()
{
	cout << "=============== My Address Book ===============\n\n";
	cout << "1. To add person\n";
	cout << "2. To display all\n";
	cout << "3. To delete person\n";
	cout << "4. To search person\n";
	cout << "5. Exit\n";

	AddressBook* head = NULL;
	string pName;
	string sName;
	long long int pPhone;
	int choice = 0;

	while (true)
	{
		cin >> choice;
		switch (choice)
		{
		case 1: while (true)
		{
			cin.ignore();
			cout << endl;
			cout << "Enter the name(press '0' to end): ";
			getline(cin, pName);
			if (pName == "0")break;
			cout << "Enter surname: ";
			getline(cin, sName);
			cout << "Enter phone: ";
			cin >> pPhone;
			AddressBook* bleah = new AddressBook;
			bleah->name = pName;
			bleah->surname = sName;
			bleah->phone = pPhone;
			bleah->next = NULL;

			if (head == NULL)
			{
				head = bleah;
			}
			else
			{
				AddressBook* temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = bleah;
			}
		}
				break;
		case 2: display(head);
			break;
		case 3: cin.get();
			cout << "Enter the name: ";
			getline(cin, pName);
			delPerson(head, pName);
			break;
		case 4: cin.get();
			cout << "Enter the name: ";
			getline(cin, pName);
			search(head, pName);
			break;
		case 5: return 0;
		default: return 0;
		}
		cout << "=============== My Address Book ===============\n\n";
		cout << "1. To add person\n";
		cout << "2. To display all\n";
		cout << "3. To delete person\n";
		cout << "4. To search person\n";
		cout << "5. Exit\n";
		cout << endl;
	}

	delMemory(head);

	return 0;
}
