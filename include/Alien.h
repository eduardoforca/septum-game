#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Vec2.h"
#include <vector>
#include <memory>
#include <queue>

using std::vector;
using std::queue;
using std::weak_ptr;

class Alien: public Component {
	public:
		/**
		 * Creates an Alien with a set number of minions
		 * @param associated associated GameObject
		 * @param nMinions number of minions to orbit the alien
		 */
		Alien (GameObject& associated, int nMinions);
		~Alien ();
		/**
		 * Sets the component up
		 */
		void Start ();
		/**
		 * Updates component state
		 * @param dt
		 */
		void Update (float dt);
		/**
		 * Renders the component
		 */
		void Render ();
		/**
		 * Checks if the Component is from the passed type
		 * @param type type to be checked
		 * @retval true the passed type is Alien
		 * @retval false the passed type is not Alien
		 */
		bool Is (string type) const;

		void NotifyCollision (GameObject& other);
	private:
		class Action {
			public:
				enum ActionType {
					MOVE, SHOOT
				};
				ActionType type;
				Vec2 pos;
				Action (ActionType type, float x, float y);
		};
		
		Vec2 speed;
		int hp;
		int nMinions;
		queue<Action> taskQueue;
		vector<weak_ptr<GameObject>> minionArray;

};
