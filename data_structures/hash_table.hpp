#ifndef __HASH_TABLE_HPP
#define __HASH_TABLE_HPP

#include <list>
#include <string>

class HashTable {
    private:
        size_t count;
        static const int _hashPairs = 10;
        std::list<std::pair<int, std::string>> table[_hashPairs];
    public:
        HashTable();
        ~HashTable();
        bool isEmpty() const;
        int hashFunction(int key);
        void insertOne(int key, std::string value);
        void removeOne(int key);
        std::string searchTable(int key);
        void printTable();
};


HashTable::HashTable()
{
    count = 0;
}


HashTable::~HashTable()
{
    for (unsigned i{0}; i < _hashPairs; i++) {
        removeOne(i);
    }
}


bool HashTable::isEmpty() const
{
    if (count == 0) {
        return true;
    }
    return false;
}


void HashTable::insertOne(int key, std::string value)
{

}


void removeOne(int key)
{

}


std::string searchTable(int key) 
{

}


void printTable()
{

}




#endif