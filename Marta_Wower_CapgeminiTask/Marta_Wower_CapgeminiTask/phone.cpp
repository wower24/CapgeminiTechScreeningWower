#include "phone.h"

Phone::Phone() {
	std::cout << "?";
}

Phone::Phone(std::string brandName, std::string modelName, std::string formFactor, int yearOfIssue, int screenSize, int price) {
	this->brandName = brandName;
	this->modelName = modelName;
	this->formFactor = formFactor;
	this->yearOfIssue = yearOfIssue;
	this->screenSize = screenSize;
	this->price = price;
	this->phoneID = phones.size() + 1;

	phones.push_back(*this);
}

std::string Phone::getBrandName() {
	return this->brandName;
}

std::string Phone::getFormFactor() {
	return this->formFactor;
}

int Phone::getScreenSize() {
	return this->screenSize;
}

int Phone::getPhoneID() {
	return this->phoneID;
}

std::string Phone::toString() {
	std::string phoneString = "";

	phoneString = "ID: " + std::to_string(this->phoneID) + "\n Brand Name: " + this->brandName + "\n  Model Name: " + this->modelName + "\n--------------------\n";

	return phoneString;

}

Phone::~Phone() {
	std::cout << "Phone deleted\n";
}

//template for finding maximum values for report 3 and 4
template <typename T> T findMax(std::vector<T> vec)
{
    std::map<T, int> counter;
    //load names into the map, anytime a name repeats increase the value
    for (T element : vec) {
        int value = 0;

        if (counter.count(element))
            value = counter.find(element)->second;

        counter.insert_or_assign(element, ++value);
    }
    int max = 0;
    std::pair<T, int> maxEntry;

    for (auto& entry : counter) {
        if (entry.second > max) {
            max = entry.second;
            maxEntry = entry;
        }
    }

    return maxEntry.first;
}

void addPhone() {
    std::string brandName;
    std::string modelName;
    std::string formFactor;
    int yearOfIssue;
    int screenSize;
    int price;

    std::cout << "Input brand name: ";
    getline(std::cin, brandName);
    std::cout << std::endl;
    std::cout << "Input model name: ";
    getline(std::cin, modelName);
    std::cout << std::endl;
    std::cout << "Input form factor: ";
    getline(std::cin, formFactor);
    std::cout << std::endl;
    std::cout << "Now please input the year of issue, screen size and price in one line, separated by spaces: ";
    std::cin >> yearOfIssue >> screenSize >> price;
    std::cout << std::endl;

    new Phone(brandName, modelName, formFactor, yearOfIssue, screenSize, price);
}

void deletePhone(int phoneID) {
    phones.erase(phones.begin() + phoneID);
}

void report(std::string brandName) {
    for (Phone phone : phones) {
        if (phone.getBrandName() == brandName)
            std::cout << phone.toString();
    }
}

void report(std::string formFactor, int screenSize) {
    for (Phone phone : phones) {
        if (phone.getFormFactor() == formFactor && phone.getScreenSize() == screenSize)
            std::cout << phone.toString();
    }
}

void report(std::vector<std::string> names) {
    std::cout << "The name of the brand with the maximum quantity of the phones is: " + findMax(names) << std::endl;
}

void report(std::vector<int> screenSizes) {
    std::cout << "TOP screen size is: " << findMax(screenSizes);
}

void report() {
    for (Phone phone : phones)
        std::cout << phone.toString();
}

