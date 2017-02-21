#include "MiniCppUnit.hxx"
#include "Author.hxx"

class AuthorTests : public TestFixture<AuthorTests>
{
public:
	TEST_FIXTURE( AuthorTests )
	{
		TEST_CASE( testName_byDefault );
	
	}
	void testName_byDefault()
	{
		Author author;
		ASSERT_EQUALS( "Pedro", author.getName() );
	}

	

};

REGISTER_FIXTURE( AuthorTests )
