#pragma once

class ProjectileBase
{
public:
	ProjectileBase();
	virtual ~ProjectileBase();

	void Update(float deltaTime);

	float GetProjectileDamage() const;
	int GetPositionX() const;
	int GetPositionY() const;
	float GetSpeed() const;
	float GetAngle() const;

private:
	int positionX = 0;
	int positionY = 0;
	float speed = 3.0f;
	float damage = 50.0f;
	float angle = 0.0f; // maybe I don't need this, we'll see in the view part.
};
