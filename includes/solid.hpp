#pragma once

#define _USE_MATH_DEFINES

#include "camera.hpp"
#include "renderobject.hpp"
#include "transform.hpp"
#include "utils.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <limits>
#include <memory>
#include <queue>
#include <stdexcept>
#include <vector>



class solid {
	public:
		class transform transform;

		solid(camera *const &camera);

		void set_color(sf::Color const &color);

		void add_vertex(sf::Vector3f const &vertex);
		void add_face(std::vector<int> const &face);

		void
		render_into(std::priority_queue<render_object> &objects) const;

	protected:
		std::vector<sf::Vector3f> vertices_;
		std::vector<std::vector<int>> faces_;
		sf::Color color_;
		camera *camera_;
		int light_intensity = 70; 

		//cmyk color thingys
		//if y intensity is set to 1 and c and m are set to 0,
		//everything will have a yellow tint

		//feel free to play around and make some nice color combos
		float r_intensity = 51; 
		float g_intensity = 102; 
		float b_intensity = 255; 
};

