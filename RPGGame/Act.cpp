#include "Act.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool Act::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::stringstream chapterContent;
    int currentChapterId = 0;

    while (std::getline(file, line)) {
        if (line.rfind("# Rozdzial", 0) == 0) {
            if (chapterContent.tellp() > 0) {
                chapters.push_back({ currentChapterId, chapterContent.str() });
                chapterCompleted[currentChapterId] = false;
                chapterContent.str("");
                chapterContent.clear();
            }

            currentChapterId++;
        }
        else {
            chapterContent << line << '\n';
        }
    }

    if (chapterContent.tellp() > 0) {
        chapters.push_back({ currentChapterId, chapterContent.str() });
        chapterCompleted[currentChapterId] = false;
    }

    file.close();
    return true;
}

std::string Act::getChapterContent(int id) const {
    for (const auto& chapter : chapters) {
        if (chapter.id == id) {
            return chapter.content ;

        }
    }
    return "";
}

void Act::markChapterCompleted(int id) {
    if (chapterCompleted.find(id) != chapterCompleted.end()) {
        chapterCompleted[id] = true;
    }
}

bool Act::isChapterCompleted(int id) const {
    auto it = chapterCompleted.find(id);
    if (it != chapterCompleted.end()) {
        return it->second;
    }
    return false;
}

void Act::printAllChaptersStatus() const {
    for (const auto& chapter : chapters) {
        std::cout << "Rozdzial " << chapter.id
            << " - " << (isChapterCompleted(chapter.id) ? "Ukonczony" : "Nie ukonczony") << std::endl;
    }
}
int Act::getFirstIncompleteChapter() const {
    for (const auto& chapter : chapters) {
        int id = chapter.id;
        auto it = chapterCompleted.find(id);
        if (it == chapterCompleted.end() || !it->second) {
            return id;
        }
    }
    return -1; // Wszystkie rozdzia³y ukoñczone
}
int Act::getLastCompletedChapter() const {
    int lastCompletedId = -1;
    for (const auto& chapter : chapters) {
        int id = chapter.id;
        auto it = chapterCompleted.find(id);
        if (it != chapterCompleted.end() && it->second) {
            lastCompletedId = id;
        }
    }
    return lastCompletedId;
}
