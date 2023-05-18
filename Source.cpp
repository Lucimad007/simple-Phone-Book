#include <iostream>
#include <utility>
#include <list>
#include <map>
#define clear system("cls")

std::map<std::string ,std::list<std::pair<std::string, std::string>>> book;
std::list<std::string> favorites;

void showMenu() {
	std::cout << "1.Add a contact" << std::endl;
	std::cout << "2.Edit a contact" << std::endl;
	std::cout << "3.Remove a contact" << std::endl;
	std::cout << "4.Add a pair to a contact" << std::endl;
	std::cout << "5.Edit a pair to a contact" << std::endl;
	std::cout << "6.Remove a pair to a contact" << std::endl;
	std::cout << "7.Add a contact to favorites" << std::endl;
	std::cout << "8.Remove a contact from favorites" << std::endl;
	std::cout << "9.Change order in favorites" << std::endl;
	std::cout << "10.Show all contacts in alphabetical order";
	std::cout << "11.Show favorite contacts based on order that saved" << std::endl;
	std::cout << "12.Search a contact by beggining letters of his/her name" << std::endl;
	std::cout << "\n\n\n";
}


void addContact() {
	std::list<std::pair<std::string, std::string>> tempList;
	std::pair<std::string, std::string> tempPair;
	std::string name;
	int count;

	std::cout << "Enter Name : ";
	std::cin >> name;
	
	std::cout << "How many number does he/she have? ";
	std::cin >> count;
	while (count){
		std::cout << "Enter Label : ";
		std::cin >> tempPair.first;
		std::cout << "Enter Numer : ";
		std::cin >> tempPair.second;
		std::list<std::pair<std::string, std::string>>::iterator tempIterator = tempList.end();
		tempList.insert(tempIterator, tempPair);
		count--;
	}

	std::pair<std::string, std::list<std::pair<std::string, std::string>>> myPair = { name , tempList };
	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator tempIterator = book.end();
	book.insert(tempIterator, myPair);
}

void editContact() {
	std::list<std::pair<std::string, std::string>> tempList;
	std::pair<std::string, std::string> tempPair;
	std::cout << "Enter name of contact that should be edited : ";
	std::string name;
	std::cin >> name;
	int count = 0;

	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator myIterator = book.find(name);

	if (myIterator == book.end())
		return;

	std::cout << "How many number does he/she have? ";
	std::cin >> count;
	while (count) {
		std::cout << "Enter Label : ";
		std::cin >> tempPair.first;
		std::cout << "Enter Numer : ";
		std::cin >> tempPair.second;
		std::list<std::pair<std::string, std::string>>::iterator tempIterator = tempList.end();
		tempList.insert(tempIterator, tempPair);
		count--;
	}

	myIterator->second = tempList;
}

void removeContact() {
	std::cout << "Enter name of contact that should be deleted : ";
	std::string name;
	std::cin >> name;
	book.erase(name);
}

void addPair() {
	std::list<std::pair<std::string, std::string>> tempList;
	std::pair<std::string, std::string> tempPair;
	std::cout << "Enter name of contact that should be edited : ";
	std::string name;
	std::cin >> name;
	int count = 0;

	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator myIterator = book.find(name);

	if (myIterator == book.end())
		return;

	tempList = myIterator->second;
	std::cout << "How many number do you want to add? ";
	std::cin >> count;
	while (count) {
		std::cout << "Enter Label : ";
		std::cin >> tempPair.first;
		std::cout << "Enter Numer : ";
		std::cin >> tempPair.second;
		std::list<std::pair<std::string, std::string>>::iterator tempIterator = tempList.end();
		tempList.insert(tempIterator, tempPair);
		count--;
	}

	myIterator->second = tempList;
}

void editPair() {
	editContact();
}

void removePair() {
	std::list<std::pair<std::string, std::string>> tempList;
	std::cout << "Enter name of contact that should be edited : ";
	std::string name;
	std::cin >> name;

	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator tempIterator = book.find(name);

	if (tempIterator == book.end())
		return;

	tempIterator->second = tempList;	//this list is empty
}

void addFavorite() {
	std::cout << "Enter name of contact that should be edited : ";
	std::string name;
	std::cin >> name;
	favorites.insert(favorites.end(), name);		//we can also find his/her info in our map
	std::cout << "added!" << std::endl;
}

void removeFavorite() {
	std::cout << "Enter name of contact that should be edited : ";
	std::string name;
	std::cin >> name;
	std::list<std::string>::iterator tempIterator = favorites.begin();

	while (tempIterator != favorites.end()) {
		if(name == *tempIterator)
			favorites.erase(tempIterator);
		std::advance(tempIterator, 1);
	}
}


int main() {
	//simple temorary phone book project
	std::string input;
	showMenu();

	return 0;
}