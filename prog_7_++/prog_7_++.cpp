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
