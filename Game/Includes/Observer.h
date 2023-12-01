#pragma once

// Template class for defining observers that respond to notifications.
template<typename T>
class Observer
{
public:
    // Virtual destructor to ensure proper cleanup in derived classes.
    virtual ~Observer() = default;

    // Abstract method that should be implemented by concrete observers.
    // This method is called when the observer is notified about a change or event.
    virtual void OnNotify(const T& value) = 0;
};
