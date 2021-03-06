#include <iostream>
#include "Allocator.h"
#include "Integer.h"
#include "Object.h"
#include <cstdlib>
#include "ArrayList_IndexOutOfRange.h"
#include "ArrayList_IllegalPointer.h"
#include "Boolean.h"

/*
    哪里有什么岁月静好
    只不过是有人在为我们负重前行
*/

#ifndef Action__ArrayList
#define Action__ArrayList
namespace Action
{
    template <class T>
    class ArrayList: public Object
    {
        public:
            friend class String;
            struct Pointer
            {
                private:
                    ArrayList<T> * m_list;
                    int m_index;
                public:
                    Pointer(ArrayList<T> & now_list, Integer index) :
                        m_list(&now_list), m_index(index.get_int()) {}

                    T & operator *()
                    {
                        if(m_index >= m_list->size() || m_index < 0)
                            throw ArrayList_IndexOutOfRange();
                        return (*m_list) [m_index];
                    }

                    T * operator ->()
                    {
                        return & (operator *());
                    }

                    Pointer operator ++ (int)
                    {
                        return Pointer(*m_list, m_index++);
                    }

                    Pointer & operator ++()
                    {
                        ++m_index;
                        return *this;
                    }

                    Pointer operator -- (int)
                    {
                        return Pointer(*m_list, m_index--);
                    }

                    Pointer & operator --()
                    {
                        --m_index;
                        return *this;
                    }

                    Pointer operator + (Integer offset) const
                    {
                        return Pointer(*m_list, m_index + offset);
                    }

                    Pointer operator - (Integer offset) const
                    {
                        return Pointer(*m_list, m_index - offset);
                    }

                    Pointer operator += (Integer offset)
                    {
                        m_index += offset.get_int();
                        return *this;
                    }

                    Pointer operator -= (Integer offset)
                    {
                        m_index -= offset.get_int();
                        return *this;
                    }

                    Boolean operator == (const Pointer & another_pointer) const
                    {
                        return Boolean(m_list == another_pointer.m_list && m_index == another_pointer.m_index);
                    }

                    Boolean operator != (const Pointer & another_pointer) const
                    {
                        return NOT(*this == another_pointer);
                    }

                    void insert(const T & value)
                    {
                        m_list->insert(m_index, value);
                    }

                    void insert(const Pointer & begin, const Pointer & end)
                    {
                        if(begin.m_list != end.m_list)
                            throw ArrayList_IllegalPointer();
                        m_list->insert(m_index, *begin.m_list, begin.m_index, end.m_index);
                    }

                    void erase()
                    {
                        m_list->erase(m_index);
                    }
            };

            ArrayList();
            ArrayList(Integer);
            ArrayList(const ArrayList &);
            ArrayList & operator = (const ArrayList &);
            virtual Pointer begin()
            {
                return Pointer(*this, 0);
            }
            virtual Pointer end()
            {
                return Pointer(*this, size());
            }

            virtual void resize(Integer, const T & Val = T());
            virtual T & operator [](Integer);
            virtual T at(Integer) const;
            virtual T front() const;
            virtual T back() const;
            virtual void push_back(const T &);
            virtual void pop_back();
            virtual void insert(Integer, const T &);
            virtual void insert(Pointer, const T &);
            virtual void insert(Integer, const ArrayList<T> &,
                                Integer, Integer);
            virtual void insert(Integer, const ArrayList<T> &);
            virtual void erase(Integer);
            virtual void erase(Integer, Integer);
            virtual void erase(Pointer);
            virtual void clear();
            virtual Boolean operator == (const Object &) const override;
            virtual inline Integer size() const
            {
                return m_size;
            }
            virtual inline Boolean empty() const
            {
                return Boolean(size() <= 0);
            }
            virtual Integer find(const T &) const;
            virtual String get_name() const override;
            virtual String to_string() const override;
            virtual ~ArrayList();
        protected:
            int m_size;
            Allocator<T> m_alloc;
            T * m_data;
    };
}
#endif /* Action__ArrayList */
