#include <iostream>
#include "Integer.h"
#include "ArrayList.h"
#include "BitSet_OutOfRange.h"
#include "Boolean.h"
#include "String.h"
/*

*/

#ifndef Action__BitSet
#define Action__BitSet
namespace Action
{
	class BitSet: public Object
	{
	public:
		BitSet();
		BitSet(const BitSet &);
		virtual void push_back(Boolean);
		virtual void set(Integer,Boolean);
		virtual Boolean get(Integer);
		virtual BitSet & operator =(const BitSet &);
		virtual Boolean operator ==(const Object & Arg) const override;
		virtual String get_name() const override{
			return "Action::BitSet";
		}
		virtual String to_string() const override{
			return m_data.to_string();
		}
		virtual ~BitSet(){}
	private:
		const static int BITCOUNT=8*sizeof(char);
		int m_iptrByte,m_iptrBit;
		ArrayList<char> m_data;
	};
}
#endif /* Action__BitSet */