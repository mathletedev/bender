#include "solid.hpp"

solid::solid(camera *const &camera) {
	camera_ = camera;
}

void solid::set_color(sf::Color const &color) {
	color_ = color;
}

void solid::add_vertex(sf::Vector3f const &vertex) {
	vertices_.push_back(vertex);
}

void solid::add_face(std::vector<int> const &face) {
	if (face.size() < 3)
		throw std::runtime_error("Face must have at least 3 vertices");

	faces_.push_back(face);
}

void solid::draw(std::priority_queue<render_object> &objects) const {
	// for (auto const &vertex : vertices_) {
	// 	matrix point = camera_->get_projection_matrix(vertex.z) *
	// 		       transform.to_matrix() * vertex;

	// 	sf::CircleShape circle(5);
	// 	circle.setPosition(point.get(0, 0), point.get(1, 0));
	// 	circle.setOrigin(5, 5);

	// 	target.draw(circle, states);
	// }

	for (auto const &face : faces_) {
		sf::ConvexShape *convex = new sf::ConvexShape();
		convex->setPointCount(face.size());

		std::vector<sf::Vector2f> points(face.size());

		std::vector<double> zs(face.size());
		double min_z = std::numeric_limits<double>::max();

		for (int i = 0; i < face.size(); ++i) {
			sf::Vector3f vertex = vertices_[face[i]];

			zs[i] = vertex.z;
			min_z = std::min<double>(min_z, vertex.z);

			matrix point =
			    camera_->get_projection_matrix(vertex.z) *
			    transform.to_matrix() * vertex;
			points[i] = {(float)point.get(0, 0),
				     (float)point.get(1, 0)};

			convex->setPoint(i, {(float)point.get(0, 0),
					     (float)point.get(1, 0)});
		}

		convex->setFillColor(color_);

		objects.push(render_object(convex, min_z));

		for (int i = 0; i <= face.size(); ++i) {
			sf::Vector2f point1 = points[i % face.size()];
			sf::Vector2f point2 = points[(i + 1) % face.size()];

			double length = utils::distance(point1, point2);
			double angle = utils::angle(point1, point2);

			sf::RectangleShape *line =

			    new sf::RectangleShape(sf::Vector2f(length, 2));
			line->rotate(angle * 180 / M_PI);
			line->setPosition(point1);
			line->setFillColor(sf::Color::White);

			objects.push(render_object(
			    line, std::min(zs[i % face.size()],
					   zs[(i + 1) % face.size()])));
		}
	}
}
