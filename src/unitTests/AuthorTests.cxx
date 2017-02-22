#include "MiniCppUnit.hxx"
#include "Author.hxx"

class AuthorTests : public TestFixture<AuthorTests>
{
public:
	TEST_FIXTURE( AuthorTests )
	{
		TEST_CASE( testName_byDefault );
		TEST_CASE( testName_addingName );
	
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

	

};

REGISTER_FIXTURE( AuthorTests )
