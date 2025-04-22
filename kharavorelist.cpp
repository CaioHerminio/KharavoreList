#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

struct Hero {
    std::string name;
    int power;
    std::string gender;
    int original_index;
};

int main() {
    // Step 0: Initialize the heroes list
    std::vector<Hero> heroes = {
        {"Thunderclaw", 542137}, {"Starblaze", 310982},
        {"Ironvolt", 811530}, {"Nightshade", 125674},
        {"Stormwarden", 673892}, {"Embermist", 782345},
        {"Voidstrike", 224650}, {"Crystalflare", 895321},
        {"Gravitus", 501073}, {"Moonveil", 153008},
        {"Blazehound", 660247}, {"Sylphara", 47109},
        {"Titanborn", 720905}, {"Arcanabelle", 362988},
        {"Riftblade", 346110}, {"Lumisera", 588012},
        {"Frostmark", 136089}, {"Celestira", 891340},
        {"Dreadcore", 451882}, {"Zephyra", 304655},
        {"Magnus Vortex", 703741}, {"Virellia", 139204},
        {"Shockflare", 491882}, {"Mirage Nova", 828117},
        {"Blackquake", 134760}, {"Seraphina Storm", 715993},
        {"Ironhowl", 650210}, {"Nebulight", 389443},
        {"Nightcore", 297511}, {"Electravine", 811309},
        {"Pyrosurge", 190477}, {"Aethera Flux", 479102},
        {"Steelburst", 582694}, {"Solandra", 231874},
        {"Phantomwake", 400220}, {"Vortexia", 795500},
        {"Venomforge", 282013}, {"Quasaria", 129981},
        {"Brimblade", 871307}, {"Nyx Warden", 327660},
        {"Onyx Wolf", 177220}, {"Glimmerthorn", 492737},
        {"Voltknight", 365198}, {"Halocryne", 603443}
    };

    // Annotate gender and index
    for (size_t i = 0; i < heroes.size(); ++i) {
        heroes[i].original_index = i;
        heroes[i].gender = (i % 2 == 0) ? "Male" : "Female";
    }

    // Step 1: Sort heroes by power descending
    std::vector<Hero> sorted = heroes;
    std::sort(sorted.begin(), sorted.end(), [](const Hero& a, const Hero& b) {
        return a.power > b.power;
    });

    // Step 2: Champion
    Hero champion = sorted[0];

    // Step 3: Separate remaining heroes by gender
    std::vector<Hero> remaining(sorted.begin() + 1, sorted.end());

    std::vector<Hero> males, females;
    for (const auto& h : remaining) {
        if (h.gender == "Male") males.push_back(h);
        else females.push_back(h);
    }

    // Step 4: Top 3 males
    std::vector<Hero> top_males(males.begin(), males.begin() + 3);

    // Step 5: Top 3 females
    std::vector<Hero> top_females(females.begin(), females.begin() + 3);

    // Step 6: Exclude champion + top 3 males + top 3 females
    std::set<std::string> excluded_names = { champion.name };
    for (const auto& h : top_males) excluded_names.insert(h.name);
    for (const auto& h : top_females) excluded_names.insert(h.name);

    std::vector<Hero> remaining_for_weakest;
    for (const auto& h : heroes) {
        if (excluded_names.find(h.name) == excluded_names.end()) {
            remaining_for_weakest.push_back(h);
        }
    }

    std::sort(remaining_for_weakest.begin(), remaining_for_weakest.end(), [](const Hero& a, const Hero& b) {
        return a.power < b.power;
    });

    std::vector<Hero> weakest_10(remaining_for_weakest.begin(), remaining_for_weakest.begin() + 10);

    // 🧾 Print results
    std::cout << "🏆 Champion:\n - " << champion.name << " (" << champion.power << ")\n";

    std::cout << "\n💪 Top 3 Males:\n";
    for (const auto& h : top_males)
        std::cout << " - " << h.name << " (" << h.power << ")\n";

    std::cout << "\n✨ Top 3 Females:\n";
    for (const auto& h : top_females)
        std::cout << " - " << h.name << " (" << h.power << ")\n";

    std::cout << "\n🧹 Weakest 10 Heroes:\n";
    for (const auto& h : weakest_10)
        std::cout << " - " << h.name << " (" << h.power << ")\n";

    return 0;
}
