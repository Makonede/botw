#pragma once

#include <heap/seadDisposer.h>
#include <math/seadMatrix.hpp>

namespace ksys::act {
class Actor;
}

namespace ksys::evt {

class Event;
class Metadata;

// TODO
class Manager {
    SEAD_SINGLETON_DISPOSER(Manager)
    Manager();
    virtual ~Manager();

    struct alignas(0x10) CallArg {
        sead::Matrix34<float> pos;
        bool field_30;
        bool isPauseOtherActors;
        bool field_32;
        bool field_33;
        Metadata* metadata;
        unsigned long long field_40;
        act::Actor* actor;
    };

public:
    void init(sead::Heap* heap);

    Event* getActiveEvent() const;
    bool hasActiveEvent() const;

    sead::Heap* getEventHeap() const { return mEventHeap; }

    bool doCallEvent(CallArg* event, int* x = nullptr);
    inline auto callEvent(const Metadata& metadata) {
        CallArg event{};
        int x = 0x1ff;

        event.isPauseOtherActors = true;
        event.metadata = const_cast<Metadata*>(&metadata);

        if (doCallEvent(&event, &x)) {
            if (x != 500) {
                reinterpret_cast<unsigned int*>(this)[0x74bd] |= 0x100u;
            }

            return true;
        }

        return false;
    }

private:
    u8 pad_20[0x1d178 - 0x20];
    sead::Heap* mEventHeap;
};

}  // namespace ksys::evt
