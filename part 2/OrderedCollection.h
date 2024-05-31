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
			if(this->size() < 72)
			{
				if(this->size() == 0)
				{
					this->setSmallestItem(src);
					this->setLargestItem(src);
					
					(*this)[0] = src;
					this->incrSize();
				}
				else{
					if (src < this->getSmallestItem()) {
						this->setSmallestItem(src);
					}
					if (src > this->getLargestItem()) {
						this->setLargestItem(src);
					}

					int low{}, mid{};
					int high = this->size() - 1;
					while (low <= high)
					{
						mid = (high + low) / 2;
						if(src < (*this)[mid]){

							high = mid - 1;
						}
						else {
							low = mid + 1;
						}
					}

					for(int i = this->size(); i > low; --i)
					{
						(*this)[i] = (*this)[i - 1];
					}
					(*this)[low] = src;
					this->incrSize();
				}
				return true;
			}
			return false;
		}



	};


}

#endif
