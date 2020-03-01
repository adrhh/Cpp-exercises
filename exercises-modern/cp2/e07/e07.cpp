
#include <windows.h>
#include <vector>
#include <memory>
#include <vector>
#include <iostream>

template<typename Traits>
class unique_handle
{
	using pointer = typename Traits::pointer;
	pointer m_value;
public:
	unique_handle(unique_handle const&) = delete;
	unique_handle& operator=(unique_handle const&) = delete;
	explicit unique_handle(pointer value = Traits::invalid()) noexcept
		: m_value{ value } {}
	unique_handle(unique_handle&& other) noexcept
		: m_value{ other.release() } {}
	unique_handle& operator=(unique_handle&& other) noexcept
	{
		if (this != &other)
			reset(other.release());
		return *this;
	}
	~unique_handle()
	{
		Traits::close(m_value);
	}
	explicit operator bool() const noexcept
	{
		return m_value != Traits::invalid();
	}
	pointer get() const noexcept
	{
		return m_value;
	}
	pointer release() noexcept
	{
		auto value = m_value;
		m_value = Traits::invalid();
		return value;
	}
	bool reset(pointer value = Traits::invalid()) noexcept
	{
		if (m_value != value)
		{
			Traits::close(m_value);
			m_value = value;
		}
		return static_cast<bool>(*this);
	}
	void swap(unique_handle<Traits> & other) noexcept
	{
		std::swap(m_value, other.m_value);
	}
};

template <typename Traits>
void swap(unique_handle<Traits>& left, unique_handle<Traits>& right)
{
	left.swap(right);
}

template <typename Traits>
bool operator==(const unique_handle<Traits>& right, const unique_handle<Traits>& left)
{
	return right.get() == left.get();
}

template <typename Traits>
bool operator!=(const unique_handle<Traits>& right, const unique_handle<Traits>& left)
{
	return right.get() != left.get();
}

struct handle_traits
{
	using pointer = HANDLE;
	static pointer invalid() noexcept { return nullptr; }
	static void close(pointer value) noexcept
	{
		CloseHandle(value);
	}
};

using handle = unique_handle<handle_traits>;

int main()
{
	handle hand{
		CreateFileW(
			L"test.txt",
			GENERIC_READ,
			FILE_SHARE_READ,
			nullptr,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			nullptr
		)
	};
	if (!(!hand))
	{
		std::vector<char> buff(127);
		auto data_ptr = buff.data();
		unsigned long bytesRead = 0;
		do {
			if (!ReadFile(
				hand.get(),
				data_ptr++,
				1,
				&bytesRead,
				nullptr
			))break;
		} while (*data_ptr != '\n');
		std::cout << "first line from file:" << std::endl;
		for (auto const& c : buff)
			std::cout << c;
	}

	return 0;
}
