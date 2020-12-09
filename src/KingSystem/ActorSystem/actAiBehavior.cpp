#include "KingSystem/ActorSystem/actAiBehavior.h"

namespace ksys::act::ai {

Behavior::Behavior(const InitArg& arg)
    : mActor(arg.actor), mDefIdx(static_cast<u16>(arg.def_idx)) {}

}  // namespace ksys::act::ai
