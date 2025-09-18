#pragma once
#include <vector>
#include <string>
#include <map>

class ASCIIArtLibrary {
public:
    enum ArtType {
        PWEZORA_TEXT,
    };

    static std::vector<std::string> getArt(ArtType type) {
        auto it = artCollection.find(type);
        if (it != artCollection.end()) {
            return it->second;
        }
        return getArt(PWEZORA_TEXT); // Default fallback
    }

    static std::vector<std::string> getRandomSkull() {
        std::vector<ArtType> arts = {PWEZORA_TEXT};
        int random = rand() % arts.size();
        return getArt(arts[random]);
    }

private:
    static std::map<ArtType, std::vector<std::string>> artCollection;
    static void initializeCollection();
};

// Initialize the collection
std::map<ASCIIArtLibrary::ArtType, std::vector<std::string>> ASCIIArtLibrary::artCollection = {
    {PWEZORA_TEXT, {
        "",
        "    ########  ##   ##  ########  ########  #######   ########   #####  ",
        "    ##    ##  ##   ##  ##              ##  ##   ##   ##    ##  ##   ## ",
        "    ########  ## # ##  ######        ##    ##   ##   ########  ####### ",
        "    ##        #######  ##        ##        ##   ##   ##    ##  ##   ## ",
        "    ##         ## ##   ########  ########  #######   ##    ##  ##   ## ",
        "",
        "    ===================================================================",
        "    ###################################################################",
        "    ###################################################################",
        "    ===================================================================",
        "",
        "    +-----------------------------------------------------------+",
        "    |              OPEN SOURCE CRYPTOCURRENCY                 |",
        "    |                  ANALYSIS TOOLS                        |",
        "    +-----------------------------------------------------------+",
        "",
        "    +-- PROJECT DESCRIPTION --------------------------------+",
        "    | Utilizes all available analysis data from the internet |",
        "    | to decide which crypto coins to invest in and at what  |",
        "    | quantity. Smart investment recommendations powered by   |",
        "    | comprehensive market analysis and data aggregation.    |",
        "    +-----------------------------------------------------------+",
        "",
        "    +-- PROJECT INFO ----------------------------------------+",
        "    | Creator: Dismas Ndadila                                 |",
        "    | GitHub:  @DismasNdadila                                 |",
        "    | License: MIT (Open Source)                              |",
        "    | Started: 2025                                           |",
        "    +-----------------------------------------------------------+",
        ""
    }}
};