#include "apartment.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdexcept> // Добавлен заголовочный файл для работы с исключениями

using namespace std;
namespace apartment {

	Owner::Owner(const std::string& fio, std::string& name)
		: fio(fio), name(name) {}

	std::string Owner::GetFIO_OWNER() const {
		return fio;
	}

	std::string Owner::GetNAME_OWNER() const {
		return name;
	}

	int Owner::GetTotalOwners() {  // Статический метод для получения общего числа владельцев
		return totalOwners;
	}


	Flat::Flat(const std::string& street, int num_flat, int kol_rooms, int square)
		: street(street), num_flat(num_flat), kol_rooms(kol_rooms), square(square) {}

	std::string Flat::GetSTREET() const {
		return street;
	}

	int Flat::GetNUM_FLAT() const {
		return num_flat;
	}

	int Flat::GetKOL_ROOMS() const {
		return kol_rooms;
	}

	int Flat::GetSQUARE() const {
		return square;
	}


	Concierge::Concierge(const std::string& concierge_fio, std::string& concierge_name)
		: concierge_fio(concierge_fio), concierge_name(concierge_name) {}

	std::string Concierge::GetFIO_CONCIERGE() const {
		return concierge_fio;
	}

	std::string Concierge::GetNAME_CONCIERGE() const {
		return concierge_name;
	}


	Doorway::Doorway(const int num_doorway, int kol_flat)
		: num_doorway(num_doorway), kol_flat(kol_flat) {}

	int Doorway::GetNUM_DOORWAY() const {
		return num_doorway;
	}

	int Doorway::GetKOl_FLAT() const {
		return kol_flat;
	}

	House::House(const std::string& street, int num_house, int kol_rezidents)
		: street(street), num_house(num_house), kol_rezidents(kol_rezidents) {}

	House::House(const Flat& flat, int num_house, int kol_rezidents)
		: street(flat.GetSTREET()), num_house(num_house), kol_rezidents(kol_rezidents) {}

	std::string House::GetSTREET() const {
		return street;
	}

	int House::GetNUM_HOUSE() const {
		return num_house;
	}

	int House::GetKOL_REZIDENTS() const {
		return kol_rezidents;
	}


	//////////////////////////////////////////////////////////


	ApartmentDataBase::ApartmentDataBase() {}
	ApartmentDataBase::~ApartmentDataBase() {}

	void ApartmentDataBase::AddOwner(const Owner& owner) {
		owners.push_back(owner);
	}

	// Дополнение к методу ApartmentDataBase::AddFlat
	void ApartmentDataBase::AddFlat(const Flat& flat) {
		try {
			// Добавление квартиры в вектор
			flats.push_back(flat);
			totalApartments++;
		}
		catch (const exception& e) {
			cerr << "Ошибка при добавлении квартиры: " << e.what() << endl;
		}
	}

	void ApartmentDataBase::AddConcierge(const Concierge& concierge) {
		concierges.push_back(concierge);
	}

	void ApartmentDataBase::AddDoorway(const Doorway& doorway) {
		doorways.push_back(doorway);
	}

	void ApartmentDataBase::AddHouse(const House& house) {
		houses.push_back(house);
	}

	void ApartmentDataBase::PrintOwnerList() const {
		if (owners.empty()) {
			std::cout << "          Данных о владельце нет..." << std::endl;
		}
		else {
			std::cout << "          Данные о владельце" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			for (const Owner& owner : owners) {
				std::cout << "Фамилия: " << owner.GetFIO_OWNER() << std::endl;
				std::cout << "Имя: " << owner.GetNAME_OWNER() << std::endl;
				std::cout << "-----------------------------------------" << std::endl;
			}
		}
	}

	// Дополнение к методу ApartmentDataBase::PrintFlatList
	void ApartmentDataBase::PrintFlatList() const {
		if (flats.empty()) {
			std::cout << "          Данных о квартире нет..." << std::endl;
		}
		else {
			std::cout << "Общее количество квартир: " << GetTotalApartments() << std::endl;
			std::cout << "          Данные о квартире" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			for (const Flat& flat : flats) {
				std::cout << "Адрес квартиры: " << flat.GetSTREET() << std::endl;
				std::cout << "Номер квартиры: " << flat.GetNUM_FLAT() << std::endl;
				std::cout << "Кол-во комнат: " << flat.GetKOL_ROOMS() << std::endl;
				std::cout << "Площадь квартиры (кв. м): " << flat.GetSQUARE() << std::endl;
				std::cout << "-----------------------------------------" << std::endl;
			}
		}
	}

	// Дополнение к методу ApartmentDataBase::PrintFlatList
	void ApartmentDataBase::PrintSortedFlatList() const {
		vector<Flat> sortedFlats = flats;  // Создание копии вектора квартир
		sort(sortedFlats.begin(), sortedFlats.end(), [](const Flat& a, const Flat& b) {
			return a.GetSQUARE() < b.GetSQUARE();  // Сортировка по площади квартиры
			});

		// Вывод отсортированного списка квартир
		for (const Flat& flat : sortedFlats) {
			cout << "Адрес квартиры: " << flat.GetSTREET() << endl;
			cout << "Номер квартиры: " << flat.GetNUM_FLAT() << endl;
			cout << "Кол-во комнат: " << flat.GetKOL_ROOMS() << endl;
			cout << "Площадь квартиры (кв. м): " << flat.GetSQUARE() << endl;
			cout << "-----------------------------------------" << endl;
		}
	}

