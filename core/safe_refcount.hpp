#pragma once

// Code copied from Godot and updated to fit with pulsar

#include <atomic>
#include <type_traits>


template <class T>
class SafeNumeric {
	std::atomic<T> value;

	static_assert(std::atomic<T>::is_always_lock_free);

public:
	void set(T p_value) {
		value.store(p_value, std::memory_order_release);
	}

	T get() const {
		return value.load(std::memory_order_acquire);
	}

	T increment() {
		return value.fetch_add(1, std::memory_order_acq_rel) + 1;
	}

	// Returns the original value instead of the new one
	T postIncrement() {
		return value.fetch_add(1, std::memory_order_acq_rel);
	}

	T decrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel) - 1;
	}

	// Returns the original value instead of the new one
	T postDecrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel);
	}

	T add(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel) + p_value;
	}

	// Returns the original value instead of the new one
	T postAdd(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel);
	}

	T sub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel) - p_value;
	}

	// Returns the original value instead of the new one
	T postSub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel);
	}

	T exchangeIfGreater(T p_value) {
		while (true) {
			T tmp = value.load(std::memory_order_acquire);
			if (tmp >= p_value) {
				return tmp; // already greater, or equal
			}
			if (value.compare_exchange_weak(tmp, p_value, std::memory_order_release)) {
				return p_value;
			}
		}
	}

	T conditionalIncrement() {
		while (true) {
			T c = value.load(std::memory_order_acquire);
			if (c == 0) {
				return 0;
			}
			if (value.compare_exchange_weak(c, c + 1, std::memory_order_release)) {
				return c + 1;
			}
		}
	}

	explicit SafeNumeric<T>(T p_value = static_cast<T>(0)) {
		set(p_value);
	}
};

class SafeFlag {
	std::atomic_bool flag;

	static_assert(std::atomic_bool::is_always_lock_free);

public:
	bool isSet() const {
		return flag.load(std::memory_order_acquire);
	}

	void set() {
		flag.store(true, std::memory_order_release);
	}

	void clear() {
		flag.store(false, std::memory_order_release);
	}

	void setTo(bool p_value) {
		flag.store(p_value, std::memory_order_release);
	}

	explicit SafeFlag(bool p_value = false) {
		setTo(p_value);
	}
};

class SafeRefCount {
	SafeNumeric<uint32_t> count;

public:
	bool ref() { // true on success
		return count.conditionalIncrement() != 0;
	}

	uint32_t refVal() { // none-zero on success
		return count.conditionalIncrement();
	}

	bool unref() { // true if must be disposed of
		return count.decrement() == 0;
	}

	uint32_t unrefVal() { // 0 if must be disposed of
		return count.decrement();
	}

	uint32_t get() const {
		return count.get();
	}

	void init(uint32_t p_value = 1) {
		count.set(p_value);
	}
};
