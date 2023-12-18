#ifndef ASF_LOGGING_LOGSDK_STRING_VIEW_HPP
#define ASF_LOGGING_LOGSDK_STRING_VIEW_HPP

#include <ostream>
#include <string>
#include <algorithm>

// for MSVC compiler
#ifdef _MSVC_LANG
#  define ASF_LOGSDK_STRINGVIEW_CPLUSPLUS           _MSVC_LANG
#else
#  define ASF_LOGSDK_STRINGVIEW_CPLUSPLUS           __cplusplus
#endif

// c++14 and later
#if ASF_LOGSDK_STRINGVIEW_CPLUSPLUS >= 201402L
#  define ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR     constexpr
#else
#  define ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR
#endif

// c++17 and later
#if ASF_LOGSDK_STRINGVIEW_CPLUSPLUS >= 201703L
#  define ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR     constexpr
#  define ASF_LOGSDK_STRINGVIEW_ATTR_NODISCARD      [[nodiscard]]
#else
#  define ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR
#  define ASF_LOGSDK_STRINGVIEW_ATTR_NODISCARD
#endif

// C++20 and later
#if ASF_LOGSDK_STRINGVIEW_CPLUSPLUS >= 202002L
#  define ASF_LOGSDK_STRINGVIEW_CXX20_CONSTEXPR constexpr
#else
#  define ASF_LOGSDK_STRINGVIEW_CXX20_CONSTEXPR
#endif

#if ASF_LOGSDK_STRINGVIEW_CPLUSPLUS >= 202002L && defined(__cpp_lib_char8_t)
#  define ASF_LOGSDK_STRINGVIEW_HAS_CHAR8T  1
#endif

namespace asf {
namespace logging {
namespace logsdk {

/**
 * \class basic_string_view
 * \brief An implementation of ``std::basic_string_view`` for pre-C++17
 * 
 * The template class basic_string_view describes an object that can refer to a constant
 * contiguous sequence of char-like objects with the first element of the sequence at position zero.
 */
template<typename CharT, typename Traits = std::char_traits<CharT>>
class basic_string_view
{
public:
    // types
    using traits_type = Traits;
    using value_type = CharT;
    using pointer = value_type * ;
    using const_pointer = const value_type*;
    using reference = value_type & ;
    using const_reference = const value_type&;
    using const_iterator = const_pointer;
    using iterator = const_iterator;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using reverse_iterator = const_reverse_iterator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

#if ASF_LOGSDK_STRINGVIEW_CPLUSPLUS >= 201703L
    static constexpr size_type npos = static_cast<size_type>(-1);
#else
    static const size_type npos;
#endif

    /**
     * \brief Default constructor. Constructs an empty basic_string_view.
     * 
     * After construction, data() is equal to nullptr, and size() is equal to 0.
     */
    constexpr basic_string_view() noexcept
        : data_(nullptr), size_(0) {}
 
    /**
     * \brief Copy constructor. Constructs a view of the same content as other.
     * 
     * After construction, data() is equal to other.data(), and size() is equal to other.size().
     */
    constexpr basic_string_view(const basic_string_view& other) noexcept = default;
 
    /**
     * \brief Constructs a view of the null-terminated character string pointed to by \a str,
     * not including the terminating null character.
     * 
     * The length of the view is determined as if by Traits::length(str).
     * The behavior is undefined if [str, str+Traits::length(str)) is not a valid range.
     * After construction, data() is equal to \a str, and size() is equal to Traits::length(str).
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR basic_string_view(const CharT* str)
        : data_(str), size_(Traits::length(str)) {}
 
    /**
     * \brief Constructs a view of the first count characters of the character array starting with the
     * element pointed by \a str. \a str can contain null characters.
     * 
     * The behavior is undefined if [str, str+len) is not a valid range (even though the constructor
     * may not access any of the elements of this range). After construction, data() is equal to \a str,
     * and size() is equal to \a len.
     */
    constexpr basic_string_view(const CharT* str, size_type len)
        : data_(str), size_(len) {}

    /**
     * \brief Replaces the view with that of \a view.
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR basic_string_view& operator=(const basic_string_view& view) noexcept = default;

    /**
     * \brief Returns an iterator to the first character of the view.
     * 
     * \sa end(), cbegin(), rbegin()
     */
    constexpr const_iterator begin() const noexcept { return this->data_; }

    /**
     * \brief Returns an iterator to the first character of the view.
     * 
     * \sa cend(), begin(), crbegin()
     */
    constexpr const_iterator cbegin() const noexcept { return this->data_; }

    /**
     * \brief Returns an iterator to the character following the last character of the view.
     * 
     * This character acts as a placeholder, attempting to access it results in undefined behavior.
     * 
     * \sa begin(), cend(), rend()
     */
    constexpr const_iterator end() const noexcept { return this->data_ + this->size_; }

    /**
     * \brief Returns an iterator to the character following the last character of the view.
     * 
     * This character acts as a placeholder, attempting to access it results in undefined behavior.
     * 
     * \sa cbegin(), end(), crend()
     */
    constexpr const_iterator cend() const noexcept { return this->data_ + this->size_; }

