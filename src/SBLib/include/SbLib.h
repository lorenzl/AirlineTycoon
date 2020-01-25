#pragma once

#include <string>
#include <list>

typedef CStdString SBStr;

template <class T>
class SBList
{
public:
    SBList() : mList() { mIt = mList.end(); }

    T& Add(const T& elem)
    {
        mList.push_back(elem);
        return mList.back();
    }

    int GetNumberOfElements()
    {
        return mList.size();
    }

    T& Get(size_t i)
    {
        GetFirst();
        while (--i > 0)
            GetNext();
        return GetLastAccessed();
    }

    T& GetLastAccessed()
    {
        return *mIt;
    }

    void RemoveLastAccessed()
    {
        mList.erase(mIt);
    }

    void Clear()
    {
        if (!mList.empty())
           mList.clear();
    }

    T& GetFirst() { return *(mIt = mList.begin()); }
    T& GetNext() { return *mIt++; }
    bool IsLast() { return mIt == mList.end(); }

private:
    std::list<T> mList;
    typename std::list<T>::iterator mIt;
};
