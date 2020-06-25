#pragma once

namespace ksb
{
	template<typename ForwardIter, typename Func>
	constexpr Func ForEach(ForwardIter begin, ForwardIter end, Func func)
	{
		while (begin != end)
		{
			func(*begin);
			begin++;
		}

		return func;
	}

	template<typename ForwardIter, typename Func>
	constexpr Func ForEachN(ForwardIter begin, size_t n, Func func)
	{
		for (size_t i = 0; i < n; i++)
		{
			func(*begin);

			begin++;
		}

		return func;
	}

	template <typename ForwardIter, typename T>
	constexpr size_t Count(ForwardIter begin, ForwardIter end, const T& target)
	{
		size_t count = 0;

		while (begin != end)
		{
			if (*begin == target)
			{
				count++;
			}
			begin++;
		}

		return count;
	}

	template <typename ForwardIter, typename UnaryPredicate>
	constexpr size_t CountIf(ForwardIter begin, ForwardIter end, UnaryPredicate func)
	{
		size_t count = 0;
		while (begin != end)
		{
			if (func(*begin))
			{
				count++;
			}
			begin++;
		}

		return count;
	}

	template <typename InputIter1, typename InputIter2>
	std::pair<InputIter1, InputIter2> Mismatch(InputIter1 firstBegin, InputIter1 firstEnd, InputIter2 secondBegin)
	{
		while (firstBegin != firstEnd && *firstBegin == *secondBegin)
		{
			firstBegin++;
			secondBegin++;
		}

		return std::make_pair(firstBegin, secondBegin);
	}

	template <typename ForwardIter, typename T>
	constexpr ForwardIter Find(ForwardIter begin, ForwardIter end, const T& value)
	{
		while (begin != end)
		{
			if (*begin == value)
			{
				return begin;
			}

			begin++;
		}

		return end;
	}

	template <typename ForwardIter, typename UnaryPredicate>
	constexpr ForwardIter FindIf(ForwardIter begin, ForwardIter end, UnaryPredicate func)
	{
		while (begin != end)
		{
			if (func(*begin))
			{
				return begin;
			}
			begin++;
		}

		return end;
	}

	template <typename ForwardIter, typename UnaryPredicate>
	constexpr ForwardIter FindIfNot(ForwardIter begin, ForwardIter end, UnaryPredicate func)
	{
		while (begin != end)
		{
			if (!func(*begin))
			{
				return begin;
			}
			begin++;
		}

		return end;
	}

	template <typename ForwardIter>
	constexpr ForwardIter AdjacentFind(ForwardIter begin, ForwardIter end)
	{
		if (begin == end)
		{
			return end;
		}

		// Create an iterator that is one past the begin
		ForwardIter next = begin;
		next++;

		while (next != end)
		{
			if ((*begin) == (*next))
			{
				return begin;
			}

			next++;
			begin++;
		}

		return end;
	}

	template <typename ForwardIter, typename BinaryPredicate>
	constexpr ForwardIter AdjacentFind(ForwardIter begin, ForwardIter end, BinaryPredicate func)
	{
		if (begin == end)
		{
			return end;
		}

		ForwardIter next = begin;
		next++;

		while (next != end)
		{
			if (func(*begin, *next))
			{
				return begin;
			}
			next++;
			begin++;
		}

		return end;
	}

	template<typename ForwardIter1, typename ForwardIter2>
	constexpr ForwardIter1 Search(ForwardIter1 begin, ForwardIter1 end, ForwardIter2 sBegin, ForwardIter2 sEnd)
	{
		if (begin == end || sBegin == sEnd)
		{
			return end;
		}

		while (begin != end)
		{
			auto temp = begin;

			for (auto it = sBegin;; it++, temp++)
			{
				if (it == sEnd)
				{
					return begin;
				}

				if (*temp != *it)
				{
					break;
				}
			}

			begin++;
		}

		return end;
	}

	template <typename ForwardIter1, typename ForwardIter2, typename BinaryPredicate>
	constexpr ForwardIter1 Search(ForwardIter1 begin, ForwardIter1 end, ForwardIter2 sBegin, ForwardIter2 sEnd, BinaryPredicate func)
	{
		if (begin == end || sBegin == sEnd)
		{
			return end;
		}

		while (begin != end)
		{
			ForwardIter1 temp = begin;

			for (auto it = sBegin; ; it++, temp++)
			{
				if (it == sEnd)
				{
					return begin;
				}

				if (!func(*temp, *it))
				{
					break;
				}

			}
			begin++;
		}
		return end;
	}

	template <typename ForwardIter, class T>
	constexpr ForwardIter SearchN(ForwardIter begin, ForwardIter end, size_t count, const T& value)
	{
		if (begin == end)
		{
			return end;
		}



	}

}