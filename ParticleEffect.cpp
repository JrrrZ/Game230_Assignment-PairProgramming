//Haobin Zhang & Lirong Liang
using namespace std;
#include <iostream>
#include "ParticleEffect.h"
#include "GameObject.h"
#include <cstdlib>

using namespace sf;
using namespace gm;

ParticleEffect::ParticleEffect(const Vector2f positionPE, int timePE, int number = 20) {
	objects = new GameObject * [number];
	peposition = positionPE;
	pelifespan = timePE;
	numberObjects = number;
	srand(time(NULL));
}

void ParticleEffect::update(RenderWindow& window) {
	for (int i = 0; i < numberObjects; i++) {
		objects[i]->update(window);
	}
	pelifespan--;
}

void ParticleEffect::render(RenderWindow& window) {
	for (int i = 0; i < numberObjects; i++) {
		objects[i]->render(window);
	}
}

void ParticleEffect::Emit() {
	for (int i = 0; i < 20; i++) {
		AddParticle(i);
		//cout << "hello" << endl;
	}
}

void ParticleEffect::AddParticle(int index) {
	float randomA = random(150, 250);
	float randomB = random(3000, 5000);
	float randomC = random(-10, 10);
	float randomD = random(-10, 10);
	GameObject* shape = new GameObject(Vector2f(float(peposition.x) + random(-15,15), float(peposition.y) + random(-15, 15)), 0, randomA / 10, Color::White, randomB / 10, randomC / 10, randomD / 10);
	objects[index] = shape;


}

ParticleEffect::~ParticleEffect() {
	for (int i = 0; i < 20; i++) {
		if (objects[i] != nullptr) {
			delete objects[i];
		}	
	}
}

float ParticleEffect::random(int minNum, int maxNum) {
	return minNum + rand() % (maxNum - minNum + 1);
}