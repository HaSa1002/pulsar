#pragma once

// Copied from Godot and matched to our code

#include "safe_refcount.hpp"
#include "object.hpp"

/// Reference counted object
class RefCounted : public Object {
	SafeRefCount refcount;
	SafeRefCount refcount_init;

public:
	bool is_referenced() const { return refcount_init.get() != 1; }

	bool initRef();

	bool reference(); // returns false if refcount is at zero and didn't get increased
	bool unreference();

	int referenceGetCount() const;

	RefCounted();
	~RefCounted() {}
};

template<class T>
class Ref {
	T* reference = nullptr;

	void ref(const Ref& p_from) {
		if (p_from.reference == reference) {
			return;
		}

		unref();

		reference = p_from.reference;
		if (reference) {
			reference->reference();
		}
	}

	void ref_pointer(T* p_ref) {
		ERR_FAIL_COND(!p_ref);

		if (p_ref->initRef()) {
			reference = p_ref;
		}
	}

	//virtual RefCounted * get_reference() const { return reference; }
public:
	bool operator==(const T* p_ptr) const {
		return reference == p_ptr;
	}

	bool operator!=(const T* p_ptr) const {
		return reference != p_ptr;
	}

	bool operator<(const Ref<T>& p_r) const {
		return reference < p_r.reference;
	}

	bool operator==(const Ref<T>& p_r) const {
		return reference == p_r.reference;
	}

	bool operator!=(const Ref<T>& p_r) const {
		return reference != p_r.reference;
	}

	T* operator->() {
		return reference;
	}

	T* operator*() {
		return reference;
	}

	const T* operator->() const {
		return reference;
	}

	const T* ptr() const {
		return reference;
	}

	T* ptr() {
		return reference;
	}

	const T* operator*() const {
		return reference;
	}

	void operator=(const Ref& p_from) {
		ref(p_from);
	}

	template<class T_Other>
	void operator=(const Ref<T_Other>& p_from) {
		RefCounted* refb = const_cast<RefCounted*>(static_cast<const RefCounted*>(p_from.ptr()));
		if (!refb) {
			unref();
			return;
		}
		Ref r;
		r.reference = Object::castTo<T>(refb);
		ref(r);
		r.reference = nullptr;
	}


	template<class T_Other>
	void reference_ptr(T_Other* p_ptr) {
		if (reference == p_ptr) {
			return;
		}
		unref();

		T * r = Object::castTo<T>(p_ptr);
		if (r) {
			ref_pointer(r);
		}
	}

	Ref(const Ref& p_from) {
		ref(p_from);
	}

	template<class T_Other>
	Ref(const Ref<T_Other>& p_from) {
		RefCounted* refb = const_cast<RefCounted*>(static_cast<const RefCounted*>(p_from.ptr()));
		if (!refb) {
			unref();
			return;
		}
		Ref r;
		r.reference = Object::castTo<T>(refb);
		ref(r);
		r.reference = nullptr;
	}

	Ref(T* p_reference) {
		if (p_reference) {
			ref_pointer(p_reference);
		}
	}

	inline bool is_valid() const { return reference != nullptr; }

	inline bool is_null() const { return reference == nullptr; }

	void unref() {
		if (reference && reference->unreference()) {
			delete reference;
		}
		reference = nullptr;
	}

	void instantiate() {
		ref(new T);
	}

	Ref() {}

	~Ref() {
		unref();
	}
};
