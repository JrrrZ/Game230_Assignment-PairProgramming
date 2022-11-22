//Haobin Zhang & Lirong Liang
// Include our header so that we can define our method declarations made there
#include "GameObject.h"

// For using random functionality
#include <cstdlib>
using namespace std;
#include <iostream>

// It's fine to use namespaces in .cpp files, just not .h files (will pollute your namespace otherwise)
using namespace sf;
using namespace gm;

//Clock clock;

// Our default constructor
// Makes a white circle shape on the heap with no specified position or size
GameObject::GameObject() {
	shape = new CircleShape();
	shape->setFillColor(Color::White);
	lifespan = 200;
	velocityX = 10.0f;
	velocityY = 10.0f;
	shapeType = 0;
}

// Our overloaded constructor
// Makes a white circle shape on the heap with a specified position and size
GameObject::GameObject(const Vector2f& position, int shapeName, float size, Color color, float time, float vX, float vY) {
	shapeType = shapeName;
	shape = new CircleShape(size);
	shape->setPosition(position);
	shape->setFillColor(Color::White);
	lifespan = time;
	velocityX = vX;
	velocityY = vY;
}

// Move the game object randomly each update
void GameObject::update(RenderWindow& window) {
	// Calculate the random movement amound in x and y directions
	//int velocityX =  + randomSpeedX;
	//int velocityY = BaseMovementAmount + randomSpeedY;

	// Set the game object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x + velocityX, getPosition().y + velocityY));
	lifespan--;
	//lifespan -= clock.getElapsedTime().asSeconds();
	//clock.restart();
	if (isAlive() == false) {
		shape->setFillColor(Color::Transparent);
	}
}

// Renders the game object
// Does this by telling the window to draw the dereferenced shape pointer
void GameObject::render(RenderWindow& window) {
	window.draw(*shape);
}

// Getters
// Gets the game object's position (which is stored in shape)
// Return by reference so that the returned object isn't returned by value/copied (which wastes space and time)
// Also return by const so that anyone who calls this function can't modify the referenced position within the class
// NOTE: Mark this function const since it should never modify anything in the class itself when called (i.e., it's a getter)
const Vector2f& GameObject::getPosition() const {
	return shape->getPosition();
}

// Setters
// Sets the game object's position (which is stored in shape)
void GameObject::setPosition(const Vector2f& position) {
	shape->setPosition(position);
}

boolean GameObject::isAlive() {
	if (lifespan <= 0) {
		return false;
	}
}

// Destructor
// We put the shape on the heap in the constructor, make sure we free it here now that we are done with it!
GameObject::~GameObject()
{
	delete shape;
}