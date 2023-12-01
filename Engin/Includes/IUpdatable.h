#pragma once

namespace project {
    // Interface for objects that require regular updates.
    class IUpdatable
    {
    public:
        // Virtual method to update the object with the elapsed time.
        virtual void Update(float dt) = 0;
    };
}
