#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// Function to replace {name}
void replaceName(string &text, const string &name) {
    size_t pos = 0;
    while ((pos = text.find("{name}", pos)) != string::npos) {
        text.replace(pos, 6, name);
        pos += name.length();
    }
}

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // 🔹 Common excuses (more frequent)
    vector<string> commonExcuses = {
        "{name} was working on the assignment when suddenly there was a power cut. It took a long time to come back, and most of the work was lost. {name} will complete it soon.",
        
        "{name} tried to finish the assignment on time, but the internet stopped working last night. Even after trying many times, it didn't get fixed. {name} will submit it as soon as possible.",
        
        "{name} was not feeling well while working on the assignment. Because of this, it couldn't be completed on time. {name} will try to submit it soon.",
        
        "{name} started the assignment early, but the system began lagging heavily. It became impossible to continue working properly. {name} will finish it soon.",
        
        "{name} was about to submit the assignment when the file suddenly disappeared. It could not be found anywhere on the system. {name} will redo it quickly.",
        
        "{name} got delayed due to unexpected household work and couldn't manage time properly. The assignment is almost done. {name} will submit it soon.",
        
        "{name} faced multiple technical issues while working on the assignment. This slowed down the progress a lot. {name} will complete it shortly."
    };

    // 🔹 Rare / funny excuses (less frequent)
    vector<string> rareExcuses = {
        "{name} had completed the assignment, but the file got corrupted while saving. It couldn't be recovered despite multiple attempts. {name} will redo it quickly.",
        
        "{name}'s laptop suddenly crashed while finishing the assignment. All unsaved work was lost. {name} will start again and submit it soon.",
        
        "{name} accidentally submitted the wrong file and realized it later. The correct one will be sent soon.",
        
        "{name} saved the assignment on a USB drive, but it stopped working suddenly. The file could not be accessed anymore. {name} will recreate it.",
        
        "{name}'s keyboard stopped working in the middle of typing the assignment. This caused a big delay. {name} will complete it soon.",
        
        "{name} mistakenly deleted the final version of the assignment while cleaning files. It couldn't be restored. {name} will rewrite it.",
        
        "{name} was about to upload the assignment, but the website stopped responding. After multiple attempts, it still didn't work. {name} will try again soon."
    };

    // 🔹 Weighted list
    vector<string> weightedExcuses;

    // Add common twice
    for (int i = 0; i < commonExcuses.size(); i++) {
        weightedExcuses.push_back(commonExcuses[i]);
        weightedExcuses.push_back(commonExcuses[i]);
    }

    // Add rare once
    for (int i = 0; i < rareExcuses.size(); i++) {
        weightedExcuses.push_back(rareExcuses[i]);
    }

    // 🔹 Random generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle
    shuffle(weightedExcuses.begin(), weightedExcuses.end(), gen);

    // 🔹 No repeat logic
    static int index = 0;

    if (index >= weightedExcuses.size()) {
        shuffle(weightedExcuses.begin(), weightedExcuses.end(), gen);
        index = 0;
    }

    string excuse = weightedExcuses[index++];

    // Replace name
    replaceName(excuse, name);

    // Output
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}