	void ApartmentDataBase::PrintConciergeList() const {
		if (concierges.empty()) {
			std::cout << "          Данных о консьерже нет..." << std::endl;
		}
		else {
			std::cout << "          Данные о консьерже" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			for (const Concierge& concierge : concierges) {
				std::cout << "Фамилия консьержа: " << concierge.GetFIO_CONCIERGE() << std::endl;
				std::cout << "Имя консьержа: " << concierge.GetNAME_CONCIERGE() << std::endl;
				std::cout << "-----------------------------------------" << std::endl;
			}
		}
	}

	void ApartmentDataBase::PrintDoorwayList() const {
		if (doorways.empty()) {
			std::cout << "          Данных о подъезде нет..." << std::endl;
		}
		else {
			std::cout << "          Данные о подъезде" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			for (const Doorway& doorway : doorways) {
				std::cout << "Номер подъезда: " << doorway.GetNUM_DOORWAY() << std::endl;
				std::cout << "Кол-во квартир: " << doorway.GetKOl_FLAT() << std::endl;
				std::cout << "-----------------------------------------" << std::endl;
			}
		}
	}

	void ApartmentDataBase::PrintHouseList() const {
		if (houses.empty()) {
			std::cout << "          Данных о доме нет..." << std::endl;
		}
		else {
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "          Данные о доме" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			for (const House& house : houses) {
				std::cout << "Название улицы: " << house.GetSTREET() << std::endl;
				std::cout << "Номер дома: " << house.GetNUM_HOUSE() << std::endl;
				std::cout << "Кол-во жильцов: " << house.GetKOL_REZIDENTS() << std::endl;
				std::cout << "-----------------------------------------" << std::endl;
			}
		}
	}

	Owner ApartmentDataBase::InputOwnerFromUser() {
		std::string fio;
		std::string name;

		std::cout << " ";
		std::cout << "Введите фамилию собственника: ";
		std::getline(std::cin, fio);

		std::cout << "Введите имя собственника: ";
		std::getline(std::cin, name);

		return Owner(fio, name);
	}

	Flat ApartmentDataBase::InputFlatFromUser() {
		std::string street;
		int num_flat;
		int kol_rooms;
		int square;

		std::cout << " ";
		std::cout << "Введите улицу: ";
		std::getline(std::cin, street);

		std::cout << "Введите номер квартиры: ";
		while (true) {
			std::string num_flat_Str;
			std::getline(std::cin, num_flat_Str);
			if (IsInteger(num_flat_Str)) {
				num_flat = std::stoi(num_flat_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректный номер квартиры: ";
			}
		}

		std::cout << "Введите площадь квартиры (кв. м): ";
		while (true) {
			std::string square_Str;
			std::getline(std::cin, square_Str);
			if (IsInteger(square_Str)) {
				square = std::stoi(square_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректную площадь квартиры: ";
			}
		}

		std::cout << "Введите кол-во комнат: ";
		while (true) {
			std::string  kol_rooms_Str;
			std::getline(std::cin, kol_rooms_Str);
			if (IsInteger(kol_rooms_Str)) {
				kol_rooms = std::stoi(kol_rooms_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректное кол-во комнат: ";
			}
		}

		return Flat(street, num_flat, kol_rooms, square);
	}

	Concierge ApartmentDataBase::InputConciergeFromUser() {
		std::string concierge_fio;
		std::string concierge_name;

		std::cout << " ";
		std::cout << "Введите фамилию консьержа: ";
		std::getline(std::cin, concierge_fio);

		std::cout << "Введите имя консьержа: ";
		std::getline(std::cin, concierge_name);

		return Concierge(concierge_fio, concierge_name);
	}

	Doorway ApartmentDataBase::InputDoorwayFromUser() {
		int kol_flat;
		int num_doorway;

		std::cout << "Введите номер подъезда: ";
		while (true) {
			std::string num_doorway_Str;
			std::getline(std::cin, num_doorway_Str);
			if (IsInteger(num_doorway_Str)) {
				num_doorway = std::stoi(num_doorway_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректный номер подъезда: ";
			}
		}

		std::cout << "Введите кол-во квартир в подъезде: ";
		while (true) {
			std::string kol_flat_Str;
			std::getline(std::cin, kol_flat_Str);
			if (IsInteger(kol_flat_Str)) {
				kol_flat = std::stoi(kol_flat_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректное кол-во квартир: ";
			}
		}

		return Doorway(num_doorway, kol_flat);
	}

	House ApartmentDataBase::InputHouseFromUser() {
		std::string street;
		int num_house;
		int kol_rezidents;

		std::cout << " ";
		std::cout << "Введите улицу: ";
		std::getline(std::cin, street);

		std::cout << "Введите номер дома: ";
		while (true) {
			std::string num_house_Str;
			std::getline(std::cin, num_house_Str);
			if (IsInteger(num_house_Str)) {
				num_house = std::stoi(num_house_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректный номер дома: ";
			}
		}

		std::cout << "Введите общее кол-во жильцов: ";
		while (true) {
			std::string kol_rezidents_Str;
			std::getline(std::cin, kol_rezidents_Str);
			if (IsInteger(kol_rezidents_Str)) {
				kol_rezidents = std::stoi(kol_rezidents_Str);
				break;
			}
			else {
				std::cout << "Ошибка! Введите корректное кол-во жильцов: ";
			}
		}

		return House(street, num_house, kol_rezidents);
	}
