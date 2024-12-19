/*
Mục lục của một cuốn sách được lưu trữ dưới dạng một cây trong đó mỗi node có thể là chapter, section, subsection, subsubsection.  
Khai báo cấu trúc cây để biểu diễn cuốn sách. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện:  
Xác định số chương của cuốn sách 
Tìm chương dài nhất của cuốn sách 
Thực hiện tìm một mục và xoá mục đó khỏi sách. Lưu ý cập nhật lại số trang của từng mục.  
*/

#include <iostream>
#include <string>
using namespace std;

enum NodeType {BOOK, CHAPTER, SECTION, SUBSECTION, SUBSUBSECTION}; // NodeType co the la chapter, section, subsection, subsubsection

/* example for tree of tableOfContents:
                                  Book
Chapter           1(first)       2(next)         3(next)   
Section         1.1      1.2       2.1        3.1        3.2
Subsection               1.2.1
Subsubsection            1.2.1.1
*/

struct Node {
    string Title;
    NodeType Type;
    int Page;
    Node* first;
    Node* next;

    Node(string str, NodeType type, int page):
        Title(str), Type(type), Page(page), first(nullptr), next(nullptr) {}
};

void addChild(Node* parent, Node* child) {
    if (!parent->first) {
        parent->first = child;
    } else {
        Node* brother = parent->first;
        while (brother->next) {
            brother = brother->next;
        }
        brother->next = child;
    }
}

void display(Node* root, int& p) {
    if (!root) return;
    if (root->Type == BOOK) {
        cout << root->Title << endl;
    } else {
        p += root->Page;
        cout << root->Title << " ...... " << p << endl;
    }
    display(root->first, p);
    display(root->next, p);
}

int countChapters(Node* root) {
    if (!root) return 0;
    int count = (root->Type == CHAPTER) ? 1 : 0;
    return count + countChapters(root->first) + countChapters(root->next);
}

Node* findLongestChapter(Node* root) {
    Node* longest = nullptr;
    int maxPages = 0;

    while (root) {
        if (root->Type == CHAPTER && root->Page > maxPages) {
            longest = root;
            maxPages = root->Page;
        }
        root = root->next;
    }

    return longest;
}

void deleteSubtree(Node* node) {
    if (!node) return;
    deleteSubtree(node->first);
    deleteSubtree(node->next);
    delete node;
}

bool deleteChapter(Node*& root, const string& target, int& removedPages) {
    if (!root) return false;

    if (root->Title == target && root->Type == CHAPTER) {
        removedPages += root->Page;
        Node* temp = root;
        root = root->next;
        delete temp;
        return true;
    }

    if (deleteChapter(root->first, target, removedPages)) return true;
    return deleteChapter(root->next, target, removedPages);
}

int main() {
    Node* book = new Node("Sach giao khoa", BOOK, 0);

    Node* chapter1 = new Node("Chapter 1: Ly thuyet", CHAPTER, 11);
    Node* chapter2 = new Node("Chapter 2: Vi du", CHAPTER, 22);
    Node* chapter3 = new Node("Chapter 3: Bai tap van dung", CHAPTER, 33);

    Node* section1_1 = new Node("1.1 Ly thuyet 1", SECTION, 5);
    Node* section1_2 = new Node("1.2 Ly thuyet 2", SECTION, 6);
    Node* subsection1_2_1 = new Node("1.2.1 Dinh nghia 1", SUBSECTION, 2);
    Node* subsubsection1_2_1_1 = new Node("1.2.1.1 Bo de 1", SUBSUBSECTION, 4);

    Node* section2_1 = new Node("2.1 Vi du 1", SECTION, 22);

    Node* section3_1 = new Node("3.1 Dang bai 1", SECTION, 11);
    Node* section3_2 = new Node("3.2 Dang bai 2", SECTION, 22);

    addChild(book, chapter1);
    addChild(book, chapter2);
    addChild(book, chapter3);

    addChild(chapter1, section1_1);
    addChild(chapter1, section1_2);
    addChild(section1_2, subsection1_2_1);
    addChild(subsection1_2_1, subsubsection1_2_1_1);

    addChild(chapter2, section2_1);

    addChild(chapter3, section3_1);
    addChild(chapter3, section3_2);

    int p=0;
    cout << "Table of Contents:\n";
    display(book, p);

    int chapterCount = countChapters(book);
    cout << "\nNumber of chapters: " << chapterCount << endl;

    Node* longestChapter = findLongestChapter(book->first);
    if (longestChapter) {
        cout << "Longest chapter: " << longestChapter->Title << " with " << longestChapter->Page << " pages." << endl;
    }

    // Delete Chapter
    string target;
    cout << "\nEnter the title of the chapter to delete (Chapter 2: Vi du): ";
    getline(cin, target);

    int removedPages = 0;
    if (deleteChapter(book, target, removedPages)) {
        cout << "Deleted chapter: " << target << ", removed pages: " << removedPages << endl;
    } else {
        cout << "Chapter not found: " << target << endl;
    }
    p=0;
    cout << "\nUpdated Table of Contents:\n";
    display(book, p);
    
    deleteSubtree(book);
    return 0;
}
