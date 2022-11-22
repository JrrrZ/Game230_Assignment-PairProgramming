//Haobin Zhang & Lirong Liang
// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include "GameObject.h"
#include "ParticleEffect.h"
// For using random functionality
#include <cstdlib>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
ParticleEffect* pe;
// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {
	// Set the random seed
	srand(time(NULL));

	
	// Randomly create between 5 and 50 game objects on the heap
	// Randomly determine the number of objects to create
	//numberObjects = 20;
	// Dynamically allocate an array on the heap to hold pointers to that randomly generated number
	//objects = new GameObject * [numberObjects];

	// Go through each object pointer in the array and allocate an object that it can point to
	//for (int i = 0; i < numberObjects; i++) {
	//	objects[i] = new HCircle();
		// We will just make all objects the same size and start them in the center of the sreen for now
		// All game objects move randomly so we will be able to see them all somewhat at runtime :)
	//	objects[i]->setPosition(sf::Mouse::getPosition(window));
	//	objects[i]->setSize(50);

	//}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput(sf::RenderWindow& window) {
	// Check for events from the window
	// E.g., is the window being closed?
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (pe != nullptr) {
					delete pe;
				}
					pe = new ParticleEffect(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y), 400, 20);
					//for (int i = 0; i < 20; i++) {
					//	pe->AddParticle(i);
					//}
					pe->Emit();
					//pe->render(window);
			}
		}
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window) {
	// Go through each game object and call its update to change state every frame
	// This nicely follows the game loop programming pattern :)
	if (pe != NULL) {
		pe->update(window);
	}
}


// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();
	if (pe != nullptr)
		pe->render(window);
	//for (int i = 0; i < 20; i++) {
	//	pe[i]->update(window);
	//}
	//pe->render(window);
	// Go through each game object and call its render to display it on the window
	// This nicely follows the game loop programming pattern :)
	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {
	// We allocated all these game objects and an array... Make sure we clean up when done!
	// First, go through each game object in the array and free it from the heap

	// Then free the array itself from the heap!
	// NOTE: this order is critical! The other way around would cause a memory leak and potential errors/unexpected behavior
	delete[] pe;
}

int Game::random(int minNum, int maxNum) {
	return minNum + rand() % (maxNum - minNum + 1);
}
