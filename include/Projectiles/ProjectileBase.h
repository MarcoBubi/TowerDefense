#pragma once

class ProjectileBase
{
public:
	ProjectileBase(int x, int y, int targetX, int targetY);
	virtual ~ProjectileBase();

	void Update(float deltaTime);

	float GetProjectileDamage() const;
	int GetPositionX() const;
	int GetPositionY() const;
	float GetSpeed() const;
	float GetAngle() const;

protected:
	void SetAngle();
	void CalculateMovement();

	float positionX = 0.0f; // setting this 2 values to float for a smoother movement
	float positionY = 0.0f;
	float movementX = 0.0f;
	float movementY = 0.0f;
	int targetX = 0;
	int targetY = 0;
	float speed = 4.0f;
	float damage = 50.0f;
	float angle = 0.0f; // maybe I don't need this, we'll see in the view part.
};
