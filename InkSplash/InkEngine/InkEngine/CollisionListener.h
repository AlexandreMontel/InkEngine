#pragma once
#include <box2d/box2d.h>
//#include "Entity.h"


namespace InkEngine {
	
	class CollisionListener : public b2ContactListener
	{

		//bool A = false, B = false;
		virtual void BeginContact(b2Contact* contact) override;

		virtual void EndContact(b2Contact* contact) override;
	};
}
	