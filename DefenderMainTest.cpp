#include <iostream>
#include <vector>
#include "Defender1.h"
#include "Defender2.h"

using namespace std;

/**
 * @brief Shows the stats for a defender. This function is just like the update()
 * method from your AttackerTest file.
 * @param d The defender object to display.
 */
void update(const Defender& d) {
    cout << d.getName() << " (" << d.getType() << ")"
              << " | Health: " << d.getHealth()
              << " | Position: (" << d.getPosition().row << ", " << d.getPosition().col << ")"
              << endl;
}

int main() {
    /* shows one of each defender type
    creates instances of each defender subclass
    */
    Defender1 d1(1, 1); // Shooting defender
    Defender2 d2(2, 1); // Income-generating defender

    // Calls the update() for each defender
    cout << "=== Initial Stats ===" << endl;
    // shows the stats for each defender - helps visualise the starting stats before any actions
    update(d1);
    update(d2);

    // Applies damage to each defender using takeDamage()
    cout << endl
              << "=== Simulate Damage ===" << endl;
    // shows to reduce health for behaviour changes

    cout << "Defender1 takes 2 damage" << endl;
    d1.takeDamage(2);
    update(d1);

    cout << "Defender2 takes 3 damage" << endl;
    d2.takeDamage(3);
    update(d2);

    // The move() function for Defender1 will fire a projectile on every second call.
    cout << endl
              << "=== Move Defenders & Fire Projectiles ===" << endl;
    cout << "--- Turn 1 ---" << endl;
    d1.move(); // d1's internal counter (willFire) is now 2. No projectile yet.
    d2.move(); // d2's move() does nothing, but we call it for consistency.
    cout << "Defender1 has moved. No projectile fired." << endl;


    cout << "\n--- Turn 2 ---" << endl;
    d1.move(); // d1's counter is now 3. Fires a projectile.
    cout << "Defender1 has moved. Should fire a projectile." << endl;


    // Prints the status of any projectiles fired
    cout << endl << "Checking for projectiles..." << endl;
    vector<Projectile*>& projectiles = d1.getProjectiles();
    cout << d1.getName() << " has " << projectiles.size() << " projectile(s)." << endl;

    if (!projectiles.empty()) {
        Projectile* p = projectiles.front();
        cout << "Projectile Position: (" << p->getPosition().row << ", " << p->getPosition().col << ")" << endl;
        cout << "Projectile Damage: " << p->getDamage() << endl;
    }

    // Clean up memory for any projectiles created with 'new'
    for(size_t i = 0; i < projectiles.size(); ++i) {
        delete projectiles[i];
    }
    projectiles.clear();

    return 0;
}