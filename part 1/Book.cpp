
#include <string>
#include "Book.h"

using namespace std;
namespace seneca
{
	Book::Book() {};

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages): m_title(title), m_numChapters(nChapters), m_numPages(nPages) {};

	bool Book::emptyBook() const
	{
		return (m_title.length() > 0 && m_numChapters > 0 && m_numPages > 0) ? false : true;
	}

	ostream& Book::print(ostream& os) const
	{
		if(!emptyBook())
		{
			os.setf(ios::right);
			os.width(56);

			string displayStr = m_title + "," + to_string(m_numChapters) + "," + to_string(m_numPages);
			os << displayStr  << " | ";

			os.unsetf(ios::right);
			os.setf(ios::left);
			os.setf(ios::fixed);
			os.precision(6);
			os.width(15);

			string avgPageStr = "(" + to_string((double)m_numPages / (double)m_numChapters) + ")";
			os << avgPageStr;
			os.unsetf(ios::left);
			os.unsetf(ios::fixed);
		}
		else
		{
			os << "| Invalid book data";
		}
		return os;
	}

	ostream& operator<<(ostream& os, const Book& bk)
	{
		return bk.print(os);
	}


}