    /**
     * \brief Returns a reverse iterator to the first character of the reversed view.
     * 
     * It corresponds to the last character of the non-reversed view.
     * 
     * \sa rend(), begin(), crbegin(),
     */
    constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }

    /**
     * \brief Returns a reverse iterator to the first character of the reversed view.
     * 
     * It corresponds to the last character of the non-reversed view.
     * 
     * \sa crend(), rbegin(), cbegin(),
    */
    constexpr const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

    /**
     * \brief Returns a reverse iterator to the character following the last character of the reversed view.
     * 
     * It corresponds to the character preceding the first character of the non-reversed view.
     * 
     * This character acts as a placeholder, attempting to access it results in undefined behavior.
     * 
     * \sa rbegin(), crend(), end()
     */
    constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

    /**
     * \brief Returns a reverse iterator to the character following the last character of the reversed view.
     * 
     * It corresponds to the character preceding the first character of the non-reversed view.
     * This character acts as a placeholder, attempting to access it results in undefined behavior.
     * 
     * \sa crbegin(), rend(), cend(),
     */
    constexpr const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }
 
    /**
     * \brief Returns the number of CharT elements in the view, i.e. std::distance(begin(), end()).
     * 
     * \sa length(), max_size(), empty()
     */
    constexpr size_type size() const noexcept { return this->size_; }

    /**
     * \brief Returns the number of CharT elements in the view, i.e. std::distance(begin(), end()).
     * 
     * \sa size(), max_size(), empty()
     */
    constexpr size_type length() const noexcept { return this->size_; }

    /**
     * \brief The largest possible number of char-like objects that can be referred to by a view.
     * 
     * \sa size(), length(), empty()
     */
    constexpr size_type max_size() const noexcept 
    { 	
        return (npos - sizeof(size_type) - sizeof(void*)) / sizeof(value_type) / 4;
    }

    /**
     * \brief Checks if the view has no characters, i.e. whether size() == 0.
     * 
     *\sa size(), length(), max_size()
     */
    ASF_LOGSDK_STRINGVIEW_ATTR_NODISCARD constexpr bool empty() const noexcept { return this->size_ == 0; }
 
    /**
     * \brief Returns a const reference to the character at specified location \a pos.
     * 
     * No bounds checking is performed: the behavior is undefined if pos >= size().
     * 
     * \sa at()
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR const_reference operator[](size_type pos) const noexcept
    {
        return *(this->data_ + pos);
    }
 
    /**
     * \brief Returns a reference to the character at specified location \a pos with bounds checking.
     * 
     * \exception std::out_of_range will be thrown on invalid access.
     * 
     * \sa operator[]()
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR const_reference at(size_t pos) const
    {
        if (pos >= this->size_)
        {
            throw std::out_of_range("out of range in " __FILE__);
        }
        return *(this->data_ + pos);
    }
 
    /**
     * \brief Returns reference to the first character in the view.
     * 
     * The behavior is undefined if empty() == true.
     * 
     * \sa back(), empty()
     */
    constexpr const_reference front() const { return *(this->data_); }
    
    /**
     * \brief Returns reference to the last character in the view.
     * 
     * The behavior is undefined if empty() == true.
     * 
     * \sa front(), empty()
     */
    constexpr const_reference back() const { return *(this->data_ + this->size_ - 1); }

    /**
     * \brief Returns a pointer to the underlying character array.
     * 
     * The pointer is such that the range [data(); data() + size()) is valid and the values
     * in it correspond to the values of the view.
     * 
     * \note Unlike std::basic_string::data() and string literals, data() may return a pointer
     *       to a buffer that is not null-terminated. Therefore it is typically a mistake to pass data()
     *       to a routine that takes just a const CharT* and expects a null-terminated string.
     * 
     * \sa front(), back()
     */
    constexpr const_pointer data() const noexcept { return this->data_; }
 
    /**
     * \brief Moves the start of the view forward by \a n characters.
     * 
     * The behavior is undefined if n > size().
     * 
     * \sa remove_suffix()
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR void remove_prefix(size_type n)
    {
        this->data_ += n;
        this->size_ -= n;
    }

    /**
     * \brief Moves the end of the view back by \a n characters.
     * 
     * The behavior is undefined if n > size().
     * 
     * \sa remove_prefix()
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR void remove_suffix(size_type n)
    {
        size_ -= n;
    }

    /**
     * \brief Exchanges the view with that of \a other.
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR void swap(basic_string_view& other) noexcept
    {
        std::swap(this->data_, other.data_);
        std::swap(this->size_, other.size_);
    }
 
    /**
     * \brief  Copies the substring [pos, pos + rcount) to the character array pointed to by \a dest,
     * where rcount is the smaller of \a count and size() - pos.
     * 
     * Equivalent to:
     * \code
     *     Traits::copy(dest, data() + pos, rcount).
     * \endcode
     * 
     * \param dest     pointer to the destination character string.
     * \param count    requested substring length.
     * \param pos      position of the first character
     * \return Number of characters copied.
     * \exception std::out_of_range if \a pos > size().
     * \note std::basic_string_view::copy() has no constexpr specifier before C++20.
     * 
     * \sa substr()
     */
    ASF_LOGSDK_STRINGVIEW_CXX20_CONSTEXPR size_type copy(CharT* dest, size_type count, size_type pos = 0) const
    {
        if (pos > size())
        {
            throw std::out_of_range("out of range");
        }
        size_type rlen = std::min(count, this->size_ - pos);
        traits_type::copy(dest, data() + pos, rlen);
        return rlen;
    }
 
