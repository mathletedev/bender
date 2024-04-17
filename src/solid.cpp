#include "solid.hpp"

solid::solid(sf::Color const &color, camera *const &camera) {
	color_ = color;
	camera_ = camera;
}

void solid::add_vertex(sf::Vector3f const &vertex) {
	vertices_.push_back(vertex);
}

void solid::add_face(std::vector<int> const &face) {
	if (face.size() < 3)
		throw std::runtime_error("Face must have at least 3 vertices");

	faces_.push_back(face);
}

void solid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	// for (auto const &vertex : vertices_) {
	// 	matrix point = camera_->get_projection_matrix(vertex.z) *
	// 		       transform.to_matrix() * vertex;

	// 	sf::CircleShape circle(5);
	// 	circle.setPosition(point.get(0, 0), point.get(1, 0));
	// 	circle.setOrigin(5, 5);

	// 	target.draw(circle, states);
	// }

	for (auto const &face : faces_) {
		sf::VertexArray lines(sf::LinesStrip, face.size() + 1);

		sf::ConvexShape convex;
		convex.setPointCount(face.size());

		for (int i = 0; i < face.size(); ++i) {
			sf::Vector3f vertex = vertices_[face[i]];

			matrix point =
			    camera_->get_projection_matrix(vertex.z) *
			    transform.to_matrix() * vertex;

			convex.setPoint(i, {(float)point.get(0, 0),
					    (float)point.get(1, 0)});
		}

		convex.setFillColor(color_);

		target.draw(convex, states);
	}
}
