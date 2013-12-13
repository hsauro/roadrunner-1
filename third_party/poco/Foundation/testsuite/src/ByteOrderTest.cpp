//
// ByteOrderTest.cpp
//
// $Id: //poco/1.4/Foundation/testsuite/src/ByteOrderTest.cpp#1 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "ByteOrderTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/ByteOrder.h"


using Poco::ByteOrder;
using Poco::Int16;
using Poco::UInt16;
using Poco::Int32;
using Poco::UInt32;
#if defined(POCO_HAVE_INT64)
using Poco::Int64;
using Poco::UInt64;
#endif


ByteOrderTest::ByteOrderTest(const std::string& name): CppUnit::TestCase(name)
{
}


ByteOrderTest::~ByteOrderTest()
{
}


void ByteOrderTest::testByteOrderFlip()
{
	{
		Int16 norm = (Int16) 0xAABB;
		Int16 flip = ByteOrder::flipBytes(norm);
		assert (UInt16(flip) == 0xBBAA);
		flip = ByteOrder::flipBytes(flip);
		assert (flip == norm);
	}
	{
		UInt16 norm = (UInt16) 0xAABB;
		UInt16 flip = ByteOrder::flipBytes(norm);
		assert (flip == 0xBBAA);
		flip = ByteOrder::flipBytes(flip);
		assert (flip == norm);
	}
	{
		Int32 norm = 0xAABBCCDD;
		Int32 flip = ByteOrder::flipBytes(norm);
		assert (UInt32(flip) == 0xDDCCBBAA);
		flip = ByteOrder::flipBytes(flip);
		assert (flip == norm);
	}
	{
		UInt32 norm = 0xAABBCCDD;
		UInt32 flip = ByteOrder::flipBytes(norm);
		assert (flip == 0xDDCCBBAA);
		flip = ByteOrder::flipBytes(flip);
		assert (flip == norm);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = (Int64(0x8899AABB) << 32) + 0xCCDDEEFF;
		Int64 flip = ByteOrder::flipBytes(norm);
		assert (flip == (Int64(0xFFEEDDCC) << 32) + 0xBBAA9988);
		flip = ByteOrder::flipBytes(flip);
		assert (flip == norm);
	}
	{
		UInt64 norm = (UInt64(0x8899AABB) << 32) + 0xCCDDEEFF;
		UInt64 flip = ByteOrder::flipBytes(norm);
		assert (flip == (UInt64(0xFFEEDDCC) << 32) + 0xBBAA9988);
		flip = ByteOrder::flipBytes(flip);
		assert (flip == norm);
	}
	#endif
}


void ByteOrderTest::testByteOrderBigEndian()
{
#if defined(POCO_ARCH_BIG_ENDIAN)
	//
	// big-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toBigEndian(norm);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toBigEndian(norm);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toBigEndian(norm);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toBigEndian(norm);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toBigEndian(norm);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toBigEndian(norm);
		assert (norm == flip);
	}
	#endif
	
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromBigEndian(norm);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromBigEndian(norm);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromBigEndian(norm);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromBigEndian(norm);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromBigEndian(norm);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromBigEndian(norm);
		assert (norm == flip);
	}
	#endif
#else
	//
	// little-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#endif
	
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromBigEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#endif
#endif
}


void ByteOrderTest::testByteOrderLittleEndian()
{
#if defined(POCO_ARCH_LITTLE_ENDIAN)
	//
	// big-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	#endif
	
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toLittleEndian(norm);
		assert (norm == flip);
	}
	#endif
#else
	//
	// little-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#endif
	
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromLittleEndian(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#endif
#endif
}


void ByteOrderTest::testByteOrderNetwork()
{
#if defined(POCO_ARCH_BIG_ENDIAN)
	//
	// big-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toNetwork(norm);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toNetwork(norm);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toNetwork(norm);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toNetwork(norm);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toNetwork(norm);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toNetwork(norm);
		assert (norm == flip);
	}
	#endif
	
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromNetwork(norm);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromNetwork(norm);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromNetwork(norm);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromNetwork(norm);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromNetwork(norm);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromNetwork(norm);
		assert (norm == flip);
	}
	#endif
#else
	//
	// little-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#endif
	
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromNetwork(norm);
		assert (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assert (norm == flip);
	}
	#endif
#endif
}


void ByteOrderTest::setUp()
{
}


void ByteOrderTest::tearDown()
{
}


CppUnit::Test* ByteOrderTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ByteOrderTest");

	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderFlip);
	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderBigEndian);
	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderLittleEndian);
	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderNetwork);

	return pSuite;
}