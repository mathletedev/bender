#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window;
  window.create(sf::VideoMode(1000, 1000), "Bender");

  sf::CircleShape ball(50);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      window.clear();

      window.draw(ball);

      window.display();
    }
  }

  return 0;
}