    /**
     * \brief Returns a view of the substring [pos, pos + count),
     * where count is the smaller of \a count and size() - pos.
     * 
     * \sa copy(), find()
     */
    ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR basic_string_view substr(size_type pos, size_type count = npos) const
    {
        if (pos > size())
        {
            throw std::out_of_range("out of range");
        }
        return basic_string_view(data() + pos, std::min(size() - pos, count));
    }
 
    /**
     * \brief The length rlen of the sequences to compare is the smaller of size() and v.size().
     * 
     * The function compares the two views by calling Traits::compare(data(), v.data(), rlen),
     * and returns a value according to the following table:
     * <table>
     *     <tr><th rowspan="1" colspan="2">Condition                                                            <th> Result                 <th> Return Value
     *     <tr><td rowspan="1" colspan="2">Traits::compare(data(), v.data(), rlen)  < 0                         <td> this is less than v    <td> <0
     *     <tr><td rowspan="3" colspan="1">Traits::compare(data(), v.data(), rlen) == 0 <td> size()  < v.size() <td> this is less than v    <td> <0
     *     <tr>                                                                         <td> size() == v.size() <td> this is equal to v     <td>  0
     *     <tr>                                                                         <td> size()  > v.size() <td> this is greater than v <td> >0
     *     <tr><td rowspan="1" colspan="2">Traits::compare(data(), v.data(), rlen)  > 0                         <td> this is greater than v <td> >0
     * </table>
     * 
     * \return negative value if this view is less than the other character sequence,
     *         zero if the both character sequences are equal, positive value if this view is
     *         greater than the other character sequence.
     * 
     * \sa operator==(), operator!=(), operator<(), operator>(), operator<=(), operator>=()
    */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR int compare(basic_string_view v) const noexcept
    {
        const int cmp = Traits::compare(this->data_, v.data_, std::min(this->size_, v.size_));
        return cmp != 0 ? cmp : (this->size_ == v.size_ ? 0 : size_ < v.size_ ? -1 : 1);
    }
 
    /**
     * Equivalent to:
     * \code
     *     substr(pos1, count1).compare(v);
     * \endcode
     * 
     * \return negative value if this view is less than the other character sequence,
     *         zero if the both character sequences are equal, positive value if this view is
     *         greater than the other character sequence.
     * 
     * \sa substr(), operator==(), operator!=(), operator<(), operator>(), operator<=(), operator>=()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR int compare(size_type pos1, size_type count1, basic_string_view v) const noexcept
    {
        return substr(pos1, count1).compare(v);
    }
 
    /**
     * Equivalent to:
     * \code
     *     substr(pos1, count1).compare(v.substr(pos2, count2));
     * \endcode
     * 
     * \return negative value if this view is less than the other character sequence,
     *         zero if the both character sequences are equal, positive value if this view is
     *         greater than the other character sequence.
     * 
     * \sa substr(), operator==(), operator!=(), operator<(), operator>(), operator<=(), operator>=()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR int compare(size_type pos1, size_type count1,
        basic_string_view v, size_type pos2, size_type count2) const
    {
        return substr(pos1, count1).compare(v.substr(pos2, count2));
    }
 
    /**
     * Equivalent to:
     * \code
     *     compare(basic_string_view(s)).
     * \endcode
     * 
     * \return negative value if this view is less than the other character sequence,
     *         zero if the both character sequences are equal, positive value if this view is
     *         greater than the other character sequence.
     * 
     * \sa operator==(), operator!=(), operator<(), operator>(), operator<=(), operator>=()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR int compare(const CharT* s) const
    {
        return compare(basic_string_view(s));
    }
 
    /**
     * Equivalent to:
     * \code
     *     substr(pos1, count1).compare(basic_string_view(s));
     * \endcode
     * 
     * \return negative value if this view is less than the other character sequence,
     *         zero if the both character sequences are equal, positive value if this view is
     *         greater than the other character sequence.
     * 
     * \sa substr(), operator==(), operator!=(), operator<(), operator>(), operator<=(), operator>=()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR int compare(size_type pos1, size_type count1, const CharT* s) const
    {
        return substr(pos1, count1).compare(basic_string_view(s));
    }
 
    /**
     * Equivalent to:
     * \code
     *     substr(pos1, count1).compare(basic_string_view(s, count2));
     * \endcode
     * 
     * \return negative value if this view is less than the other character sequence,
     *         zero if the both character sequences are equal, positive value if this view is
     *         greater than the other character sequence.
     * 
     * \sa substr(), operator==(), operator!=(), operator<(), operator>(), operator<=(), operator>=()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR int compare(size_type pos1, size_type count1,
        const CharT* s, size_type count2) const
    {
        return substr(pos1, count1).compare(basic_string_view(s, count2));
    }
 
    /**
     * \brief Checks if the string view begins with the given prefix.
     * 
     * Effectively returns:
     * \code
     *     size() >= x.size() && compare(0, x.size(), x) == 0;
     * \endcode
     * 
     * \note std::basic_string_view provides this function since from C++20, use it carefully.
     * 
     * \sa ends_with(), compare()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR bool starts_with(basic_string_view x) const noexcept
    {
        return this->size_ >= x.size_ && Traits::compare(this->data_, x.data_, x.size_) == 0;
    }
 
    /**
     * \brief Checks if the string view begins with the given prefix.
     * 
     * Effectively returns:
     * \code
     *     !empty() && Traits::eq(front(), x);
     * \endcode
     * 
     * \note std::basic_string_view provides this function since from C++20, use it carefully.
     * 
     * \sa ends_with(), compare()
     */
    constexpr bool starts_with(CharT x) const noexcept
    {
        return !empty() && Traits::eq(x, front());
    }
 
