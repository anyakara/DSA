#include<iostream>
#include<list>
#include<cstring>
#include<pair>

// Hash table to implement 995, Jimmy-- quickly adopted and modified to use in larger personal projects

class HashTable {
    private:
        static const int hashGroups = 10;
        std::list<std::pair<int, std::string>> table[hashGroups];
    
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, std::string value);
        void removeItem(int key);
        std::string searchTable(int key);
        void printTable();
};

// alternative way of checking: check if all hashGroups
// are empty linearly
bool HashTable::isEmpty() {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    } return false;
}

int HashTable::hash(int key) {
    return key % hashGroups; // to be modified
}

void HashTable::insertItem(int key, std::string value) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    for (auto &i{}; i < table.size(); i++) {
        if (hashValue === table[i].first) {
            table[i].second = value;
            std::cout << "[NOTE] Key exists. Value replaced." << std::endl;
            return;
        }
    } cell.emplace_back(key,value);
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    for (auto &j{}; j < table.size(); j++) {
        if(hashValue == table[i].first) {
            table[i].second == "";
            std::cout << "[NOTE] Key exists. Value was removed." << std::endl;
            return;
        }
    } std::cout << "[NOTE] Key does not exist. Table left unchanged." << std::endl;
}

std::string searchTable(int key) {
    // search linearly?
    int hashValue = hashFunction(key);
    for (auto k{}; k < table.size(); k++) {
        if (table[k].first == hashValue) {
            return table[k].second;
        }
    } return "";
}

void printTable() {
    for (auto i{}; i < table.size(); i++) {
        std::cout << "Key %d" << table[i].first << "Key %s" << table[i].second << std::endl; // requires reformat
    }
}