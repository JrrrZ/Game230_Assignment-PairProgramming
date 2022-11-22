//Haobin Zhang & Lirong Liang
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

 // Use our gm namespace for both Game and GameObject classes
namespace gm {
	// Global constants related to our GameObject
	//const int BaseMovementAmount = -3;
	//const int randomSpeedX = -3;
	//const int randomSpeedY = 3;

	// Our GameObject class! Maintains a shape and functionality needed to manipulate/render it
	// Will draw a circle and move that circle in a random direction every frame
	class GameObject {
	private:
		// Our shape object that the class maintains
		CircleShape* shape;
		//RectangleShape* shape;
		int shapeType;
		float lifespan;
		float velocityX;
		float velocityY;

	public:
		// Default constructor
		GameObject();
		// Overloaded constructor
		GameObject(const Vector2f& position, int shapeName, float size, Color color, float time, float vX, float vY);

		// Game loop programming pattern functions
		virtual void update(RenderWindow& window);

		virtual void render(RenderWindow& window);

		// Setters
		void setPosition(const Vector2f& position);
		void setSize(float radius);

		// Getter
		const Vector2f& getPosition() const;

		boolean isAlive();

		// Destructor
		~GameObject();
	};
}

#endif