    /**
     * \brief Checks if the string view begins with the given prefix.
     * 
     * Effectively returns:
     * \code
     *     starts_with(basic_string_view(x));
     * \endcode
     * 
     * \note std::basic_string_view provides this function since from C++20, use it carefully.
     * 
     * \sa ends_with(), compare()
     */
    constexpr bool starts_with(const CharT* x) const noexcept
    {
        return starts_with(basic_string_view(x));
    }
 
    /**
     * \brief Checks if the string view ends with the given suffix.
     * 
     * Effectively returns:
     * \code
     *     size() >= x.size() && compare(size() - x.size(), npos, x) == 0;
     * \endcode
     * 
     * \note std::basic_string_view provides this function since from C++20, use it carefully.
     * 
     * \sa starts_with(), compare()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR bool ends_with(basic_string_view x) const noexcept
    {
        return size_ >= x.size_ &&
            Traits::compare(data_ + size_ - x.size_, x.data_, x.size_) == 0;
    }
 
    /**
     * \brief Checks if the string view ends with the given suffix.
     * 
     * Effectively returns:
     * \code
     *     !empty() && Traits::eq(back(), x);
     * \endcode
     * 
     * \note std::basic_string_view provides this function since from C++20, use it carefully.
     * 
     * \sa starts_with(), compare()
     */
    constexpr bool ends_with(CharT x) const noexcept
    {
        return !empty() && Traits::eq(x, back());
    }
 
    /**
     * \brief Checks if the string view ends with the given suffix.
     * 
     * Effectively returns:
     * \code
     *     ends_with(basic_string_view(x)).
     * \endcode
     * 
     * \note std::basic_string_view provides this function since from C++20, use it carefully.
     * 
     * \sa starts_with(), compare()
     */
    constexpr bool ends_with(const CharT* x) const noexcept
    {
        return ends_with(basic_string_view(x));
    }

