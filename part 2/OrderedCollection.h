#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include <iostream>
#include "Collection.h"

namespace seneca
{
	template <typename T>
	class OrderedCollection : public Collection<T, 72>
	{
	public:
		OrderedCollection() : Collection<T, 72>() {};
		bool operator+=(const T& src){
			if(Collection<T, 72>::size() < 72)
			{
				if(Collection<T, 72>::size() == 0)
				{
					Collection<T, 72>::setSmallestItem(src);
					Collection<T, 72>::setLargestItem(src);
					/*Collection<T, 72>::m_items[0] = src;*/
					this->operator[](0) = src;
					Collection<T, 72>::incrSize();
				}
				else{
					if (src < Collection<T, 72>::getSmallestItem()) {
						Collection<T, 72>::setSmallestItem(src);
					}
					if (src > Collection<T, 72>::getLargestItem()) {
						Collection<T, 72>::setLargestItem(src);
					}

					int low{}, mid{};
					int high = Collection<T, 72>::size() - 1;
					while (low <= high)
					{
						mid = (high + low) / 2;
						if(src < this->operator[](mid)){

						//if (src < Collection<T, 72>::m_items[mid]) {
							high = mid - 1;
						}
						else {
							low = mid + 1;
						}
					}

					for(int i =  Collection<T, 72>::size(); i > low; --i)
					{
						//Collection<T, 72>::m_items[i] = Collection<T, 72>::m_items[i - 1];
						this->operator[](i) = this->operator[](i - 1);
					}
					//Collection<T, 72>::m_items[low] = src;
					this->operator[](low) = src;
					Collection<T, 72>::incrSize();
				}
				return true;
			}
			return false;
		}



	};


}

#endif
