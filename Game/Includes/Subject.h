#pragma once
#include "Observer.h"
#include <list>

template<typename T>
class Subject
{
public:
    // Add an observer to the list of listeners
    void AddListener(Observer<T>* o)
    {
        m_Observers.push_back(o);
    }

    // Remove an observer from the list of listeners
    void RemoveListener(Observer<T>* o)
    {
        m_Observers.remove(o);
    }

    // Notify all listeners with a value of type T
    void Invoke(const T& value)
    {
        for (Observer<T>* o : m_Observers)
        {
            o->OnNotify(value);
        }
    }

private:
    // List of observers (listeners) of type T
    std::list<Observer<T>*> m_Observers;
};
