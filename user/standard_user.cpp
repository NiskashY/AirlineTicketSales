#include "standard_user.h"

bool StandardUser::StandardUserAllowed() const {
    return access_;
}