    /**
     * \brief Checks if the string view contains the given string view.
     * 
     * \note std::basic_string_view provides this function since from C++23, use it carefully.
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR bool contains(basic_string_view v) const noexcept
    {
        return find(v) != npos;
    }

    /**
     * \brief Checks if the string view contains the given single charactor.
     * 
     * \note std::basic_string_view provides this function since from C++23, use it carefully.
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR bool contains(CharT c) const noexcept
    {
        return find(c) != npos;
    }

    /**
     * \brief Checks if the string view contains the given null-terminated character string.
     * 
     * \note std::basic_string_view provides this function since from C++23, use it carefully.
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR bool contains(const CharT* s) const noexcept
    {
        return find(s) != npos;
    }
 
    /**
     * \brief Finds the first substring equal to the given character sequence.
     * 
     * Finds the first occurence of \a v in this view, starting at position \a pos.
     * 
     * \return Position of the first character of the found substring, or npos if no such substring is found.
     * 
     * \sa rfind(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find(basic_string_view v, size_type pos = 0) const noexcept
    {
        if (pos > size() || v.empty() || v.size() > size() - pos)
        {
            return npos;
        }
        const CharT* cur = this->data_ + pos;
        const CharT* last = cend() - v.size() + 1;
        for ( ; cur != last; ++cur)
        {
            cur = Traits::find(cur, last - cur, v[0]);
            if (!cur)
            {
                break;
            }
            if (Traits::compare(cur, v.cbegin(), v.size()) == 0)
            {
                return cur - this->data_;
            }
        }
        return npos;
    }

    /**
     * \brief Finds the first substring equal to the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find(basic_string_view(std::addressof(ch), 1), pos);
     * \endcode
     * 
     * \return Position of the first character of the found substring, or npos if no such substring is found.
     * 
     * \sa rfind(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find(CharT ch, size_type pos = 0) const noexcept
    {
        if (pos <= size())
        {
            const CharT* ret_ptr = Traits::find(this->data_ + pos, this->size_ - pos, ch);
            if (ret_ptr)
            {
                return ret_ptr - this->data_;
            }
        }
        return npos;
    }

    /**
     * \brief Finds the first substring equal to the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find(basic_string_view(s, count), pos).
     * \endcode
     * 
     * \return Position of the first character of the found substring, or npos if no such substring is found.
     * 
     * \sa rfind(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find(const CharT* s, size_type pos, size_type count) const noexcept
    {
        return find(basic_string_view(s, count), pos);
    }

    /**
     * \brief Finds the first substring equal to the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find(basic_string_view(s), pos);
     * \endcode
     * 
     * \return Position of the first character of the found substring, or npos if no such substring is found.
     * 
     * \sa rfind(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find(const CharT* s, size_type pos = 0) const noexcept
    {
        return find(basic_string_view(s), pos);
    }
 
    /**
     * \brief Finds the last substring equal to the given character sequence.
     * 
     * Finds the last occurence of \a v in this view, starting at position \a pos.
     * 
     * \return Position of the first character of the found substring or npos if no such substring is found.
     * 
     * \sa find(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type rfind(basic_string_view v, size_type pos = npos) const noexcept
    {
        if (this->size_ < v.size_)
        {
            return npos;
        }
        if (pos > this->size_ - v.size_)
        {
            pos = this->size_ - v.size_;
        }
        if (v.size_ == 0u)
        { // an empty string is always found
            return pos;
        }
        for (const CharT* cur = this->data_ + pos; ; --cur)
        {
            if (Traits::compare(cur, v.data_, v.size_) == 0)
            {
                return cur - this->data_;
            }
            if (cur == this->data_)
            {
                return npos;
            }
        }
    }

    /**
     * \brief Finds the last substring equal to the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     rfind(basic_string_view(std::addressof(c), 1), pos);
     * \endcode
     * 
     * \return Position of the first character of the found substring or npos if no such substring is found.
     * 
     * \sa find(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type rfind(CharT c, size_type pos = npos) const noexcept
    {
        return rfind(basic_string_view(&c, 1), pos);
    }

    /**
     * \brief Finds the last substring equal to the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     rfind(basic_string_view(s, count), pos);
     * \endcode
     * 
     * \return Position of the first character of the found substring or npos if no such substring is found.
     * 
     * \sa find(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type rfind(const CharT* s, size_type pos, size_type count) const noexcept
    {
        return rfind(basic_string_view(s, count), pos);
    }

    /**
     * \brief Finds the last substring equal to the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     rfind(basic_string_view(s), pos);
     * \endcode
     * 
     * \return Position of the first character of the found substring or npos if no such substring is found.
     * 
     * \sa find(), find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type rfind(const CharT* s, size_type pos = npos) const noexcept
    {
        return rfind(basic_string_view(s), pos);
    }
 
    /**
     * \brief Finds the first character equal to any of the characters in the given character sequence.
     * 
     * Finds the first occurence of any of the characters of \a v in this view, starting at position \a pos.
     * 
     * \return Position of the first occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_of(basic_string_view v, size_type pos = 0) const noexcept
    {
        if (pos >= this->size_ || v.size_ == 0)
        {
            return npos;
        }
        const_iterator iter = std::find_first_of(
            this->cbegin() + pos, this->cend(), v.cbegin(), v.cend(), Traits::eq);
        return iter == this->cend() ? npos : std::distance(this->cbegin(), iter);
    }

    /**
     * \brief Finds the first character equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_first_of(basic_string_view(std::addressof(c), 1), pos);
     * \endcode
     * 
     * \return Position of the first occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_of(CharT c, size_type pos = 0) const noexcept
    {
        return find(c, pos);
    }

    /**
     * \brief Finds the first character equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_first_of(basic_string_view(s, count), pos);
     * \endcode
     * 
     * \return Position of the first occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_of(const CharT* s, size_type pos, size_type count) const noexcept
    {
        return find_first_of(basic_string_view(s, count), pos);
    }

    /**
     * \brief Finds the first character equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_first_of(basic_string_view(s), pos);
     * \endcode
     * 
     * \return Position of the first occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_last_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_of(const CharT* s, size_type pos = 0) const noexcept
    {
        return find_first_of(basic_string_view(s), pos);
    }

    /**
     * \brief Finds the last character equal to one of characters in the given character sequence.
     * 
     * Exact search algorithm is not specified. The search considers only the interval [0; pos].
     * If the character is not present in the interval, npos will be returned.
     * Finds the last occurrence of any of the characters of v in this view, ending at position pos.
     * 
     * \return Position of the last occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_of(basic_string_view v, size_type pos = npos) const noexcept
    {
        return find_last_of(v.data_, pos, v.size_);
    }

    /**
     * \brief Finds the last character equal to one of characters in the given character sequence.
     * 
     * Exact search algorithm is not specified. The search considers only the interval [0; pos].
     * If the character is not present in the interval, npos will be returned.
     * 
     * Equivalent to:
     * \code
     *     find_last_of(basic_string_view(std::addressof(c), 1), pos);
     * \endcode
     * 
     * \return Position of the last occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_of(CharT c, size_type pos = npos) const noexcept
    {
        return this->rfind(c, pos);
    }

    /**
     * \brief Finds the last character equal to one of characters in the given character sequence.
     * 
     * Exact search algorithm is not specified. The search considers only the interval [0; pos].
     * If the character is not present in the interval, npos will be returned.
     * 
     * Equivalent to:
     * \code
     *     find_last_of(basic_string_view(s, count), pos);
     * \endcode
     * 
     * \return Position of the last occurrence of any character of the substring, or npos if no such character is found.
     * \sa find(), rfind(), find_first_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_of(const CharT* s, size_type pos, size_type count) const noexcept
    {
        size_type size = this->size_;
        if (size && count)
        {
            if (--size > pos)
            {
                size = pos;
            }
            do
            {
                if (traits_type::find(s, count, this->data_[size]))
                {
                    return size;
                }
            } while (size-- != 0);
        }
        return npos;
    }

    /**
     * \brief Finds the last character equal to one of characters in the given character sequence.
     * 
     * Exact search algorithm is not specified. The search considers only the interval [0; pos].
     * If the character is not present in the interval, npos will be returned.
     * 
     * Equivalent to:
     * \code
     *     find_last_of(basic_string_view(s), pos);
     * \endcode
     * 
     * \return Position of the last occurrence of any character of the substring, or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_first_not_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_of(const CharT* s, size_type pos = npos) const noexcept
    {
        return find_last_of(s, pos, traits_type::length(s));
    }

    /**
     * \brief Finds the first character not equal to any of the characters in the given character sequence.
     * 
     * Finds the first character not equal to any of the characters of \a v in this view, starting at position \a pos.
     * 
     * \return Position of the first character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_not_of(basic_string_view v, size_type pos = 0) const noexcept
    {
        return find_first_not_of(v.data_, pos, v.size_);
    }

    /**
     * \brief Finds the first character not equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_first_not_of(basic_string_view(std::addressof(c), 1), pos);
     * \endcode
     * 
     * \return Position of the first character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_not_of(CharT c, size_type pos = 0) const noexcept
    {
        for ( ; pos < this->size_; ++pos)
        {
            if (!traits_type::eq(this->data_[pos], c))
            {
                return pos;
            }
        }
        return npos;
    }

    /**
     * \brief Finds the first character not equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_first_not_of(basic_string_view(s, count), pos);
     * \endcode
     * 
     * \return Position of the first character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_not_of(const CharT* s, size_type pos, size_type count) const noexcept
    {
        for ( ;pos < this->size_; ++pos)
        {
            if (!traits_type::find(s, count, this->data_[pos]))
            {
                return pos;
            }
        }
        return npos;
    }

    /**
     * \brief Finds the first character not equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_first_not_of(basic_string_view(s), pos);
     * \endcode
     * 
     * \return Position of the first character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_last_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_first_not_of(const CharT* s, size_type pos = 0) const noexcept
    {
        return find_first_not_of(s, pos, traits_type::length(s));
    }

    /**
     * \brief Finds the last character not equal to any of the characters in the given character sequence.
     * 
     * Finds the last character not equal to any of the characters of \a v in this view, starting at position \a pos.
     * 
     * \return Position of the last character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_first_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_not_of(basic_string_view v, size_type pos = npos) const noexcept
    {
        return find_last_not_of(v.data_, pos, v.size_);
    }

    /**
     * \brief Finds the last character not equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_last_not_of(basic_string_view(std::addressof(c), 1), pos);
     * \endcode
     * 
     * \return Position of the last character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_first_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_not_of(CharT c, size_type pos = npos) const noexcept
    {
        size_type size = this->size_;
        if (size)
        {
            if (--size > pos)
            {
                size = pos;
            }
            do
            {
                if (!traits_type::eq(this->data_[size], c))
                {
                    return size;
                }
            } while (size--);
        }
        return npos;
    }

    /**
     * \brief Finds the last character not equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_last_not_of(basic_string_view(s, count), pos);
     * \endcode
     * 
     * \return Position of the last character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_first_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_not_of(const CharT* s, size_type pos, size_type count) const noexcept
    {
        size_type size = this->size_;
        if (size)
        {
            if (--size > pos)
            {
                size = pos;
            }
            do
            {
                if (!traits_type::find(s, count, this->data_[size]))
                {
                    return size;
                }
            } while (size--);
        }
        return npos;
    }

    /**
     * \brief Finds the last character not equal to any of the characters in the given character sequence.
     * 
     * Equivalent to:
     * \code
     *     find_last_not_of(basic_string_view(s), pos);
     * \endcode
     * 
     * \return Position of the last character not equal to any of the characters in the given string,
     *         or npos if no such character is found.
     * 
     * \sa find(), rfind(), find_first_of(), find_last_of(), find_first_not_of()
     */
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type find_last_not_of(const CharT* s, size_type pos = npos) const noexcept
    {
        return find_last_not_of(basic_string_view(s), pos);
    }

private:
    template <typename r_iter>
    ASF_LOGSDK_STRINGVIEW_CXX17_CONSTEXPR size_type reverse_distance(r_iter first, r_iter last) const noexcept
    {
        // Portability note here: std::distance is not NOEXCEPT, but calling it with a string_view::reverse_iterator will not throw.
        return size_ - 1 - std::distance(first, last);
    }

