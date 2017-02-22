#include "MiniCppUnit.hxx"
#include "Author.hxx"

class AuthorTests : public TestFixture<AuthorTests>
{
public:
	TEST_FIXTURE( AuthorTests )
	{
		TEST_CASE( testName_byDefault );
		TEST_CASE( testName_addingName );
		TEST_CASE( testEmployed_byDefault );
		TEST_CASE( testEmployed_afterHiring );
	
	}
	void testName_byDefault()
	{
		Author author;
		ASSERT_EQUALS( "Pedro", author.getName() );
	}
	void testName_addingName()
	{
		Author author;
		author.setName("Antonio");
		ASSERT_EQUALS( "Antonio", author.getName() );
	}
	void testEmployed_byDefault()
	{
		Author author;
		ASSERT_EQUALS( false, author.isEmployed() );
	}
	void testEmployed_afterHiring()
	{
		Author author;
		author.hire();
		ASSERT_EQUALS( true, author.isEmployed() );
	}

	

};

REGISTER_FIXTURE( AuthorTests )
