#include <iostream>
#include "Object.h"

/*
    我本可以忍受黑暗
    如果不曾见过太阳
*/

#ifndef Action__Byte
#define Action__Byte
namespace Action
{
    class Boolean;
    class Byte : public Object
    {
        private:
            char m_value;
        public:
            Byte()
            {
                m_value = 0;
            }
            Byte(char value)
            {
                m_value = value;
            }
            Byte(const Byte & another)
            {
                m_value = another.m_value;
            }
            Byte & operator = (const Byte & another)
            {
                m_value = another.m_value;
                return *this;
            }
            virtual inline char get_val() const
            {
                return m_value;
            }
            virtual inline void set_val(char value)
            {
                m_value = value;
            }
            virtual Boolean operator == (const Object &) const override;
            virtual String get_name() const override;
            virtual String to_string() const override;
            virtual int hash_code() const override;
    };
}
#endif /* Action__Byte */
