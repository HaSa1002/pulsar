#include "common.hpp"
#include "string/string.hpp"

#include <functional>
#include <map>
#include <set>
#include <iostream>

#include "doctest.h"

namespace pulsar {
	// Get rid of std::function
	// https://stackoverflow.com/questions/9054774/difference-between-stdfunction-and-a-standard-function-pointer/9054802#9054802
	// https://stackoverflow.com/questions/28746744/passing-capturing-lambda-as-function-pointer

	template <class... Args>
	class Event {
	public:
		using Func = std::function<void(Args...)>;
		const size_t InvalidId = std::numeric_limits<size_t>::max();

	private:
		std::map<size_t, Func> callbacks;
		size_t max_id = 0;

	public:
		size_t connect(Func&& callback) {
			ERR_FAIL_COND_V_MSG(!callback, InvalidId, "A function callback needs to be bound!");
			callbacks[max_id++] = callback;
			return max_id - 1;
		}

		void disconnect(size_t id) {
			ERR_FAIL_COND_MSG(callbacks.find(id) == callbacks.end(),
					"Tried to disconnect non existent id");
			callbacks.erase(id);
		}

		void emit(Args&&... args) {
			for (auto listener : callbacks) {
				ERR_CONTINUE_MSG(!listener.second, "Empty listener was tried to be emitted!");
				listener.second(args...);
			}
		}

		Event<Args...>& operator()(Args&&... args) {
			emit(std::forward<Args>(args)...);
			return *this;
		}

		size_t get_last_id() {
			ERR_FAIL_COND_V_MSG(max_id == 0, InvalidId, "You cannot obtain an id without binding a callback first!");
			return max_id - 1;
		}

		size_t operator+=(Func&& callback) {
			return connect(std::forward<Func>(callback));
		}

		Event<Args...>& operator-=(const size_t& id) {
			disconnect(id);
			return *this;
		}
	};

	template <>
	class Event<void> {
	public:
		using Func = std::function<void(void)>;

	private:
		std::map<size_t, Func> callbacks;
		size_t max_id = 0;

	public:
		size_t connect(Func&& callback) {
			callbacks[max_id++] = callback;
			return max_id - 1;
		}

		void disconnect(size_t id) {
			ERR_FAIL_COND_MSG(callbacks.find(id) == callbacks.end(),
					"Tried to disconnect non existent id");
			callbacks.erase(id);
		}

		void emit() {
			for (auto listener : callbacks) {
				listener.second();
			}
		}

		Event<void>& operator()() {
			for (auto listener : callbacks) {
				listener.second();
			}
			return *this;
		}

		size_t get_last_id() {
			ERR_FAIL_COND_V_MSG(max_id == 0, std::numeric_limits<size_t>::max(), "You cannot obtain an id without binding a callback first!");
			return max_id - 1;
		}

		size_t operator+=(Func&& callback) {
			callbacks[max_id++] = callback;
			return max_id - 1;
		}

		Event<void>& operator-=(const size_t& id) {
			disconnect(id);
			return *this;
		}
	};

	TEST_CASE("Event/Signal Tests") {
		SUBCASE("Event<const char*>") {
			Event<const char*> OnMessage;
			int calls = 0;
			size_t id = OnMessage.connect([&calls](const char* str) {
				std::cout << "Received Message: " << str << "\n";
				CHECK_EQ(str, "Hello World");
				++calls;
			});
			CHECK_EQ(id, 0);
			OnMessage.emit("Hello World");
			OnMessage.disconnect(id);
			OnMessage("garbage message"); //if someone get's called, we will get failed checks and a wrong counter
			id = OnMessage += [&calls](const char* str) {
				std::cout << "Hello again\n";
				CHECK_EQ(str, "second message");
				++calls;
			};
			OnMessage("second message");
			OnMessage -= id;
			auto callback = [&calls](const char* str) {
				CHECK_EQ(str, "third message");
				++calls;
			};
			OnMessage += callback;
			OnMessage("third message");
			OnMessage -= OnMessage.get_last_id();
			OnMessage("fourth message"); //shouldn't call anything
			CHECK_EQ(calls, 3);
		}

		SUBCASE("Event<int, int>") {
			Event<int, int> OnMultiply;
			size_t calls = 0;
			for (size_t i = 0; i < 10; i++) {
				CHECK_EQ(OnMultiply.connect([i, &calls](int a, int b) { 
					std::cout << "Num " << i << " resulting in " << i + a * b << "\n"; 
					++calls; }),
						i);
			}
			OnMultiply(2, 4);
			CHECK_EQ(calls, 10);
		}

		SUBCASE("Event<void>") {
			Event<void> OnPressed;
			size_t calls = 0;
			size_t id = OnPressed += [&calls]() {
				++calls;
			};
			OnPressed();
			OnPressed.emit();
			OnPressed -= id;
			OnPressed();
			CHECK_EQ(calls, 2);
		}
	}
} // namespace pulsar