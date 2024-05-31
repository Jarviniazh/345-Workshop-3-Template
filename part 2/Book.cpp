#include <string>
#include "Book.h"

using namespace std;
namespace seneca
{
	Book::Book() {};

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages): m_title(title), m_numChapters(nChapters), m_numPages(nPages) {};

	bool Book::emptyBook() const{
		return (m_title.length() > 0 && m_numChapters > 0 && m_numPages > 0) ? false : true;
	}

	double Book::chPageRatio() const{
		return static_cast<double>(m_numPages) / static_cast<double>(m_numChapters);
	}

	ostream& Book::print(ostream& os) const{
		if(!emptyBook())
		{
			os.setf(ios::right);
			os.width(56);
			os << m_title + "," + to_string(m_numChapters) + "," + to_string(m_numPages) << " | ";
			os.unsetf(ios::right);

			os.setf(ios::left);
			os.setf(ios::fixed);
			os.precision(6);
			os.width(15);
			os << "(" + to_string(chPageRatio()) + ")";
			os.unsetf(ios::left);
			os.unsetf(ios::fixed);
		}
		else
		{
			os << "| Invalid book data";
		}
		return os;
	}

	ostream& operator<<(ostream& os, const Book& bk){
		return bk.print(os);
	}

	bool Book::operator<(const Book& other) const {
		return (chPageRatio() < other.chPageRatio());
	}

	bool Book::operator>(const Book& other) const {
		return (chPageRatio() > other.chPageRatio());
	}

}