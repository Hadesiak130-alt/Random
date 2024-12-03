#include <Geode/Geode.hpp>
#include <cstdlib> // For random number generation

using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>

class $modify(MyPlayLayer, PlayLayer) {
    void onPlayerDied(PlayerObject* player, const char* deathCause) {
        PlayLayer::onPlayerDied(player, deathCause);

        // 1/30 chance to send to a random level
        if (std::rand() % 30 == 0) {
            log::info("Random level trigger activated!");
            
            // Generate a random level ID
            int randomID = 1 + std::rand() % 112720768; // Replace with an appropriate ID range
            
            auto GM = GameManager::sharedState();
            GM->playOnlineLevel(randomID, true);
        }
    }
};
