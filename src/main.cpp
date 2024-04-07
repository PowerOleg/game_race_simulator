#include <iostream>
#include "Camel.h"
#include "Centaur.h"
#include "Fast_moving_camel.h"
#include "Eagle.h"

const int PLACES_QUANTITY = 10;
int places_count = 0;

void start_race(int* ground_based_vehicle_array, int size, int race_type, int distance)
{
	std::cout << "\nRace results: " << std::endl;
	int vehicle = -1;
	double result_time = -1;
	Camel* camel = nullptr;
	Centaur* centaur = nullptr;
	Fast_moving_camel* fast_moving_camel = nullptr;
	Eagle* eagle = nullptr;
	for (size_t i = 0; i < size; i++)
	{
		vehicle = ground_based_vehicle_array[i];
		switch (vehicle)
		{
		case 1:
			std::cout << "Off-road boots. ";
			//TODO1!!!!!!!!!!!!
			break;
		case 2:
			std::cout << "Broomstick. ";
			//TODO2!!!!!!!!!!!!
			break;
		case 3:
			std::cout << "Camel. " ;
			camel = new Camel();
			result_time = camel->go(distance);
			std::cout << "Time: " << result_time << std::endl;
			break;
		case 4:
			std::cout << "Centaur. ";
			centaur = new Centaur();
			result_time = centaur->go(distance);
			std::cout << "Time: " << result_time << std::endl;
			break;
		case 5:
			std::cout << "Eagle. ";
			eagle = new Eagle();
			result_time = eagle->go(distance);
			std::cout << "Time: " << result_time << std::endl;
			break;
		case 6:
			std::cout << "Fast-moving camel. ";
			fast_moving_camel = new Fast_moving_camel();
			result_time = fast_moving_camel->go(distance);
			std::cout << "Time: " << result_time << std::endl;
			break;
		case 7:
			std::cout << "Magic carpet. ";
			//TODO3!!!!!!!!!!!!
			std::cout << "Time: " << result_time << std::endl;
			break;
		}
		
	}

	delete camel;
	delete fast_moving_camel;
}

void print_registered_vehicles(int* ground_based_vehicle_array, int size)
{
	std::cout << "Registered vehicles: ";
	int vehicle = -1;
	for (size_t i = 0; i < size; i++)
	{
		
		vehicle = ground_based_vehicle_array[i];
		if (i > 0 && vehicle != 0)
		{
			std::cout << ", ";
		}
		switch (vehicle)
		{
		case 1:
			std::cout << "Off-road boots";
			break;
		case 2:
			std::cout << "Broomstick";
			break;
		case 3:
			std::cout << "Camel";
			break;
		case 4:
			std::cout << "Centaur";
			break;
		case 5:
			std::cout << "Eagle";
			break;
		case 6:
			std::cout << "Fast-moving camel";
			break;
		case 7:
			std::cout << "Magic carpet";
			break;
		default:
			break;
		}
	}
	std::cout << std::endl;
}

bool is_correct_race_type(int race_type, int local_select)
{
	if (race_type == 3)
	{
		return true;
	}
	bool result = false;
	switch (local_select)
	{
	case 1:
		result = true;
		break;
	case 2:
		result = false;
		break;
	case 3:
		result = true;
		break;
	case 4:
		result = true;
		break;
	case 5:
		result = false;
		break;
	case 6:
		result = true;
		break;
	case 7:
		result = false;
		break;
	default:
		break;
	}
	if (race_type == 1)
	{
		return result;
	}
	if (race_type == 2)
	{
		return !result;
	}
	
	return result;
}

void select_vehicle(int* vehicle_array, int distance, bool print_vehicles, int race_type)
{
	int local_select = -1;
	do
	{
		std::cout << "\nRace on the ground. Distance: " << distance << std::endl;
		if (print_vehicles)
		{
			print_registered_vehicles(vehicle_array, PLACES_QUANTITY);
		}
		std::cout << "1. Off-road boots" << std::endl;
		std::cout << "2. Broomstick" << std::endl;
		std::cout << "3. Camel" << std::endl;
		std::cout << "4. Centaur" << std::endl;
		std::cout << "5. Eagle" << std::endl;
		std::cout << "6. Fast-moving camel" << std::endl;
		std::cout << "7. Magic carpet" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Please select a vehicle or 0 to end the registration and exit: ";
		std::cin >> local_select;
		if (!is_correct_race_type(race_type, local_select))
		{
			std::cout << "\nThe wrong vehicle type for the race type";
			continue;
		}
		if (places_count >= PLACES_QUANTITY)
		{
			std::cout << "\nNo places";
			local_select = 0;
		}
			
			switch (local_select)
			{
			case 1:
				std::cout << "\nOff-road boots have been registered";
				break;
			case 2:
				std::cout << "\nBroomstick has been registered";
				break;
			case 3:
				std::cout << "\nCamel has been registered";
				break;
			case 4:
				std::cout << "\nCentaur has been registered";
				break;
			case 5:
				std::cout << "\nEagle has been registered";
				break;
			case 6:
				std::cout << "\nFast-moving camel has been registered";
				break;
			case 7:
				std::cout << "\nMagic carpet has been registered";
				break;
			case 0:
				continue;
			default:
				break;
			}
			vehicle_array[places_count++] = local_select;
		
		print_vehicles = true;
	} while (local_select != 0);
	std::cout << "\n1. Register a vehicle" << std::endl << "2. Start the race!!!" << std::endl << "Select an option: ";
	std::cin >> local_select;
	if (local_select == 1)
	{
		select_vehicle(vehicle_array, distance, true, race_type);
	}
}

int main(int argc, char** argv)
{
	int race_type = -1;
	int distance = -1;
	int add_vehicle = -1;
	int vehicle_array[PLACES_QUANTITY]{};
	std::cout << "Welcome to the race simulator!" << std::endl << "1. Race on the ground" << std::endl << "2. Race in the air" << std::endl << "3. Race for all" << std::endl << "Please choose the type of the race: ";
	std::cin >> race_type;
	std::cout << "\nPlease input the distance(positive value): ";
	std::cin >> distance;
	std::cout << "\nAt least 2 vehicles should be registered" << std::endl << "1. Register a vehicle" << std::endl << "Please select an option: ";
	std::cin >> add_vehicle;
	
	select_vehicle(vehicle_array, distance, false, race_type);
	start_race(vehicle_array, PLACES_QUANTITY, race_type, distance);
	system("Pause");
	return 0;
}