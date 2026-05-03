#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Step 1: Take user's name
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // Step 2: Ask user to choose roast type
    int choice;
    cout << "\nChoose roast type:\n";
    cout << "1. Lazy Roast\n";
    cout << "2. Smart Roast\n";
    cout << "3. Funny Roast\n";
    cout << "4. Savage Roast\n";
    cout << "5. Random Roast\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    // Step 3: Roast templates

    // Lazy Roasts
    vector<string> lazyRoasts = {
        "{name}, effort clearly isn't your thing.",
        "Even doing nothing looks exhausting for you, {name}.",
        "{name}, you've mastered the art of avoiding work.",
        "Productivity skips you on purpose, {name}.",
        "{name}, your energy disappears before you even start.",
        "Ambition gave up waiting for you, {name}.",
        "{name}, you don't delay tasks—you abandon them.",
        "Even shortcuts feel like too much work to you, {name}.",
        "{name}, you treat basic effort like a big achievement.",
        "Nothing gets done when it depends on you, {name}."
    };

    // Smart Roasts
    vector<string> smartRoasts = {
        "{name}, your logic sounds confident but never correct.",
        "Even simple ideas get lost when you explain them, {name}.",
        "{name}, thinking isn't your strength—it's your struggle.",
        "You argue like you're right, but it never works out, {name}.",
        "{name}, your reasoning fails in creative ways.",
        "Understanding avoids you completely, {name}.",
        "{name}, you make confusion look like a skill.",
        "Even basic concepts become complicated around you, {name}.",
        "{name}, your conclusions never match reality.",
        "You don't think wrong—you think differently, {name}."
    };

    // Funny Roasts
    vector<string> funnyRoasts = {
        "{name}, you turn simple situations into problems.",
        "People don't ignore you—they just stop paying attention, {name}.",
        "{name}, your presence raises questions, not standards.",
        "Even autocorrect stopped trying to fix you, {name}.",
        "{name}, you make confusion look effortless.",
        "You don't help—you just show up, {name}.",
        "{name}, you're consistent… at disappointing expectations.",
        "Nothing changes whether you're there or not, {name}.",
        "{name}, you somehow complicate everything.",
        "You don't fail once—you repeat it, {name}."
    };

    // Savage Roasts
    vector<string> savageRoasts = {
        "{name}, you're not part of the problem—you are the problem.",
        "Expectations drop the moment you get involved, {name}.",
        "{name}, even your best effort isn't enough.",
        "Nothing improves when it depends on you, {name}.",
        "{name}, you consistently deliver less than expected.",
        "People stop expecting things once they see you, {name}.",
        "{name}, your performance speaks—and it says nothing good.",
        "You don't fix problems—you create new ones, {name}.",
        "{name}, even average feels out of reach for you.",
        "Disappointment follows you everywhere, {name}."
    };

    // Default / Random Roasts
    vector<string> defaultRoasts = {
        "{name}, you don't stand out—you hold things back.",
        "Even silence adds more value than you, {name}.",
        "{name}, your presence changes very little.",
        "Nothing improves with your input, {name}.",
        "{name}, you make things slower, not better.",
        "People expect less once you're involved, {name}.",
        "{name}, you don't add value—you reduce it.",
        "Even basic expectations feel too high for you, {name}.",
        "{name}, you stay consistent at being unimpressive.",
        "You don't contribute—you just exist, {name}."
    };

    // Step 4: Initialize random seed
    srand(time(0));

    string selectedRoast;

    // Step 5: Select roast based on user choice
    if (choice == 1) {
        selectedRoast = lazyRoasts[rand() % lazyRoasts.size()];
    }
    else if (choice == 2) {
        selectedRoast = smartRoasts[rand() % smartRoasts.size()];
    }
    else if (choice == 3) {
        selectedRoast = funnyRoasts[rand() % funnyRoasts.size()];
    }
    else if (choice == 4) {
        selectedRoast = savageRoasts[rand() % savageRoasts.size()];
    }
    else {
        selectedRoast = defaultRoasts[rand() % defaultRoasts.size()];
    }

    // Step 6: Replace {name} with actual name (if present)
    size_t pos = selectedRoast.find("{name}");
    if (pos != string::npos) {
        selectedRoast.replace(pos, 6, name);
    }

    // Step 7: Display final roast
    cout << "\n Roast Result \n";
    cout << selectedRoast << endl;

    return 0;
}