#include <iostream>
#include <vector>
#include "Defender1.h"
#include "Defender2.h"

/**
 * @brief Shows the stats for a defender. This function is just like the update()
 * method from your AttackerTest file.
 * @param d The defender object to display.
 */
void update(const Defender& d) {
    std::cout << d.getName() << " (" << d.getType() << ")"
              << " | Health: " << d.getHealth()
              << " | Position: (" << d.getPosition().row << ", " << d.getPosition().col << ")"
              << std::endl;
}

int main() {
    /* shows one of each defender type
    creates instances of each defender subclass
    */
    Defender1 d1(1, 1); // Shooting defender
    Defender2 d2(2, 1); // Income-generating defender

    // Calls the update() for each defender
    std::cout << "=== Initial Stats ===" << std::endl;
    // shows the stats for each defender - helps visualise the starting stats before any actions
    update(d1);
    update(d2);

    // Applies damage to each defender using takeDamage()
    std::cout << std::endl
              << "=== Simulate Damage ===" << std::endl;
    // shows to reduce health for behaviour changes

    std::cout << "Defender1 takes 2 damage" << std::endl;
    d1.takeDamage(2);
    update(d1);

    std::cout << "Defender2 takes 3 damage" << std::endl;
    d2.takeDamage(3);
    update(d2);

    // The move() function for Defender1 will fire a projectile on every second call.
    std::cout << std::endl
              << "=== Move Defenders & Fire Projectiles ===" << std::endl;
    std::cout << "--- Turn 1 ---" << std::endl;
    d1.move(); // d1's internal counter (willFire) is now 2. No projectile yet.
    d2.move(); // d2's move() does nothing, but we call it for consistency.
    std::cout << "Defender1 has moved. No projectile fired." << std::endl;


    std::cout << "\n--- Turn 2 ---" << std::endl;
    d1.move(); // d1's counter is now 3. Fires a projectile.
    std::cout << "Defender1 has moved. Should fire a projectile." << std::endl;


    // Prints the status of any projectiles fired
    std::cout << std::endl << "Checking for projectiles..." << std::endl;
    std::vector<Projectile*>& projectiles = d1.getProjectiles();
    std::cout << d1.getName() << " has " << projectiles.size() << " projectile(s)." << std::endl;

    if (!projectiles.empty()) {
        Projectile* p = projectiles.front();
        std::cout << "Projectile Position: (" << p->getPosition().row << ", " << p->getPosition().col << ")" << std::endl;
        std::cout << "Projectile Damage: " << p->getDamage() << std::endl;
    }

    // IMPORTANT: Clean up memory for any projectiles created with 'new'
    for(size_t i = 0; i < projectiles.size(); ++i) {
        delete projectiles[i];
    }
    projectiles.clear();

    return 0;
}