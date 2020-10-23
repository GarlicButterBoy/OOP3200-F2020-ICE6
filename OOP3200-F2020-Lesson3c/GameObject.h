#pragma once
#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include "Vector2D.h"

class GameObject
{
public:
	// Constructors
	GameObject();
	GameObject(int id, float x, float y);
	GameObject(int id, const Vector2D<float>& position);
	GameObject( int id, std::string name, const Vector2D<float>& position);
	GameObject( int id, std::string name, float x, float y);

	// Rule of Three
	~GameObject(); // Destructor
	GameObject(const GameObject& other_object); // Copy Constructor
	GameObject& operator=(const GameObject& other_object); // Assignment Operator

	// Accessors
	Vector2D<float> GetPosition() const;
	int GetID() const;
	std::string GetName() const;

	// Mutators
	void SetPosition(float x, float y);
	void SetPosition(const Vector2D<float>& new_position);
	void SetID(int id);
	void SetName(std::string name);

	// Utility Functions
	std::string ToString() const;
	std::string ToFile() const;

	// input/output operator overloads
	friend std::ostream& operator<<(std::ostream& out, const GameObject& rhs)
	{
		out << rhs.ToString();
		return out;
	}

	//friend std::ifstream& operator>>(std::ifstream& in, GameObject& rhs)
	//{
	//	int id = 0;
	//	in >> id;



	//	in >> rhs.m_id;
	//	in.ignore();
	//	in >> rhs.m_name;
	//	in.ignore();
	//	in >> rhs.m_position;
	//	in.ignore();

	//	return in;
	//}

private:
	int m_id{};
	std::string m_name;
	Vector2D<float> m_position;
};

#endif /* defined (__GAME_OBJECT__) */

