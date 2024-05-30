#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include "Book.h"

namespace seneca
{
	template <typename T, unsigned C>
	class Collection
	{
		T  m_items[C]{};
		static T  m_smallestItem; //How to Define it outside the class definition???
		static T  m_largestItem;
		size_t m_numItems{};
	protected:
		T& setSmallestItem(const T& src){
			return (src < m_smallestItem) ? m_smallestItem = src : m_smallestItem;
		}

		T& setLargestItem(const T& src){
			return (src > m_largestItem) ? m_largestItem = src : m_largestItem;
		}
	public:
		Collection() {};
		T getSmallestItem() const {
			return m_smallestItem;
		}

		T getLargestItem() const {
			return m_largestItem;
		}

		size_t size() const {
			return m_numItems;
		}

		unsigned capacity() const {
			return C;
		}

		bool operator+=(const T& src){
			if(m_numItems < C)
			{
				setLargestItem(src);
				setSmallestItem(src);
				m_items[m_numItems++] = src;
				return true;
			}
			return false;
		}

		std::ostream& print(std::ostream& os) const{
			os << "[";
			for (int i = 0; i < m_numItems; ++i)
			{
				os << m_items[i];
				if(i < m_numItems - 1)
					os << ",";
			}
			os << "]" <<std:: endl;
			return os;
		}
	};

	template <typename T, unsigned C>
	T Collection<T,C>::m_smallestItem = 9999;

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem = -9999;

	template<>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

	template<>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

	//Part 2

}

#endif