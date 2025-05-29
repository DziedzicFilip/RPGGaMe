#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

class Act {
private:
    struct Chapter {
        int id;
        std::string content;
    };

    std::vector<Chapter> chapters;
    std::unordered_map<int, bool> chapterCompleted;

public:
    bool loadFromFile(const std::string& filename) {
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

    std::string getChapterContent(int id) const {
        for (const auto& chapter : chapters) {
            if (chapter.id == id) {
                return chapter.content;
            }
        }
        return "Rozdzial nie znaleziony.";
    }

    void markChapterCompleted(int id) {
        if (chapterCompleted.find(id) != chapterCompleted.end()) {
            chapterCompleted[id] = true;
        }
    }

    bool isChapterCompleted(int id) const {
        auto it = chapterCompleted.find(id);
        if (it != chapterCompleted.end()) {
            return it->second;
        }
        return false;
    }

    void printAllChaptersStatus() const {
        for (const auto& chapter : chapters) {
            std::cout << "Rozdzial " << chapter.id
                << " - " << (isChapterCompleted(chapter.id) ? "Ukonczony" : "Nie ukonczony") << std::endl;
        }
    }
};
