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

// convert solid into render_objects and push into queue
void solid::render_into(std::priority_queue<render_object> &objects) const {
	// vertices
	for (auto const &vertex : vertices_) {
		matrix transformed = transform.to_matrix() * vertex;
		matrix point =
		    camera_->get_projection_matrix(vertex.z) * transformed;

		auto circle = std::make_shared<sf::CircleShape>(5);
		circle->setPosition(point.get(0, 0), point.get(1, 0));
		circle->setOrigin(5, 5);
		circle->setFillColor(sf::Color::Transparent);

		objects.push(render_object(circle, transformed.get(2, 0),
					   PRIORITIES::POINT));
	}

	// faces
	for (auto const &face : faces_) {
		auto convex = std::make_shared<sf::ConvexShape>();
		convex->setPointCount(face.size());

		std::vector<sf::Vector2f> points(face.size());

		// store z-indices and keep minimum
		std::vector<double> zs(face.size());
		double min_z = std::numeric_limits<double>::max();

		for (int i = 0; i < face.size(); ++i) {
			sf::Vector3f vertex = vertices_[face[i]];

			matrix transformed = transform.to_matrix() * vertex;

			zs[i] = transformed.get(2, 0);
			min_z = std::min<double>(min_z, zs[i]);

			matrix point =
			    camera_->get_projection_matrix(vertex.z) *
			    transformed;

			points[i] = {(float)point.get(0, 0),
				     (float)point.get(1, 0)};

			convex->setPoint(i, {(float)point.get(0, 0),
					     (float)point.get(1, 0)});
		}

		// convex->setFillColor(
		// sf::Color(rand() % 255, rand() % 255, rand() % 255));
		convex->setFillColor(color_);

		objects.push(render_object(convex, min_z, PRIORITIES::PLANE));

		// edges
		for (int i = 0; i <= face.size(); ++i) {
			sf::Vector2f point1 = points[i % face.size()];
			sf::Vector2f point2 = points[(i + 1) % face.size()];

			double length = utils::distance(point1, point2);
			double angle = utils::angle(point1, point2);

			// no line shape, so rotate a rectangle
			auto line = std::make_shared<sf::RectangleShape>(
			    sf::Vector2f(length, 4));
			line->rotate(angle * 180 / M_PI);
			line->setPosition(point1);
			line->setOrigin(0, 2);
			line->setFillColor(sf::Color::White);

			objects.push(
			    render_object(line,
					  std::min(zs[i % face.size()],
						   zs[(i + 1) % face.size()]),
					  PRIORITIES::LINE));
		}
	}
}
