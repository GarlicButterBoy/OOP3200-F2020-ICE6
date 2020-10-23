#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>

#include <vector>

#include "GameObject.h"
#include "Vector3D.h"


static void BuildGameObjects(std::vector<GameObject*>& game_objects, const int num = 2)
{
	for (auto count = 0; count < num; ++count)
	{
		int id;
		std::cout << "Enter the gameObject's ID: ";
		std::cin >> id;
		Vector2D<float> point;
		std::cout << "Enter the gameObject's Position (x, y): ";
		std::cin >> point;
		std::cout << "\n--------------------------------------------------------------" << std::endl;
		std::cout << "You Entered " << id << " for the gameObject's ID " << std::endl;
		std::cout << "You Entered " << point << " for the gameObject's Position" << std::endl;
		std::cout << "--------------------------------------------------------------\n" << std::endl;
		auto* gameObject = new GameObject(id, point);
		game_objects.push_back(gameObject);
	}

}

static void CompareGameObjects(GameObject* object1, GameObject* object2)
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Magnitude of first gameObject is: " << object1->GetPosition().GetMagnitude() << std::endl;
	std::cout << "Magnitude of second gameObject is: " << object2->GetPosition().GetMagnitude() << std::endl;
	std::cout << "Distance between first gameObject and second gameObject is: "
		<< Vector2D<float>::Distance(object1->GetPosition(), object2->GetPosition()) << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << "The angle (in degrees) from the first gameObject to the second gameObject is: "
		<< Vector2D<float>::SignedAngle(object1->GetPosition(), object2->GetPosition()) << std::endl;

	std::cout << "--------------------------------------------------------------\n" << std::endl;
	std::cout << "First Game Object Details:" << std::endl;
	std::cout << object1->ToString() << std::endl;

	std::cout << "Second Game Object Details:" << std::endl;
	std::cout << object2->ToString() << std::endl;
}


int main()
{
	//map is made of key-value pairs (a string and a gameobject)
	//key is a string, value is a GameObject
	std::map<std::string, GameObject*> gameObjects;

	auto* ship = new GameObject( 0, "Ship", 3.0f, 4.0f);
	auto* enemy = new GameObject( 1, "Enemy", 10.0f, 14.0f);
	auto* space_station = new GameObject(2, "SpaceStation", 100.0f, 200.0f);

	std::cout << ship->ToString() << std::endl;
	std::cout << enemy->ToString() << std::endl;

	gameObjects[ship->GetName()] = ship;
	gameObjects[enemy->GetName()] = enemy;
	gameObjects[space_station->GetName()] = space_station;

	//for every game_object in gameObjects loop
	for (const auto& game_object : gameObjects)
	{
		std::cout << "Key   : " << game_object.first << std::endl;
		std::cout << "Value : " << std::endl << game_object.second->ToString() << std::endl;
	}

	auto distance = Vector2D<float>::Distance(gameObjects["Ship"]->GetPosition(), gameObjects["Enemy"]->GetPosition());
												//gameObjects["Ship"]->GetPosition(), gameObjects["Enemy"]->GetPosition()
	std::cout << "Distance between our ship and our enemies ship:" << std::endl << std::to_string(distance);

	std::ofstream outfile{"GameObjects.txt", std::ios::out};

	outfile << gameObjects["Ship"]->ToFile() << std::endl;
	outfile << gameObjects["Enemy"]->ToFile() << std::endl;
	outfile << gameObjects["SpaceStation"]->ToFile() << std::endl;
	outfile.close();


	std::cout << "-------------------------------------------\n\n";

	std::ifstream infile;
	std::string fileName = "GameObjects.txt";

	infile.open(fileName.c_str());

	if (infile.is_open())
	{
		int id = 0;
		float x, y = 0;
		std::string name;

		while (!infile.fail())
		{
			infile >> id >> name;
			infile.ignore(1, ' ');
			infile.ignore(1, '(');
			infile >> x;
			infile.ignore(1, ',');
			infile.ignore(1, ' ');
			infile >> y;
			infile.ignore(1, ')');

			auto* tempObject = new GameObject(id, name, x, y);
			gameObjects[name + " 2"] = tempObject;
		}
		infile.close();
	}

	for (const auto& game_object : gameObjects)
	{
		std::cout << "Key   : " << game_object.first << std::endl;
		std::cout << "Value : " << std::endl << game_object.second->ToString() << std::endl;
	}

	//std::vector<GameObject*> gameObjects;

	//int num_of_GO;
	//std::cout << "How Many Game Objects do you need?: ";
	//std::cin >> num_of_GO;
	//std::cout << "\n--------------------------------------------------------------" << std::endl;

	//BuildGameObjects(gameObjects, num_of_GO);
	//
	//
	//int index1;
	//std::cout << "What is the First Object index?: ";
	//std::cin >> index1;
	//std::cout << "\n--------------------------------------------------------------" << std::endl;
	//int index2;
	//std::cout << "What is the Second Object index?: ";
	//std::cin >> index2;
	//std::cout << "\n--------------------------------------------------------------" << std::endl;
	//
	//CompareGameObjects(gameObjects[index1], gameObjects[index2]);
	//CompareGameObjects(gameObjects[index1], gameObjects[index2]);
}

