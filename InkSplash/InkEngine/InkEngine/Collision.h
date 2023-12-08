#pragma once
#include "RigidBody.h"

namespace InkEngine {
	class Collision
	{




	protected:
		
		RigidBody* MyRb;
		RigidBody* OtherRb;



	public:
		
		//getters
		RigidBody* GetMyRb();
		RigidBody* GetOtherRb();

		//setters		
		void SetMyRb(RigidBody* rB);
		void SetOtherRb(RigidBody* rB);
	};
}
