#pragma once

class ControllerBase
{
public:
	virtual ~ControllerBase() = default;

	virtual void Start();
	virtual void Update(float deltaTime) = 0;
};