#pragma once



namespace InkEngine {
	class Entity;
	class ICollisionable
	{
	public :

		virtual void BeginCollision(Entity* Other) = 0;

		virtual void EndCollision(Entity* Other) = 0;

	};
}

