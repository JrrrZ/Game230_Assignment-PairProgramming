//Haobin Zhang & Lirong Liang
#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H
#include "Game.h"
#include "GameObject.h"

using namespace sf;
using namespace gm;

class ParticleEffect
{
private:
	GameObject** objects;
	Vector2f peposition;
	int pelifespan;
	int numberObjects = 20;

public:
	ParticleEffect(const Vector2f positionPE, int timePE, int number);
	virtual void update(RenderWindow& window);
	virtual void render(RenderWindow& window);
	virtual void Emit();
	virtual void AddParticle(int index);
	//boolean isAlive();
	~ParticleEffect();
	float random(int minNum, int maxNum);
};

#endif
