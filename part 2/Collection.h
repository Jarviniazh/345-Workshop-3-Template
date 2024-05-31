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
		static T  m_smallestItem; 
		static T  m_largestItem;
		int m_numItems{};
	protected:
		T& setSmallestItem(const T& src) {
			return (src < m_smallestItem) ? m_smallestItem = src : m_smallestItem;
		}

		T& setLargestItem(const T& src){
			return (src > m_largestItem) ? m_largestItem = src : m_largestItem;
		}

		//Part 2
		T& operator[](int i) {
			return m_items[i];
		}

		int incrSize() {
			return m_numItems++;
		}

	public:
		Collection() {};
		T getSmallestItem() const {
			return m_smallestItem;
		}

		T getLargestItem() const {
			return m_largestItem;
		}

		unsigned size() const {
			return m_numItems;
		}

		unsigned capacity() const {
			return C;
		}

		bool operator+=(const T& src){
			if(static_cast<unsigned int>(m_numItems) < C)
			{
				setLargestItem(src);
				setSmallestItem(src);
				m_items[m_numItems++] = src;
				return true;
			}
			return false;
		}

		std::ostream& print(std::ostream& os) const{
			if (m_numItems > 0) {
				os << "[";
				for (int i = 0; i < m_numItems; ++i)
				{
					os << m_items[i];
					if (i < m_numItems - 1)
						os << ",";
				}
				os << "]" << std::endl;
			}
			return os;
		}
	};

	template <typename T, unsigned C>
	T Collection<T,C>::m_smallestItem = 9999;

	template <typename T, unsigned C>
	T Collection<T, C>::m_largestItem = -9999;

	//Specialization for Book
	template<>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

	template<>
	Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

	//Part 2
	template<>
	Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

	template<>
	Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

	template<>
	std::ostream& Collection<Book, 10>::print(std::ostream& os) const {
		if(size() > 0) {
			os << "| ---------------------------------------------------------------------------|" << std::endl;
			for (auto i = 0u; i < size(); ++i) {
				os << "| ";
				m_items[i].print(os) << " |" << std::endl;
			}
			os << "| ---------------------------------------------------------------------------|" << std::endl;
		}
		return os;
	}

	template<>
	std::ostream& Collection<Book, 72>::print(std::ostream& os) const {
		if (size() > 0) {
			os << "| ---------------------------------------------------------------------------|" << std::endl;
			for (auto i = 0u; i < size(); ++i) {
				os << "| ";
				m_items[i].print(os) << " |" << std::endl;
			}
			os << "| ---------------------------------------------------------------------------|" << std::endl;
		}
		return os;
	}

}

#endif