    template <typename Iterator>
    Iterator find_not_of(Iterator first, Iterator last, basic_string_view v) const noexcept
    {
        for ( ; first != last; ++first)
        {
            if (0 == Traits::find(v.data_, v.size_, *first))
            {
                return first;
            }
        }
        return last;
    }

private:
    const value_type* data_;
    std::size_t size_;
}; // class basic_string_view

/**
 * \brief Compares two views.
 * 
 * \li All comparisons are done via the compare() member function (which itself is defined in terms of Traits::compare()):
 *     Two views are equal if both the size of lhs and rhs are equal and each character in \a x has an equivalent character
 *     in \a y at the same position.
 * \li The ordering comparisons are done lexicographically -- the comparison is performed by a function equivalent to
 *     std::lexicographical_compare.
 * 
 * \return \c true if the corresponding comparison holds, \c false otherwise.
 */
template<typename CharT, typename Traits>
inline ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR bool operator==(basic_string_view<CharT, Traits> x, basic_string_view<CharT, Traits> y) noexcept
{
    if (x.size() != y.size())
    {
        return false;
    }
    return x.compare(y) == 0;
}

/**
 * \brief Compares two views.
 * 
 * \li All comparisons are done via the compare() member function (which itself is defined in terms of Traits::compare()):
 *     Two views are equal if both the size of lhs and rhs are equal and each character in \a x has an equivalent character
 *     in \a y at the same position.
 * \li The ordering comparisons are done lexicographically -- the comparison is performed by a function equivalent to
 *     std::lexicographical_compare.
 * 
 * \return \c true if the corresponding comparison holds, \c false otherwise.
 */
template<typename CharT, typename Traits>
inline ASF_LOGSDK_STRINGVIEW_CXX14_CONSTEXPR bool operator!=(basic_string_view<CharT, Traits> x, basic_string_view<CharT, Traits> y) noexcept
{
    if (x.size() != y.size())
    {
        return true;
    }
    return x.compare(y) != 0;
}

/**
 * \brief Compares two views.
 * 
 * \li All comparisons are done via the compare() member function (which itself is defined in terms of Traits::compare()):
 *     Two views are equal if both the size of lhs and rhs are equal and each character in \a x has an equivalent character
 *     in \a y at the same position.
 * \li The ordering comparisons are done lexicographically -- the comparison is performed by a function equivalent to
 *     std::lexicographical_compare.
 * 
 * \return \c true if the corresponding comparison holds, \c false otherwise.
 */
template<typename CharT, typename Traits>
inline constexpr bool operator<(basic_string_view<CharT, Traits> x, basic_string_view<CharT, Traits> y) noexcept
{
    return x.compare(y) < 0;
}

/**
 * \brief Compares two views.
 * 
 * \li All comparisons are done via the compare() member function (which itself is defined in terms of Traits::compare()):
 *     Two views are equal if both the size of lhs and rhs are equal and each character in \a x has an equivalent character
 *     in \a y at the same position.
 * \li The ordering comparisons are done lexicographically -- the comparison is performed by a function equivalent to
 *     std::lexicographical_compare.
 * 
 * \return \c true if the corresponding comparison holds, \c false otherwise.
 */
template<typename CharT, typename Traits>
inline constexpr bool operator>(basic_string_view<CharT, Traits> x, basic_string_view<CharT, Traits> y) noexcept
{
    return x.compare(y) > 0;
}

/**
 * \brief Compares two views.
 * 
 * \li All comparisons are done via the compare() member function (which itself is defined in terms of Traits::compare()):
 *     Two views are equal if both the size of lhs and rhs are equal and each character in \a x has an equivalent character
 *     in \a y at the same position.
 * \li The ordering comparisons are done lexicographically -- the comparison is performed by a function equivalent to
 *     std::lexicographical_compare.
 * \return \c true if the corresponding comparison holds, \c false otherwise.
 */
template<typename CharT, typename Traits>
inline constexpr bool operator<=(basic_string_view<CharT, Traits> x, basic_string_view<CharT, Traits> y) noexcept
{
    return x.compare(y) <= 0;
}

/**
 * \brief Compares two views.
 * 
 * \li All comparisons are done via the compare() member function (which itself is defined in terms of Traits::compare()):
 *     Two views are equal if both the size of lhs and rhs are equal and each character in \a x has an equivalent character
 *     in \a y at the same position.
 * \li The ordering comparisons are done lexicographically -- the comparison is performed by a function equivalent to
 *     std::lexicographical_compare.
 * 
 * \return \c true if the corresponding comparison holds, \c false otherwise.
 */
template<typename CharT, typename Traits>
inline constexpr bool operator>=(basic_string_view<CharT, Traits> x, basic_string_view<CharT, Traits> y) noexcept
{
    return x.compare(y) >= 0;
}

/**
 * Equivalent to:
 * \code
 *     x == basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator==(basic_string_view<CharT, Traits> x,
    const std::basic_string<CharT, Traits, Allocator>& y) noexcept
{
    return x == basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) == y;
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator==(const std::basic_string<CharT, Traits, Allocator>& x,
    basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) == y;
}

/**
 * Equivalent to:
 * \code
 *     x == basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator==(basic_string_view<CharT, Traits> x, const CharT* y) noexcept
{
    return x == basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) == y;
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator==(const CharT* x, basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) == y;
}

/**
 * Equivalent to:
 * \code
 *     x != basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator!=(basic_string_view<CharT, Traits> x,
    const std::basic_string<CharT, Traits, Allocator>& y) noexcept
{
    return x != basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) != y;
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator!=(const std::basic_string<CharT, Traits, Allocator>& x,
    basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) != y;
}

/**
 * Equivalent to:
 * \code
 *     x != basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator!=(basic_string_view<CharT, Traits> x, const CharT* y) noexcept
{
    return x != basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) != y;
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator!=(const CharT* x, basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) != y;
}

/**
 * Equivalent to:
 * \code
 *     x < basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator<(basic_string_view<CharT, Traits> x,
    const std::basic_string<CharT, Traits, Allocator>& y) noexcept
{
    return x < basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) < y;
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator<(const std::basic_string<CharT, Traits, Allocator>& x,
    basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) < y;
}

/**
 * Equivalent to:
 * \code
 *     x < basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator<(basic_string_view<CharT, Traits> x, const CharT* y) noexcept
{
    return x < basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) < y;
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator<(const CharT* x, basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) < y;
}

/**
 * Equivalent to:
 * \code
 *     x > basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator>(basic_string_view<CharT, Traits> x,
    const std::basic_string<CharT, Traits, Allocator>& y) noexcept
{
    return x > basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) > y;
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator>(const std::basic_string<CharT, Traits, Allocator>& x,
    basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) > y;
}

/**
 * Equivalent to:
 * \code
 *     x > basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator>(basic_string_view<CharT, Traits> x,
    const CharT* y) noexcept
{
    return x > basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) > y;
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator>(const CharT* x, basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) > y;
}

/**
 * Equivalent to:
 * \code
 *     x <= basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator<=(basic_string_view<CharT, Traits> x,
    const std::basic_string<CharT, Traits, Allocator>& y) noexcept
{
    return x <= basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) <= y;
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator<=(const std::basic_string<CharT, Traits, Allocator>& x,
    basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) <= y;
}

/**
 * Equivalent to:
 * \code
 *     x <= basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator<=(basic_string_view<CharT, Traits> x, const CharT* y) noexcept
{
    return x <= basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) <= y;
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator<=(const CharT* x, basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) <= y;
}

/**
 * Equivalent to:
 * \code
 *     x >= basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator>=(basic_string_view<CharT, Traits> x,
    const std::basic_string<CharT, Traits, Allocator>& y) noexcept
{
    return x >= basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) >= y;
 * \endcode
 */
template<typename CharT, typename Traits, typename Allocator>
inline constexpr bool operator>=(const std::basic_string<CharT, Traits, Allocator>& x,
    basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) >= y;
}

