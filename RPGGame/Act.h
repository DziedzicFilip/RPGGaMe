#pragma once
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
    bool loadFromFile(const std::string& filename);
    std::string getChapterContent(int id) const;
    void markChapterCompleted(int id);
    bool isChapterCompleted(int id) const;
    void printAllChaptersStatus() const;
    int getFirstIncompleteChapter() const;
};
