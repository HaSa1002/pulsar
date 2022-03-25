#include "reference.hpp"

bool RefCounted::initRef() {
	if (reference()) {
		if (!is_referenced() && refcount_init.unref()) {
			unreference(); // first referencing is already 1, so compensate for the ref above
		}

		return true;
	} else {
		return false;
	}
}

int RefCounted::referenceGetCount() const {
	return refcount.get();
}

bool RefCounted::reference() {
	return refcount.refVal() != 0;
}

bool RefCounted::unreference() {
	return refcount.unrefVal() == 0;
}

RefCounted::RefCounted() {
	refcount.init();
	refcount_init.init();
}
