export module synodic.soul.engine:structures;

import std;

// Span: Non-owning view over a contiguous sequence (similar to std::span)
// Using std::span namespace for compatibility
export namespace std {

template <typename T>
class span {
public:
    using element_type = T;
    using value_type = std::remove_cv_t<T>;
    using size_type = std::size_t;
    using pointer = T*;
    using reference = T&;
    using iterator = T*;

    // Constructors
    constexpr span() noexcept : data_(nullptr), size_(0) {}

    constexpr span(pointer ptr, size_type count) noexcept
        : data_(ptr), size_(count) {}

    constexpr span(pointer first, pointer last) noexcept
        : data_(first), size_(last - first) {}

    template <std::size_t N>
    constexpr span(element_type (&arr)[N]) noexcept
        : data_(arr), size_(N) {}

    template <typename Container>
    constexpr span(Container& cont) noexcept
        : data_(cont.data()), size_(cont.size()) {}

    // Element access
    constexpr reference operator[](size_type idx) const noexcept {
        return data_[idx];
    }

    constexpr pointer data() const noexcept { return data_; }
    constexpr size_type size() const noexcept { return size_; }
    constexpr bool empty() const noexcept { return size_ == 0; }

    // Iterators
    constexpr iterator begin() const noexcept { return data_; }
    constexpr iterator end() const noexcept { return data_ + size_; }

    // Subviews
    constexpr span<element_type> subspan(size_type offset, size_type count) const noexcept {
        return span(data_ + offset, count);
    }

private:
    pointer data_;
    size_type size_;
};

} // namespace std

// RingBuffer: Fixed-size circular buffer
export template <typename T, std::size_t N>
class RingBuffer {
public:
    RingBuffer() : head_(0), tail_(0), size_(0) {}

    // Add element to the buffer (overwrites oldest if full)
    void Push(const T& value) {
        buffer_[head_] = value;
        head_ = (head_ + 1) % N;
        if (size_ < N) {
            ++size_;
        } else {
            tail_ = (tail_ + 1) % N;
        }
    }

    void Push(T&& value) {
        buffer_[head_] = std::move(value);
        head_ = (head_ + 1) % N;
        if (size_ < N) {
            ++size_;
        } else {
            tail_ = (tail_ + 1) % N;
        }
    }

    // Access elements (0 is newest, N-1 is oldest)
    T& operator[](std::size_t index) noexcept {
        std::size_t actual_index = (head_ - 1 - index + N) % N;
        return buffer_[actual_index];
    }

    const T& operator[](std::size_t index) const noexcept {
        std::size_t actual_index = (head_ - 1 - index + N) % N;
        return buffer_[actual_index];
    }

    // Size queries
    std::size_t size() const noexcept { return size_; }
    std::size_t capacity() const noexcept { return N; }
    bool empty() const noexcept { return size_ == 0; }
    bool full() const noexcept { return size_ == N; }

    // Clear the buffer
    void clear() noexcept {
        head_ = 0;
        tail_ = 0;
        size_ = 0;
    }

private:
    std::array<T, N> buffer_;
    std::size_t head_;
    std::size_t tail_;
    std::size_t size_;
};

// TypeTraits: Additional type trait utilities
export namespace TypeTraits {

// Check if a type is any of the given types
template <typename T, typename... Types>
struct is_any_of : std::bool_constant<(std::is_same_v<T, Types> || ...)> {};

template <typename T, typename... Types>
inline constexpr bool is_any_of_v = is_any_of<T, Types...>::value;

// Function traits
template <typename T>
struct function_traits;

template <typename R, typename... Args>
struct function_traits<R(Args...)> {
    using return_type = R;
    using argument_types = std::tuple<Args...>;
    static constexpr std::size_t arity = sizeof...(Args);
};

template <typename R, typename... Args>
struct function_traits<R(*)(Args...)> : function_traits<R(Args...)> {};

template <typename C, typename R, typename... Args>
struct function_traits<R(C::*)(Args...)> : function_traits<R(Args...)> {
    using class_type = C;
};

template <typename C, typename R, typename... Args>
struct function_traits<R(C::*)(Args...) const> : function_traits<R(Args...)> {
    using class_type = C;
};

} // namespace TypeTraits
