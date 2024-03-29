#include <iostream>
#include <utility>
#include <list>
#include <map>
#define clear system("cls")

std::map<std::string, std::list<std::pair<std::string, std::string>>> book;
std::list<std::string> favorites;

void showMenu() {
	std::cout << "1.Add a contact" << std::endl;
	std::cout << "2.Edit a contact" << std::endl;
	std::cout << "3.Remove a contact" << std::endl;
	std::cout << "4.Add a pair to a contact" << std::endl;
	std::cout << "5.Edit a pair of a contact" << std::endl;
	std::cout << "6.Remove a pair of a contact" << std::endl;
	std::cout << "7.Add a contact to favorites" << std::endl;
	std::cout << "8.Remove a contact from favorites" << std::endl;
	std::cout << "9.Change order in favorites" << std::endl;
	std::cout << "10.Show all contacts in alphabetical order" << std::endl;
	std::cout << "11.Show favorite contacts based on order that saved" << std::endl;
	std::cout << "12.Search a contact by beginning letters of his/her name" << std::endl;
	std::cout << "\n\n\n";
}

void addContact() {
	std::list<std::pair<std::string, std::string>> tempList;
	std::pair<std::string, std::string> tempPair;
	std::string name;
	int count;

	std::cout << "Enter Name : ";
	std::cin >> name;

	std::cout << "How many numbers does he/she have? ";
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
	std::cout << "Enter name of contact that should be edited : ";
	std::string name;
	std::cin >> name;

	std::string label, number;
	std::cout << "Enter label : ";
	std::cin >> label;
	std::cout << "Enter number : ";
	std::cin  >> number;

	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator tempIterator = book.find(name);

	if (tempIterator == book.end())
		return;

	std::list<std::pair<std::string, std::string>>& tempList = tempIterator->second;
	for(auto it = tempList.begin(); it != tempList.end(); ++it)
    {
        if(it->first == label && it->second == number)
        {
            it = tempList.erase(it);
            return;
        }
        std::advance(it, 1);
    }

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
		if (name == *tempIterator)
			tempIterator = favorites.erase(tempIterator);   // if we don't do that we will get unexpected errors
		std::advance(tempIterator, 1);
	}
}

void swapFavorites() {
	std::string name1, name2;
	std::list<std::string>::iterator tempIterator = favorites.begin();
	std::list<std::string>::iterator tempIterator2 = favorites.begin();

	std::cout << "Enter first Name : ";
	std::cin >> name1;
	std::cout << "Enter second Name : ";
	std::cin >> name2;

	while (tempIterator != favorites.end()) {
		if (name1 == *tempIterator)
			break;
		std::advance(tempIterator, 1);
	}

	while (tempIterator2 != favorites.end()) {
		if (name2 == *tempIterator2)
			break;
		std::advance(tempIterator2, 1);
	}

	if (tempIterator == favorites.end() || tempIterator2 == favorites.end()) {
		std::cout << "Wrong inputs!" << std::endl;
		return;
	}

	*tempIterator = name2;
	*tempIterator2 = name1;
}

void showContacts() {
	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator tempIterator = book.begin();

	while (tempIterator != book.end()) {
		std::cout << "name : " << std::endl << tempIterator->first << " numbers : " << std::endl;
		std::list<std::pair<std::string, std::string>> tempList = tempIterator->second;
		std::list<std::pair<std::string, std::string>>::iterator listIterator = tempList.begin();
		while (listIterator != tempList.end()) {
			std::cout << "Type : " << listIterator->first << " number : " << listIterator->second << std::endl;
			std::advance(listIterator, 1);
		}
		std::advance(tempIterator, 1);
	}
}

void showFavorites() {
	std::string name;
	std::list<std::string>::iterator favoriteIterator = favorites.begin();
	while (favoriteIterator != favorites.end()) {
		std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator tempIterator = book.begin();
		name = *favoriteIterator;
		while (tempIterator != book.end()) {
			if (name == tempIterator->first)
				break;
			std::advance(tempIterator, 1);
		}

		if (tempIterator == book.end()){
			std::advance(favoriteIterator, 1);
			continue;
		}

		std:: cout << name << std::endl;
		std::cout << "numbers : " << std::endl;
		std::list<std::pair<std::string, std::string>>::iterator listIterator = (tempIterator->second).begin();
		while (listIterator != (tempIterator->second).end()) {
			std::cout << "Type : " << listIterator->first << " number : " << listIterator->second << std::endl;
			std::advance(listIterator, 1);
		}

		std::advance(favoriteIterator, 1);
	}
}

void searchContact() {
	std::string input;
	std::cout << "Enter the string : ";
	std::cin >> input;

	std::map<std::string, std::list<std::pair<std::string, std::string>>>::iterator tempIterator = book.begin();
	while (tempIterator != book.end()) {
		if ((tempIterator->first).find(input) == 0 && (tempIterator->first)[0] == input[0]) {		//because i think default of that function is also 0
			std::cout << tempIterator->first << std::endl;
			std::cout << "numbers : " << std::endl;
			std::list<std::pair<std::string, std::string>>::iterator listIterator = (tempIterator->second).begin();
			while (listIterator != (tempIterator->second).end()) {
				std::cout << "Type : " << listIterator->first << " number : " << listIterator->second << std::endl;
				std::advance(listIterator, 1);
			}

		}
		std::advance(tempIterator, 1);
	}

}

int main() {
	//simple temorary phone book project
	std::string input;
	showMenu();

	while (true) {
		std::cin >> input;
		clear;

		if (input == "1") {
			addContact();
		}
		else if (input == "2") {
			editContact();
		}
		else if (input == "3") {
			removeContact();
		}
		else if (input == "4") {
			addPair();
		}
		else if (input == "5") {
			editPair();
		}
		else if (input == "6") {
			removePair();
		}
		else if (input == "7") {
			addFavorite();
		}
		else if (input == "8") {
			removeFavorite();
		}
		else if (input == "9") {
			swapFavorites();
		}
		else if (input == "10") {
			showContacts();
            getchar();  //  '\n'
			getchar();  //  pause
		}
		else if (input == "11") {
			showFavorites();
            getchar();  //  '\n'
			getchar();  //  pause
		}
		else if (input == "12") {
			searchContact();
            getchar();  //  '\n'
			getchar();  //  pause
		}

		clear;
		showMenu();
	}

	return 0;
}
