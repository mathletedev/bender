#include "solid.hpp"
#include <iostream>

solid::solid(camera *const &camera) {
	camera_ = camera;
}

void solid::add_vertex(sf::Vector3f const &vertex) {
	vertices_.push_back(vertex);
}

void solid::add_edge(int const &v1, int const &v2) {
	if (v1 < 0 || v1 >= vertices_.size() || v2 < 0 ||
	    v2 >= vertices_.size())
		throw std::invalid_argument("Invalid vertex index");

	edges_[v1].push_back(v2);
	edges_[v2].push_back(v1);
}

void solid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	for (auto const &vertex : vertices_) {
		matrix point = camera_->get_projection_matrix(vertex.z) *
			       transform.to_matrix() * vertex;

		sf::CircleShape circle(5);
		circle.setPosition(point.get(0, 0), point.get(1, 0));

		target.draw(circle, states);
	}
}
