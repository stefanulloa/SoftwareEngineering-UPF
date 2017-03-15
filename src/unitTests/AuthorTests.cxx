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
		TEST_CASE( testEmployed_afterFiring );
	
	}
	void testName_byDefault()
	{
		Author author;
		ASSERT_EQUALS( "-- Unnamed --", author.name() );
	}
	void testName_addingName()
	{
		Author author;
		author.name("Antonio");
		ASSERT_EQUALS( "Antonio", author.name() );
	}
	void testEmployed_byDefault()
	{
		Author author;
		ASSERT_EQUALS( false, author.isEmployed() );
	}
	void testEmployed_afterHiring()
	{
		Author author;
		author.contract();
		ASSERT_EQUALS( true, author.isEmployed() );
	}
	void testEmployed_afterFiring()
	{
		Author author;
		author.contract();
		author.fire();
		ASSERT_EQUALS( false, author.isEmployed() );
	}

	

};

REGISTER_FIXTURE( AuthorTests )