/**
 * Equivalent to:
 * \code
 *     x >= basic_string_view<CharT, Traits>(y);
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator>=(basic_string_view<CharT, Traits> x, const CharT* y) noexcept
{
    return x >= basic_string_view<CharT, Traits>(y);
}

/**
 * Equivalent to:
 * \code
 *     basic_string_view<CharT, Traits>(x) >= y;
 * \endcode
 */
template<typename CharT, typename Traits>
inline constexpr bool operator>=(const CharT* x, basic_string_view<CharT, Traits> y) noexcept
{
    return basic_string_view<CharT, Traits>(x) >= y;
}

/**
 * \brief Behaves as a FormattedOutputFunction.
 */
template<class CharT, class Traits>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
    const basic_string_view<CharT, Traits> str)
{
    os.rdbuf()->sputn(str.data(), str.size());
    return os;
}

#if ASF_LOGSDK_STRINGVIEW_CPLUSPLUS < 201703L
template<typename CharT, typename Traits>
const typename basic_string_view<CharT, Traits>::size_type basic_string_view<CharT, Traits>::npos = 
    static_cast<typename basic_string_view<CharT, Traits>::size_type>(-1);
#endif

using StringView = basic_string_view<char>;
using WStringView = basic_string_view<wchar_t>;
using U16StringView = basic_string_view<char16_t>;
using U32StringView = basic_string_view<char32_t>;
#if defined(ASF_LOGSDK_STRINGVIEW_HAS_CHAR8T)
using U8StringView = basic_string_view<char8_t>;
#endif

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_STRING_VIEW_HPP