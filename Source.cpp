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

int main() {
	//simple temorary phone book project
	std::string input;
	showMenu();

	return 0;
}