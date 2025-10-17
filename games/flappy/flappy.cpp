#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 600), "Flappy Bird Simple");
    window.setFramerateLimit(60);

    // Bird setup
    sf::CircleShape bird(25); // bigger
    bird.setFillColor(sf::Color::Red);
    float birdY = 300;
    float velocity = 0;
    const float gravity = 0.5;

    // Pipes setup
    std::vector<sf::RectangleShape> pipes;
    int pipeSpacing = 200;
    int pipeWidth = 60;
    int pipeGap = 150;
    srand(time(0));

    // Create initial pipes
    for (int i = 0; i < 3; ++i) {
        int topHeight = rand() % 300 + 50;
        sf::RectangleShape topPipe(sf::Vector2f(pipeWidth, topHeight));
        topPipe.setPosition(400 + i * pipeSpacing, 0);
        topPipe.setFillColor(sf::Color::Green);

        sf::RectangleShape bottomPipe(sf::Vector2f(pipeWidth, 600 - topHeight - pipeGap));
        bottomPipe.setPosition(400 + i * pipeSpacing, topHeight + pipeGap);
        bottomPipe.setFillColor(sf::Color::Green);

        pipes.push_back(topPipe);
        pipes.push_back(bottomPipe);
    }

    int score = 0;
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        // fallback: use system font path
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    scoreText.setString("Score: 0");

    bool gameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !gameOver)
                velocity = -4; // Jump
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && gameOver) {
                // Reset game
                birdY = 300;
                velocity = 0;
                pipes.clear();
                for (int i = 0; i < 3; ++i) {
                    int topHeight = rand() % 300 + 50;
                    sf::RectangleShape topPipe(sf::Vector2f(pipeWidth, topHeight));
                    topPipe.setPosition(400 + i * pipeSpacing, 0);
                    topPipe.setFillColor(sf::Color::Green);

                    sf::RectangleShape bottomPipe(sf::Vector2f(pipeWidth, 600 - topHeight - pipeGap));
                    bottomPipe.setPosition(400 + i * pipeSpacing, topHeight + pipeGap);
                    bottomPipe.setFillColor(sf::Color::Green);

                    pipes.push_back(topPipe);
                    pipes.push_back(bottomPipe);
                }
                score = 0;
                scoreText.setString("Score: 0");
                gameOver = false;
            }
        }

        if (!gameOver) {
            // Bird physics
            velocity += gravity;
            birdY += velocity;
            if (birdY > 575) { // ground limit
                birdY = 575;
                velocity = 0;
                gameOver = true;
            }
            if (birdY < 0) {
                birdY = 0;
                velocity = 0;
            }
            bird.setPosition(100, birdY);

            // Move pipes
            for (auto &pipe : pipes)
                pipe.move(-2, 0); // slower movement

            // Recycle pipes & update score
            for (int i = 0; i < pipes.size(); i += 2) {
                if (pipes[i].getPosition().x + pipeWidth < 0) {
                    int topHeight = rand() % 300 + 50;
                    pipes[i].setSize(sf::Vector2f(pipeWidth, topHeight));
                    pipes[i].setPosition(400, 0);

                    pipes[i + 1].setSize(sf::Vector2f(pipeWidth, 600 - topHeight - pipeGap));
                    pipes[i + 1].setPosition(400, topHeight + pipeGap);

                    score++;
                    scoreText.setString("Score: " + std::to_string(score));
                }
            }

            // Collision detection
            for (auto &pipe : pipes) {
                if (bird.getGlobalBounds().intersects(pipe.getGlobalBounds())) {
                    gameOver = true;
                }
            }
        }

        // Drawing
        window.clear(sf::Color::Cyan);
        for (auto &pipe : pipes)
            window.draw(pipe);
        window.draw(bird);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}
